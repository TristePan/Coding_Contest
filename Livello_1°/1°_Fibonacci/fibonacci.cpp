//Si realizzi un programma in C++ che preso in input un numero intero n calcoli e restituisca in output l'n-esimo elemento della sequenza di Fibonacci. Si supponga che la sequenza parta dalla posizione 1.

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long int fibonacci(int n) {

    long int n1 = 1, n2 = 1, next;

    if(n == 0 || n == 1) return 1;

    for(int i = 2; i < n; i++) {
        next = n2;
        n2 = n1;
        n1 = next + n2;
    }

    cout << n1 << endl;
    return n1;
}

int main() {

    fstream fin("input.txt", fstream::in);
    fstream fout("output.txt", fstream::out);
    
    for(int i = 0; i < 100; i++) {
        long int nFibo;
        fin >> nFibo;
        nFibo = fibonacci(nFibo);
        fout << nFibo << endl;
    }
}
