#include "PQueue.h"

PQueue::PQueue()
{
    head = NULL;
    tail = NULL;
    qSize = 0;
};

int PQueue::size()
{
    return qSize;
}

void PQueue::setSize(int s)
{
    qSize = s;
}

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
        if (node->getName() < head->getName())
        {
            node->setNext(head);
            head = node;
        }
        else
        {

            CountryNode *infront = head->getNext();
            CountryNode *behind = head;

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

after:

    qSize++;
}

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

CountryNode *PQueue::front()
{
    return head;
}

bool PQueue::isEmpty()
{
    return (qSize == 0 || head == NULL);
}

void PQueue::printAll()
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