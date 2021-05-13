//
// Created by Raya Esplin on 5/10/21.
//

#ifndef PROJECT1_STARTER_CODE_PARAMETER_H
#define PROJECT1_STARTER_CODE_PARAMETER_H
#include <string>

class Parameter {
private:
    std::string myString;
    bool isID;
public:
    Parameter(std::string aString, bool isitID);
    ~Parameter();
    std::string getParameter();
    bool getBool();
};


#endif //PROJECT1_STARTER_CODE_PARAMETER_H
