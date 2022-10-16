#include "PQueue.h"

PQueue::PQueue()
{
    head = NULL;
    tail = NULL;
    qSize = 0;
};


// Returns the current size of the priority queue
int PQueue::size()
{
    return qSize;
}

// Set the size of the pqueue
void PQueue::setSize(int s)
{
    qSize = s;
}

// Creates a country node based on the given information, 
void PQueue::enqueue(string name, int size, int pop, string gov)
{

    CountryNode *node = new CountryNode(name, size, pop, gov);
    node->setNext(NULL);

    if (head == NULL)
    {
        head = node;
    }
    else
    {

        // If created node is alphabetically less than the current head, set the current node's next node as the head and reassign
        // head to the current node
        if (node->getName() < head->getName())
        {
            node->setNext(head);
            head = node;
        }
        else
        {

            
            CountryNode *infront = head->getNext();
            CountryNode *behind = head;

            // Go through the pqueue from the head until you find the node which falls before the current node alphabetically, insert
            // the curent node in its new position, and set its next Node to the net node it replaced
            while (infront != NULL && node->getName() > behind->getName())
            {
                behind = infront;
                infront = behind->getNext();
            }

            if (infront == NULL) // We have reached the end of the list
            {
                behind->setNext(node);
                return;
            }

            node->setNext(infront);
            behind->setNext(node);
            return;
        }
    }

    qSize++;
}


// Reassigns the head of the priority queue to the next CountryNode pointed to by the old head if NOT NULL and decreases the size
// of the current queue
CountryNode *PQueue::dequeue()
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

// Returns the CountryNode at the top of the priority queue
CountryNode *PQueue::front()
{
    return head;
}

// Returns true if the current size of the pqueue is 0 or if the head of the pQueue is null, returns false otherwise
bool PQueue::isEmpty()
{
    return (qSize == 0 || head == NULL);
}

// Prints all data contained within the current ADT
void PQueue::printAll()
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