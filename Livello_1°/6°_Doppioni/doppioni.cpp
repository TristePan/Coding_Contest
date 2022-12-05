#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main() {

    fstream in("input.txt", fstream::in);
    fstream out("output.txt", fstream::out);

    for(int i = 0; i < 101; i++) {
        
        int n;
        in >> n;
        int c = 0;
        int v[n];
        
        //cout << n << " " << endl;

        for(int k = 0; k < n; k++) {
            in >> v[k];
            //cout << v[k] << " ";
        }

        //cout << endl;

        for(int j = 0; j < n; j++) {
            //cout << "j = " << j << endl;
            for(int z = 0; z < n; z++) {
                //cout << "z = " << z << endl;
                if(v[j] == v[z] && j != z && v[j] != 0 && v[z] != 0) {
                    //cout << v[j] << " " << v[z] << endl;
                    c++;
                    v[z] = 0;
                }
            }
        }
        //cout << endl;
        out << c << endl;
        c = 0;
    }
}