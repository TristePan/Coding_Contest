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
        //cout << n;

        int *num = new int[n];

        for(int j = 0; j < n; j++) {
            in >> num[j];
            //cout << num[j] << " ";
            if(num[j] % 2 != 0) {
                out << num[j] << " ";
            }
        }
        out << endl;
    }

}