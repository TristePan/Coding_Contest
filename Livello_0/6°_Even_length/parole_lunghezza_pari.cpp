//Si fornisca un programma in grado di valutare se una data stringa di input abbia o meno una lunghezza pari, ovvero sia composta da un numero pari di caratteri.
//In caso affermativo il programma dovrà stampare in output la stringa nella sua forma originale;
//altrimenti viene richiesta la stampa della stringa senza il suo ultimo carattere,
//in modo tale che la stringa stampata in output abbia sempre una lunghezza pari.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    string output;

    for(int i = 0; i < 100; i++) {
        string parola;
        fin >> parola;

        if(parola.length() % 2 == 0) {
            fout << parola << endl;
        } else {
            fout << parola.substr(0, parola.length() - 1) << endl;
        }
    }
}