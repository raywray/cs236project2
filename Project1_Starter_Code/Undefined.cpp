//
// Created by Raya Esplin on 5/3/21.
//

//TODO: NEED TO WORK ON

#include "Undefined.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] == '^' ||
        input[index] == '$' ||
        input[index] == '&') {
        Serr();
    }
    else {
        return;
    }
}

void UndefinedAutomaton::S1(const std::string& input) {
    if (isalpha(input[index]) || isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);

    }
    else if (input[index] == '\n') {
        inputRead++;
        index++;
        S2(input);

    }
}

void UndefinedAutomaton::S2(const std::string& input) {
    return;
}