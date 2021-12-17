#include "Admin.h"
#include "QLK.h"
#include "User.h"
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
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
                    cout << "Countinue? : ";
                    cin >> choice;
                    if (choice == "n" || choice == "N" || choice == "no" || choice == "No" || choice == "NO") {
                        system("cls");
                        break;
                    }
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
                    cout << "\t\t\t\t" << "+            Admin menu           +" << endl;
                    cout << "\t\t\t\t" << "+---------------------------------+" << endl;
                    cout << endl;
                    cout << "------->" << "Welcome Admin!" << endl;
                    cout << "------->" << "What do you want to do:" << endl;
                    cout << "------->" << "1. Show Game Database" << endl;
                    cout << "------->" << "2. Add Game" << endl;
                    cout << "------->" << "3. Update Game Info" << endl;
                    cout << "------->" << "4. Remove Game From Database" << endl;
                    cout << "------->" << "5. Show User List" << endl;
                    cout << "------->" << "6. Delete User" << endl;
                    cout << "------->" << "7. Back" << endl;
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
                        cout << "Enter your sort type(Ex: year, rate, price, name): ";
                        cin >> choice;
                        db_Game.Sort(choice);
                        db_Game.Show_QLK();
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
                        cout << "Enter amount: ";
                        cin >> _NumberS_game;
                        cout << "Enter Rating: ";
                        cin >> _Rating_game;
                        Game Obj_g(_Name_game, _Genre_game, _Developer_game, _ReleaseYear_game, _Price_game, _NumberS_game, _Rating_game);
                        db_Game.addGameDB(Obj_g, GameDBPath);
                        system("pause");
                        system("cls");
                    } else if (choose == 3) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+         Update Game Info        +" <<endl;
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
                        cout << "Enter amount: ";
                        cin >> _NumberS_game;
                        cout << "Enter Rating: ";
                        cin >> _Rating_game;
                        Game Obj_g(_Name_game, _Genre_game, _Developer_game, _ReleaseYear_game, _Price_game, _NumberS_game, _Rating_game);
                        int idx_g = db_Game.search(_Name_game);
                        db_Game.Update_data(Obj_g, idx_g);
                        system("pause");
                        system("cls");
                    } else if (choose == 4) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+    Remove Game from databas     +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        string _Name_game;
                        cout << "Which game do you want to remove: ";
                        cin >> _Name_game;
                        int idx_g = db_Game.search(_Name_game);
                        Game obj_g = db_Game.Return_object(idx_g);
                        db_Game.deleteGameDB(obj_g, idx_g, GameDBPath);
                        system("pause");
                        system("cls");
                    } else if (choose == 5) {
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << "\t\t\t\t" << "+            VAPORWAVE            +" <<endl;
                        cout << "\t\t\t\t" << "+         Show User List          +" <<endl;
                        cout << "\t\t\t\t" << "+---------------------------------+" <<endl;
                        cout << endl;
                        db_User.showListUser(db_Game);
                        system("pause");
                        system("cls");
                    } else if (choose == 6) {
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
                        cout << "Success....";
                        system("pause > nul");
                    } else if (choose == 7) {
                        break;
                    }
                }
                break;
            }
        } else if (choose == 2) {
            while (true) {
                while (true) {
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
                        if (choice == "n" || choice == "N" || choice == "no" || choice == "No" || choice == "NO") {
                            system("cls");
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
                    cout << "\t\t\t\t" << "+            User menu            +" <<endl;
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
                        cout << "\t\t\t\t" << "+        Show your library        +" <<endl;
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
                        db_Game.Show_QLK();
                        cout << "Enter Name of Game you want to buy: ";
                        cin >> name;
                        int idx = db_Game.search(name);
                        Game gameObj = db_Game.Return_object(idx);
                        User.buy(gameObj);
                        db_Game.updateStock(true, 0, idx);
                        cout << "Casting magic spells in the background please wait (*^_^*)" << endl;
                        cout << endl;
                        streamsize prev_precision = cout.precision();
                        for (double i = 0; i < 10; i++) {
                            cout << "\33[2K\r"
                                << "[" << string(6 * i, char(219)) << string(6 * (10 - i), '-') << "]    " << 10 * i << "%  |  " << showpoint << setprecision(2) << "ETA: 00:00:0" << 5 - 0.5 * i;
                            usleep(500000);
                        }
                        cout << "\33[2K\r"
                            << "[" << string(60, char(219)) << "]    "
                            << "100%  |  "
                            << "Completed";
                        usleep(500000);
                        cout << noshowpoint << setprecision(prev_precision);
                        cout << endl;
                        cout << endl;
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
                        cout << "Enter your Number: ";
                        cin >> Money;
                        User.addBalance(Money);
                        system("pause");
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
            cout << "Enter username: ";
            cin >> username;
            cout << endl;
            cout << "Enter password: ";
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