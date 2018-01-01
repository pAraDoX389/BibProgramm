/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ansible
 *
 * Created on 15. Dezember 2017, 19:29
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//globale Variabeln
//------------------------------------------------------------------------------
int main_var = 0;


//Auslagerung für Klassendatei
//------------------------------------------------------------------------------
enum kind {books = 1, cd = 2};

//Basisklasse 
//------------------------------------------------------------------------------
class Element{
 protected:
    //Element() {} 
 public:
    virtual ~Element() {}
    
    virtual const string getTitle() = 0;
    virtual const string getAuthor() = 0;
    virtual const int getNumber() = 0;
    virtual const int getActual() = 0;
    virtual const int getQuota() = 0;
    virtual kind getType() = 0;
    virtual void setTitle(string value) = 0;
    virtual void setAuthor(string value) = 0;
    virtual void setNumber(int value) = 0;
    virtual void setActual(int value) = 0;
    virtual void setQuota(int value) = 0; 
    virtual void setType(kind value) = 0;
};

//1. abgeleitete Klasse
//--------------------------------------------------------
class Book : public Element {
 private:
    string title_;
    string author_;
    int number_;
    int actual_;
    int quota_;
    kind type_ = books;
 public:
    const string getTitle();
    const string getAuthor();
    const int getNumber();
    const int getActual();
    const int getQuota();
    kind getType();
    void setTitle(string value);
    void setAuthor(string value);
    void setNumber(int value);
    void setActual(int value);
    void setQuota(int value); 
    void setType(kind value);
};

const string Book::getTitle() {
    return title_;
}

const string Book::getAuthor() {
    return author_;
}

const int Book::getNumber(){
    return number_;
}

const int Book::getActual(){
    return actual_;
}

const int Book::getQuota() {
    return quota_;
}

kind Book::getType() {
    return type_;
} 

void Book::setAuthor(string value) {
    this->author_ = value;
}

void Book::setTitle(string value) {
    this->title_ = value;
}

void Book::setNumber(const int value){
    this->number_ = value;
}

void Book::setActual(int value) {
    this->actual_ = value;
}

void Book::setQuota(int value) {
    this->quota_ = value;
}

void Book::setType(kind value) {
    this->type_ = value;
    return;
}

//Fabrikklasse
//momentan nur als Fabrik für Book, hier soll noch erweitert werden
//------------------------------------------------------------------------------
class Factory {
 public: 
     Book* newBook();
};

Book* Factory::newBook() {
    return new Book;
}

//Eigene Funktion um Eingabepuffer zulöschen und auf ein Enter zu warten
//------------------------------------------------------------------------------
void clrInputBuf();
Book * createBook();


/*hier soll das BibProgramm entstehen
 *Platzhalter für Dokumentationstool (z.B. Doxygen) 
 */
//------------------------------------------------------------------------------
int main(int argc, char** argv) {
    while (main_var!=7) {
        
        //zum Testen
        Book* x;
        Factory fab;
        
        // Hauptmenü
        cout << "+----------------------+" << "\n";
        cout << "|   BibProgramm v0.0   |" << "\n";
        cout << "+----------------------+" << "\n";
        cout << "\n";
        cout << "***Hauptmenu***\n\n";
        cout << "1. Bestand anzeigen\n";
        cout << "2. Suchen nach Nummer\n";
        cout << "3. Ausleihen\n";
        cout << "4. Zurückgeben\n";
        cout << "5. Neues Buch hinzufügen\n";
        cout << "6. Löschen\n";
        cout << "7. Programm verlassen\n\n";
        
        cout << "Was möchten Sie tuen?\n";
        cin >> setw(1) >> main_var;
        clrInputBuf();
        cout << endl;
           
        //Fallunterscheidung
        switch (main_var) {
            case 1: 
                cout << "Platzhalter Anzeigen\n";
                break;
            case 2: 
                cout << "Platzhalter Suchen\n";
                break;
            case 3: 
                cout << "Platzhalter Ausleihen\n";
                break;
            case 4: 
                cout << "Platzhalter Zurückgeben\n";
                break;
            case 5: 
                //Implementierung nur zum Test
                // erst eine Factory als Variable erzeugen !!!
                x = createBook();
                cout << x->getTitle() << endl;
                //bis hier------------------------------------------------------
                cout << "Platzhalter Hinzufügen\n";
                break;
            case 6: 
                cout << "Platzhalter Löschen\n";
                break;
            case 7: 
                cout << "Platzhalter Beenden\n";
                break;
            default : 
                cout << "Falsche Eingabe!" << endl << endl;
                cin.clear();
                cin.ignore(INT16_MAX,'\n');
                cout << "Weiter mit Enter...";
                clrInputBuf();
                break;
        }
    }
    return 0;
}

//Implementierung eigener Funktionen 
//Auslagern!
//------------------------------------------------------------------------------
void clrInputBuf()
{
   int c = 1;
   while( ((c = getchar()) != EOF) && (c != '\n') );
}

//Unterprogramm um ein neues Buch zu erstellen und mit de richtigen Werten zu 
//initialisieren
//------------------------------------------------------------------------------
Book * createBook() {
    
    //Initialisierung aller benötigten variablen
    Factory fac;
    Book * newBook;
    string string_var;
    int int_var;
    
    //Erzeugen eines neuen Buchs
    newBook = fac.newBook();
   
    //Abfragen der Werte, anschließend schreiben der Werte
    std::cout << "Wie heißt das Buch?" << endl;
    getline(cin, string_var);
    clrInputBuf();
    cout << endl;
    newBook->setTitle(string_var);
   

    
    
    return newBook;
}
