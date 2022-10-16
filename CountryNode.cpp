#include "CountryNode.h"
#include <string>

CountryNode::CountryNode(const string& cName, const int& cSize, const int& cPop, const string& cGov) : name(cName), size(cSize), population(cPop), government(cGov) {}

string CountryNode::getName()
{
    return name;
}

int CountryNode::getSize()
{
    return size;
}

int CountryNode::getPopulation()
{
    return population;
}

string CountryNode::getGov()
{
 return government;
}

CountryNode* CountryNode::getNext()
{
    return next;
}

void CountryNode::setNext(CountryNode* neNext){
    next = neNext;
}
