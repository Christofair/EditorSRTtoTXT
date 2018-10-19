//
// Created by Christofair on 05.07.2017.
//

#ifndef EXERCISEDEXTENDCLASS_PLIKTXT_H
#define EXERCISEDEXTENDCLASS_PLIKTXT_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class PlikTXT : public ifstream{
public:
    vector<string> linie;
    string nazwa_pliku;
    int x = 60;
    int y = 11;
    //Methods
    using basic_ifstream::basic_ifstream;
    string odczytajLinie(int ktora);
    pos_type wczytajLinie();
    string polaczLinie(int, int);
    virtual void display(int);
};

struct PlikTw : public PlikTXT, ofstream{
    using ofstream::basic_ofstream;
    using ofstream::open;
    using ofstream::close;
    using ofstream::is_open;
    string nazwa_pliku;
    int x = 1;
    int y = 1;
    void display(int);
    void zapisz();
};


#endif //EXERCISEDEXTENDCLASS_PLIKTXT_H
