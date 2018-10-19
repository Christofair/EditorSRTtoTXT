#include <fstream>
#include <windows.h>
#include <conio.h>

#include "PlikSRT.h"
#include "PlikTXT.h"
#include "function.h"


using namespace std;



int main() {
    system("mode con cp select=1250");
    system("mode con cols=140 lines=24");
    //system("cls");
    int LINE = 0;
    bool zmieniono = false;
    string to_save;
    PlikTw file_tw;
    file_tw.nazwa_pliku = "gotowe.txt";

    char znak;
    string nazwa_pliku;
    cout << "Podaj nazwe pliku(SRT): ";
    cin >> nazwa_pliku;
    PlikSRT file_srt(nazwa_pliku);
    file_srt.nazwa_pliku = nazwa_pliku;

    cout << "Podaj nazwe pliku(TXT): ";
    cin >> nazwa_pliku;
    PlikTXT file_txt(nazwa_pliku);
    file_txt.nazwa_pliku = nazwa_pliku;

    while (file_srt.wczytajBlok() != -1);
    while(file_txt.wczytajLinie() != -1);

    to_save = file_txt.odczytajLinie(LINE);
    do {
        system("cls");
        file_srt.display(LINE);
        file_txt.display(LINE);
        file_tw.display(LINE);
        display_actions();
        gotoxy(10,10);
        cout << to_save;
        switch_cursor();
        znak = getch();
        switch(znak){
            case 'a': {
                if(LINE < file_tw.linie.size()) file_tw.linie[LINE] = to_save;
                else file_tw.linie.push_back(to_save);
                zmieniono = false;
                LINE++;
                break;
            }
            case 'n': LINE++;break;
            case 'p': LINE--;break;
            case 'c': {
                int l1,l2;
                gotoxy(1,20);
                cout << "linia1 linia2: "; cin >> l1 >> l2;
                to_save = CombinedLines(file_txt.linie[l1-1], file_txt.linie[l2-1]);
                zmieniono = true;
                break;
            }
            case 'e':{
                gotoxy(1,20);
                string line;
                string help;
                int pos;
                cout << "Nowa linia do zapisu: "; getline(cin, line);
                pos = file_txt.linie[LINE].find_first_of('}');
                pos = file_txt.linie[LINE].find('}',pos+1);
                to_save = file_txt.linie[LINE].substr(0, pos+1) + line;
                zmieniono = true;
            }
            default: break;
        }
        if(!zmieniono) to_save = file_txt.odczytajLinie(LINE);
        else continue;
    }while(znak != 27);
    file_tw.open(file_tw.nazwa_pliku);
    file_tw.zapisz();

    file_tw.close();
    file_srt.close();
    file_txt.close();
    cin.ignore();

    return 0;
}