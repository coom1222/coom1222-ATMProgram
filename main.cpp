#include <iostream>
using namespace std;
#include "ATMachine.h"
#include "Account.h"

// 지금은 feature 브랜치
// 다시 커밋합니다.

int main() {
    int select;
    // 고객 수(100명), ATM 잔금 초기화, 관리자 암호
    ATMachine atm(100, 50000, "admin");
    while (1) {
        atm.displayMenu();
        cout <<"메뉴를 선택하세요: ";
        cin >> select;
        cout << endl;
        switch (select) {
            case 1:
                atm.createAccount();
                break;
            case 2:
                atm.checkMoney();
                break;
            case 9:
                break;

                default:
                cout << "번호 확인 후 다시 입력하세요." << endl;
        }
    }
}
