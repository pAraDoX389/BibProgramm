/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   book.hpp
 * Author: kasslernetbook
 *
 * Created on 18. März 2018, 12:07
 */

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
 private:
    std::string title_;
    std::string author_;
    int number_;
    int actual_;
    int quota_;
 public:
    Book() = default;
    virtual~Book() = default;
    const std::string getTitle();
    const std::string getAuthor();
    const int getNumber();
    const int getActual();
    const int getQuota();
    void setTitle(std::string value);
    void setAuthor(std::string value);
    void setNumber(int value);
    void setActual(int value);
    void setQuota(int value); 
};

//Erzeugungsklasse
//------------------------------------------------------------------------------
class Create {
 private:    
 public:
    Create() =default;
    ~Create() = default;
    Book newBook();
};

#endif /* BOOK_HPP */

