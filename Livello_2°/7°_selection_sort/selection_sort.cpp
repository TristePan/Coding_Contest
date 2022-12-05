#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void selection_sort(int *v, int n, ostream& out) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        count += min - i;
        swap(v[i], v[min]);
    }
    out << count;
}


int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);


    for(int i = 0; i < 100; i++) {
        int n;
        in >> n;
        //cout << n << " ";
        int *v = new int[n];
        for(int j = 0; j < n; j++) {
            in >> v[j];
            //cout << v[j] << " ";
        }
        selection_sort(v, n, out);
        out << endl;
    }

}