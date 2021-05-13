#ifndef TOKEN_H
#define TOKEN_H
#pragma once
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    UNDEFINED,
    EOF_TYPE,
    ID,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    STRING_TYPE,
    COMMENT
};

class Token
{
private:
    std::string description = "";
    int line;
    TokenType type;

public:
    Token(TokenType type, std::string description, int line);

    std::string toString();

    TokenType getToken();

    std::string getTokenString();
    std::string getDescription();
    int getLine();

};

#endif // TOKEN_H

