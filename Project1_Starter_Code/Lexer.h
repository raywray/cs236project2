#ifndef LEXER_H
#define LEXER_H

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
#include "EOF.h"
#include "StringAuto.h"
#include "Undefined.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"


class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    /*std::vector<AddAutomaton*> add;
    std::vector<ColonAutomaton*> colon;
    std::vector<ColonDashAutomaton*> colon_dash;
    std::vector<CommaAutomaton*> comma;
    std::vector<CommentAutomaton*> comment;
    std::vector<EOFAutomaton*> eof_types;
    std::vector<FactsAutomaton*> facts;
    std::vector<IDAutomaton*> id;
    std::vector<LeftParenAutomaton*> left_paren;
    std::vector<MultiplyAutomaton*> multiply;
    std::vector<PeriodAutomaton*> period;
    std::vector<QMarkAutomaton*> qmark;
    std::vector<QueriesAutomaton*> queries;
    std::vector<RightParenAutomaton*> right_paren;
    std::vector<RulesAutomaton*> rules;
    std::vector<SchemesAutomaton*> schemes;
    std::vector<StringAutomaton*> string_auto;
    std::vector<UndefinedAutomaton*> undefined;*/

    void CreateAutomata();

    /*std::list<std::string> automata_list = { "AddAutomaton", "ColonAutomaton", "ColonDashAutomaton", "CommaAutomaton",
                                             "CommentAutomaton", "EOFAutomaton", "FactsAutomaton", "IDAutomaton",
                                             "LeftParenAutomaton", "MultiplyAutomaton", "PeriodAutomaton",
                                             "QMarkAutomaton", "QueriesAutomaton", "RightParenAutomaton", "RulesAutomaton",
                                             "SchemesAutomaton", "StringAutomaton", "UndefinedAutomaton" };*/

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    std::string toString();
    
    // TODO: add other public methods here

};

#endif // LEXER_H

