//
// Created by Raya Esplin on 5/10/21.
//

#include "Rule.h"
Rule::Rule() {}
Rule::~Rule() {}

void Rule::setHeadPredicate(Predicate newPredicate) {
    headPredicate = newPredicate;
}
void Rule::addPredicate(Predicate toBeAdded) {
    rule_vector.push_back(toBeAdded);
}


std::string Rule::RuleToString() {
    std::stringstream ruleString;
    ruleString << headPredicate.PredicateToString() << " :- ";
    int i = 0;
    while (i != (int)rule_vector.size()) {
        ruleString << rule_vector.at(i).PredicateToString();
        i++;
        if (i != (int)rule_vector.size()) {
            ruleString << ",";
        }
    }
    return ruleString.str();
}