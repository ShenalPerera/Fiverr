#ifndef CODE_INVESTDATA_H
#define CODE_INVESTDATA_H


#include <vector>

using namespace std;
// This class hold the year-end details
class InvestData {
    private:
        vector<int> years;                      // Each year number {1,2,3,...}
        vector<double> yearEndBalances;         // Relevant year-end balance for each year
        vector<double> yearEndEarnedInterests;  // Relevant year-end interest in each year
    public:
        // Constructor
        InvestData();
        // Getter and setter
        const vector<int> &getYears() const;
        void setYears(const vector<int> &_years);
        const vector<double> &getYearEndBalances() const;
        void setYearEndBalances(const vector<double> &_yearEndBalances);
        const vector<double> &getYearEndEarnedInterests() const;
        void setYearEndEarnedInterests(const vector<double> &yearEndEarnedInterests);



};

#endif //CODE_INVESTDATA_H
