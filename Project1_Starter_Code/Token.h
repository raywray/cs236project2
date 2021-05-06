#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    // TODO: add the other types of tokens
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
    // TODO: add member variables for information needed by Token
    std::string description = "";
    int line;
    TokenType type;

public:
    Token(TokenType type, std::string description, int line);

    // TODO: add other needed methods
    std::string toString();
    //void SetValues(std::string token, int lineNumber);
    //void SetComplexValues(std::string type, std::string token, int lineNumber)

};

#endif // TOKEN_H

