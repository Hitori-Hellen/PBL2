#include "Admin.h"
#include "QLK.h"
#include "User.h"
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Person.h"
#include <unistd.h>

using namespace std;
string GetPassword(int length = 32) {
    char c;
    string password;
    c = _getch();
    while (c != 13) {
        if (c == 8 && password != "") {
            password.pop_back();
            cout << '\b' << " " << '\b';
            length++;
        }
        if (c != 8 && length != 0) {
            password += c;
            cout << "*";
            length--;
        }
        c = _getch();
    }
    return password;
}
int main() {
    system("color 0B");
    string GameDBPath = "GameDB.txt";
    string UserDBPath = "UserDB.txt";
    QLK db_Game(GameDBPath);
    ListUser db_User(UserDBPath);
    Admin Admin;
    User User;
    int choose;
    string username, password;
    string choice;
    string name;
    cout << R"(
                    <+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>

                       __     __ _     ____    ___   ____ __        __ _ __     __ _____
                       \ \   / // \   |  _ \  / _ \ |  _ \\ \      / // \\ \   / /| ____|
                        \ \ / // _ \  | |_) || | | || |_) |\ \ /\ / // _ \\ \ / / |  _|
                         \ V // ___ \ |  __/ | |_| ||  _ <  \ V  V // ___ \\ V /  | |___
                          \_//_/   \_\|_|     \___/ |_| \_\  \_/\_//_/   \_\\_/   |_____|


                    <+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>
                 ______  ____
                /_  __/ / __/___ _ ___  ___ _
                 / /_  _\ \ / _ `// _ \/ _ `/      /\/\
                /_/(_)/___/ \_,_//_//_/\_, /      / /  \
                                      /___/      / / /\ \      ______  ___
                                                 \ \/ / /     /_  __/ / _ \ __ __ ___   ___  ___ _
                                                  \  / /       / /_  / // // // // _ \ / _ \/ _ `/
                                                   \/\/       /_/(_)/____/ \_,_/ \___//_//_/\_, /
                                                                                           /___/
    )" << endl;
    sleep(3);
    system("cls");
    cout << "\t\t\t\t" << "+------------------------------------------------+" << endl;
    cout << "\t\t\t\t" << "+       PBL2 : He thong quan ly mua ban Game     +" << endl;
    cout << "\t\t\t\t" << "+                     Nhom : 3                   +" << endl;
    cout << "\t\t\t\t" << "+                Nguoi thuc hien:                +" << endl;
    cout << "\t\t\t\t" << "+      Nguyen Trong Sang - Le Viet Tung Duong    +" << endl;
    cout << "\t\t\t\t" << "+------------------------------------------------+" << endl;
    sleep(3);
    system("cls");
    while (true) {
        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
        cout << endl;
        cout << "------->" << "Welcome" << endl;
        cout << "------->" << "Who Are You" << endl;
        cout << "------->" << "1.Admin" << endl;
        cout << "------->" << "2.User" << endl;
        cout << "------->" << "3.New Guy!" << endl;
        cout << "------->" << "4.Exit" << endl;
        cout << endl;
        cout << "Pick your poison: ";
        cin >> choose;
        system("cls");
        if (choose == 1) {
            while (true) {
                while (true) {
                    cout << "Are you admin for real? ";
                    cin >> choice;
                    if (choice == "n" || choice == "N" || choice == "no" || choice == "No" || choice == "NO") {
                        system("cls");
                        break;
                    }
                    system("cls");
                    cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                    cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                    cout << "\t\t\t\t" << "+           Admin Login           +" <<endl;
                    cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                    cout << endl;
                    cout << "Sign in!" << endl;
                    cout << "Account :";
                    cin >> username;
                    cout << "Password :";
                    password = GetPassword();
                    cout << endl;
                    if (Admin.signIn(username, password) == true) {
                        cout << endl;
                        cout << "Success!" << endl;
                        sleep(2);
                        system("cls");
                        break;
                    }
                }
                if (Admin.signIn(username, password) == false) {
                    break;
                }
                system("cls");
                while (true) {
                    cout << "\t\t\t\t" << "+---------------------------------+" << endl;
                    cout << "\t\t\t\t" << "+            VAPORWAVE            +" << endl;
                    cout << "\t\t\t\t" << "+         Admin Dashboard         +" << endl;
                    cout << "\t\t\t\t" << "+---------------------------------+" << endl;
                    cout << endl;
                    cout << "------->" << "Welcome Admin!" << endl;
                    cout << "------->" << "What do you want to do:" << endl;
                    cout << "------->" << "1. Show Game Database" << endl;
                    cout << "------->" << "2. Add Game" << endl;
                    cout << "------->" << "3. Remove Game From Database" << endl;
                    cout << "------->" << "4. Show User List" << endl;
                    cout << "------->" << "5. Delete User" << endl;
                    cout << "------->" << "6. Back" << endl;
                    cout << endl;
                    cout << "Pick your poison: ";
                    cin >> choose;
                    system("cls");
                    if (choose == 1) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+       Show Game Database        +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        cout << "Enter your sort type(Ex: year, rating, price, name): ";
                        cin >> choice;
                        db_Game.sort(choice);
                        db_Game.showGameDB();
                        system("pause");
                        system("cls");
                    } else if (choose == 2) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+             Add Game            +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        string _Name_game;
                        string _Genre_game;
                        string _Developer_game;
                        int _ReleaseYear_game;
                        int _Price_game;
                        int _NumberS_game;
                        double _Rating_game;
                        cout << "Enter Name: ";
                        cin >> _Name_game;
                        cout << "Enter Genre: ";
                        cin >> _Genre_game;
                        cout << "Enter Developer: ";
                        cin >> _Developer_game;
                        cout << "Enter Release year: ";
                        cin >> _ReleaseYear_game;
                        cout << "Enter Price: ";
                        cin >> _Price_game;
                        cout << "Enter Amount: ";
                        cin >> _NumberS_game;
                        cout << "Enter Rating: ";
                        cin >> _Rating_game;
                        Game Obj_g(_Name_game, _Genre_game, _Developer_game, _ReleaseYear_game, _Price_game, _NumberS_game, _Rating_game);
                        db_Game.addGameDB(Obj_g, GameDBPath);
                        system("pause");
                        system("cls");
                    }  else if (choose == 3) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+    Remove Game from Database    +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        string _Name_game;
                        db_Game.showGameDB();
                        cout << "Which game do you want to remove: ";
                        cin >> _Name_game;
                        int idx_g = db_Game.search(_Name_game);
                        Game obj_g = db_Game.returnGameObj(idx_g);
                        db_Game.deleteGameDB(obj_g, idx_g, GameDBPath);
                        db_Game.showGameDB();
                        system("pause");
                        system("cls");
                    } else if (choose == 4) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+         Show User List          +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        db_User.showListUser(db_Game);
                        system("pause");
                        system("cls");
                    } else if (choose == 5) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+           Delete User           +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        cout << "Enter Account you want to delete: ";
                        string ND;
                        cin >> ND;
                        int User_idx = db_User.searchUser(ND);
                        db_User.deleteAccount(ND, User_idx, UserDBPath);
                        cout << "Aaaaaand it's gone";
                        sleep(2);
                        system("cls");
                    } else if (choose == 6) {
                        break;
                    }
                }
                break;
            }
        } else if (choose == 2) {
            while (true) {
                while (true) {
                    cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                    cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                    cout << "\t\t\t\t" << "+            User Login           +" <<endl;
                    cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                    cout << endl;
                    cout << "Sign in!" << endl;
                    cout << "Account :";
                    cin >> username;
                    cout << "Password :";
                    password = GetPassword();
                    cout << endl;
                    if (db_User.signIn(username, password) == true) {
                        cout << endl;
                        cout << "Success!" << endl;
                        sleep(2);
                        system("cls");
                        break;
                    } else if (db_User.signIn(username, password) == false) {
                        cout << "Login authentication failed. Would you like to retry? ";
                        cin >> choice;
                        system("cls");
                        if (choice == "n" || choice == "N" || choice == "no" || choice == "No" || choice == "NO") {
                            break;
                        }
                    }
                }
                if (db_User.signIn(username, password) == false) {
                    break;
                }
                User = db_User.returnUser(username);
                while (true) {
                    system("cls");
                    cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                    cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                    cout << "\t\t\t\t" << "+            User Menu            +" <<endl;
                    cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                    cout << endl;
                    cout << "------->" << "Welcome " << User.getAccount() << endl;
                    cout << "------->" << "What do you want to do" << endl;
                    cout << "------->" << "1. Show your library" << endl;
                    cout << "------->" << "2. Buy some Game" << endl;
                    cout << "------->" << "3. Add Funds" << endl;
                    cout << "------->" << "4. Back" << endl;
                    cout << endl;
                    cout << "Pick your poison: ";
                    cin >> choose;
                    system("cls");
                    if (choose == 1) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+        Show your Library        +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        User.showUser(db_Game);
                        system("pause");
                        system("cls");
                    } else if (choose == 2) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+          Buy some Game          +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        db_Game.showGameDB();
                        cout << "Yo you wanna buy this new epic game called Half-Life 3 ?" << endl;
                        cout << "Nah i think imma go with ";
                        cin >> name;
                        int idx = db_Game.search(name);
                        Game gameObj = db_Game.returnGameObj(idx);
                        User.buy(gameObj);
                        db_Game.updateStock(true, 0, idx);
                        User.showUser(db_Game);
                        system("pause");
                        system("cls");
                    } else if (choose == 3) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+          Add more Funds         +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        int Money;
                        cout << "Wasting money on video games i see. So tell me how much this time: ";
                        cin >> Money;
                        User.addBalance(Money);
                        cout << endl << "Should've bought some pineapple pizza with all that money";
                        sleep(3);
                        system("cls");
                    } else if (choose == 4) {
                        break;
                    }
                }
                break;
            }
        } else if (choose == 3) {
            cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
            cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
            cout << "\t\t\t\t" << "+             Register            +" <<endl;
            cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
            cout << endl;
            cout << "Tell me your username. Better not be some edgy names: ";
            cin >> username;
            cout << endl;
            cout << "Tell me your password. Don't worry, this will be our little secret: ";
            cin >> password;
            db_User.signUp(username, password, UserDBPath);
            system("cls");
        } else if (choose == 4) {
            cout << "Are you sure you want to exit (#^.^#) ";
            string ans;
            cin >> ans;
            if (ans == "y" || ans == "Yes" || ans == "YES" || ans == "yes") {
                system("cls");
                cout << "\33[2K\rAlright see you next time (^-^)/";
                sleep(2);
                system("color 0F");
                break;
            }
            else {
                system("cls");
                continue;
            }
        }
    }
}