/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "book.hpp"



/**
 * gibt Titel des Buches zurück
 * 
 * @return title_ (const std::string)
 */
const std::string Book::getTitle() const {
    return title_;
}

/**
 * gibt Autor des Buches zurück
 * 
 * @return author_ (const std::string)
 */
const std::string Book::getAuthor() const {
    return author_;
}

/**
 * gibt ID des Buches zurück
 * 
 * @return id_ (const int)
 */
const int Book::getID() const {
    return id_;
}

/**
 * gibt vorhandene Anzahl an Bücher zurück
 * 
 * @return actual_ (const int)
 */
const int Book::getActual() const {
    return actual_;
}

/**
 * gibt Bestand eines Buches zurück
 * 
 * @return quota_ (const int)
 */
const int Book::getQuota() const {
    return quota_;
}

/**
 * setzt Autor des Buches
 * 
 * @param value (std::string)
 */
void Book::setAuthor(const std::string value) {
    this->author_ = value;
}

/**
 * setzt Titel des Buches
 *  
 * @param value (int)
 */
void Book::setTitle(const std::string value) {
    this->title_ = value;
}

/**
 * setzt ID des Buches
 * 
 * @param value (int)
 */
void Book::setID(const int value){
    this->id_ = value;
}

/**
 * setzt vorhandene Anzahl an Bücher 
 * 
 * @param value (int)
 */
void Book::setActual(const int value) {
    this->actual_ = value;
}

/**
 * setzt Bestand eines Buches 
 * 
 * @param value (int)
 */
void Book::setQuota(const int value) {
    this->quota_ = value;
}

/**
 * Konstruktor mit default-Werten
 * 
 * @param title (std::string, default = {})
 * 
 * @param author (std::string, default = {})
 * 
 * @param id (int, default = 0)
 * 
 * @param actual (int, default = 0)
 * 
 * @param quota (int, default = 0)
 */
Book::Book(const std::string title, const std::string author, const int id, 
        const int actual, const int quota) {
    title_ = title;
    author_ = author;
    id_ = id;
    actual_ = actual;
    quota_ = quota;
}

/**
 * Methode zur Erzeugung eines Book-Objektes, beim Anlegen des Book-Objektes 
 * wird geprüft, ob das ID-Attribut schon vergeben ist
 * 
 * @param keys (std::vector<int>) Liste von Ganzzahlwerten
 * 
 * @return newbook (Book)
 */
Book Create::newBook(const std::vector<int> keys) {
    std::string title, author;
    int id, actual, quota;
    
    system("clear");
    std::cout << "Erstellen eines neuen Buches" << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;
    
    std::cout << "Wie lautet der Titel des Buches? " << std::endl;
    std::getline(std::cin, title);
    
    
    std::cout << "Wie lautet der Autor des Buches? " << std::endl;
    std::getline(std::cin, author);
    
    while (1) {
        do {
            std::cout << "Wie lautet die ID des Buches? " << std::endl;
            std::cin >> id;
            std::cin.ignore();
            if (std::cin.good()) {
                    break;  
            }
            std::cin.clear();
            std::cin.ignore();
            id = {};
        } while(1);
        
        if (!(this->isElementOf(keys, id))) {
            break;
        }
        std::cout << "ID des Buches schon vergeben !!!" << std::endl; 
        std::cout << std::endl;
    } 
    
    do {
        std::cout << "Wie viele Bücher sind im Bestand? " << std::endl;
        std::cin >> quota;
        std::cin.ignore();
        if (std::cin.good()) {
            break;
        }
        std::cin.clear();
        std::cin.ignore();
        quota = {};       
    } while(1);
    
    do {
        std::cout << "Wieviele Bücher sind davon nicht ausgeliehen?" << std::endl;
        std::cin >> actual;
        std::cin.ignore();
        if (std::cin.good()) {
                break;
            }
        std::cin.clear();
        std::cin.ignore();
        actual = {};
    } while(1);
    
    Book newBook(title, author, id, actual, quota);
    return newBook;
}

/**
 * prüft ob value in keys enthalten ist
 * 
 * @param keys (std::vector<int>)
 * 
 * @param value (int)
 * 
 * @return true wenn value in keys enthalten
 *         false wenn value nicht in keys enthalten
 */
bool Create::isElementOf(const std::vector<int> keys, const int value) {
    for (auto it : keys) {
        if (it == value) {
            return true;
        }
    }
    return false;
}

