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

/**
 * erstellen eines neuen Elementes vom Typ book im Attribut von Database-Klasse
 * 
 * @return 0 wenn erfolgreich
 */
int Database::newElement() {
    Create create;
   
    auto IDList = this->getKeys();
    auto newBook = create.newBook(IDList);
    database_.emplace(newBook.getID(), newBook);
    return 0;
}

/**
 * Implementierung eines Singleton, static Methode, damit wird erreicht das 
 * die Datenbank nur einmal erzeugtwird und dann immer auf diese zurück 
 * gegriffen wird 
 * 
 * @return Instanz vom Typ Datenbankklasse
 */
Database& Database::getInstance() {
       static Database instance;
       return instance;
    };
    
/**
* Speichert die Datenbank in einem JSON-File,
* JSON-File heißt Database.json und liegtim Projektordner
* 
* @param savePath (std::string), Pfad ist relativ zum Projektordner
* 
* @return 0 wenn erfolgreich
*/ 
int Database::saveDatabase(const std::string savePath) {
    
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
    file.open(savePath);
    file << saveDatabase;
    file.close();
    
    saveBook.clear();
    saveDatabase.clear();
    return 0;
}

/**
 * laden einer Databasekasse
 * 
 * @loadPath (std::string), Pfad ist relativ zum Projektordner
 * 
 * @return 0 wenn erfolgreich,
 *         1 wenn keine Database vorhanden
 */
int Database::loadDatabase(const std::string loadPath) {
    
    auto data = Database::getInstance().database_;
    json loadDatabase;
    
    std::ifstream file;
    file.open(loadPath);
    
    //Wenn keine Datenbank vorhanden oder ein anderer Fehler beim öffnen 
    //auftritt, dann wird hier abgebrochen
    if (file.fail()) {
        return 1;
    }
    
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

/**
 * zeigt ganze Datenbank an
 * 
 * @return 0 wenn erfolgreich
 */
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

/**
 * fragt ab, welche ID man möchte
 * 
 * @return id des Buches, Rückgabe vom Typ int 
 */
int Database::askForID() {
    int id {};
  
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

/**
 * zeigt Element mit dem Key des Parameters id an
 * 
 * @param id (const int)
 * 
 * @return 0 wenn gefunden, 1 wenn nicht gefunden
 */
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

/**
 * Ausleihen eines Buches, Prüfung ob noch Bücher vorhanden sind ist integriert
 * 
 * @return 0 wenn ausgeliehen oder abgbrochen wird, 
 *         1 wenn nicht gefunden oder kein Buch mehr vorhanden
 */
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

/**
 * zurückgeben eines Buches, Prüfung ob schon alle Bücher zurückgegeben 
 * sind ist integriert
 * 
 * @return 0 wenn Rückgabe erfolgreich oder durch Antwort abgebrochen
 *         1 wenn Bücher schon vollzählig
 */
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

/**
 * Löschen eines Buches oder der gesamten Datenbank
 * 
 * @return 0 wenn Löschen erfolgreich oder durch Antwort abgebrochen
 *         1 wenn Bücher oder Database nicht vorhanden
 */
int Database::interactiveClear() {
    std::string choiceString {};
    int id {}, choiceInt {};
    
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

/**
 * gibt die Keys aller Elemente von database_ als Vektor zurück
 * 
 * @return keys (std::vector<int>)
 */
const std::vector<int> Database::getKeys() {
    std::vector<int> keys {};
    
    for (auto& it : database_) {
        keys.push_back(it.first);
    }
    
    return keys;
}
