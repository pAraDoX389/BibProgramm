/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   database.hpp
 * Author: kasslernetbook
 *
 * Created on 18. März 2018, 22:07
 * 
 * Attribut ist eine Map, ID des Buches ist der Key, Element vom Typ book
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <map>
#include <fstream>
#include <locale>
#include "book.hpp"
#include "../../../nlohmann_json/json/single_include/nlohmann/json.hpp"



using json = nlohmann::json;



class Database {
private:
     std::map<int, Book> database_;
     Database();
 public:
     Database(const Database&) = delete;
     Database& operator=(const Database&) = delete;
     ~Database() = default;
     static Database& getInstance();
     int newElement();
     int loadDatabase();
     int saveDatabase();
     int showDatabase();
     int showElementByID(const int id);
     int askForID();
     int lendBook();
     int returnBook();
     int interactiveClear();
};

#endif /* DATABASE_HPP */

