#include <iostream>

using namespace std;

template <typename T>
void func(const T& x) {
    static int count = 0;
    cout << "x = " << x << "count = " << count << endl;
    ++count;
    return;
}

int main() {
    double mt[2][3] = {1,2,3,4,5,6};
    for(int f = 0; f < 2; f++) {
        for(int c = 0; c < 3; c++) {
            cout << *(*(mt+f)+c) << " ";
        }
        cout << "\n";

    }
}