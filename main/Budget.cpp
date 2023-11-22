#include "Budget.h"

long BudgetService::query(date::year_month_day from, date::year_month_day to) {
    if (budgetRepo.findAll().empty()) {
        return 0;
    }
    auto firstBudget = budgetRepo.findAll()[0];
    return getOverlappingDayCount(from, to, firstBudget);
}

long
BudgetService::getOverlappingDayCount(const year_month_day &from, const year_month_day &to, Budget &firstBudget) const {
    if (firstBudget.getStart() > to || firstBudget.getEnd() < from) {
        return 0;
    }
    auto overlappingStart = std::max(firstBudget.getStart(), from);
    auto overlappingEnd = std::min(firstBudget.getEnd(), to);
    return (overlappingEnd.day() - overlappingStart.day()).count() + 1;
}

BudgetService::BudgetService(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}

year_month_day Budget::getStart() {
    return this->yearMonth / 1;
}

year_month_day Budget::getEnd() {
    return this->yearMonth / last;
}
