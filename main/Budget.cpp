#include "Budget.h"

long BudgetService::query(date::year_month_day from, date::year_month_day to) {
    if (budgetRepo.findAll().empty()) {
        return 0;
    }
    return 1;
}

BudgetService::BudgetService(BudgetRepo &budgetRepo) : budgetRepo(budgetRepo) {

}
