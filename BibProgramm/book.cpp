/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>

#include "book.hpp"

const std::string Book::getTitle() {
    return title_;
}

const std::string Book::getAuthor() {
    return author_;
}

const int Book::getNumber(){
    return number_;
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

void Book::setNumber(const int value){
    this->number_ = value;
}

void Book::setActual(int value) {
    this->actual_ = value;
}

void Book::setQuota(int value) {
    this->quota_ = value;
}

//Erzeugungsklasse
//------------------------------------------------------------------------------

Book Create::newBook() {
    std::string titel;
    
    std::cout << "Erstellen eines neuen Buches" << std::endl;
    std::cout << "Titel des Buches: " << std::endl;
    std::cin >> std::setw(120) >> titel;
    
    //hier weitermachen mit Bucherstellung
    
    Book newBook;
    return newBook;
}

