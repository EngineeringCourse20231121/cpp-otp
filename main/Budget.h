#ifndef CPP_OTP_BUDGET_H
#define CPP_OTP_BUDGET_H
#include <vector>
#include "date.h"

using namespace date;

struct Budget {
    year_month yearMonth;
    int amount;

    year_month_day getStart();
};

class BudgetRepo {
public:
    virtual std::vector<Budget> findAll() = 0;
};

class BudgetService {
public:
    explicit BudgetService(BudgetRepo &budgetRepo);
    long query(date::year_month_day from, date::year_month_day to);
private:
    BudgetRepo &budgetRepo;
};

#endif //CPP_OTP_BUDGET_H
