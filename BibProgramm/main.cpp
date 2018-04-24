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
 * 
 * Implementierung eines Bibliothekprogrammes, dient zur Verwaltung eines 
 * kleinen Buchbestandes, Datenbank wird mit einer JSON-Datei verwaltet,
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

//eigene erstellte includes
#include "database.hpp"
#include "functions.hpp"


//globale Variabeln
//------------------------------------------------------------------------------

int main_var = 0;

//------------------------------------------------------------------------------
int main(int argc, char** argv) {
    Database& database = Database::getInstance();
    database.loadDatabase("Database.json");
    while (main_var != 8) {
        
        //Hauptmenü
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
        std::cout << "7. Programm speichern\n";
        std::cout << "8. Programm speichern und verlassen\n\n";
        
        //Abfrage was gemacht werden soll
        std::cout << "Was möchten Sie tuen?\n";
        std::cin >> std::setw(1) >> main_var;
        std::cin.ignore();
        std::cout << std::endl;
           
        //Fallunterscheidung
        switch (main_var) {
            case 1: 
                database.showDatabase();
                func::continueRoutine();
                break;
            case 2: 
                database.showElementByID(database.askForID());
                func::continueRoutine();
                break;
            case 3: 
                database.lendBook(); 
                func::continueRoutine();
                break;
            case 4: 
                database.returnBook();
                func::continueRoutine();
                break;
            case 5: 
                database.newElement();
                break;
            case 6: 
                database.interactiveClear();
                func::continueRoutine();
                break;
            case 7: 
                database.saveDatabase("Database.json"); 
                break;
            case 8: 
                database.saveDatabase("Database.json"); 
                break;
            default : 
                std::cout << "Falsche Eingabe!" << std::endl << std::endl;
                func::continueRoutine();
                break;
        }
    }
    return 0;
}


