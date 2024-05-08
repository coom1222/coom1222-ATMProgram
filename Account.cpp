//
// Created by 준민쓰 MacBook Air on 4/12/24.
//
// 여긴 feature 브랜치에요
#include <iostream>
// #include "ATMachine.h"
#include "Account.h"

using namespace std;

//계좌개설
void Account::create(int id, int money, std::string name, std::string password) {
    nID = id;
    nBalance = money;
    strAccountName = name;
    strPassword = password;
}

//return값:nBalance(잔고) or 인증실패(AUTHENTIFICATION_FAIL)
int Account::check(int id, string password) {
    int authResult = authenticate(id, password); // 인증 결과를 int로 받음
    if (authResult == AUTHENTIFICATION_SUCCESS) { // 인증 성공시
        return nBalance; // 현재 잔액 반환
    } else { // 인증 실패시
        return AUTHENTIFICATION_FAIL; // 인증 실패 상수 반환
    }
}

// 인증 메소드
// 인증 메서드 수정본
int Account::authenticate(int id, string passwd) {
    if ((nID == id) && (strPassword == passwd)) {
        return AUTHENTIFICATION_SUCCESS; // 인증 성공
    } else {
        return AUTHENTIFICATION_FAIL; // 인증 실패
    }
}
