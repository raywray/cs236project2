//
// Created by Raya Esplin on 5/3/21.
//

#ifndef PROJECT1_STARTER_CODE_UNDEFINED_H
#define PROJECT1_STARTER_CODE_UNDEFINED_H
#pragma once

#include "Automaton.h"

class UndefinedAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
    void S7(const std::string& input);
    void S8(const std::string& input);
    void S9(const std::string& input);
    void S10(const std::string& input);
    void S11(const std::string& input);
    void S12(const std::string& input);
    void S13(const std::string& input);
    void S14(const std::string& input);

public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_UNDEFINED_H
