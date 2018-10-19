//
// Created by Christofair on 02.07.2017.
//

#ifndef EXERCISEDEXTENDCLASS_PLIKSRT_H
#define EXERCISEDEXTENDCLASS_PLIKSRT_H

#include <fstream>
#include <vector>

using namespace std;

class PlikSRT : public ifstream{
public:
    using basic_ifstream::basic_ifstream;
    struct Blok{
        Blok() {}
        string dane = "";
    };
    int x = 1;
    int y = 11;
    string nazwa_pliku;
    vector<Blok> bloki;
    pos_type wczytajBlok();
    string odczytajBlok(unsigned);
    void display(int);
};

#endif //EXERCISEDEXTENDCLASS_PLIKSRT_H
