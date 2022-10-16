#include "Stack.h"
#include <iostream>

Stack::Stack(){
    head = NULL;
};


// Creates a new node and pushes it to the head of the ADT, sets the current head of the node to the nextNode of the new head
void Stack::push(string name, int size, int pop, string gov)
{

    CountryNode* node = new CountryNode(name, size, pop, gov);

    if (head == NULL)
    {
        node->setNext(NULL);
        head = node;
        return;
    }

    node->setNext(head);
    head = node;
}

// Returns the pointer of the countrynode at the top/head of the ADT structure
CountryNode* Stack::getHead()
{
    return head;
}

//If there is a nextNode to the currentHead of the ADT structure, sets that nextNode to the currentHead of the ADT
void Stack::pop()
{

    if (head != NULL)
    {
        CountryNode* next = head->getNext();

        if (next != NULL)
        {
            head = next;
        }
    }
}

// Prints all data contained within the current ADT
void Stack::printAll()
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