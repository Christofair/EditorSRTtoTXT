//
// Created by Christofair on 02.07.2017.
//
#include <iostream>
#include <cstring>

#include "PlikSRT.h"
#include "function.h"


using namespace std;
using pos_type = basic_ifstream<char>::pos_type;

pos_type PlikSRT::wczytajBlok() {
    char znak;
    Blok zapis;
    bool juz = false;
    while (true) {
        this->get(znak);
        zapis.dane += znak;
        if (juz) {
            if (znak == '\n') {
                break;
            } else {
                juz = false;
            }
        } else {
            if (znak == '\n') {
                juz = true;
            } else {
                continue;
            }
        }
    }
    bloki.push_back(zapis);
    return this->tellg();
}
string PlikSRT::odczytajBlok(unsigned numer){
    if(numer > bloki.size()-1) return "";
    else return bloki[numer].dane;
}

void PlikSRT::display(int n) {
    gotoxy(x,y);
    cout << nazwa_pliku << " (SRT) " << endl << endl;
    cout << odczytajBlok(n) << endl;
}
