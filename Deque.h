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

    void insertFirst(string name, int size, int pop, string gov);
    void insertLast(string name, int size, int pop, string gov);

    void removeFirst();
    void removeLast();

    CountryNode* first();
    CountryNode* last();

    bool isEmpty();
    int size();

};