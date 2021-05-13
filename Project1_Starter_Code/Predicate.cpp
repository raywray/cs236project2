//
// Created by Raya Esplin on 5/10/21.
//

#include "Predicate.h"
#include <sstream>
Predicate::Predicate(std::vector<Parameter> myVector, std::string thisID) {
    parameter_vector = myVector;
    myID = thisID;
}

Predicate::Predicate(std::string allAlone) {
    myID = allAlone;
}
Predicate::Predicate() {

}

Predicate::~Predicate() {

}

void Predicate::addParameter(Parameter toAdd) {
    parameter_vector.push_back(toAdd);
}


std::string Predicate::PredicateToString() {
    std::stringstream predicateString;
    predicateString << myID << "(";
    int i = 0;
    while (i != (int)parameter_vector.size()) {
        predicateString << parameter_vector.at(i).getParameter();
        i++;
        if (i != (int)parameter_vector.size()) {
            predicateString << ",";
        }
    }
    predicateString << ")";
    return predicateString.str();
}