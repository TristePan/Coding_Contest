#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream in("input.txt", fstream::in);
fstream out("output.txt", fstream::out);

void solution(int *l, int n, int f, int c, ostream& out) {
    for(int j = 0; j < n; j++) {
            if(l[j] > f) {
                c++;
            }
    }

    //cout << c << " ";
    out << c << " ";

    for(int i = 0; i < n; i++) {
        if(l[i] > f){
            out << l[i] << " ";
        }
    }
    out << endl;
    //cout << endl;
}


int main() {

    int n;
    int f;
    int *l;
    int c = 0;

    for(int i = 0; i < 100; i++) {

        in >> n;
        in >> f;

        l = new int[n];

        for(int j = 0; j < n; j++) {
            in >> l[j];
            //cout << l[j] << " ";
        }


        solution(l, n, f, c, out);
        
    }
}
