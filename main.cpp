#include "Stack.h"
#include "Queue.h"
#include "PQueue.h"
#include "Deque.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string strings[4];

void split(string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= str.length())
    {
        if (str[i] == seperator || i == str.length())
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int main()
{

    ifstream nodeFile{"Countries.dat", ios::in};
    if (!nodeFile)
    {
        cout << "Error loading Countries.dat" << endl;
        return -1;
    }

    Queue q;
    PQueue pq;
    Deque dq;
    Stack s;

    string data;

    while (!nodeFile.eof())
    {
        getline(nodeFile, data, '\n');

        split(data, ',');

        stringstream a(strings[1]);
        stringstream b(strings[2]);

        int size, pop;
        a >> size;
        b >> pop;

        q.enqueue(strings[0], size, pop, strings[3]);
        pq.enqueue(strings[0], size, pop, strings[3]);
        dq.insertFirst(strings[0], size, pop, strings[3]);
        s.push(strings[0], size, pop, strings[3]);

    }

    cout << "QUEUE OUTPUT: \n";
    q.printAll();
    cout << endl;

    cout << "PQUEUE OUTPUT: \n";
    pq.printAll();
    cout << endl;

    cout << "DEQUE OUTPUT: \n";
    dq.printAll();
    cout << endl;

    cout << "STACK OUTPUT: \n";
    s.printAll();
    cout << endl;

    q.dequeue();
    pq.dequeue();
    s.pop();
    dq.removeFirst();
    dq.removeLast();
    dq.removeLast();
    dq.removeLast();

    cout << "==================" << endl << endl;

    cout << "QUEUE OUTPUT: \n";
    q.printAll();
    cout << endl;

    cout << "PQUEUE OUTPUT: \n";
    pq.printAll();
    cout << endl;

    cout << "DEQUE OUTPUT: \n";
    dq.printAll();
    cout << endl;

    cout << "STACK OUTPUT: \n";
    s.printAll();
    cout << endl;

    return 0;
}
