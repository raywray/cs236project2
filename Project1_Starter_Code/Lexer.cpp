#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include <iostream>
#include <sstream>

using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
}

std::string Lexer::toString() {
    stringstream tokenss;
    for (unsigned int i = 0; i < tokens.size(); i++) {
        tokenss << tokens[i]->toString() << endl;
    }
    return tokenss.str();
}

std::string Lexer::totalTokens() {
    stringstream totalTss;
    totalTss << "Total Tokens = " << tokens.size();
    return totalTss.str();
}

std::vector<Token*> Lexer::getTokens() {
    return(tokens);
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new UndefinedAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton *maxAutomaton = automata[0];

        //Delete Whitespace!
        while(isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber += 1;
            }
            input.erase(0, 1);
            maxRead = 0;
        }

        for (unsigned int i = 0; i < automata.size(); i++) {
            int inputRead = automata[i]->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
        }
        if (maxRead > 0) {
            Token *newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            if (newToken->getToken() != TokenType::COMMENT) {
                tokens.push_back(newToken);
            }
            input.erase(0, maxRead);
        } else {
            maxRead = 1;
            Token *newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
            tokens.push_back(newToken);
            input.erase(0, maxRead);
        }

        //Delete Whitespace!
        while(isspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber += 1;
            }
            input.erase(0, 1);
            maxRead = 0;
        }

    }
    Token *newToken = new Token(TokenType::EOF_TYPE, "", lineNumber);
    tokens.push_back(newToken);

}



