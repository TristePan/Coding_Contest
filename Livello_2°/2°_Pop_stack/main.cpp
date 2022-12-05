#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

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
            stack<int> stack;
            for (int z=0; z<n; z++) {
                if (valori[z][0] == 'i') {
                    string temp;
                    for (int s=1; s<valori[z].size(); s++) {
                        temp += valori[z][s];
                    }
                    //int t = stoi(tmp);
                    stack.push(stoi(temp));
                } else {
                    stack.pop();
                }
            }
            stack.stampa(out);
        } else if(tipo == "double") {
            stack<double> stack;
            for(int z = 0; z < n; z++) {
                if(valori[z][0] == 'i') {
                    string temp;
                    for(int k = 1; k < valori[z].size(); k++) {
                        temp += valori[z][k];
                    }
                    stack.push(stod(temp));
                } else {
                    stack.pop();
                }
            }
            stack.stampa(out);
        } else {
            stack<string> stack;
            for(int z = 0; z < n; z++) {
                if(valori[z][0] == 'i') {
                    string temp;
                    for(int k = 1; k < valori[z].size(); k++) {
                        temp += valori[z][k];
                    }
                    stack.push(temp);
                } else {
                    stack.pop();
                }
            }
            stack.stampa(out);
        }

        delete [] valori;

    }
}