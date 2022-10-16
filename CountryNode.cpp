#include "CountryNode.h"
#include <string>

CountryNode::CountryNode(const string &cName, const int &cSize, const int &cPop, const string &cGov) : name(cName), size(cSize), population(cPop), government(cGov) {}

// Reassigns the name of the current countrynode to the new name n
void CountryNode::setName(string &n)
{
    name = n;
}

// Returns the current name of the CountryNode
string CountryNode::getName()
{
    return name;
}

// Reassigns the size value of the current Countrynode
void CountryNode::setSize(int &s)
{
    size = s;
}

//Returns the size of the current CountryNode 
int CountryNode::getSize()
{
    return size;
}

//Reassigns the value of the current countryNode's population to p
void CountryNode::setPopulation(int &p)
{
    population = p;
}

//Returns the current population of the countryNode
int CountryNode::getPopulation()
{
    return population;
}

//Reassigns the current countryNode's government model to gov
void CountryNode::setGov(string &gov)
{
    government = gov;
}


// Returns the government model of the current country node
string CountryNode::getGov()
{
    return government;
}


// Sets the stored pointer of the next countryNode to neNext
void CountryNode::setNext(CountryNode *neNext)
{
    next = neNext;
}

// Returns a pointer to the next CountryNode that this object is linked too
CountryNode *CountryNode::getNext()
{
    return next;
}

// Returns all the data of the current Country Node
string CountryNode::getAllData()
{
    string data = "";
    data.append(name);
    data.append("\t" + to_string(size));
    data.append("\t" + to_string(population));
    data.append("\t" + government + "\n");

    return data;
}
