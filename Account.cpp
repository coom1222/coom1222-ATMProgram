#include <iostream>
// #include "ATMachine.h"
#include "Account.h"
using namespace std;


Account::Account() {
    nID = -1;
    nBalance = 0;
}
//계좌개설
void Account::create(int id, int money, string& name, string& password) {
    nID = id;
    nBalance = money;
    strAccountName = name;
    strPassword = password;
}

//return값:nBalance(잔고) or 인증실패(AUTHENTIFICATION_FAIL)
int Account::check(int id, string& password) {
    if (nID == id && strPassword == password) {
        return nBalance;
    } else {
        return AUTHENTIFICATION_FAIL;
    }
}




void Account::close() {
    if (nBalance == 0) {
        nID = -1;
        strAccountName = "";
        strPassword = "";
    }
}

int Account::getBalance() {
    return nBalance;
}

