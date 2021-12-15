#include "User.h"
#include <iostream>
#pragma once
using namespace std;

class Admin : public User {
public:
    Admin();
    bool loginAdmin(string, string);
};