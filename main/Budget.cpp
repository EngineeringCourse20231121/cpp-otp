#include "Budget.h"

long BudgetService::query(date::year_month_day from, date::year_month_day to) {
    auto total = 0;
    for (auto &item: budgetRepo.findAll()) {
        total += getOverlappingDayCount(from, to, item);
    }
    return total;
}

long
BudgetService::getOverlappingDayCount(const year_month_day &from, const year_month_day &to, Budget &budget) const {
    if (budget.getStart() > to || budget.getEnd() < from) {
        return 0;
    }
    auto overlappingStart = std::max(budget.getStart(), from);
    auto overlappingEnd = std::min(budget.getEnd(), to);
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
