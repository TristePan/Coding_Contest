#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void inverti(string *parole, int index, ostream& out) {
    for(int i = 0; i < parole[index].size(); i++) {
        
    }
}

int main() {
    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    int n;

    for(int i = 0; i < 3; i++) {

        in >> n;
        cout << n << " ";

        string *parole = new string[n];
        string temp;

        for(int j = 0; j < n; j++) {
            in >> parole[j];
            parole[j] == temp;
            cout << temp << " ";
        }
        cout << endl;
    }
}