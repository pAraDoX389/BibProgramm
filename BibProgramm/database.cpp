/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "database.hpp"



using json = nlohmann::json;



Database::Database () {
    database_.clear();
}

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

int Database::loadDatabase() {
    auto data = Database::getInstance().database_;
    json loadDatabase;
    
    std::ifstream file;
    file.open("Database.json");
    file >> loadDatabase;
    file.close();
    
    for (auto it = loadDatabase.begin(); it != loadDatabase.end(); it++) {
        Book newBook;
        
        auto x = it.value();
        newBook.setTitle(it.value()["title"]);
        newBook.setAuthor(it.value()["author"]);
        newBook.setID(it.value()["ID"]);
        newBook.setActual(it.value()["actual"]);
        newBook.setQuota(it.value()["quota"]);
        
        database_.emplace(newBook.getID(), newBook);
    }
    return 0;
}

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

int Database::askForID() {
    int id;
  
    system("clear");
    std::cout << "Wie lautet die ID des gesuchten Buches?" << std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::cin >> id;
    return id;
}

int Database::showElementByID(const int id) {
    auto it = database_.find(id);
    if (it != database_.end()) {
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

int Database::lendBook() {
    std::string choice;
    int id;
    
    id = Database::askForID();
    Database::showElementByID(id);
    
    while (1) {    
        std::cout << "Wollen Sie dieses Buch ausleihen? (j/n)";
        std::cin.clear();
        std::cin.ignore(INT16_MAX,'\n');
        std::cin >> choice;
        if (choice == "J" || choice == "j") {
            if (database_.at(id).getActual() <= database_.at(id).getQuota()
                    && database_.at(id).getQuota() > 0) {
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

int Database::returnBook() {
    std::string choice;
    int id;
    
    id = Database::askForID();
    Database::showElementByID(id);
    
    std::cout << "Wollen Sie dieses Buch zurückgeben? (j/n)";
    std::cin.clear();
    std::cin.ignore(INT16_MAX,'\n');
    std::cin >> choice;
    if (choice == "J" || choice == "j") {
        if (database_.at(id).getActual() < database_.at(id).getQuota()
                && database_.at(id).getQuota() != database_.at(id).getActual()) {
            database_.at(id).setActual(database_.at(id).getActual()+1);
            std::cout << "Ein Exemplar zurückgegeben." << std::endl;
            std::cout << "Noch " << database_.at(id).getActual() 
                << " Exemplare vorhanden." << std::endl;
            return 0;
        }
    } else if (choice == "N" || choice == "n") {
        std::cout << "Zurückgeben abgebrochen!" << std::endl;
        return 0;
    } else {
        std::cout << "Falsche Eingabe!" << std::endl << std::endl;
    }
}
