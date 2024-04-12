#ifndef ATMACHINE_H
#define ATMACHINE_H
#include "Account.h"    //  동적 생성된 고객계좌 배열 포인터 참조를 위해 추가
using std::string;
#define NEGATIVE_ATM_BALANCE -10 // ATM 잔액 부족

// 지금은 feature 브랜치

class ATMachine {
private:
    Account* pAcctArray; // 동적 생성된 고객계좌 배열 포인터
    int nMachineBalance; // ATM 잔고
    int nMaxAccountNum; // 동적 생성된 고객계좌 배열 크기
    int nCurrentAccountNum; // 개설된 고객 계좌 수
    string strManagerPassword; // 관리자 비밀번호
public:
    ATMachine(int size, int balance, string password); // 계좌 배열크기, ATM 잔고, 관리자 암호 초기화
    ~ATMachine();
    void displayMenu(); // ATM 기능 선택 화면
    void createAccount(); // 계좌 개설
    void checkMoney(); // 계좌 조회
};

#endif

//createAccount() 에서 계좌번호 생성시 (100 ~ 999번) 까지 랜덤으로 번호 생성
//#include <random>
// random_device , mt19937 클래스 활용
