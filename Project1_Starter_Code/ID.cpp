//
// Created by Raya Esplin on 5/3/21.
//

#include "ID.h"
void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        myWord += index;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalpha(input[index]) || isdigit(input[index])) {
        inputRead++;
        S1(input);
        myWord += index;
    }
    else if (input[index] == '\n') {
        inputRead++;
        S2(input);
        myWord += index;
    }
    if (myWord == "Schemes" || //checks keywords
        myWord == "Facts" ||
        myWord == "Rules" ||
        myWord == "Queries") {
        Serr();
    }
    else {
        Serr();
    }
}

void IDAutomaton::S2(const std::string& input) {
    return;
}