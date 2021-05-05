//
// Created by Raya Esplin on 5/3/21.
//

#include "LeftParen.h"
void LeftParenAutomaton::S0(const std::string& input) {
    if (input[index] == '(') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}