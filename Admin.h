#include "User.h"
#include <iostream>
#pragma once
using namespace std;

class Admin : public Person {
public:
    Admin();
    void setAccount(string);
    void setPassword(string);
    string getAccount();
    string getPassword();
    bool signIn(string, string);
};