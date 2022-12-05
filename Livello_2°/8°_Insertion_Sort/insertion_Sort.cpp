#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void insertion_sort(int *v, int n, ostream& out) {
    int count = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                count++;
            }
        }
    }
    out << count;
}

int main() {
    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    int n;

    for(int i = 0; i < 100; i++) {
        in >> n;
        int *v = new int[n];

        for(int j = 0; j < n; j++) {
            in >> v[j];
        }
        insertion_sort(v, n, out);
        out << endl;
    }
}