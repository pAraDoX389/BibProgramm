/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>

#include "functions.hpp"

namespace func {

/**
 * stellt eine Ja/Nein-Frage, das (j/n) wird mit angefügt
 * 
 * @param quest (std::string)
 * 
 * @return 0 für Ja,
 *         1 für Nein,
 *         2 für beliebige andere Eingabe,
 *         -1 für einen Fehler
 */
int questionYesNo(std::string quest) {
    try {
        std::string answer {};
        
        quest.append("(j/n)");
        std::cout << quest << std::endl;
        std::getline(std::cin, answer);
        if (answer == "J" || answer == "j") {
            return 0;
        } else if (answer == "N" || answer == "n") {
            return 1;
        } else {
            return 2;
        }
    }
    
    catch(...) {
        std::cout << "Error bei der Eingabe!!!";
        std::cin.sync();
        std::cin.clear();
        return -1;              
    }   
}

/**
 * stellt eine Frage nach einer Ganzzahl, dazu wird die gestellte Frage 
 * ausgegeben und value mit gegeben Werten verglichen, Rückgabewert gibt 
 * Antwort der Frage zurück
 * 
 * @param quest (const std::string)
 * 
 * @param valueList (std::vector<int>)
 * 
 * @param value (int&)
 * 
 * @return 0 für in valueList,
 *         1 für nicht in valueList,
 *         -1 für einen Fehler
 */
int questionInt(const std::string quest, const std::vector<int> valueList, 
        int& value) {
    try { 
        int answer {};
        
        std::cout << quest;
        std::cin >> answer;      
        std::cin.ignore();
        
        //fängt Fehler bei falscher Eingabe ab und wirft Fehler
        if (std::cin.fail()) {
            throw "error";
        }
            
        for (const int it : valueList) {
            if (it == answer) {
                value = answer;
                std::cin.sync();
                return 0;
            }
        }
        return 1;
    }
    
    catch (...) {
        std::cout << "Error bei der Eingabe!!!" << std::endl << std::endl;
        std::cin.clear();
        return -1;
    }
}

/**
 * Funktion für "Weiter mit Enter..."
 */
void continueRoutine() {
    char answer;
    do {
        std::cout << "Weiter mit Enter..." << std::endl; 
        std::cin.sync();
        std::cin.clear();
        answer = std::cin.get();
    } while (!isspace(answer));
}

}