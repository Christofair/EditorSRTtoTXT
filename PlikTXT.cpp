//
// Created by Christofair on 05.07.2017.
//

#include "PlikTXT.h"
#include "function.h"

using namespace std;
using pos_type = basic_ifstream<char>::pos_type;


pos_type PlikTXT::wczytajLinie() {
    char newline = '\n';
    string linia = "";
    char znak;
    while (this->get(znak), znak != newline) {
        linia += znak;
    }
    linie.push_back(linia);
    return this->tellg();
}
string PlikTXT::odczytajLinie(int ktora){
    if(ktora >= linie.size() || ktora < 0) return "";
    else return linie[ktora];
}
string PlikTXT::polaczLinie(int linia1, int linia2){
    string nowa_linia;
    string line_one = linie[linia1 - 1];
    string line_two = linie[linia2 - 1];
    line_one = line_one.substr(0,line_one.length()-1) + '|';
    int pos;
    pos = line_two.find_first_of('}');
    line_two = line_two.substr(pos+1);
    pos = line_two.find_first_of('}');
    line_two = line_two.substr(pos+1);
    nowa_linia = line_one + line_two;
    return nowa_linia;
}

void PlikTXT::display(int n) {
    gotoxy(this->x,this->y);
    cout << nazwa_pliku << " (TXT) " << endl;
    gotoxy(x,y+2);
    int line = 3;
    for(int i=n-1; i < n+2; i++) {
        gotoxy(x,y+line);
        if(i == n) cout << "-->  ";
        cout << odczytajLinie(i) << endl;
        line++;
    }
}
void PlikTw::display(int n) {
    gotoxy(x, y);
    cout << nazwa_pliku << " (TXT) " << endl;
    gotoxy(x,y+2);
    int line = 3;
    for(int i=n-1; i < n+2; i++) {
        gotoxy(x,y+line);
        if(i == n) cout << "-->  ";
        cout << odczytajLinie(i) << endl;
        line++;
    }
}
void PlikTw::zapisz(){
    if(this->is_open()){
        for(auto &line : linie){
            line += '\n';
            this->write(line.c_str(), line.length());
        }
    }
    else {
        cout << "Plik jest zamkniety!";
    }
}
