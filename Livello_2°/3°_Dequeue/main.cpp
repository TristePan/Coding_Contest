#include <iostream>
#include <fstream>
#include <string>
#include "queue.h"

using namespace std;

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    string tipo;
    int n;

    for(int i = 0; i < 100; i++) {
        in >> tipo;
        in >> n;
        cout << tipo << " " << n << " ";

        string *valori = new string[n];
        for(int j = 0; j < n; j++) {
            in >> valori[j];
            cout << valori[j] << " ";
        }
        cout << endl;

        if (tipo == "int" || tipo == "bool") {
            Queue<int> coda(n);
            for (int z=0; z<n; z++) {
                if (valori[z][0] == 'i') {
                    string temp;
                    for (int s=1; s<valori[z].size(); s++) {
                        temp += valori[z][s];
                    }
                    //int t = stoi(tmp);
                    coda.enqueue(stoi(temp));
                } else {
                    coda.dequeue(coda.getHead());
                }
            }
            coda.stampa(out);
        } else if(tipo == "double") {
            Queue<double> coda(n);
            for(int z = 0; z < n; z++) {
                if(valori[z][0] == 'i') {
                    string temp;
                    for(int k = 1; k < valori[z].size(); k++) {
                        temp += valori[z][k];
                    }
                    coda.enqueue(stod(temp));
                } else {
                    coda.dequeue(coda.getHead());
                }
            }
            coda.stampa(out);
        } else {
            Queue<string> coda(n);
            for(int z = 0; z < n; z++) {
                if(valori[z][0] == 'i') {
                    string temp;
                    for(int k = 1; k < valori[z].size(); k++) {
                        temp += valori[z][k];
                    }
                    coda.enqueue(temp);
                } else {
                    coda.dequeue(coda.getHead());
                }
            }
            coda.stampa(out);
        }

        delete [] valori;
        

    }

}