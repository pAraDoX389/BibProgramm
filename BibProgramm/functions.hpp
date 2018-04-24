/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: kasslernetbook
 *
 * Created on 17. April 2018, 15:59
 * 
 * Sammlung von Funktionen für BibProgramm
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits> 
#include <vector>

#include <sstream>

namespace func {

int questionYesNo(std::string quest);

int questionInt(const std::string quest, const std::vector<int> valueList, 
        int& value);

void continueRoutine();

}

#endif /* FUNCTIONS_HPP */

