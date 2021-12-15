#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(){
    this->Account = "admin";
    this->Password = "hello";
}
bool Admin::Login_admin(string Admin_account, string Admin_password){
    bool check = false;
    if(this->Account == Admin_account && this->Password == Admin_password){
        check = true;
    }
    return check;
}