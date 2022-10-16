#include "Deque.h"

Deque::Deque()
{
    head = NULL;
    tail = NULL;
    qSize = 0;
}

int Deque::size()
{
    return qSize;
}

void Deque::setSize(int s)
{
    qSize = s;
}

void Deque::insertFirst(string name, int size, int pop, string gov)
{
    CountryNode *node = new CountryNode(name, size, pop, gov);

    if (head == NULL)
    {
        node->setNext(NULL);
        head = node;

        if (tail == NULL)
        {
            tail = node;
        }
    }
    else
    { // Head is not null
        node->setNext(head);
        head = node;
    }
}

void Deque::removeFirst()
{
    if (head != NULL)
    {
        CountryNode *next = head->getNext();
        if (next != NULL)
        {
            head = next;
        }else{
            head = NULL;
            tail = NULL;
        }
    }
}

void Deque::insertLast(string name, int size, int pop, string gov)
{
        CountryNode *node = new CountryNode(name, size, pop, gov);

        if(tail == NULL && head == NULL){
            insertFirst(name, size, pop, gov);
            return;
        }

        if(tail != NULL)
        {
            node->setNext(NULL);
            tail->setNext(node);
            tail = node;
        }
}

void Deque::removeLast()
{
    if(tail == NULL) return;


    CountryNode* curr = head;
    CountryNode* next = curr->getNext();
    CountryNode* infront = next->getNext();
    
    while(infront != NULL)
    {
        curr = infront;
        next = curr->getNext();
        infront = next->getNext();
    }

    next = NULL;

    curr->setNext(NULL);
    tail = curr;

}

CountryNode *Deque::first()
{
    return head;
}

CountryNode *Deque::last()
{
    return tail;
}

bool Deque::isEmpty()
{
    return (qSize == 0 || (head == NULL && tail == NULL));
}

void Deque::printAll()
{
    cout << "[";

    if (head == NULL)
    {
        cout << "Empty Stack";
    }
    else
    {
        cout << head->getName();
        CountryNode *next = head->getNext();

        while (next != NULL)
        {
            cout << ", " << next->getName();
            next = next->getNext();
        }
    }

    cout << "]" << endl;
}
