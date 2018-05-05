/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input.hpp
 * Author: kasslernetbook
 *
 * Created on 3. Mai 2018, 10:55
 */

#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <iomanip>
#include <string>

namespace SE {
    
    int input(const int min, const int max, const int tries, 
            const std::string quest, int& input);

    int input(const float min, const float max, const int tries, 
            const std::string quest, float& input);

    int input(const double min, const double max, const int tries, 
            const std::string quest, double& input);
    
}



#endif /* INPUT_HPP */

