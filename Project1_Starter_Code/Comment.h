//
// Created by Raya Esplin on 5/3/21.
//
#pragma once
#ifndef PROJECT1_STARTER_CODE_COMMENT_H
#define PROJECT1_STARTER_CODE_COMMENT_H

#include "Automaton.h"

class CommentAutomaton : public Automaton
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

public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_COMMENT_H
