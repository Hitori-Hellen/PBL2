#include <iostream>
#pragma once
using namespace std;
class Person{
    protected:
        string Account;
        string Password;
    public:
        virtual void setAccount(string) = 0;
        virtual void setPassword(string) = 0;
        virtual string getAccount() = 0;
        virtual string getPassword() = 0;
};