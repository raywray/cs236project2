//
// Created by Raya Esplin on 5/10/21.
//
#pragma once
#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H
#include "Token.h"
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include "DatalogProgram.h"
#include "Parameter.h"


class Parser {
private:
    std::vector<Token*> tokenvector;
    DatalogProgram myProgram;
public:
    int counter = 0;
    Parser(std::vector<Token*> tokenvector);
    ~Parser();
    void parse();
    //Datalog parse();
    void match(TokenType current, TokenType toMatch);
    void Advance();
    void datalogProgram();
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    void scheme();
    void fact();
    void rule();
    void query();
    Predicate headPredicate();
    Predicate predicate();
    void predicateList(Rule& newRule);
    void parameterList(Predicate& myPredicate);
    void stringList(Predicate& myPredicate);
    void idList(Predicate& myPredicate);
    void parameter(Predicate& myPredicate);

    std::string ParserToString();

};


#endif //PROJECT1_STARTER_CODE_PARSER_H
