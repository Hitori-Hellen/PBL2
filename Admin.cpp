#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin() {
    this->Account = "admin";
    this->Password = "hello";
}
bool Admin::signIn(string Admin_account, string Admin_password) {
    bool check = false;
    if (this->Account == Admin_account && this->Password == Admin_password) {
        check = true;
    }
    return check;
}
void Admin::setAccount(string Admin_Account) {
    this->Account = Admin_Account;
}
string Admin::getAccount() {
    return this->Account;
}
void Admin::setPassword(string Admin_Password) {
    this->Password = Admin_Password;
}
string Admin::getPassword() {
    return this->Password;
}