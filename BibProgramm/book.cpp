/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "book.hpp"



const std::string Book::getTitle() const {
    return title_;
}

const std::string Book::getAuthor() const {
    return author_;
}

const int Book::getID() const {
    return id_;
}

const int Book::getActual() const {
    return actual_;
}

const int Book::getQuota() const {
    return quota_;
}

void Book::setAuthor(const std::string value) {
    this->author_ = value;
}

void Book::setTitle(const std::string value) {
    this->title_ = value;
}

void Book::setID(const int value){
    this->id_ = value;
}

void Book::setActual(const int value) {
    this->actual_ = value;
}

void Book::setQuota(const int value) {
    this->quota_ = value;
}

Book::Book(const std::string title, const std::string author, const int id, 
        const int actual, const int quota) {
    title_ = title;
    author_ = author;
    id_ = id;
    actual_ = actual;
    quota_ = quota;
}

//Erzeugerklasse
Book Create::newBook() {
    std::string title, author;
    int id, actual, quota;
    
    system("clear");
    std::cout << "Erstellen eines neuen Buches" << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;
    
    std::cout << "Wie lautet der Titel des Buches? " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, title);
    
    
    std::cout << "Wie lautet der Autor des Buches? " << std::endl;
    std::getline(std::cin, author);
   
    do {
        std::cout << "Wie lautet die ID des Buches? " << std::endl;
        std::cin >> id;
        if (std::cin.good()) {
            break;
        }
        id = {};
        std::cin.clear();
        std::cin.ignore();
    } while(1);
    
    do {
        std::cout << "Wie viele Bücher sind im Bestand? " << std::endl;
        std::cin >> quota;
        if (std::cin.good()) {
            break;
        }
        quota = {};
        std::cin.clear();
        std::cin.ignore();
    } while(1);
    
    do {
        std::cout << "Wieviele Bücher sind davon nicht ausgeliehen?" << std::endl;
        std::cin >> actual;
        if (std::cin.good()) {
                break;
            }
        actual = {};
        std::cin.clear();
        std::cin.ignore();
    } while(1);
    
    Book newBook(title, author, id, actual, quota);
    return newBook;
}

