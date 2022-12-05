#include <iostream>
#include <fstream>
#include <string>
#include "inserimento_in_pila.h"

using namespace std;

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    int n;
    string tipo;

    for(int i = 0; i < 100; i++) {
        in >> tipo;
        in >> n;
        //cout << tipo << " " << n << " ";

        int v = 0;

        string *valori = new string[n];

        for(int j = 0; j < n; j++) {
            in >> valori[j];
            //cout << valori[j] << " ";
        }
        //cout << endl;

        if(tipo == "int") {
            Pila<int> pila(n);
            for(int z = 0; z < n; z++) {
                pila.push(stoi(valori[z]));
            }
            
            pila.stampa(out);
        } else if(tipo == "char") {
            Pila<char> pila(n);
            for(int z = 0; z < n; z++) {
                pila.push(valori[z][0]);
            }
            pila.stampa(out);
        } else if(tipo == "double") {
            Pila<double> pila(n);
            for(int z = 0; z < n; z++) {
                pila.push(stod(valori[z]));
            }
            pila.stampa(out);
        } else {
            Pila<bool> pila(n);
            for(int z = 0; z < n; z++) {
                pila.push(stoi(valori[z]));
            }
            pila.stampa(out);
        }
    }
}