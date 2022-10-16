#ifndef COUNTRYNODE_H
#define COUNTRYNODE_H

#include <string>
#include <iostream>

using namespace std;

class CountryNode
{
private:
    string name;
    int size;
    int population;
    string government;

    CountryNode* next;

public:
    CountryNode(const string&, const int&, const int&, const string&);


// Accessor functions to retrieve private data of the Country Node class
    string getName();
    int getSize();
    int getPopulation();
    string getGov();

    string getAllData();

    CountryNode* getNext();

// Reassignment or 'Setter' funtions to reassign private data fields of the Country Node class
    void setName(string& name);
    void setSize(int& size);
    void setPopulation(int& size);
    void setGov(string& government);

    void setNext(CountryNode* CountryNode);
};

#endif
