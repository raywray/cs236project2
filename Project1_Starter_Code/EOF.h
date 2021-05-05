//
// Created by Raya Esplin on 5/3/21.
//

#ifndef PROJECT1_STARTER_CODE_EOF_H
#define PROJECT1_STARTER_CODE_EOF_H

#include "Automaton.h"

class EOFAutomaton : public Automaton
{
private:
    void S1(const std::string& input);

public:
    EOFAutomaton() : Automaton(TokenType::EOF_TYPE) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_EOF_H
