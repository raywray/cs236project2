//
// Created by Raya Esplin on 5/10/21.
//

#ifndef PROJECT1_STARTER_CODE_RULE_H
#define PROJECT1_STARTER_CODE_RULE_H
#include "Predicate.h"
#include <vector>
#include <sstream>


class Rule {
private:
    //TODO: make predicate object
    Predicate headPredicate;
    std::vector<Predicate> rule_vector;
    //store list of predicates
public:
    Rule();
    ~Rule();
    void setHeadPredicate(Predicate newPredicate);
    void addPredicate(Predicate toBeAdded);
    std::string RuleToString();

};


#endif //PROJECT1_STARTER_CODE_RULE_H
