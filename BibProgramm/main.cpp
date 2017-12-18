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

int a = 0;
bool check;

using namespace std;

/*hier soll das BibProgramm entstehen
 * 
 */
int main(int argc, char** argv) {
    //while (a!=5) {
        
        // Hauptmenü
        cout << "+----------------------+" << "\n";
        cout << "|   BibProgramm v0.0   |" << "\n";
        cout << "+----------------------+" << "\n";
        cout << "\n";
        cout << "***Hauptmenu***\n\n";
        cout << "1. Bestand anzeigen\n";
        cout << "2. Suchen nach Nummer\n";
        cout << "3. Neues Buch hinzufügen\n";
        cout << "4. Löschen\n";
        cout << "5. Programm verlassen\n\n";
        
        //Abfrage was getaen werden soll   
        cout << "Was möchten Sie tuen?\n";
        cin >> setw(2) >> a;
        cin.sync();
        cout << endl; 
        
        //Fehlerhafte Eingabe Abfangen -> funktioniert noch nicht
        check = !iswdigit(a);
        cout << "Zahl ? = " <<check << endl;
     
            
        
        //Fallunterscheidung
        switch (a) {
            case 1: 
                cout << "Platzhalter Anzeigen\n";
                break;
            case 2: 
                cout << "Platzhalter Suchen\n";
                break;
            case 3: 
                cout << "Platzhalter Hinzufügen\n";
                break;
            case 4: 
                cout << "Platzhalter Löschen\n";
                break;
            case 5: 
                cout << "Platzhalter Beenden\n";
                break;
            default : 
                cout << "Falsche Eingabe\n";
                break;
        }
    //}
    return 0;
}

