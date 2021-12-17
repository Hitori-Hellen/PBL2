#include "User.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
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
void User::setUser_library(string arr[], int len_arr) {
    this->User_library = new string[len_arr];
    for (int i = 0; i < len_arr; i++) {
        *(this->User_library + i) = *(arr + i);
    }
}
int User::getUser_library_len() {
    return this->User_library_len;
}
void User::setUser_library_len(int len) {
    this->User_library_len = len;
}
void User::setAccount(string User_Account) {
    this->Account = User_Account;
}
string User::getAccount() {
    return this->Account;
}
void User::setPassword(string User_Password) {
    this->Password = User_Password;
}
string User::getPassword() {
    return this->Password;
}
void User::setAge(int User_Age) {
    this->Age = User_Age;
}
int User::getAge() {
    return this->Age;
}
void User::setBalance(long User_Balance) {
    this->Balance = User_Balance;
}
void User::addBalance(long Add_money) {
    this->Balance += Add_money;
    ofstream tempFile("temp.txt");
    ifstream UserDBFile("UserDB.txt");
    string line;
    string usrname;
    getline(UserDBFile, line);
    istringstream iss(line);
    iss >> usrname;
    if (usrname != this->Account) {
        tempFile << line;
        while(getline(UserDBFile, line)) {
            istringstream iss1(line);
            iss1 >> usrname;
            if (usrname == this->Account) {
                tempFile << endl << this->getAccount() << " " << this->getPassword() << " " << this->getAge() << " " << this->getBalance() << " " << this->getUser_library_len();
                for (int i = 0; i < this->User_library_len; i++) {
                    tempFile << " " << *(this->User_library + i);
                }
            } else {
                tempFile << endl << line;
            }
        }
    } else if (usrname == this->Account) {
        tempFile << this->getAccount() << " " << this->getPassword() << " " << this->getAge() << " " << this->getBalance() << " " << this->getUser_library_len();
        for (int i = 0; i < this->User_library_len; i++) {
            tempFile << " " << *(this->User_library + i);
        }
        while(getline(UserDBFile, line)) {
            tempFile << endl << line;
        }
    }
    tempFile.close();
    UserDBFile.close();
    remove("UserDB.txt");
    rename("temp.txt", "UserDB.txt");
}
long User::getBalance() {
    return this->Balance;
}
void User::buy(Game GameObj) {
    bool libraryCheck = false;
    for (int i = 0; i < this->User_library_len; i++) {
        if (*(this->User_library + i) == GameObj.getName()) {
            libraryCheck = true;
            break;
        }
    }
    if (libraryCheck) {
        cout << "You already own this game!";
    } else if (GameObj.getStock() == 0) {
        cout << "This game is out of stock!";
    } else if (this->Balance < GameObj.getPrice()) {
        cout << "Your wallet balance is too low to cover this transaction!";
    } else {
        if (this->User_library_len == 0) {
            this->User_library = new string[User_library_len + 1];
            *(User_library + this->User_library_len) = GameObj.getName();
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
            *(this->User_library + this->User_library_len) = GameObj.getName();
            this->User_library_len++;
        }
        this->Balance -= GameObj.getPrice();
        GameObj.setStock(GameObj.getStock() - 1);
        ofstream tempFile("temp.txt");
        ifstream UserDBFile("UserDB.txt");
        string line;
        string usrname;
        getline(UserDBFile, line);
        istringstream iss(line);
        iss >> usrname;
        if (usrname != this->Account) {
            tempFile << line;
            while(getline(UserDBFile, line)) {
                istringstream iss1(line);
                iss1 >> usrname;
                if (usrname == this->Account) {
                    tempFile << endl << this->getAccount() << " " << this->getPassword() << " " << this->getAge() << " " << this->getBalance() << " " << this->getUser_library_len();
                    for (int i = 0; i < this->User_library_len; i++) {
                        tempFile << " " << *(this->User_library + i);
                    }
                } else {
                    tempFile << endl << line;
                }
            }
        } else if (usrname == this->Account) {
            tempFile << this->getAccount() << " " << this->getPassword() << " " << this->getAge() << " " << this->getBalance() << " " << this->getUser_library_len();
            for (int i = 0; i < this->User_library_len; i++) {
                tempFile << " " << *(this->User_library + i);
            }
            while(getline(UserDBFile, line)) {
                tempFile << endl << line;
            }
        }
        tempFile.close();
        UserDBFile.close();
        remove("UserDB.txt");
        rename("temp.txt", "UserDB.txt");

        ofstream tempFile1("temp1.txt");
        ifstream GameDBFile("GameDB.txt");
        string gameName;
        getline(GameDBFile, line);
        istringstream iss2(line);
        iss2 >> gameName;
        if (gameName != GameObj.getName()) {
            tempFile1 << line;
            while(getline(GameDBFile, line)) {
                istringstream iss1(line);
                iss1 >> gameName;
                if (gameName == GameObj.getName()) {
                    tempFile1 << endl << GameObj.getName() << " " << GameObj.getGen() << " " << GameObj.getDev() << " " << GameObj.getYear() << " " << GameObj.getPrice() << " " << GameObj.getStock() << " " << GameObj.getRating();
                } else {
                    tempFile1 << endl << line;
                }
            }
        } else if (gameName == GameObj.getName()) {
            tempFile1 << GameObj.getName() << " " << GameObj.getGen() << " " << GameObj.getDev() << " " << GameObj.getYear() << " " << GameObj.getPrice() << " " << GameObj.getStock() << " " << GameObj.getRating();
            while(getline(GameDBFile, line)) {
                tempFile1 << endl << line;
            }
        }
        tempFile1.close();
        GameDBFile.close();
        remove("GameDB.txt");
        rename("temp1.txt", "GameDB.txt");
    }
}
void User::showUser(QLK &DB) {
    cout << "Your Account: " << this->Account << " "
         << "Your Age: " << this->Age << " "
         << "Your Balance: " << this->Balance << endl;
    cout << "Your library Game: " << this->User_library_len << endl;
    cout << "+----------------------------------------------------------------------------------------+" <<endl;
    cout << "+ Name                | Genre               | Developer | Year | Price    | Stock | Rate |" <<endl;
    cout << "+----------------------------------------------------------------------------------------+" <<endl;
    for (int i = 0; i < this->User_library_len; i++) {
        int Game_index = DB.search(*(this->User_library + i));
        Game obj_temp = DB.returnGameObj(Game_index);
        cout << "| " << setw(20) << left << obj_temp.getName() << "| " << setw(20) << left << obj_temp.getGen()
        << "| " << setw(10) << left << obj_temp.getDev()
        << "| " << setw(5) << left << obj_temp.getYear()
        << "| " << setw(9) << left << obj_temp.getPrice()
        << "| " << setw(6) << left << obj_temp.getStock()
        << "| " << setw(5) << left << obj_temp.getRating() << "|" <<endl;
    }
    cout << "+----------------------------------------------------------------------------------------+" <<endl;
}
ListUser::ListUser(string UserDBPath) {
    int number_of_lines = 0;
    ifstream in;
    in.open(UserDBPath);
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
    in.open(UserDBPath);
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
            User_Temp_obj.setAccount(Var_User_Account);
            User_Temp_obj.setPassword(Var_User_Password);
            User_Temp_obj.setAge(Var_User_Age);
            User_Temp_obj.setBalance(Var_User_Balance);
            User_Temp_obj.setUser_library_len(Var_User_library_len);
            User_Temp_obj.setUser_library(arr, i);
            *(List_User + this->List_user_len) = User_Temp_obj;
            this->List_user_len++;
        }
    }
    in.close();
}
ListUser::~ListUser() {
    delete[] this->List_User;
}
bool ListUser::signIn(string Input_Account, string Input_Password) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->getAccount() == Input_Account && (this->List_User + i)->getPassword() == Input_Password) {
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
bool ListUser::checkAccount(string Input) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->getAccount() == Input) {
            inp = true;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}

