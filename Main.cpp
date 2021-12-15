#include "Admin.h"
#include "QLK.h"
#include "User.h"
#include <conio.h>
#include <fstream>
#include <iostream>

using namespace std;
string GetPassword(int length = 12) {
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
    /*
        xu li Delete(QLK), buy(User)-ghi vao txt, Delete_user(ListUser)-xoa trong txt, Sort(Tangdan,Giamdan)
        Ham Show_limit_and_search(), doi mat khau CPassword_user()
        Hoan thien Menu main - Sua logic
    */
    string FilePath = "GameDB.txt";
    string FilePath_user = "UserDB.txt";
    QLK db_Game(FilePath);
    ListUser db_User(FilePath_user);
    Admin Admin;
    User User;
    int choose;
    string tk, mk;
    string choice;
    string name;
    bool cb = true;
    while (true) {
        cout << "Welcome" << endl;
        cout << "Who Are You" << endl;
        cout << "1.Admin" << endl;
        cout << "2.User" << endl;
        cout << "3.New Guy!" << endl;
        cout << "4.Exit" << endl;
        cout << endl;
        cout << "Pick your poison: ";
        cin >> choose;
        system("cls");
        if (choose == 1) {
            while (true) {
                while (true) {
                    cout << "Countinue? : ";
                    cin >> choice;
                    if (choice == "No" || choice == "N" || choice == "n") {
                        system("cls");
                        break;
                    }
                    cout << "Sign in!" << endl;
                    cout << "Account :";
                    cin >> tk;
                    cout << "Password :";
                    mk = GetPassword();
                    cout << endl;
                    if (Admin.loginAdmin(tk, mk) == true) {
                        cout << endl;
                        cout << "Success!" << endl;
                        system("pause");
                        char x = getchar();
                        system("cls");
                        break;
                    }
                }
                // !
                if (Admin.loginAdmin(tk, mk) == false) {
                    break;
                }
                system("cls");
                while (true) {
                    cout << "Welcome Admin!" << endl;
                    cout << "What do you want to do:" << endl;
                    cout << "1. Show Game Database" << endl;
                    cout << "2. Add Game" << endl;
                    cout << "3. Update Game Info" << endl;
                    cout << "4. Remove Game From Database" << endl;
                    cout << "5. Show User List" << endl;
                    cout << "6. Back" << endl;
                    cout << endl;
                    cout << "Pick your poison: ";
                    cin >> choose;
                    system("cls");
                    if (choose == 1) {
                        cout << "Enter your sort type: ";
                        cin >> choice;
                        db_Game.Sort(choice);
                        db_Game.Show_QLK();
                        //cout << "Press anykey to come back..";
                        system("pause");
                        char x = getchar();
                        system("cls");
                    } else if (choose == 2) {
                        // INFIle
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
                        db_Game.Add(Obj_g, FilePath);
                        system("pause");
                        char x = getchar();
                        system("cls");
                    } else if (choose == 3) {
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
                        char x = getchar();
                        system("cls");
                    } else if (choose == 4) {
                        // Delete File
                        string _Name_game;
                        cout << "Which game do you want to remove: ";
                        cin >> _Name_game;
                        int idx_g = db_Game.search(_Name_game);
                        Game obj_g = db_Game.Return_object(idx_g);
                        db_Game.Delete(obj_g, idx_g);
                        system("pause");
                        char x = getchar();
                        system("cls");
                    } else if (choose == 5) {
                        db_User.Show_ListUser(db_Game);
                        system("pause");
                        char x = getchar();
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
                    cout << "Sign in!" << endl;
                    cout << "Account :";
                    cin >> tk;
                    cout << "Password :";
                    mk = GetPassword();
                    cout << endl;
                    if (db_User.Sign_in(tk, mk) == true) {
                        cout << endl;
                        cout << "Success!" << endl;
                        system("pause");
                        char x = getchar();
                        system("cls");
                        break;
                    } else if (db_User.Sign_in(tk, mk) == false) {
                        cout << "Countinue? : ";
                        cin >> choice;
                        if (choice == "No" || choice == "N" || choice == "n") {
                            system("cls");
                            break;
                        }
                    }
                }
                if (db_User.Sign_in(tk, mk) == false) {
                    break;
                }
                User = db_User.Return_User(tk);
                while (true) {
                    system("cls");
                    cout << "Welcome " << User.getAccount() << endl;
                    cout << "What do you want to do" << endl;
                    cout << "1. Show your library" << endl;
                    cout << "2. Buy some Game" << endl;
                    cout << "3. Add more Balance" << endl;
                    cout << "4. Back" << endl;
                    cout << endl;
                    cout << "choose your choice: ";
                    cin >> choose;
                    system("pause");
                    char x = getchar();
                    system("cls");
                    if (choose == 1) {
                        User.showUser(db_Game);
                        system("pause");
                        char x = getchar();
                        system("cls");
                    } else if (choose == 2) {
                        db_Game.Show_QLK();
                        // func
                        cout << "Enter Name of Game you want to buy: ";
                        cin >> name;
                        User.buy(name);
                        User.showUser(db_Game);
                        system("pause");
                        char x = getchar();
                        system("cls");
                    } else if (choose == 3) {
                        int Money;
                        cout << "Enter your Number: ";
                        cin >> Money;
                        // password??
                        User.addBalance(Money);
                        system("pause");
                        char x = getchar();
                        system("cls");
                    } else if (choose == 4) {
                        break;
                    }
                }
                break;
            }
        } else if (choose == 3) {
            cout << "Nhap tk: ";
            cin >> tk;
            cout << endl;
            cout << "Nhap mk: ";
            cin >> mk;
            db_User.Sign_up(tk, mk, FilePath_user);
        } else if (choose == 4) {
            cout << "See you soon";
            break;
        }
    }
}