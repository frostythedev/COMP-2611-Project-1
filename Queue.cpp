#include "Queue.h"
#include <iostream>


// Default constructor to initialize variables 
Queue::Queue()
{
    head = NULL;
    qSize = 0;
}


// Get the current size of the queue
int Queue::size()
{
    return qSize;
}

// Sets the size of the current queue to s
void Queue::setSize(int s)
{
    qSize = s;
}

// Creates a new countryNode, sets it to the head if the current head is null. If currentHead is not null and it does not have anext
// node that it currently points too, set the created node as the next node. If the head currently points to a nextNode, loop until
// we reach the end of the ADT structure and append the createdNode to the end of the structure
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

// Removes the queue at the head/front of the queue
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

// Returns the node at the front/head of the queue
CountryNode* Queue::front(){
    return head;
}

// Returns true if the current size of the pqueue is 0 or if the head of the pQueue is null, returns false otherwise
bool Queue::isEmpty()
{
    return (qSize == 0 || head == NULL);
}

// Prints all data contained within the current ADT
void Queue::printAll()
{
    //cout << "[";

    if (head == NULL)
    {
        cout << "Empty Stack";
    }
    else
    {
        cout << head->getAllData();
        CountryNode* next = head->getNext();

        while (next != NULL)
        {
            //cout << next->getAllData();
            cout << next->getAllData();
            next = next->getNext();
        }
    }

    //cout << "]" << endl;
}