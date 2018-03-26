/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "book.hpp"

const std::string Book::getTitle() {
    return title_;
}

const std::string Book::getAuthor() {
    return author_;
}

const int Book::getID(){
    return id_;
}

const int Book::getActual(){
    return actual_;
}

const int Book::getQuota() {
    return quota_;
}

void Book::setAuthor(std::string value) {
    this->author_ = value;
}

void Book::setTitle(std::string value) {
    this->title_ = value;
}

void Book::setID(const int value){
    this->id_ = value;
}

void Book::setActual(int value) {
    this->actual_ = value;
}

void Book::setQuota(int value) {
    this->quota_ = value;
}

Book::Book(std::string title, std::string author, int id, int actual, int quota) {
    title_ = title;
    author_ = author;
    id_ = id;
    actual_ = actual;
    quota_ = quota;
}

//Erzeugerklasse
//------------------------------------------------------------------------------

Book Create::newBook() {
    std::string title, autor;
    int id, actual, quota;
    
    system("clear");
    std::cout << "Erstellen eines neuen Buches" << std::endl;
    std::cout << "----------------------------" << std::endl << std::endl;
    
    std::cout << "Wie lautet der Titel des Buches? " << std::endl;
    std::cin >> title;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.sync();
    
    std::cout << "Wie lautet der Autor des Buches? " << std::endl;
    std::cin >> autor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.sync();
    
    std::cout << "Wie lautet die ID des Buches? " << std::endl;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    std::cin.sync();
    
    std::cout << "Wie viele Bücher sind im Bestand? " << std::endl;
    std::cin >> quota;
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    std::cin.sync();
    
    std::cout << "Wieviele Bücher sind davon nicht ausgeliehen?" << std::endl;
    std::cin >> actual;
    std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    std::cin.sync();
    
    Book newBook(title, autor, id, actual, quota);
    return newBook;
}

