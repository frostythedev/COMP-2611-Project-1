#include "CountryNode.h"

class PQueue
{

private:
    CountryNode* head;
    CountryNode* tail;

    int qSize;

    public:
    PQueue();

    void setSize(int newSize);
    int size();

    CountryNode* dequeue();

    void enqueue(string name, int size, int pop, string econ);

    CountryNode* front();
    
    bool isEmpty();

    void printAll();

    CountryNode* getHead();
    CountryNode* getTail();

};