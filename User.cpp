#include "User.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

User::User() {
}
User::User(string User_Account, string User_Password) {
    this->Account = User_Account;
    this->Password = User_Password;
    this->Age = 0;
    this->Balance = 0;
    this->User_library_len = 0;
    this->User_library = nullptr;
}
User::User(string User_Account, string User_Password, int User_Age, long User_Balance) {
    this->Account = User_Account;
    this->Password = User_Password;
    this->Age = User_Age;
    this->Balance = User_Balance;
    this->User_library_len = 0;
    this->User_library = nullptr;
}
User::~User() {
}
/* void User::CreateUser_library(){
    this->User_library = new string[this->User_library_len + 1];
    *(this->User_library + this->User_library_len) = "Empty";
} */
void User::sUser_library(string arr[], int len_arr) {
    this->User_library = new string[len_arr];
    for (int i = 0; i < len_arr; i++) {
        *(this->User_library + i) = *(arr + i);
    }
}
int User::gUser_library_len() {
    return this->User_library_len;
}
/*
string User::gUser_library(){
    return *(this->User_library + 0);
} */
void User::sUser_library_len(int len) {
    this->User_library_len = len;
}
void User::sAccount(string User_Account) {
    this->Account = User_Account;
}
string User::gAccount() {
    return this->Account;
}
void User::sPassword(string User_Password) {
    this->Password = User_Password;
}
string User::gPassword() {
    return this->Password;
}
void User::sAge(int User_Age) {
    this->Age = User_Age;
}
int User::gAge() {
    return this->Age;
}
void User::sBalance(long User_Balance) {
    this->Balance = User_Balance;
}
void User::aBalance(long Add_money) {
    this->Balance += Add_money;
}
long User::gBalance() {
    return this->Balance;
}
void User::Buy(string Game_ID) {
    if (this->User_library_len == 0) {
        this->User_library = new string[User_library_len + 1];
        *(User_library + this->User_library_len) = Game_ID;
        this->User_library_len++;
    } else {
        string *Temp = new string[this->User_library_len];
        for (int i = 0; i < this->User_library_len; i++) {
            *(Temp + i) = *(this->User_library + i);
        }
        delete[] this->User_library;
        this->User_library = new string[this->User_library_len + 1];
        for (int i = 0; i < this->User_library_len; i++) {
            *(this->User_library + i) = *(Temp + i);
        }
        *(this->User_library + this->User_library_len) = Game_ID;
        this->User_library_len++;
    }
}
void User::Show_User(QLK &DB) {
    cout << "Your Account: " << this->Account << " "
         << "Your Age: " << this->Age << " "
         << "Your Balance: " << this->Balance << endl;
    cout << "Your library Game: " << this->User_library_len << endl;
    for (int i = 0; i < this->User_library_len; i++) {
        int Game_index = DB.Search(*(this->User_library + i));
        Game obj_temp = DB.Return_object(Game_index);
        obj_temp.Show();
    }
}
// void User::Show_User_Name() {
//     cout << this->Account << " " << this->Password << endl;
// }
string User::Show_User_library() {
    return *(this->User_library);
}
ListUser::ListUser(string FilePath_user) {
    int number_of_lines = 0;
    ifstream in;
    in.open(FilePath_user);
    string line;
    while (getline(in, line)) {
        ++number_of_lines;
    }
    this->List_user_len = 0;
    this->List_User = new User[number_of_lines];
    in.close();
    string Var_User_Account;
    string Var_User_Password;
    int Var_User_Age;
    long Var_User_Balance;
    int Var_User_library_len;
    string Var_User_Game_Id;
    in.open(FilePath_user);
    string line1;
    while (getline(in, line1)) {
        istringstream iss(line1);
        iss >> Var_User_Account >> Var_User_Password >> Var_User_Age >> Var_User_Balance >> Var_User_library_len;
        if (Var_User_library_len == 0) {
            User User_Temp_obj(Var_User_Account, Var_User_Password, Var_User_Age, Var_User_Balance);
            *(List_User + this->List_user_len) = User_Temp_obj;
            this->List_user_len++;
        } else {
            int i = 0;
            string *arr = new string[Var_User_library_len];
            while (iss >> Var_User_Game_Id) {
                *(arr + i) = Var_User_Game_Id;
                i++;
            }
            User User_Temp_obj;
            User_Temp_obj.sAccount(Var_User_Account);
            User_Temp_obj.sPassword(Var_User_Password);
            User_Temp_obj.sAge(Var_User_Age);
            User_Temp_obj.sBalance(Var_User_Balance);
            User_Temp_obj.sUser_library_len(Var_User_library_len);
            User_Temp_obj.sUser_library(arr, i);
            *(List_User + this->List_user_len) = User_Temp_obj;
            this->List_user_len++;
        }
    }
    in.close();
}
ListUser::~ListUser() {
    delete[] this->List_User;
}
bool ListUser::Sign_in(string Input_Account, string Input_Password) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gAccount() == Input_Account && (this->List_User + i)->gPassword() == Input_Password) {
            inp = true;
            break;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}
bool ListUser::Check_account(string Input) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gAccount() == Input) {
            inp = true;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}
bool ListUser::Check_password(string Input) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gPassword() == Input) {
            inp = true;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}
void ListUser::Sign_up(string Input_Account, string Input_Password, string FilePath_user) {
    while (true) {
        if (this->Check_account(Input_Account) == false) {
            User Person(Input_Account, Input_Password);
            cout << "Please enter your age: ";
            int Input_Age;
            cin >> Input_Age;
            Person.sAge(Input_Age);
            // Person.CreateUser_library();
            User *Temp = new User[this->List_user_len];
            for (int i = 0; i < this->List_user_len; i++) {
                *(Temp + i) = *(this->List_User + i);
            }
            delete[] this->List_User;
            this->List_User = new User[this->List_user_len + 1];
            for (int i = 0; i < this->List_user_len; i++) {
                *(this->List_User + i) = *(Temp + i);
            }
            *(this->List_User + this->List_user_len) = Person;
            this->List_user_len++;
            ofstream userdb;
            userdb.open(FilePath_user, ios::app);
            userdb << endl;
            userdb << Person.gAccount() << " " << Person.gPassword() << " " << Person.gAge() << " " << Person.gBalance() << " "
                   << "0";
            userdb.close();
            break;
        } else {
            cout << "Your account is used. Please use another name!!!" << endl;
        }
    }
}
void ListUser::Show_ListUser(QLK &DB) {
    cout << this->List_user_len << endl;
    for (int i = 0; i < this->List_user_len; i++) {
        (*(this->List_User + i)).Show_User(DB);
    }
}
int ListUser::Search_user(string User_name) {
    int base = -1;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gAccount() == User_name) {
            base = i;
            break;
        }
    }
    return base;
}
User ListUser::Return_User(string User_Name) {
    int Index_User = Search_user(User_Name);
    User Temp_User;
    Temp_User = *(this->List_User + Index_User);
    return Temp_User;
}