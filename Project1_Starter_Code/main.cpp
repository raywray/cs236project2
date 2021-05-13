#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Parser.h"
#include "DatalogProgram.h"

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();


    std::ifstream in(argv[1]);

    stringstream buffer;
    buffer<<in.rdbuf();
    string inputString = buffer.str();
    //cout << inputString << endl;
    lexer->Run(inputString);
    //cout << lexer->toString();
    //cout << lexer->totalTokens();
    // TODO: make lists for queries, rules, etc
    // TODO: make a list of pointers from feks schemes -> predicates

    Parser myParser(lexer->getTokens());
    try {
        myParser.parse();
        cout << "Success!" << endl;
        cout << myParser.ParserToString();
        //TODO: parser.toString()
    }
    catch (string e) {
        cout << "Failure!" << endl;
        cout << e << endl;
    }


    delete lexer;

    return 0;
}