#include <iostream>
#include <conio.h>
using namespace std;

const int wiersz = 20;
const int kolumna = 10;

char labirynt[wiersz][kolumna] = {
    {'#','$','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#','#','#','#',' ','#'},
    {'#',' ','#',' ',' ','#','#','#',' ','#'},
    {'#',' ','#','#',' ',' ','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ',' ','#',' ','#'},
    {'#',' ','#',' ',' ','#',' ','#',' ','#'},
    {'#',' ',' ','#',' ','#',' ','#',' ','#'},
    {'#','#','#',' ',' ','#',' ','#',' ','#'},
    {'#',' ',' ',' ','#',' ',' ','#',' ','#'},
    {'#',' ','#','#',' ',' ','#',' ',' ','#'},
    {'#',' ','#',' ',' ','#','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ','#','#'},
    {'#','#',' ',' ','#',' ','#',' ',' ','#'},
    {'#',' ',' ','#',' ',' ',' ','#',' ','#'},
    {'#',' ','#',' ',' ','#',' ','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','@','#'},
};

int graczWiersz, graczKolumna;

void poczatek(){
    cout << "_____________________________________________\n";
    cout << "\t\tGra labirynt\n";
    cout << "           Gracz oznaczony jest \'x\'\n";
    cout << "   Musisz dotrzec do wyjscia oznaczonym \'@\'\n";
    cout << "\t \tSterowanie\n";
    cout << "    l - lewo, p - prawo, g - gora, d - dol\n";
    cout << "\tAby rozpoczac kliknij spacje\n";
    cout << "_____________________________________________\n";

    while(_getch() != ' '){

    }
}

void Labirynt(){
    system("cls");
    for(int i = 0; i < wiersz; ++i){
        for(int j = 0; j < kolumna; ++j){
            if(i == graczWiersz && j == graczKolumna){
                cout << 'x' << ' ';
            }
            else{
                cout << labirynt[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

bool ruchGracza(char kierunek){
    int nowyWiersz = graczWiersz;
    int nowaKolumna = graczKolumna;

    switch(kierunek){
        case 'g':
            nowyWiersz--;
            break;
        case 'd':
            nowyWiersz++;
            break;
        case 'l':
            nowaKolumna--;
            break;
        case 'p':
            nowaKolumna++;
            break;
    }

    if(nowyWiersz >= 0 && nowyWiersz < wiersz && nowaKolumna >= 0 && nowaKolumna < kolumna && labirynt[nowyWiersz][nowaKolumna] != '#' && labirynt[nowyWiersz][nowaKolumna] != '$'){
        if(labirynt[nowyWiersz][nowaKolumna] == '@'){
            return true;
        }

        labirynt[graczWiersz][graczKolumna] = ' ';
        graczWiersz = nowyWiersz;
        graczKolumna = nowaKolumna;
        labirynt[graczWiersz][graczKolumna] = '$';
        return false;
    }
    return false;
}

int main(){
    poczatek();

    for(int i = 0; i < wiersz; ++i){
        for(int j = 0; j < kolumna; ++j){
            if(labirynt[i][j] == '$'){
                graczWiersz = i;
                graczKolumna = j;
                break;
            }
        }
    }

    graczWiersz = 1;
    labirynt[graczWiersz][graczKolumna] = 'x';
    char kierunek;

    do{
        Labirynt();
        cout << "Wpisz q aby wyjsc" << endl;
        kierunek = _getch();

        if(kierunek == 'q'){
            break;
        }
    }while(!ruchGracza(kierunek));
    return 0;
}