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

void Deque::insertFirst(string name, int size, int pop, string econ)
{
    CountryNode *node = new CountryNode(name, size, pop, econ);

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

void Deque::insertLast(string name, int size, int pop, string econ)
{
        CountryNode *node = new CountryNode(name, size, pop, econ);

        if(tail == NULL && head == NULL){
            insertFirst(name, size, pop, econ);
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

// void Deque::enqueue(string name, int size, int pop, string econ)
// {

//     CountryNode *node = new CountryNode(name, size, pop, econ);
//     node->setNext(NULL);

//     if (head == NULL)
//     {
//         head = node;
//         tail = node;
//     }
//     else
//     {

//         if (node->getName() < head->getName())
//         {
//             node->setNext(head);
//             head = node;
//         }
//         else
//         {

//             CountryNode *infront = head->getNext();
//             CountryNode *behind = head;

//             while (infront != NULL && node->getName() > behind->getName())
//             {
//                 behind = infront;
//                 infront = behind->getNext();
//             }

//             if (infront == NULL) // We have reached the end of the list
//             {
//                 behind->setNext(node);
//                 return;
//             }

//             node->setNext(infront);
//             behind->setNext(node);
//             return;
//         }
//     }

// after:

//     qSize++;
// }

// CountryNode* Deque::dequeue()
// {

//     if (head == NULL)
//         return NULL;

//     CountryNode *h = head;

//     if (head->getNext() == NULL)
//     {
//         head = NULL;
//     }
//     else
//     {
//         head = head->getNext();
//     }

//     qSize--;
//     return h;
// }

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
