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
#include <set>
#include "book.hpp"
#include "../../../nlohmann_json/json/single_include/nlohmann/json.hpp"

class Database {
 private:
     std::map<int, Book> database;
 public:
     Database();
     ~Database() = default;
     int newElement();
};

#endif /* DATABASE_HPP */