void ListUser::signUp(string Input_Account, string Input_Password, string UserDBPath) {
    while (true) {
        if (this->checkAccount(Input_Account) == false) {
            User Person(Input_Account, Input_Password);
            cout << "Waiiittttt a minute how old are you: ";
            int Input_Age;
            cin >> Input_Age;
            Person.setAge(Input_Age);
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
            userdb.open(UserDBPath, ios::app);
            userdb << endl;
            userdb << Person.getAccount() << " " << Person.getPassword() << " " << Person.getAge() << " " << Person.getBalance() << " "
                   << "0";
            userdb.close();
            cout << "Here's your account now go grab some games and give me the $$$";
            sleep(2);
            break;
        } else {
            cout << "This name's already taken. Try zZ_DaRkF1Am3mAsTeR69420_Zz" << endl;
            sleep(2);
            break;
        }
    }
}
void ListUser::showListUser(QLK &DB) {
    cout << "Number of User: " << this->List_user_len << endl;
    for (int i = 0; i < this->List_user_len; i++) {
        (*(this->List_User + i)).showUser(DB);
    }
}
int ListUser::searchUser(string User_name) {
    int base = -1;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->getAccount() == User_name) {
            base = i;
            break;
        }
    }
    return base;
}
User ListUser::returnUser(string User_Name) {
    int Index_User = searchUser(User_Name);
    User Temp_User;
    Temp_User = *(this->List_User + Index_User);
    return Temp_User;
}
void ListUser::deleteAccount(string Account, int idx, string UserDBPath) {
    if (this->List_user_len == 1) {
        delete[] this->List_User;
    } else {
        User *temp = new User[this->List_user_len];
        for (int i = 0; i < this->List_user_len; i++) {
            *(temp + i) = *(this->List_User + i);
        }
        delete[] this->List_User;
        this->List_User = new User[this->List_user_len - 1];
        for (int i = 0; i < this->List_user_len - 1; i++) {
            if (i < idx) {
                *(this->List_User + i) = *(temp + i);
            } else {
                *(this->List_User + i) = *(temp + i + 1);
            }
        }
        this->List_user_len--;
    }
    ofstream tempFile("temp.txt");
    ifstream UserDBFile(UserDBPath);
    string line;
    string usrname;
    getline(UserDBFile, line);
    istringstream iss(line);
    iss >> usrname;
    if (usrname != Account) {
        tempFile << line;
        while(getline(UserDBFile, line)) {
            istringstream iss1(line);
            iss1 >> usrname;
            if (usrname != Account) {
                tempFile << endl << line;
            }
        }
    } else if (usrname == Account) {
        getline(UserDBFile, line);
        tempFile << line;
        while(getline(UserDBFile, line)) {
            tempFile << endl << line;
        }
    }
    tempFile.close();
    UserDBFile.close();
    remove("UserDB.txt");
    rename("temp.txt", "UserDB.txt");
}