#include "QLK.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// QLK::QLK(){
//     this->arr = nullptr;
//     this->len = 0;
// }
QLK::QLK(string FilePath) {
    int number_of_lines = 0;
    ifstream in;
    in.open(FilePath);
    string line;
    while (getline(in, line)) {
        ++number_of_lines;
    }
    this->len = 0;
    this->arr = new Game[number_of_lines];
    // cout << number_of_lines << endl;
    in.close();
    string _Name_game;
    string _Genre_game;
    string _Developer_game;
    int _ReleaseYear_game;
    int _Price_game;
    int _NumberS_game;
    double _Rating_game;
    in.open(FilePath);
    while (!in.eof()) {
        in >> _Name_game >> _Genre_game >> _Developer_game >> _ReleaseYear_game >> _Price_game >> _NumberS_game >> _Rating_game;
        Game object;
        object.setName(_Name_game);
        object.setGen(_Genre_game);
        object.setDev(_Developer_game);
        object.setYear(_ReleaseYear_game);
        object.setPrice(_Price_game);
        object.setStock(_NumberS_game);
        object.setRating(_Rating_game);
        *(arr + this->len) = object;
        this->len++;
    }
    in.close();
}
QLK::~QLK() {
    delete[] this->arr;
}
void QLK::Length(int x) {
    this->len = x;
}
int QLK::Length() {
    return this->len;
}
void QLK::Add(Game l, string FilePath) {
    if (this->len == 0) {
        this->arr = new Game[this->len + 1];
        *(this->arr + this->len) = l;
    } else {
        Game *Dulieu = new Game[this->len];
        for (int i = 0; i < this->len; i++) {
            *(Dulieu + i) = *(this->arr + i);
        }
        delete[] this->arr;
        this->arr = new Game[this->len + 1];
        for (int i = 0; i < this->len; i++) {
            *(this->arr + i) = *(Dulieu + i);
        }
        *(this->arr + this->len) = l;
    }
    ofstream gamedb;
    gamedb.open(FilePath, ios::app);
    gamedb << endl;
    gamedb << l.getName() << " " << l.getGen() << " " << l.getDev() << " " << l.getYear() << " " << l.getPrice() << " " << l.getStock() << " " << l.getRating();
    gamedb.close();
    this->len++;
}
// con tro ham
void QLK::Sort(string c) {
    if (c == "year") {
        for (int i = 0; i < this->len - 1; i++) {
            for (int j = this->len - 1; j > i; j--) {
                if ((*(this->arr + j)).getYear() < (*(this->arr + j - 1)).getYear()) {
                    Game *cop = new Game[this->len];
                    *(cop) = *(this->arr + j);
                    *(this->arr + j) = *(this->arr + j - 1);
                    *(this->arr + j - 1) = *(cop);
                }
            }
        }
    } else if (c == "price") {
        for (int i = 0; i < this->len - 1; i++) {
            for (int j = this->len - 1; j > i; j--) {
                if ((*(this->arr + j)).getPrice() < (*(this->arr + j - 1)).getPrice()) {
                    Game *cop = new Game[this->len];
                    *(cop) = *(this->arr + j);
                    *(this->arr + j) = *(this->arr + j - 1);
                    *(this->arr + j - 1) = *(cop);
                }
            }
        }
    } else if (c == "rate") {
        for (int i = 0; i < this->len - 1; i++) {
            for (int j = this->len - 1; j > i; j--) {
                if ((*(this->arr + j)).getRating() < (*(this->arr + j - 1)).getRating()) {
                    Game *cop = new Game[this->len];
                    *(cop) = *(this->arr + j);
                    *(this->arr + j) = *(this->arr + j - 1);
                    *(this->arr + j - 1) = *(cop);
                }
            }
        }
    } else {
        for (int i = 0; i < this->len - 1; i++) {
            for (int j = this->len - 1; j > i; j--) {
                if ((*(this->arr + j)).getName() < (*(this->arr + j - 1)).getName()) {
                    Game *cop = new Game[this->len];
                    *(cop) = *(this->arr + j);
                    *(this->arr + j) = *(this->arr + j - 1);
                    *(this->arr + j - 1) = *(cop);
                }
            }
        }
    }
}
void QLK::Show_QLK() {
    for (int i = 0; i < this->len; i++) {
        (*(this->arr + i)).show();
    }
}
void QLK::Delete(Game l, int idx) {
    if (this->len == 1) {
        delete[] this->arr;
    } else {
        Game *temp = new Game[this->len];
        for (int i = 0; i < this->len; i++) {
            *(temp + i) = *(this->arr + i);
        }
        delete[] this->arr;
        this->arr = new Game[this->len - 1];
        for (int i = 0; i < this->len - 1; i++) {
            if (i < idx) {
                *(this->arr + i) = *(temp + i);
            } else {
                *(this->arr + i) = *(temp + i + 1);
            }
        }
        this->len--;
    }
}
void QLK::Update_data(Game l, int index) {
    *(this->arr + index) = l;
}
void QLK::Update_numberS(bool x, int y = 0, int index = 0) {
    if (x == true) {
        (*(this->arr + index)).setStock((*(this->arr + index)).getStock() - 1);
    } else {
        (*(this->arr + index)).setStock((*(this->arr + index)).getStock() + y);
    }
}
int QLK::search(string inp) {
    int base = -1;
    for (int i = 0; i < this->len; i++) {
        if ((this->arr + i)->getName() == inp) {
            base = i;
            break;
        }
    }
    return base;
}
Game QLK::Return_object(int idx) {
    Game object;
    object = *(this->arr + idx);
    return object;
}
int Find_string(string s1, string s2) {
    int i, j;
    int l1 = s1.length();
    int l2 = s2.length();
    for (i = 0; i < l2 - l1; i++) {
        for (j = 0; j < l1; j++) {
            if (s2[i + j] != s1[j]) {
                break;
            }
        }
        if (j == l1) {
            return i;
        }
    }
    return -1;
}
void QLK::Search_and_Show(string Game_id) {
    for (int i = 0; i < this->len; i++) {
        Game Temp_obj = *(this->arr + i); // 0 error
        // Temp_obj.show();
        string Name_g = Temp_obj.getName();
        if (Find_string(Game_id, Name_g) != -1) {
            Temp_obj.show();
        }
    }
}