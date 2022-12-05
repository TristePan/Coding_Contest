//Si fornisca un programma che date in input tre parole di lunghezza variabile sia in grado di individuare, tra queste, quelle caratterizzate dagli estremi uguali e di contarne il numero.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    string output;

    for(int i = 0; i < 100; i++) {
        int n1, n2, n3;
        string parola1, parola2, parola3;
        int contatore = 0;

        fin >> n1 >> parola1 >> n2 >> parola2 >> n3 >> parola3;

        if(parola1[0] == parola1[parola1.length() - 1]) {
            contatore++;
        }
        if(parola2[0] == parola2[parola2.length() - 1]) {
            contatore++;
        }        
        if(parola3[0] == parola3[parola3.length() - 1]) {
            contatore++;
        }

        fout << contatore << endl;
    }
}