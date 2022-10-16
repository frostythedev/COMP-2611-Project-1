#include "CountryNode.h"

class Queue
{

private:
    int qSize;
    CountryNode* head;

public:
    Queue();

    void setSize(int newSize);
    int size();

    CountryNode* dequeue();

    void enqueue(string name, int size, int pop, string gov);

    CountryNode* front();
    
    bool isEmpty();

    void printAll();
};