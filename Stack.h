#include "CountryNode.h"

class Stack
{

private:
    CountryNode* head;

public:
    Stack();

    void push(string name, int size, int pop, string economy);

    void pop();

    void printAll();

    CountryNode* getHead();
};