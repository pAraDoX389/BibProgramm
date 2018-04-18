/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "database.hpp"
#include "functions.hpp"



using json = nlohmann::json;



Database::Database () {
    database_.clear();
}

//erstellt neues Buch an richtiger Stelle in Datenbank
int Database::newElement() {
    Create create;
    auto newBook = create.newBook();
    database_.emplace(newBook.getID(), newBook);
    return 0;
}

//static method
Database& Database::getInstance() {
       static Database instance;
       return instance;
    };

//Speichern der Datenbank    
int Database::saveDatabase() {
    auto data = Database::getInstance().database_;
    json saveDatabase = {}, saveBook = {};
    
    for (auto it = data.begin(); it != data.end(); it++) {
        saveBook["title"] = it->second.getTitle();
        saveBook["author"] = it->second.getAuthor();
        saveBook["ID"] = it->second.getID();
        saveBook["actual"] = it->second.getActual();
        saveBook["quota"] = it->second.getQuota();
        saveDatabase += saveBook;
    }
    
    std::ofstream file;
    file.open("Database.json");
    file << saveDatabase;
    file.close();
    
    saveBook.clear();
    saveDatabase.clear();
    return 0;
}

//Laden der Datenbank
int Database::loadDatabase() {
    auto data = Database::getInstance().database_;
    json loadDatabase;
    
    std::ifstream file;
    file.open("Database.json");
    file >> loadDatabase;
    file.close();
    
    for (auto it = loadDatabase.begin(); it != loadDatabase.end(); it++) {
        Book newBook;
        
        newBook.setTitle(it.value()["title"]);
        newBook.setAuthor(it.value()["author"]);
        newBook.setID(it.value()["ID"]);
        newBook.setActual(it.value()["actual"]);
        newBook.setQuota(it.value()["quota"]);
        
        database_.emplace(newBook.getID(), newBook);
    }
    return 0;
}

//Anzeigen der gesamten Datenbank
int Database::showDatabase() {
    system("clear");
    std::cout << "+----------------------+" << std::endl;
    std::cout << "|   Bücherübersicht    |" << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << std::endl;
    for (auto it = database_.begin(); it != database_.end(); it++){
        std::cout << "Titel: "<< it->second.getTitle() << std::endl;
        std::cout << "ID: "<< it->second.getID() << std::endl;
        std::cout << "Autor: "<< it->second.getAuthor() << std::endl;
        std::cout << "Vorrätig: "<< it->second.getActual() << std::endl;
        std::cout << "Bestand: "<< it->second.getQuota() << std::endl;
        std::cout << std::endl;
        std::cout << "+----------------------+" << std::endl << std::endl;
    }
    return 0;
}

//ermittelt interaktiv ID eines Buches
int Database::askForID() {
    int id ;
  
    system("clear");  
    do {
        std::cout << "Wie lautet die ID des gesuchten Buches?" << std::endl;
        std::cin >> id;
        std::cin.ignore();
        if (std::cin.good()) {
            break;
        }
        id = {};
    } while(1);
    return id;
}

//zeigt ein Daten eines Buches an, welches über die ID ermittelt wird
int Database::showElementByID(const int id) {
    auto it = database_.find(id);
    if (it != database_.end()) {
        std::cout << std::endl;
        std::cout << "Titel: "<< it->second.getTitle() << std::endl;
        std::cout << "ID: "<< it->second.getID() << std::endl;
        std::cout << "Autor: "<< it->second.getAuthor() << std::endl;
        std::cout << "Vorrätig: "<< it->second.getActual() << std::endl;
        std::cout << "Bestand: "<< it->second.getQuota() << std::endl;
        std::cout << std::endl << std::endl;
        return 0;
    } else {
        std::cout << "Kein Buch gefunden!" << std::endl << std::endl;
        return 1;
    }
}

