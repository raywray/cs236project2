//
// Created by Raya Esplin on 5/3/21.
//

#include "QMark.h"
void QMarkAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}