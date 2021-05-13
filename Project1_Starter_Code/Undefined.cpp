//
// Created by Raya Esplin on 5/3/21.
//

#include "Undefined.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] == '^' ||
        input[index] == '$' ||
        input[index] == '&') {
        inputRead++;
        index++;
        S1(input);
        return;
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '#') {
        index++;
        inputRead++;
        S7(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S1(const std::string& input) {
    return;
}

void UndefinedAutomaton::S2(const std::string& input) {
    if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] != '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S4(input);
    }
    /*else {
        Serr();
    }*/
}

void UndefinedAutomaton::S3(const std::string& input) {
    if (index == (int)input.size()) {
        index++;
        inputRead++;
        S6(input);
    }
    /*else if (input[index] == '\n') {
        inputRead++;
        return;
    }*/
    else if (input[index] == '\n') {
        newLines++;
        index++;
        inputRead++;
        S3(input);
    }
    else if (input[index] != '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        inputRead++;
        return;
    }
}

void UndefinedAutomaton::S4(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S5(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S6(const std::string& input) {
    return;
}

void UndefinedAutomaton::S7(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S8(input);
    }
    /*else if (input[index] != '|') {
        inputRead++;
        index++;
        S11(input);
    }*/
    else {
        Serr();
    }
}

void UndefinedAutomaton::S8(const std::string& input) {
    if (index == (int)input.size()) {
        return;
    }
    else if (input[index] == '\n') {
        inputRead++;
        index++;
        newLines++;
        S11(input);
    }
    else if (input[index] != '|') {
        inputRead++;
        index++;
        S11(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S9(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S9(const std::string& input) {
    if (input[index] != '#') {
        index++;
        inputRead++;
        S11(input);
    }
    else if (input[index] == '#') {
        index++;
        inputRead++;
        S10(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S10(const std::string& input) {
    Serr();
}

void UndefinedAutomaton::S11(const std::string& input) {
    if (index == (int)input.size()) {
        return;
    }
    if (input[index] == '\n') {
        inputRead++;
        index++;
        newLines++;
        S11(input);
    }
    else if (input[index] != '|') {
        index++;
        inputRead++;
        S11(input);
    }
    else if (input[index] == '|') {
        index++;
        inputRead++;
        S12(input);
    }
    /*else if (index == (int)input.size()) {
        inputRead++;
        S14(input);
    }*/
    else {
        Serr();
    }
}

void UndefinedAutomaton::S12(const std::string& input) {
    if (input[index] == '#') {
        index++;
        inputRead++;
        S13(input);
    }
    else if (input[index] == '\n') {
        index++;
        inputRead++;
        newLines++;
        S11(input);
    }
    else {
        index++;
        inputRead++;
        S11(input);
    }
}

void UndefinedAutomaton::S13(const std::string& input) {
    Serr();
}

void UndefinedAutomaton::S14(const std::string& input) {
    return;
}
