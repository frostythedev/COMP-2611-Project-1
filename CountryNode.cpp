#include "CountryNode.h"
#include <string>

CountryNode::CountryNode(const string& cName, const int& cSize, const int& cPop, const string& cEcon) : name(cName), size(cSize), population(cPop), economy(cEcon) {}

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

string CountryNode::getEconomy()
{
 return economy;
}

CountryNode* CountryNode::getNext()
{
    return next;
}

void CountryNode::setNext(CountryNode* neNext){
    next = neNext;
}
