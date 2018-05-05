/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "input.hpp"

//TODO Template für Eingabe() erstellen
//TODO Überladung Eingabe() für float und double hinzufügen
//TODO Testen der Überladung
//TODO git-branche für weitere Entwicklung als Software-Engineering-Projekt

/**
 * dient zur Abfrage von int-, float- und double-Eingaben
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
        
        for (auto it = 0; it <= tries; ++it)
            std::cout << quest << std::endl;
            std::getline(std::cin, rawInput);
            checkInput = std::stoi(rawInput);
            if(std::cin.good() && checkInput >= min && checkInput <= max) {
                input = checkInput;
                return 0;
            } else if (checkInput < min) {
                std::cout << "Eingabe zu klein !" << std::endl;
            } else if (checkInput > max) {
                std::cout << "Eingabe zu groß !" << std::endl;
            }
            return 1;
    }
    
    //hier werdenalle Fehler abgefangen
    catch(...) {
        std::cin.clear();
        std::cout << "Fehler bei der Eingabe !!!" << std::endl;
        return 2;
    }
    
}

int input(float min, float max, int tries, std::string quest, float& input) {
    
}

int input(double min, double max, int tries, std::string quest, double& input) {
    
}