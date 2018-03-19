/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "database.hpp"

Database::Database () {
    database.clear();
}

int Database::newElement() {
    Create create;
    auto newBook = create.newBook();
    database.emplace(newBook.getID(), newBook);
}