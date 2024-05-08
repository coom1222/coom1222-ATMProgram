//
// Created by 준민쓰 MacBook Air on 4/12/24.
//
#include <iostream>
#include "ATMachine.h"
#include "Account.h"
#include <random>
using namespace std;

// 여기서 develop할거에요
// 지금은 feature 브랜치
// 다시 커밋합니다.
ATMachine::ATMachine(int size, int balance, std::string password) {

}

void ATMachine::displayMenu(){

    cout << "-------------------" << endl;
    cout << "----TUKOREA BANK----" << endl;
    cout << "-------------------" << endl;
    cout << "1. 계좌 개설 " << endl;
    cout << "2. 계좌 조회 " << endl;
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

    cout << name << " 님 " << accountNumber << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;

}

// 계좌 조회
void ATMachine::checkMoney() {
    int accountNumber;
    string password;
    cout << "계좌 번호를 입력하세요: ";
    cin >> accountNumber;
    cout << "비밀번호를 입력하세요: ";
    cin >> password;

    for(int i = 0; i < nCurrentAccountNum; ++i) {
        if(pAcctArray[i].check(accountNumber, password)) {
            cout << "계좌 잔액: " << pAcctArray[i].check(accountNumber, password) << endl;
            return;
        }
    }
    cout << "계좌 번호 또는 비밀번호가 일치하지 않습니다." << endl;
}


ATMachine::~ATMachine() {
    delete [] pAcctArray;
}
