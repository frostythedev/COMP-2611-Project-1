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

    string getName();
    int getSize();
    int getPopulation();
    string getGov();

    CountryNode* getNext();

    void setName(string& name);
    void setSize(int& size);
    void setPopulation(int& size);
    void setGov(string& government);

    void setNext(CountryNode* CountryNode);
};

#endif
