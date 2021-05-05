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
    if (input[index] != '\'') {
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
    if (input[index] != '\'') {
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
        return;
    }
}