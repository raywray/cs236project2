//
// Created by Raya Esplin on 5/3/21.
//

#ifndef PROJECT1_STARTER_CODE_UNDEFINED_H
#define PROJECT1_STARTER_CODE_UNDEFINED_H


#include "Automaton.h"

class UndefinedAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);

public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_UNDEFINED_H
