//Provide a program that gives input three surnames of variable length and a value N
//be able to identify among these those that are similar to each other with respect to the value K.
//That is, all surnames that have a prefix of length N in common, but not a prefix of length N + 1.

// Path: cognomi_simili_copilot.cpp


#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 3;
    string cognomi[n];
    int k = 3;
    for (int i = 0; i < n; i++) {
        cout << "Inserisci il cognome " << i + 1 << ": ";
        cin >> cognomi[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cognomi[i].substr(0, k) == cognomi[j].substr(0, k) && i != j) {
                cout << "I cognomi " << cognomi[i] << " e " << cognomi[j] << " sono simili" << endl;
            }
        }
    }
}
