/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>

#include "functions.hpp"

namespace func {

//Unterprogramm zur Ja-/Nein-Abfrage
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

//Unterprogramm zur int-Anbfrage
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

//Unterprogramm zum Weiterschalten
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