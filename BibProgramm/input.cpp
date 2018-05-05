/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "input.hpp"

namespace SE {
    
    /**
     * dient zur Abfrage von int-Eingaben
     * 
     * @param min (int), Mindestwert der Eingabe
     * @param max (int), Maximalwert der Eingabe
     * @param tries (int), Anzahl der Versuche
     * @param quest (std::string), Frage die ausgegeben wird
     * @param input (int&), Referenz auf int, hier wird Eingabe zurückgegeben, 
     * in input wird nur geschrieben, wenn Eingabe richtig war 
     * @return (int), 0 wenn Eingabe im Wertebereich, 1 wenn Anzahl der Versuche überschritten,
     * 2 bei fehlerhafter Eingabe
     */
    int input(const int min, const int max, const int tries, 
            const std::string quest, int& input) {

        try {
            std::string rawInput {};
            int checkInput {};

            for (auto it = 0; it < tries; ++it) {
                std::cout << quest << std::endl;
                std::getline(std::cin, rawInput);
                checkInput = std::stoi(rawInput);
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

    /**
     * dient zur Abfrage von float-Eingaben
     * 
     * @param min (float), Mindestwert der Eingabe
     * @param max (float), Maximalwert der Eingabe
     * @param tries (int), Anzahl der Versuche
     * @param quest (std::string), Frage die ausgegeben wird
     * @param input (float&), Referenz auf int, hier wird Eingabe zurückgegeben, 
     * in input wird nur geschrieben, wenn Eingabe richtig war 
     * @return (int), 0 wenn Eingabe im Wertebereich, 1 wenn Anzahl der Versuche überschritten,
     * 2 bei fehlerhafter Eingabe
     */
    int input(const float min, const float max, const int tries, 
            const std::string quest, float& input) {
        
        try {
            std::string rawInput {};
            float checkInput {};

            for (auto it = 0; it < tries; ++it) {
                std::cout << quest << std::endl;
                std::getline(std::cin, rawInput);
                checkInput = std::stof(rawInput);
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

    /**
     * dient zur Abfrage von double-Eingaben
     * 
     * @param min (double), Mindestwert der Eingabe
     * @param max (double), Maximalwert der Eingabe
     * @param tries (int), Anzahl der Versuche
     * @param quest (std::string), Frage die ausgegeben wird
     * @param input (double&), Referenz auf int, hier wird Eingabe zurückgegeben, 
     * in input wird nur geschrieben, wenn Eingabe richtig war 
     * @return (int), 0 wenn Eingabe im Wertebereich, 1 wenn Anzahl der Versuche überschritten,
     * 2 bei fehlerhafter Eingabe
     */
    int input(const double min, const double max, const int tries, 
            const std::string quest, double& input) {
        
        try {
            std::string rawInput {};
            double checkInput {};

            for (auto it = 0; it < tries; ++it) {
                std::cout << quest << std::endl;
                std::getline(std::cin, rawInput);
                checkInput = std::stod(rawInput);
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