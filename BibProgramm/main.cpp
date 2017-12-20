/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ansible
 *
 * Created on 15. Dezember 2017, 19:29
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Eigene Funktion um Eingabepuffer zulöschen und auf ein Enter zu warten
void clrInputBuf();
int a = 0;

//Erster Entwurf der eigenen Klasse
class book {
    string name_;
    int booknumber_;
    int count_;
    string author_;
 public:
     // getter und setter implementieren
     //const int getBookNumber();
};

    


/*hier soll das BibProgramm entstehen
 *Platzhalter für Dokumentationstool (z.B. Doxygen) 
 */
int main(int argc, char** argv) {
    while (a!=7) {
        
        // Hauptmenü
        cout << "+----------------------+" << "\n";
        cout << "|   BibProgramm v0.0   |" << "\n";
        cout << "+----------------------+" << "\n";
        cout << "\n";
        cout << "***Hauptmenu***\n\n";
        cout << "1. Bestand anzeigen\n";
        cout << "2. Suchen nach Nummer\n";
        cout << "3. Ausleihen\n";
        cout << "4. Zurückgeben\n";
        cout << "5. Neues Buch hinzufügen\n";
        cout << "6. Löschen\n";
        cout << "7. Programm verlassen\n\n";
        
        cout << "Was möchten Sie tuen?\n";
        cin >> setw(1) >> a;
        cout << endl;
           
        //Fallunterscheidung
        switch (a) {
            case 1: 
                cout << "Platzhalter Anzeigen\n";
                break;
            case 2: 
                cout << "Platzhalter Suchen\n";
                break;
            case 3: 
                cout << "Platzhalter Ausleihen\n";
                break;
            case 4: 
                cout << "Platzhalter Zurückgeben\n";
                break;
            case 5: 
                cout << "Platzhalter Hinzufügen\n";
                break;
            case 6: 
                cout << "Platzhalter Löschen\n";
                break;
            case 7: 
                cout << "Platzhalter Beenden\n";
                break;
            default : 
                cout << "Falsche Eingabe!" << endl << endl;
                cin.clear();
                cin.ignore(INT16_MAX,'\n');
                cout << "Weiter mit Enter...";
                clrInputBuf();
                break;
        }
    }
    return 0;
}

void clrInputBuf()
{
   int c = 1;
   while( ((c = getchar()) != EOF) && (c != '\n') );
}
