//
// Created by Christofair on 06.07.2017.
//

#include <conio.h>
#include <map>
#include "function.h"

void gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point;
    point.X = (SHORT) (x - 1);
    point.Y = (SHORT) (y - 1);
    SetConsoleCursorPosition(hConsole, point);
}

void display_actions() {
    vector<string> akcje;
#define PB push_back
    akcje.PB("c - combine to line from TXT file");
    akcje.PB("n - display next block (from file SRT)");
    akcje.PB("p - display previous block ");
    akcje.PB("esc - exit to windows");
#undef PB
    int ak = 3;
    for(auto &akcja : akcje){
        gotoxy(60, ak);
        cout << akcja;
        ak++;
    }
}
string CombinedLines(string one, string two){
    one = one.substr(0, one.length()-2) + '|';
    int pos = two.find_first_of('}');
    two = two.substr(pos+1);
    pos = two.find_first_of('}');
    two = two.substr(pos+1);
    return one + two;
}

void switch_cursor() {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(con, &info);
    info.bVisible = not info.bVisible;
    SetConsoleCursorInfo(con, &info);
}

