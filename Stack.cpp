#include "Stack.h"
#include <iostream>

Stack::Stack(){
    head = NULL;
};

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

CountryNode* Stack::getHead()
{
    return head;
}

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