#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void solution(char c, string riga, ostream& out) {
    int index = -1;
    int count = 0;

    for(int i = 0; i < riga.size(); i++) {
        index++;
        if(c == riga[i]) {
            count++;
            out << index << " ";
        } else if(riga[i] == ' ') {
            index = -1;
        }
    }
    if(count == 0) {
        out << "none" << endl;
    } else {
        out << endl;
    }
}

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    char s;

    for(int i = 0; i < 100; i++) {
        in >> s;
        cout << s;

        string riga;
        getline(in, riga);
        cout << riga << endl;

        solution(s, riga, out);
    }
}