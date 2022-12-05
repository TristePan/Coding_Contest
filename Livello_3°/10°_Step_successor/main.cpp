#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "bst.h"

using namespace std;

int main() {

    BST<int> BstInt;
    BST<double> BstDouble;
    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    string tipo = "";
    int n = 0;
    int m = 0;

    for(int x = 0; x < 100; x++) {
        in >> tipo >> n >> m;
        if(tipo == "int") {
            int val[n];
            for(int j = 0; j < n; j++) {
                string s = "";
                in >> s;
                if(s[0] == 'i') {
                    val[j] = stoi(s.substr(4, s.length()));
                    BstInt.inserimento(val[j]);

                } else if(s[0] == 'c') {
                    val[j] = stoi(s.substr(5, s.length()));
                    BstInt.remove(val[j]);
                }
            }
            for(int y = 0; y < m; y++) {
                int valore = 0;
                int successore = 0;
                in >> valore;
                successore = BstInt.step_successor(valore);
                if(successore == -1) {
                    out << "INF ";
                } else {
                    out << successore << " ";
                }
            }
            out << endl;
            BstInt.clear();
        }
        if(tipo == "double") {
            double val[n];
            for(int j = 0; j < n; j++) {
                string s = "";
                in >> s;
                if(s[0] == 'i') {
                    val[j] = stod(s.substr(4, s.length()));
                    BstDouble.inserimento(val[j]);

                } else if(s[0] == 'c') {
                    val[j] = stod(s.substr(5, s.length()));
                    BstDouble.remove(val[j]);
                }
            }
            for(int y = 0; y < m; y++) {
                double valore = 0;
                int successore = 0;
                in >> valore;
                successore = BstDouble.step_successor(valore);
                if(successore == -1) {
                    out << "INF ";
                } else {
                    out << successore << " ";
                }
            }
            out << endl;
            BstDouble.clear();
        }
    }
}