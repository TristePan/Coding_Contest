//Si fornisca un programma che dati in input tre nomi di lunghezza variabile, sia in grado di individuare tra questi quelli che iniziano o finiscono con un determinato carattere A ma che, allo stesso tempo, non inizino ne finiscano con un altro determinato carattere B.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
        fstream fin("input.txt", fstream::in);
        fstream fout("output.txt", fstream::out);
    
        string output;
    
        for(int i = 0; i < 100; i++) {
    
            char a, b;
            int n1, n2, n3;
            string nome1, nome2, nome3;
    
            fin >> a >> b >> n1 >> nome1 >> n2 >> nome2 >> n3 >> nome3;
    
            if(nome1[0] == a || nome1[nome1.length() - 1] == a) {
                if(nome1[0] != b && nome1[nome1.length() - 1] != b) {
                    fout << nome1 << " ";
                }
            } if(nome2[0] == a || nome2[nome2.length() - 1] == a) {
                if(nome2[0] != b && nome2[nome2.length() - 1] != b) {
                    fout << nome2 << " ";
                }
            } if(nome3[0] == a || nome3[nome3.length() - 1] == a) {
                if(nome3[0] != b && nome3[nome3.length() - 1] != b) {
                    fout << nome3 << " ";
                }
                fout << "\n";
            }
        }
}