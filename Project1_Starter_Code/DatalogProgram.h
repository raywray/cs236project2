//
// Created by Raya Esplin on 5/10/21.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#include <vector>
#include "Predicate.h"
#include <set>
#include "Rule.h"

class DatalogProgram {
private:
    //TODO
    //vector of facts, schemes, rules, queries (separate)
    std::vector<Predicate> facts_vector;
    std::vector<Rule> rules_vector;
    std::vector<Predicate> queries_vector;
    std::vector<Predicate> schemes_vector;
    //make set of domain
    std::set<std::string> domainSet;
public:
    //TODO
    //toString
    DatalogProgram();
    ~DatalogProgram();
    void addScheme(Predicate myScheme);
    void addFact(Predicate myFact);
    void addQuery(Predicate myQuery);
    void addRule(Rule myRule);
    void addDomain(std::string domainString);
    std::string DatalogToString();
};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
