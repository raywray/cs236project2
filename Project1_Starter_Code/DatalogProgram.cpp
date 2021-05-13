//
// Created by Raya Esplin on 5/10/21.
//

#include "DatalogProgram.h"
#include <sstream>

DatalogProgram::DatalogProgram() {

}

DatalogProgram::~DatalogProgram() {

}

void DatalogProgram::addScheme(Predicate myScheme) {
    schemes_vector.push_back(myScheme);
}

void DatalogProgram::addFact(Predicate myFact) {
    facts_vector.push_back(myFact);
}

void DatalogProgram::addQuery(Predicate myQuery) {
    queries_vector.push_back(myQuery);
}

void DatalogProgram::addRule(Rule myRule) {
    rules_vector.push_back(myRule);
}

void DatalogProgram::addDomain(std::string domainString) {
    domainSet.insert(domainString);
}


std::string DatalogProgram::DatalogToString() {
    std::stringstream grandStreamOfThings;

    std::stringstream schemesString;
    schemesString << "Schemes(" << schemes_vector.size() << "):" << std::endl;
    for (int i = 0; i < (int)schemes_vector.size(); i++) {
        schemesString << "  " << schemes_vector.at(i).PredicateToString() << std::endl;
    }

    std::stringstream factsString;
    schemesString << "Facts(" << facts_vector.size() << "):" << std::endl;
    for (int i = 0; i < (int)facts_vector.size(); i++) {
        factsString << "  " << facts_vector.at(i).PredicateToString() << "." << std::endl;
    }

    std::stringstream rulesString;
    rulesString << "Rules(" << rules_vector.size() << "):" << std::endl;
    for (int i = 0; i < (int)rules_vector.size(); i++) {
        rulesString << "  " << rules_vector.at(i).RuleToString() << "." << std::endl;
    }

    std::stringstream queriesString;
    queriesString << "Queries(" << queries_vector.size() << "):" << std::endl;
    for (int i = 0; i < (int)queries_vector.size(); i++) {
        queriesString << "  " << queries_vector.at(i).PredicateToString() << "?" << std::endl;
    }

    std::stringstream domainString;
    domainString << "Domain(" << domainSet.size() << "):" << std::endl;
    for(std::string itr: domainSet) {
        domainString << "  " << itr << std::endl;
    }

    grandStreamOfThings << schemesString.str() + factsString.str() + rulesString.str() + queriesString.str() + domainString.str();
    return grandStreamOfThings.str();
}