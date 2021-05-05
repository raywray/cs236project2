#include "Token.h"

// read from the input string
//Create tokens for the lexer
// keep track of the index of the next char
// keep track of the current line number

//make getNextToken()?
/*switch(temp){
	case val1: //val1 gets compared to temp
		//do stuff
	break;
	case val2:
		//do other stuff
	break;
	//etc.
	default:
		//this is like an else statement
}
*/
Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    std::string tokenValue = "";
    int lineNumber = -1;
    //tokenType = ERROR;
}


std::string Token::toString() {
    std::string myToken = "";
    std::string output = "";
    switch (tokenType) {
        case TokenType::COMMA:
            myToken = "COMMA";
            break;
        case TokenType::PERIOD:
            myToken = "PERIOD";
            break;
        case TokenType::Q_MARK:
            myToken = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            myToken = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            myToken = "RIGHT_PAREN";
            break;
        case TokenType::COLON:
            myToken = "COLON";
            break;
        case TokenType::COLON_DASH:
            myToken = "COLON_DASH";
            break;
        case TokenType::MULTIPLY:
            myToken = "MULTIPLY";
            break;
        case TokenType::ADD:
            myToken = "ADD";
            break;
        case TokenType::SCHEMES:
            myToken = "SCHEMES";
            break;
        case TokenType::FACTS:
            myToken = "FACTS";
            break;
        case TokenType::RULES:
            myToken = "RULES";
            break;
        case TokenType::QUERIES:
            myToken = "QUERIES";
            break;
        case TokenType::ID:
            myToken = "ID";
            break;
        case TokenType::STRING_TYPE:
            myToken = "STRING";
            break;
        case TokenType::COMMENT:
            myToken = "COMMENT";
            break;
        case TokenType::UNDEFINED:
            myToken = "UNDEFINED";
            break;
        case TokenType::EOF_TYPE:
            myToken = "EOF";
            break;

    }
    //output = "(" + myToken + ",\"" + tokenValue + "\"," + toString(lineNumber) + ")";
    return myToken;
}
