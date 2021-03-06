#include "QLK.h"
#include "Person.h"
#include <iostream>
#pragma once

using namespace std;

class User : public Person{
protected:
    int Age;
    long Balance;
    int User_library_len;
    string *User_library;

public:
    User();
    User(string, string);
    User(string, string, int, long);
    ~User();
    void setUser_library(string *, int);
    void setUser_library_len(int);
    void setAccount(string);
    void setPassword(string);
    void setAge(int);
    void setBalance(long);
    void addBalance(long);
    int getUser_library_len();
    string getAccount();
    string getPassword();
    int getAge();
    long getBalance();
    void buy(Game);
    void search(string, QLK &); // Search and show
    void showUser(QLK &);
};

class ListUser {
private:
    User *List_User;
    int List_user_len;

public:
    ListUser(string);
    ~ListUser();
    bool checkAccount(string);
    bool signIn(string, string);
    void signUp(string, string, string);
    void showListUser(QLK &);
    User returnUser(string);
    int searchUser(string);
    void deleteAccount(string, int, string);
};