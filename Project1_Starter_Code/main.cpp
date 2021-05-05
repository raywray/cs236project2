#include "Lexer.h"
#include <fstream>

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    // TODO
    std::ifstream in(argv[1]);
    //TODO: check if file is open
    if(!in) {
        return 1;
    }
    lexer->Run(reinterpret_cast<std::string &>(argv[1]));
    lexer->toString();

    delete lexer;

    return 0;
}