//
// Created by Raya Esplin on 5/10/21.
//

#include "Parameter.h"

Parameter::Parameter(std::string aString, bool isitId) {
    isID = isitId;
    myString = aString;
}
Parameter::~Parameter() {
}

std::string Parameter::getParameter() {
    return myString;
}

bool Parameter::getBool() {
    return isID;
}

