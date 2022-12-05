//Si scriva un programma che, presa una sequenza di numeri interi,
//sia in grado di calcolare il numero minore contenuto all'interno della sequenza
//e sia in grado di trascriverlo in output.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);

    int min[100];
    
    for (int i = 0; i < 100; i++) {
        
        min[i]= INT_MAX;

        string val = "";

        while(val != "STOP") {
            fin >> val;
            if(val[0]=='1'||val[0]=='2'||val[0]=='3'||val[0]=='4'||val[0]=='5'||val[0]=='6'||val[0]=='7'||val[0]=='8'||val[0]=='9'||val[0]=='0') {
                int s = stoi(val);
                if (min[i] >= s) {
                    min[i] = s;
                }
            }
        }
        
        fout << min[i] << endl;
        cout << min[i] << endl;
    }
}