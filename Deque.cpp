#include "Deque.h"

Deque::Deque()
{
    head = NULL;
    tail = NULL;
    qSize = 0;
}


// Returns the current size of the Deque
int Deque::size()
{
    return qSize;
}

// Sets the currentSize of the Deque
void Deque::setSize(int s)
{
    qSize = s;
}


// Creates a countryNode using the provided information and inserts it at the head of the deque, 
// updates the new head to point to the previous head
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

// Removes the current head of the Deque and sets the new head to the old head's next pointer
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


// Inserts a countryNode to the tail of the deque, updates the current tail if not null to point to the new tail
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

// Removes the current Tail of the deque, sets the node that is currently pointing to the tail to the new tail once it is not null
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

// Returns the current 'head' CountryNode of the deque
CountryNode *Deque::first()
{
    return head;
}


// Returns the current 'tail' countryNode of the deque
CountryNode *Deque::last()
{
    return tail;
}

// Returns true if the current size of the deque is 0 OR the head and tail pointers are null
bool Deque::isEmpty()
{
    return (qSize == 0 || (head == NULL && tail == NULL));
}


// Prints all data contained within the current ADT
void Deque::printAll()
{
    //cout << "[";

    if (head == NULL)
    {
        cout << "Empty Deque";
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
