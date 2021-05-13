#ifndef LEXER_H
#define LEXER_H
#pragma once
#include <list>
#include <vector>

#include "Automaton.h"
#include "Token.h"
#include "Comma.h"
#include "LeftParen.h"
#include "RightParen.h"
#include "Period.h"
#include "QMark.h"
#include "Multiply.h"
#include "Add.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"
#include "ID.h"
#include "Comment.h"
#include "StringAuto.h"
#include "Undefined.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"


class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    void CreateAutomata();



public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    std::string toString();
    std::string totalTokens();
    std::vector<Token*> getTokens();

    


};

#endif // LEXER_H

