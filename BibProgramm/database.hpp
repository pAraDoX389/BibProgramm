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
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <map>
#include <fstream>
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
     
     //als nächstes implementieren
     int loadDatabase();
     int saveDatabase();
<<<<<<< HEAD
     int showDatabase();
<<<<<<< HEAD
     int showElementByID();
=======
>>>>>>> fcca3bd460bbcbb74d81fe3536f7f33cb149b69a
=======
>>>>>>> parent of 54c6dc6... Anzeigen der gesamten Datenbank und Suchen nach ID implementiert
};

#endif /* DATABASE_HPP */

