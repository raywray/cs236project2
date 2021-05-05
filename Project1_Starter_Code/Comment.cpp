//
// Created by Raya Esplin on 5/3/21.
//

#include "Comment.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] != '\n' && input[index] != '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\n') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index] == '\n') {
        inputRead++;
        index++;
        S4(input);
    }
    else if (input[index] != '\n') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S3(const std::string& input) {
    return;
}

void CommentAutomaton::S4(const std::string& input) {
    return;
}

void CommentAutomaton::S5(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S9(input);
    }
    else if (input[index] != '|') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S6(const std::string& input) {
    if (input[index] != '|') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        inputRead++;
        index++;
        S7(input);
    }
}

void CommentAutomaton::S7(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S8(input);
    }
    else {
        inputRead++;
        index++;
        S6(input);
    }
}

void CommentAutomaton::S8(const std::string& input) {
    return;
}

void CommentAutomaton::S9(const std::string& input) {
    if (input[index] != '#') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        inputRead++;
        index++;
        S10(input);
    }
}

void CommentAutomaton::S10(const std::string& input) {
    return;
}