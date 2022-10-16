#include "Queue.h"
#include <iostream>

Queue::Queue()
{
    head = NULL;
    qSize = 0;
}

int Queue::size()
{
    return qSize;
}

void Queue::setSize(int s)
{
    qSize = s;
}

void Queue::enqueue(string name, int size, int pop, string gov)
{

    CountryNode* node = new CountryNode(name, size, pop, gov);
    node->setNext(NULL);

    if (head == NULL)
    {
        head = node;
        //qSize = 0;
    }
    else
    {

        if(head->getNext() == NULL)
        {
            head->setNext(node);
        }else {

            CountryNode* last = head->getNext();

            while (last->getNext() != NULL)
            {
                last = last->getNext();
            }

            last->setNext(node);
            
        }
    }

    //head = node;
    qSize++;
}

CountryNode *Queue::dequeue()
{

    if (head == NULL)
        return NULL;

    CountryNode *h = head;

    if (head->getNext() == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->getNext();
    }

    qSize--;
    return h;
}

CountryNode* Queue::front(){
    return head;
}

bool Queue::isEmpty()
{
    return (qSize == 0 || head == NULL);
}

void Queue::printAll()
{
    cout << "[";

    if (head == NULL)
    {
        cout << "Empty Stack";
    }
    else
    {
        cout << head->getName();
        CountryNode* next = head->getNext();

        while (next != NULL)
        {
            cout << ", " << next->getName();
            next = next->getNext();
        }
    }

    cout << "]" << endl;
}