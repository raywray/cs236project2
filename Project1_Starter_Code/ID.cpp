//
// Created by Raya Esplin on 5/3/21.
//

#include "ID.h"
void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else if (index == (int)input.size()) {
        //inputRead++;
        Serr();
    }
    else {
        return;
    }
}
