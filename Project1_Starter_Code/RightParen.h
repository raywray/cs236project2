//
// Created by Raya Esplin on 5/3/21.
//

#ifndef PROJECT1_STARTER_CODE_RIGHTPAREN_H
#define PROJECT1_STARTER_CODE_RIGHTPAREN_H

#include "Automaton.h"

class RightParenAutomaton : public Automaton
{
public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_RIGHTPAREN_H
