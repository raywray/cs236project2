//
// Created by Raya Esplin on 5/3/21.
//
#pragma once
#ifndef PROJECT1_STARTER_CODE_COMMA_H
#define PROJECT1_STARTER_CODE_COMMA_H


#include "Automaton.h"

class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};



#endif //PROJECT1_STARTER_CODE_COMMA_H
