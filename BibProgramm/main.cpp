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

//eigene erstellte includes
#include "database.hpp"

//globale Variabeln
//------------------------------------------------------------------------------
int main_var = 0;

/*hier soll das BibProgramm entstehen
 *Platzhalter für Dokumentationstool (z.B. Doxygen) 
 */
//------------------------------------------------------------------------------
int main(int argc, char** argv) {
    Database& database = Database::getInstance();
    database.loadDatabase();
    while (main_var!=7) {
        
        // Hauptmenü
        std::cout << "+----------------------+" << "\n";
        std::cout << "|   BibProgramm v0.0   |" << "\n";
        std::cout << "+----------------------+" << "\n";
        std::cout << "\n";
        std::cout << "***Hauptmenu***\n\n";
        std::cout << "1. Bestand anzeigen\n";
        std::cout << "2. Suchen nach Nummer\n";
        std::cout << "3. Ausleihen\n";
        std::cout << "4. Zurückgeben\n";
        std::cout << "5. Neues Buch hinzufügen\n";
        std::cout << "6. Löschen\n";
        std::cout << "7. Programm verlassen\n\n";
        
        std::cout << "Was möchten Sie tuen?\n";
        std::cin >> std::setw(1) >> main_var;
        std::cout << std::endl;
           
        //Fallunterscheidung
        switch (main_var) {
            case 1: 
                database.showDatabase();
                std::cout << "Weiter mit Enter..." << std::endl;
                std::cin.clear();
                std::cin.ignore(INT16_MAX,'\n');
                std::cin.get();
                break;
            case 2: 
                std::cout << "Platzhalter Suchen\n";
                break;
            case 3: 
                std::cout << "Platzhalter Ausleihen\n";
                break;
            case 4: 
                std::cout << "Platzhalter Zurückgeben\n";
                break;
            case 5: 
                database.newElement();
                break;
            case 6: 
                std::cout << "Platzhalter Löschen\n";
                break;
            case 7: 
                database.saveDatabase();
                std::cout << "Platzhalter Beenden\n";
                break;
            default : 
                std::cout << "Falsche Eingabe!" << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore(INT16_MAX,'\n');
                std::cout << "Weiter mit Enter...";
                break;
        }
    }
    return 0;
}


