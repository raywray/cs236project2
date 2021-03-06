//
// Created by Raya Esplin on 5/3/21.
//

#include "StringAuto.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] != '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (index >= (int)input.size()) {
        Serr();
    }
    else if (input[index] == '\n') {
        newLines++;
        index++;
        inputRead++;
        S2(input);
    }
    else if (input[index] != '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S3(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        //inputRead++;
        return;
    }
}

void StringAutomaton::S4(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        //inputRead++;
        return;
    }
}