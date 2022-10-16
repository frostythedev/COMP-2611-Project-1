#include "CountryNode.h"

class Deque
{

    private:
    CountryNode* head;
    CountryNode* tail;
    int qSize;

    public:
    Deque();

    void setSize(int s);
    void printAll();

    //CountryNode* dequeue();
    //void enqueue(string name, int size, int pop, string econ);

    void insertFirst(string name, int size, int pop, string econ);
    void insertLast(string name, int size, int pop, string econ);

    void removeFirst();
    void removeLast();

    CountryNode* first();
    CountryNode* last();

    bool isEmpty();
    int size();

};