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

#include <iostream>
#include <iomanip>
#include <string>
#include<limits> 

class Book {
 private:
    std::string title_;
    std::string author_;
    int id_;
    int actual_;
    int quota_;
 public:
    Book(std::string title = {}, std::string author = {}, int id = 0,
        int actual = 0, int quota = 0);
    virtual~Book() = default;
    const std::string getTitle();
    const std::string getAuthor();
    const int getID();
    const int getActual();
    const int getQuota();
    void setTitle(std::string value);
    void setAuthor(std::string value);
    void setID(int value);
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

