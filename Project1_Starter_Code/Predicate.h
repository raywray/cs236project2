//
// Created by Raya Esplin on 5/10/21.
//

#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H
#include <vector>
#include <string>
#include "Parameter.h"

class Predicate {
private:
    //TODO
    std::vector<Parameter> parameter_vector;
    //vector of parameters for one element
    std::string myID;
    //string of id for one element
public:
    Predicate(std::vector<Parameter> myVector, std::string thisID);
    Predicate(std::string allAlone);
    Predicate();
    ~Predicate();
    void addParameter(Parameter toAdd);
    std::string PredicateToString();
};


#endif //PROJECT1_STARTER_CODE_PREDICATE_H
