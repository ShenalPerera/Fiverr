#include "InvestData.h"

using namespace std;


// Constructor
InvestData::InvestData() {}

// Getter and Setters
const vector<int> &InvestData::getYears() const {
    return this->years;
}

void InvestData::setYears(const vector<int> &_years) {
    this->years = _years;
}

const vector<double> &InvestData::getYearEndBalances() const {
    return this->yearEndBalances;
}

void InvestData::setYearEndBalances(const vector<double> &_yearEndBalances) {
    this->yearEndBalances = _yearEndBalances;
}

const vector<double> &InvestData::getYearEndEarnedInterests() const {
    return this->yearEndEarnedInterests;
}

void InvestData::setYearEndEarnedInterests(const vector<double> &_yearEndEarnedInterests) {
    this->yearEndEarnedInterests = _yearEndEarnedInterests;
}