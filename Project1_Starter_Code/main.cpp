#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    // TODO
    std::fstream in(argv[1]);

    stringstream buffer;
    buffer<<in.rdbuf();
    string inputString = buffer.str();
    //cout << inputString << endl;
    lexer->Run(inputString);
    cout << lexer->toString();
    cout << lexer->totalTokens();


    delete lexer;

    return 0;
}