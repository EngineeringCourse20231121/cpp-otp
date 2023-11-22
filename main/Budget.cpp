#include "Budget.h"

long BudgetService::query(date::year_month_day from, date::year_month_day to) {
    if (budgetRepo.findAll().empty()) {
        return 0;
    }
    auto firstBudget = budgetRepo.findAll()[0];
    if (firstBudget.getStart() > from) {
        return (to.day() - firstBudget.getStart().day()).count() + 1;
    }
    return (to.day() - from.day()).count() + 1;
}

BudgetService::BudgetService(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}

year_month_day Budget::getStart() {
    return this->yearMonth / 1;
}
