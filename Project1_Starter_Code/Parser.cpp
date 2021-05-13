//
// Created by Raya Esplin on 5/10/21.
//

#include "Parser.h"
#include <iostream>

using namespace std;

//check for a token type
// use try & catch to throw token that doesn't fit grammar
//or call another function
//when nonTerm has flere productions
//if next string, match string. If ID, match ID, etc
//with lambda, DON'T USE ELSE
//if no lambda, THROW NEXT TOKEN IN ELSE
//use if-else statement

Parser::Parser(std::vector<Token*> tokenvector) {
    this->tokenvector = tokenvector;
}
Parser::~Parser(){}

void Parser::parse() {
    datalogProgram();
}
void Parser::match(TokenType current, TokenType toMatch) {
    if (current == toMatch) {
        Advance();
    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }
}
void Parser::Advance() {
    counter ++;
}
void Parser::datalogProgram() {
    //datalogProgram -> SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    match(tokenvector.at(counter)->getToken(), TokenType::SCHEMES);
    match(tokenvector.at(counter)->getToken(), TokenType::COLON);
    scheme();
    schemeList();
    match(tokenvector.at(counter)->getToken(), TokenType::FACTS);
    match(tokenvector.at(counter)->getToken(), TokenType::COLON);
    factList();
    match(tokenvector.at(counter)->getToken(), TokenType::RULES);
    match(tokenvector.at(counter)->getToken(), TokenType::COLON);
    ruleList();
    match(tokenvector.at(counter)->getToken(), TokenType::QUERIES);
    match(tokenvector.at(counter)->getToken(), TokenType::COLON);
    query();
    queryList();
    match(tokenvector.at(counter)->getToken(), TokenType::EOF_TYPE);

}
void Parser::schemeList() {
    //schemeList -> scheme schemeList | lambda
    //FIRST = ID
    if(tokenvector.at(counter)->getTokenString() == "ID") {
        scheme();
        schemeList();
    }
    //FOLLOW = FACTS
    else if (tokenvector.at(counter)->getTokenString() == "FACTS") {

    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::factList() {
    //factList -> fact factList | lambda

    //FIRST = ID
    if(tokenvector.at(counter)->getTokenString() == "ID") {
        fact();
        factList();
    }
    //FOLLOW = RULES
    else if (tokenvector.at(counter)->getTokenString() == "RULES") {

    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::ruleList() {
    //ruleList -> rule ruleList | lambda

    //FIRST = ID
    if(tokenvector.at(counter)->getTokenString() == "ID") {
        rule();
        ruleList();
    }
    //FOLLOW = QUERIES
    else if (tokenvector.at(counter)->getTokenString() == "QUERIES") {

    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::queryList() {
    //queryList -> query queryList | lambda

    //FIRST = ID
    if(tokenvector.at(counter)->getTokenString() == "ID") {
        query();
        queryList();
    }
    //FOLLOW = EOF
    else if (tokenvector.at(counter)->getTokenString() == "EOF") {

    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::scheme() {
    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "ID (scheme1): " << tokenvector.at(counter)->getDescription() << endl;
    Predicate schemePredicate(tokenvector.at(counter)->getDescription());
    match(tokenvector.at(counter)->getToken(), TokenType::ID);
    match(tokenvector.at(counter)->getToken(), TokenType::LEFT_PAREN);
    //cout << "ID (scheme2): " << tokenvector.at(counter)->getDescription() << endl;
    Parameter schemeParameter(tokenvector.at(counter)->getDescription(), true);
    schemePredicate.addParameter(schemeParameter);
    match(tokenvector.at(counter)->getToken(), TokenType::ID);
    idList(schemePredicate);
    myProgram.addScheme(schemePredicate);
    match(tokenvector.at(counter)->getToken(), TokenType::RIGHT_PAREN);
}
void Parser::fact() {
    //fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    //cout << "ID (fact): " << tokenvector.at(counter)->getDescription() << endl;
    Predicate factPredicate(tokenvector.at(counter)->getDescription());
    match(tokenvector.at(counter)->getToken(), TokenType::ID);
    match(tokenvector.at(counter)->getToken(), TokenType::LEFT_PAREN);
    //cout << "STRING (fact): " << tokenvector.at(counter)->getDescription() << endl;
    Parameter factParameter(tokenvector.at(counter)->getDescription(), false);
    factPredicate.addParameter(factParameter);
    myProgram.addDomain(factParameter.getParameter());
    match(tokenvector.at(counter)->getToken(), TokenType::STRING_TYPE);
    stringList(factPredicate);
    myProgram.addFact(factPredicate);
    match(tokenvector.at(counter)->getToken(), TokenType::RIGHT_PAREN);
    match(tokenvector.at(counter)->getToken(), TokenType::PERIOD);
}
void Parser::rule() {
    //rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    Rule newRule;
    newRule.setHeadPredicate(headPredicate());
    match(tokenvector.at(counter)->getToken(), TokenType::COLON_DASH);
    newRule.addPredicate(predicate());
    predicateList(newRule);
    myProgram.addRule(newRule);
    match(tokenvector.at(counter)->getToken(), TokenType::PERIOD);
}
void Parser::query() {
    //query -> predicate Q_MARK
    Predicate queryPredicate = predicate();
    //predicate();
    match(tokenvector.at(counter)->getToken(), TokenType::Q_MARK);
    myProgram.addQuery(queryPredicate);
}
Predicate Parser::headPredicate() {
    //headPredicate -> ID LEFT_PAREN ID idList RIGHT_PAREN
    //cout << "ID (headP1): " << tokenvector.at(counter)->getDescription() << endl;
    Predicate myPredicate(tokenvector.at(counter)->getDescription());
    match(tokenvector.at(counter)->getToken(), TokenType::ID);
    match(tokenvector.at(counter)->getToken(), TokenType::LEFT_PAREN);
    //cout << "ID (headP2): " << tokenvector.at(counter)->getDescription() << endl;
    Parameter myParameter(tokenvector.at(counter)->getDescription(), true);
    myPredicate.addParameter(myParameter);
    match(tokenvector.at(counter)->getToken(), TokenType::ID);
    idList(myPredicate);
    match(tokenvector.at(counter)->getToken(), TokenType::RIGHT_PAREN);

    return myPredicate;
}
Predicate Parser::predicate() {
    //predicate -> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
   // cout << "ID (predicate): " << tokenvector.at(counter)->getDescription() << endl;
    Predicate myPredicate(tokenvector.at(counter)->getDescription());
    match(tokenvector.at(counter)->getToken(), TokenType::ID);
    match(tokenvector.at(counter)->getToken(), TokenType::LEFT_PAREN);
    parameter(myPredicate);
    parameterList(myPredicate);
    match(tokenvector.at(counter)->getToken(), TokenType::RIGHT_PAREN);
    return myPredicate;
}
void Parser::predicateList(Rule& newRule) {
    //predicateList	->	COMMA predicate predicateList | lambda

    //FIRST = COMMA
    if(tokenvector.at(counter)->getTokenString() == "COMMA") {
        match(tokenvector.at(counter)->getToken(), TokenType::COMMA);
        newRule.addPredicate(predicate());
        predicateList(newRule);
    }
    //FOLLOW = PERIOD
    else if (tokenvector.at(counter)->getTokenString() == "PERIOD") {

    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::parameterList(Predicate& myPredicate) {
    //parameterList	-> 	COMMA parameter parameterList | lambda

    //FIRST = COMMA
    if(tokenvector.at(counter)->getTokenString() == "COMMA") {
        match(tokenvector.at(counter)->getToken(), TokenType::COMMA);
        parameter(myPredicate);
        parameterList(myPredicate);
    }
    //FOLLOW = RIGHT_PAREN
    else if (tokenvector.at(counter)->getTokenString() == "RIGHT_PAREN") {
    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::stringList(Predicate& myPredicate) {
    //stringList	-> 	COMMA STRING stringList | lambda
    //FIRST = COMMA
    if(tokenvector.at(counter)->getTokenString() == "COMMA") {
        match(tokenvector.at(counter)->getToken(), TokenType::COMMA);
        //cout << "String (stringlist): " << tokenvector.at(counter)->getDescription() << endl;

        Parameter stringlistParameter(tokenvector.at(counter)->getDescription(), false);
        myPredicate.addParameter(stringlistParameter);
        myProgram.addDomain(stringlistParameter.getParameter());
        match(tokenvector.at(counter)->getToken(), TokenType::STRING_TYPE);
        stringList(myPredicate);
    }
    //FOLLOW = RIGHT_PAREN
    else if (tokenvector.at(counter)->getTokenString() == "RIGHT_PAREN") {

    }
    else {
        std::string error;
        error = "   (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::idList(Predicate& myPredicate) {
    //idList  	-> 	COMMA ID idList | lambda
    //FIRST = COMMA
    if(tokenvector.at(counter)->getTokenString() == "COMMA") {
        match(tokenvector.at(counter)->getToken(), TokenType::COMMA);
        //cout << "ID (idlist): " << tokenvector.at(counter)->getDescription() << endl;
        Parameter idlistParameter(tokenvector.at(counter)->getDescription(), true);
        myPredicate.addParameter(idlistParameter);
        match(tokenvector.at(counter)->getToken(), TokenType::ID);
        idList(myPredicate);
    }
    //FOLLOW = RIGHT_PAREN
    else if (tokenvector.at(counter)->getTokenString() == "RIGHT_PAREN") {
    }
    else {
        std::string error;
        error = "   (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }

}
void Parser::parameter(Predicate& myPredicate) {
    //parameter	->	STRING | ID
    //FIRST = STRING
    if(tokenvector.at(counter)->getTokenString() == "STRING") {
        //cout << "Parameter: " << tokenvector.at(counter)->getDescription() << endl;
        Parameter myParameter(tokenvector.at(counter)->getDescription(), false);
        myPredicate.addParameter(myParameter);
        match(tokenvector.at(counter)->getToken(), TokenType::STRING_TYPE);
    }
    //FOLLOW = ID
    else if (tokenvector.at(counter)->getTokenString() == "ID") {
        //cout << "ID (parameter): " << tokenvector.at(counter)->getDescription() << endl;
        Parameter myParameter(tokenvector.at(counter)->getDescription(), true);
        myPredicate.addParameter(myParameter);
        match(tokenvector.at(counter)->getToken(), TokenType::ID);
    }
    else {
        std::string error;
        error = "  (" + tokenvector.at(counter)->getTokenString() + ",\"" +
                tokenvector.at(counter)->getDescription() + "\"," + std::to_string(tokenvector.at(counter)->getLine()) + ")";
        throw std::string(error);
    }
}

std::string Parser::ParserToString() {
    return myProgram.DatalogToString();
}
