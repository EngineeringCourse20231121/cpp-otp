#include "gtest/gtest.h"
#include "../main/Budget.h"

namespace {

    TEST(BudgetService, NoBudget) {
        BudgetService budgetService;

        auto total = budgetService.query(2023_y / 11 / 2, 2023_y / 11 / 2);

        ASSERT_EQ(0, total);
    }

}