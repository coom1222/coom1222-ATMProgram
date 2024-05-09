//
// Created by 준민쓰 MacBook Air on 4/12/24.
//
#include <iostream>
#include "ATMachine.h"
#include "Account.h"
#include <random>
using namespace std;

// 여기서 develop할거에요
// ATM클래스의 생성자 구현

ATMachine::~ATMachine() {
    delete [] pAcctArray;
}


ATMachine::ATMachine(int size, int balance, const string& password) {
    nMaxAccountNum = size;
    nMachineBalance = balance;
    strManagerPassword = password;
    pAcctArray = new Account[size]; // size만큼 Account 객체 배열 동적 할당
    nCurrentAccountNum = 0; // 현재 계좌 수를 0으로 초기화
}

void ATMachine::displayMenu(){

    cout << "-------------------" << endl;
    cout << "----TUKOREA BANK----" << endl;
    cout << "-------------------" << endl;
    cout << "1. 계좌 개설 " << endl;
    cout << "2. 계좌 조회 " << endl;
    cout << "3. 계좌 해지 " << endl;
    cout << "4. 계좌 입금 " << endl;
    cout << "5. 계좌 출금 " << endl;
    cout << "6. 계좌 이체 " << endl;
    cout << "9. 업무 종료 " << endl;

}

// 계좌 개설
void ATMachine::createAccount() {
    // account.h에서 계좌정보 가져와서 여기서 개설
    string name;
    string password;

    cout << endl;
    cout << "------ 개설 ------" << endl;
    cout << "이름입력 : " ;
    cin >> name;
    cout << "암호 입력: ";
    cin >> password;

    // 계좌 번호 생성
    random_device rd; // 시드값을 제공하는 랜덤 디바이스 생성
    mt19937 gen(rd()); // 랜덤 디바이스를 시드로 사용하는 난수 생성기 생성
    uniform_int_distribution<int> dis(100, 999); // 100~999 범위의 균일 분포
    int accountNumber = dis(gen); // 랜덤 계좌 번호 생성

    if (nCurrentAccountNum < nMaxAccountNum) {
        pAcctArray[nCurrentAccountNum++].create(accountNumber, 0, name, password);
        cout << name << " 님 " << accountNumber << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
    } else {
        cout << "더 이상 계좌를 개설할 수 없습니다." << endl;
    }
}

// 계좌 조회
void ATMachine::checkMoney() {
    int accountNumber;
    string password;
    cout << "계좌 번호를 입력하세요: ";
    cin >> accountNumber;
    cout << "비밀번호를 입력하세요: ";
    cin >> password;

    bool found = false;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == accountNumber) {
            int balance = pAcctArray[i].check(accountNumber, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                cout << "계좌 잔액: " << balance << endl;
                found = true;
                break;
            } else {
                cout << "비밀번호가 올바르지 않습니다." << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "해당하는 계좌가 존재하지 않습니다." << endl;
    }
}


void ATMachine::closeAccount() {
    int accountNumber;
    string password;
    cout << "계좌 번호를 입력하세요: ";
    cin >> accountNumber;
    cout << "비밀번호를 입력하세요: ";
    cin >> password;

    bool found = false;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == accountNumber) {
            if (pAcctArray[i].getBalance() == 0) {
                pAcctArray[i].close();
                cout << accountNumber << "계좌가 해지되었습니다." << endl;
                found = true;
                break;
            } else {
                cout << "잔액이 남아있어 계좌를 해지할 수 없습니다." << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "해당하는 계좌가 존재하지 않습니다." << endl;
    }
}

void ATMachine::depositMoney() {
    int accountNumber;
    string password;
    int depositMoney;

    cout << "계좌 번호를 입력하세요: ";
    cin >> accountNumber;
    cout << "비밀번호를 입력하세요: ";
    cin >> password;
    cout << "입금액을 입력하세요: ";
    cin >> depositMoney;

    bool found = false;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == accountNumber) {
            int balance = pAcctArray[i].check(accountNumber, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                int newBalance = pAcctArray[i].deposit(accountNumber, password, depositMoney);
                cout << "입금이 완료되었습니다. 현재 잔액: " << newBalance << "원" << endl;
                found = true;
                break;
            } else {
                cout << "비밀번호가 올바르지 않습니다." << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "해당하는 계좌가 존재하지 않습니다." << endl;
    }
}

void ATMachine::widrawMoney() {
    int accountNumber;
    string password;
    int widrawMoney;

    cout << "계좌 번호를 입력하세요: ";
    cin >> accountNumber;
    cout << "비밀번호를 입력하세요: ";
    cin >> password;
    cout << "출금액을 입력하세요: ";
    cin >> widrawMoney;

    bool found = false;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == accountNumber) {
            int balance = pAcctArray[i].check(accountNumber, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                if(balance < widrawMoney){
                    cout << "출금액이 계좌 잔액을 초과합니다." << endl;
                }
                else{
                    int newBalance = pAcctArray[i].widraw(accountNumber, password, widrawMoney);
                    cout << "출금이 완료되었습니다. 현재 잔액: " << newBalance << "원" << endl;
                }
                found = true;
                break;
            } else {
                cout << "비밀번호가 올바르지 않습니다." << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "해당하는 계좌가 존재하지 않습니다." << endl;
    }
}

void ATMachine::transfer() {
    int fromAccountNumber, toAccountNumber;
    string password;
    int transferAmount;

    cout << "-----이체------"; << endl;
    cout << "계좌 번호를 입력하세요: ";
    cin >> fromAccountNumber;
    cout << "비밀번호를 입력하세요: ";
    cin >> password;
    cout << "이체계좌를 입력하세요: ";
    cin >> toAccountNumber;
    cout << "이체금액을 입력하세요: ";
    cin >> transferAmount;

    bool foundFromAccount = false, foundToAccount = false;
    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == fromAccountNumber) {
            int balance = pAcctArray[i].check(fromAccountNumber, password);
            if (balance != AUTHENTIFICATION_FAIL) {
                foundFromAccount = true;
                break;
            } else {
                cout << "비밀번호가 올바르지 않습니다." << endl;
                return;
            }
        }
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == toAccountNumber) {
            foundToAccount = true;
            break;
        }
    }

    if (!foundFromAccount) {
        cout << "이체할 계좌가 존재하지 않거나 비밀번호가 올바르지 않습니다." << endl;
        return;
    }

    if (!foundToAccount) {
        cout << "이체받을 계좌가 존재하지 않습니다." << endl;
        return;
    }

    for (int i = 0; i < nCurrentAccountNum; i++) {
        if (pAcctArray[i].getID() == fromAccountNumber) {
            int balance = pAcctArray[i].check(fromAccountNumber, password);
            if (balance >= transferAmount) {
                int newBalance = pAcctArray[i].widraw(fromAccountNumber, password, transferAmount);
                cout << "이체가 완료되었습니다." << endl;
                cout << "현재 잔액: " << newBalance << "원" << endl;
                break;
            } else {
                cout << "이체할 금액이 계좌 잔액을 초과합니다." << endl;
                return;
            }
        }
    }
}
