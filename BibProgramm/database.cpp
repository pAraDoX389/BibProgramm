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
    return 0;
<<<<<<< HEAD
}

//static method
Database& Database::getInstance() {
       static Database instance;
       return instance;
    };
=======
}
>>>>>>> c8f2c1b84c242757888dc8433766ab5334d107e0