//Ausleihen eines Buches
int Database::lendBook() {
    std::string choice;
    int id;
    
    id = Database::askForID();
    int check = Database::showElementByID(id);
    if (check != 0) {
                std::cout << "Ausleihen abgebrochen!" << std::endl;
                return 1;
            }
    while (1) {    
        std::cout << "Wollen Sie dieses Buch ausleihen? (j/n)";
        std::cin.sync();
        std::cin.clear();
        std::getline(std::cin, choice);
        if (choice == "J" || choice == "j") {
            if (database_.at(id).getActual() <= database_.at(id).getQuota()) {
                if (database_.at(id).getActual() == 0) {
                    std::cout << "Keine Exemplare mehr vorrätig!" << std::endl;
                    return 1;
                }
                database_.at(id).setActual(database_.at(id).getActual()-1);
                std::cout << "Ein Exemplar ausgeliehen." << std::endl;
                std::cout << "Noch " << database_.at(id).getActual() 
                    << " Exemplare vorhanden." << std::endl;
                return 0;
            }
        } else if (choice == "N" || choice == "n") {
            std::cout << "Ausleihen abgebrochen!" << std::endl;
            return 0;
        } else {
            std::cout << "Falsche Eingabe!" << std::endl << std::endl;
        }
    }
}

//Zurückgeben eines Buches
int Database::returnBook() {
    int choice {}, id {};
    
    id = Database::askForID();
    int check = Database::showElementByID(id);
    if (check != 0) {
                std::cout << "Zurückgeben abgebrochen!" << std::endl;
                return 1;
            }
    
    while (1) {
        choice = func::questionYesNo("Wollen Sie dieses Buch zurückgeben?");
        if (choice == 0) {
            if (database_.at(id).getActual() <= database_.at(id).getQuota() && 
                    database_.at(id).getQuota() != database_.at(id).getActual()) {
                database_.at(id).setActual(database_.at(id).getActual()+1);
                std::cout << "Ein Exemplar zurückgegeben." << std::endl;
                std::cout << "Noch " << database_.at(id).getActual() 
                    << " Exemplare vorhanden." << std::endl;
                return 0;
            } else {
                std::cout << "Bücher sind schon vollzählig!" << std::endl;
                return 1;
            }
        } else if (choice == 1) {
            std::cout << "Zurückgeben abgebrochen!" << std::endl;
            return 0; 
        } else if (choice == 2) {
            std::cout << "Falsche Eingabe!" << std::endl << std::endl;
        } else if (choice == -1) {
            std::cout << "Error bei der Eingabe!!!";
        }
    } 
}

//Löschen eines Buches oder der gesamten Datenbank
int Database::interactiveClear() {
    std::string choiceString {};
    int id, choiceInt {};
    
    while (1) {
        int success = func::questionInt("Löschen von\n\t (1) einem Buch\n\t (2) ganzer Datenbank ? ",
                    {1, 2}, choiceInt);
        if (success == 0) {
            break;
        } else if (success == 1) {
            std::cout << "Eingabe stimmt mit keiner möglichen Antwort überein!"
                    << std::endl << std::endl;
        } else {
            std::cin.ignore();
            std::cin.sync();
            std::cin.clear();
            while(std::cin.get()!='\n');
        }
    }
    
    while (1) {
        if (choiceInt == 1) {
            id = Database::askForID();
            int check = Database::showElementByID(id);
            if (check != 0) {
                std::cout << "Löschen abgebrochen!" << std::endl;
                return 1;
            }
            while (1) {               
                check = func::questionYesNo("Dieses Buch löschen?");
                if (check == 0) { 
                    database_.erase(id);
                    return 0;
                } else if (check == 1) {
                    std::cout << "Löschen abgebrochen!" << std::endl;
                    return 0;
                } else {
                    std::cout << "Falsche Eingabe!" << std::endl << std::endl;
                    choiceString = {};
                }
            }
        } else if (choiceInt == 2) {
            if (database_.size() == 0) {
                std::cout << "Keine Bücher zum löschen vorhanden." << std::endl;
                return 1;
            }
            while (1) {
                int check {};
                check = func::questionYesNo("Diese Datenbank löschen?");
                if (check == 0) { 
                    database_.clear();
                    return 0;
                } else if (check == 1) {
                    std::cout << "Löschen abgebrochen!" << std::endl;
                    return 0;
                } else {
                    std::cout << "Falsche Eingabe!" << std::endl << std::endl;
                }
            }
        } else {
            std::cout << "Falsche Eingabe!" << std::endl << std::endl;
            choiceInt = {};
        }
    }
    
}
