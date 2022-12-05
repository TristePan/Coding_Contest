#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solution(string x, int n, ostream& out) {
    int z = 1;

    bool condition = false;
    while(!condition) {
        if(x[z] >= '0' && x[z] <= '9') {
            z++;
        } else {
            condition = true;
        }
    }

    string tmp = x.substr(0, z);
    string tmp2 = x.substr(z+1, x.length());
    int val = stoi(tmp);
    int val2 = stoi(tmp2);

    if(x[z] == '+') {
        out << val + val2 << " ";
    } else if(x[z] == '-') {
        out << val - val2 << " ";
    } else if(x[z] == '*') {
        out << val * val2 << " ";
    } else if(x[z] == '/') {
        out << val / val2 << " ";
    } else if(x[z] == '%') {
        out << val % val2 << " ";
    }
}


int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    for(int i = 0; i < 100; i++) {

        int n;
        in >> n;
        //cout << n << " ";

        for(int j = 0; j < n; j++) {

            string x;
            in >> x;

            solution(x, n, out);
        }
        out << endl;
    }
}