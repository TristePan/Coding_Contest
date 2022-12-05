#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename H>
class Queue {
    private:
        H *queue;
        int length;
        int head;
        int tail;
        int count;

    public:
        Queue(int size);

        int getCount() const;

        bool isFull();
        
        bool isEmpty();
        
        void enqueue(H value);
        
        void dequeue(H value);
        
        void stampa(ostream& out);

        H getHead();

        ~Queue() {
            delete [] queue;
        }

};

template <typename H>
Queue<H> :: Queue(int size) {
    queue = new H[size];
    length = size;
    count = 0;
    tail = -1;
    head = 0;
}

template <typename H>
int Queue<H> :: getCount() const {
    return count;
}

template <typename H>
bool Queue<H> :: isFull() {
    return getCount() == length;
}

template <typename H>
bool Queue<H> :: isEmpty() {
    return getCount() == 0;
}

template <typename H>
void Queue<H> :: enqueue(H value) {
    if(isFull()) {
        cout << "Coda Piena!" << endl;
    }
    /*
    if(isEmpty()) {
        cout << "Coda Vuota!" << endl;
    }
    */
    tail = (tail + 1) % length;
    queue[tail] = value;
    count++;
}

template <typename H>
void Queue<H> :: dequeue(H value) {

    head = (head + 1) % length;
    count--;
}

template <typename H>
void Queue<H> :: stampa(ostream& out) {
    for(int i = head; i <= tail; i++) {
        out << queue[i] << " ";
    }
    out << endl;
}

template <typename H>
H Queue<H> :: getHead() {
    return queue[head];
}