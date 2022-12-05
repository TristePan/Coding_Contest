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

        int getSize() const;

        bool isFull();
        
        bool isEmpty();
        
        void enqueue(H value);
        
        void dequeue();
        
        void stampa(ostream& out);

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
int Queue<H> :: getSize() const {
    return count;
}

template <typename H>
bool Queue<H> :: isFull() {
    return getSize() == length;
}

template <typename H>
bool Queue<H> :: isEmpty() {
    return getSize() == 0;
}

template <typename H>
void Queue<H> :: enqueue(H value) {
    if(isFull()) {
        cout << "Coda Piena!" << endl;
    }
    if(isEmpty()) {
        head = 0;
    }

    tail = (tail + 1) % length;
    queue[tail] = value;
    count++;
}

template <typename H>
void Queue<H> :: dequeue() {
    if(isEmpty()) {
        cout << "Coda Vuota!" << endl;
    }
    if(head == tail) {
        head = -1;
        tail = -1;
    }
    else {
        head = (head + 1) % length;
    }
    count--;
}

template <typename H>
void Queue<H> :: stampa(ostream& out) {
    for(int i = 0; i < count; i++) {
        out << queue[i] << " ";
    }
    out << endl;
}