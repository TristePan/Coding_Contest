#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream in("input.txt", fstream :: in);
    fstream out("output.txt", fstream :: out);

    for(int i = 0; i < 100; i++) {
        string s;
        string spazio = " ";
        int count = 0;
        getline(in, s);
        if(s.find(spazio) != string :: npos) {
            count++;
            while(s.find(spazio) != string :: npos) {
                s.erase(0, s.find(spazio) + 1);
                count++;
            }
        }
        out << count << endl;
    }
}