//
// Created by 준민쓰 MacBook Air on 4/12/24.
//
#include <iostream>
#include "ATMachine.h"
using namespace std;

// 여기서 develop할거에요
// 지금은 feature 브랜치
void ATMachine::displayMenu(){

    cout << "-------------------" << endl;
    cout << "----TUKOREA BANK----" << endl;
    cout << "-------------------" << endl;
    cout << "1. 계좌 개설 " << endl;
    cout << "2. 계좌 해지 " << endl;
    cout << "9. 업무 종료 " << endl;

}

// 일단 빈 함수들 생성, main에서 사용하기 위함.

void ATMachine::checkMoney() {

}

void ATMachine::createAccount() {

}

ATMachine::ATMachine(int size, int balance, std::string password) {

}

ATMachine::~ATMachine() {
    delete [] pAcctArray;
}