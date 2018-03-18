/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   elements.hpp
 * Author: kasslernetbook
 *
 * Created on 18. März 2018, 11:56
 */

#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <iostream>
#include <iomanip>
#include <string>

//Variabeln
//------------------------------------------------------------------------------
enum kind {books = 1, cd = 2};

//abstrakte Basisklasse 
//------------------------------------------------------------------------------
class Element{
 public:
    virtual ~Element() = default;
    virtual const string getTitle() = 0;
    virtual const string getAuthor() = 0;
    virtual const int getNumber() = 0;
    virtual const int getActual() = 0;
    virtual const int getQuota() = 0;
    virtual kind getType() = 0;
    virtual void setTitle(string value) = 0;
    virtual void setAuthor(string value) = 0;
    virtual void setNumber(int value) = 0;
    virtual void setActual(int value) = 0;
    virtual void setQuota(int value) = 0; 
    virtual void setType(kind value) = 0;
};

//1. abgeleitete Klasse
//--------------------------------------------------------
class Book : public Element {
 private:
    string title_;
    string author_;
    int number_;
    int actual_;
    int quota_;
    kind type_ = books;
 public:
    ~Book() {};
    const string getTitle();
    const string getAuthor();
    const int getNumber();
    const int getActual();
    const int getQuota();
    kind getType();
    void setTitle(string value);
    void setAuthor(string value);
    void setNumber(int value);
    void setActual(int value);
    void setQuota(int value); 
    void setType(kind value);
};




#endif /* ELEMENTS_HPP */

