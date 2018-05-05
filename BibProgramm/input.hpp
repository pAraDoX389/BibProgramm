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

int input(int min, int max, int tries, std::string quest, int& input);

int input(float min, float max, int tries, std::string quest, float& input);

int input(double min, double max, int tries, std::string quest, double& input);

#endif /* INPUT_HPP */

