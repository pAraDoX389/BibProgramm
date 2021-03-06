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
 * 
 * enthält Definition von der Book-Klasse und einer Erzeuger-Klasse für 
 * Book-Objekte
 */

#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits> 
#include <vector>



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
    const std::string getTitle() const;
    const std::string getAuthor() const;
    const int getID() const;
    const int getActual() const;
    const int getQuota() const;
    void setTitle(const std::string value);
    void setAuthor(const std::string value);
    void setID(const int value);
    void setActual(const int value);
    void setQuota(const int value); 
};

//Erzeugerklasse
class Create {
 private:    
 public:
    Create() = default;
    ~Create() = default;
    Book newBook(const std::vector<int> keys);
    bool isElementOf(const std::vector<int> keys, const int value);
};

#endif /* BOOK_HPP */

