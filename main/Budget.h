#ifndef CPP_OTP_BUDGET_H
#define CPP_OTP_BUDGET_H
#include <vector>
#include "date.h"

using namespace date;

struct Budget {};

class BudgetRepo {
public:
    virtual std::vector<Budget> findAll() = 0;
};

class BudgetService {
public:
    long query(date::year_month_day from, date::year_month_day to);
};

#endif //CPP_OTP_BUDGET_H
