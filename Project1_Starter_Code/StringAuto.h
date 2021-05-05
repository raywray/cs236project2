//
// Created by Raya Esplin on 5/3/21.
//

#ifndef PROJECT1_STARTER_CODE_STRINGAUTO_H
#define PROJECT1_STARTER_CODE_STRINGAUTO_H

#include "Automaton.h"

class StringAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    StringAutomaton() : Automaton(TokenType::STRING_TYPE) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_STRINGAUTO_H
