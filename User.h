#include "QLK.h"
#include <iostream>
#pragma once

using namespace std;

class User {
protected:
    string Account;
    string Password;
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
    int getUser_library_len();
    void setUser_library_len(int);
    void setAccount(string);
    string getAccount();
    void setPassword(string);
    string getPassword();
    void setAge(int);
    int getAge();
    void setBalance(long);
    void addBalance(long);
    long getBalance();
    void buy(string);
    void search(string, QLK &); // Search and show
    void showUser(QLK &);
    void showUserName();
    string showUserLibrary();
};

class ListUser {
private:
    User *List_User;
    int List_user_len;

public:
    ListUser(string);
    ~ListUser();
    bool Check_account(string);
    bool Check_password(string);
    bool Sign_in(string, string);
    void Sign_up(string, string, string);
    void Show_ListUser(QLK &);
    User Return_User(string);
    int Search_user(string);
    Game Return_User_Game(int);
};