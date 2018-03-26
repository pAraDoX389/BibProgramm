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

<<<<<<< HEAD
<<<<<<< HEAD
int Database::showDatabase() {
    system("clear");
    std::cout << "+----------------------+" << std::endl;
    std::cout << "|   Bücherübersicht    |" << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << std::endl;
    for (auto it = database_.begin(); it != database_.end(); it++){
        std::cout << "Titel: "<< it->second.getTitle() << std::endl;
<<<<<<< HEAD
        std::cout << "ID: "<< it->second.getID() << std::endl;
=======
>>>>>>> fcca3bd460bbcbb74d81fe3536f7f33cb149b69a
        std::cout << "Autor: "<< it->second.getAuthor() << std::endl;
        std::cout << "Vorrätig: "<< it->second.getActual() << std::endl;
        std::cout << "Bestand: "<< it->second.getQuota() << std::endl;
        std::cout << std::endl;
        std::cout << "+----------------------+" << std::endl << std::endl;
    }
    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> fcca3bd460bbcbb74d81fe3536f7f33cb149b69a
=======
>>>>>>> parent of 54c6dc6... Anzeigen der gesamten Datenbank und Suchen nach ID implementiert
=======
>>>>>>> parent of 54c6dc6... Anzeigen der gesamten Datenbank und Suchen nach ID implementiert

