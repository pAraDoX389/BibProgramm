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
    
    /**
     * dient zur Abfrage von Eingabenverschiedenen Typus
     * 
     * @param min (Typ vom Compiler bestimmt), Mindestwert der Eingabe
     * @param max (Typ vom Compiler bestimmt), Maximalwert der Eingabe
     * @param tries (int), Anzahl der Versuche
     * @param quest (std::string), Frage die ausgegeben wird
     * @param input (Referenz aufgewünschten Typ), 
     * hier wird Eingabe zurückgegeben, in input wird nur geschrieben, 
     * wenn Eingabe richtig war 
     * @return (int), 0 wenn Eingabe im Wertebereich, 
     *                1 wenn Anzahl der Versuche überschritten, 
     *                2 bei fehlerhafter Eingabe
     */
    template<typename S, typename T>
    int getInput( const S min, const S max, const int tries, 
            const std::string quest, T& input) {
        try {
            std::stringstream convert {};
            std::string rawInput {};
            T checkInput {};

            for (auto it = 0; it < tries; ++it) {
                std::cout << quest << std::endl;
                std::getline(std::cin, rawInput);
                convert << rawInput;
                convert >> checkInput;
                if(std::cin.good() && checkInput >= min && checkInput <= max) {
                    input = checkInput;
                    return 0;
                } else if (checkInput < min) {
                    std::cout << "Eingabe zu klein !" << std::endl << std::endl;
                } else if (checkInput > max) {
                    std::cout << "Eingabe zu groß !" << std::endl << std::endl;
                }
            }
            std::cout << "Zuviele falsche Eingaben !!!" << std::endl << std::endl;
            return 1;
        }

        //hier werden alle Fehler abgefangen
        catch(...) {
            std::cin.clear();
            std::cout << "Fehler bei der Eingabe !!!" << std::endl << std::endl;
            return 2;
        }
    }
    
}



#endif /* INPUT_HPP */

