#include "gtest/gtest.h"
#include "../main/Budget.h"
#include "gmock/gmock.h"

namespace {

    class StubBudgetRepo : public BudgetRepo {
    public:
        MOCK_METHOD0(findAll, std::vector<Budget>(void));
    };

    class BudgetServiceTest : public ::testing::Test {
    protected:
        StubBudgetRepo stubBudgetRepo;
        BudgetService budgetService = BudgetService(stubBudgetRepo);

        void givenBudget(const Budget &budget) {
            ON_CALL(stubBudgetRepo, findAll()).WillByDefault(testing::Return(std::vector<Budget>{budget}));
        }
    };

    TEST_F(BudgetServiceTest, NoBudget) {
        auto total = budgetService.query(2023_y / 11 / 2, 2023_y / 11 / 2);

        ASSERT_EQ(0, total);
    }

    TEST_F(BudgetServiceTest, OneDayBudget) {
        givenBudget(Budget{2023_y / 11, 30});

        auto total = budgetService.query(2023_y / 11 / 2, 2023_y / 11 / 2);

        ASSERT_EQ(1, total);
    }

    TEST_F(BudgetServiceTest, TwoDayBudget) {
        givenBudget(Budget{2023_y / 11, 30});

        auto total = budgetService.query(2023_y / 11 / 4, 2023_y / 11 / 5);

        ASSERT_EQ(2, total);
    }

    TEST_F(BudgetServiceTest, BudgetStartAndPeriodEnd) {
        givenBudget(Budget{2023_y / 11, 30});

        auto total = budgetService.query(2023_y / 10 / 4, 2023_y / 11 / 5);

        ASSERT_EQ(5, total);
    }

    TEST_F(BudgetServiceTest, PeriodStartAndBudgetEnd) {
        givenBudget(Budget{2023_y / 11, 30});

        auto total = budgetService.query(2023_y / 11 / 4, 2023_y / 12 / 5);

        ASSERT_EQ(27, total);
    }

    TEST_F(BudgetServiceTest, PeriodEndIsBeforeBudgetStart) {
        givenBudget(Budget{2023_y / 11, 30});

        auto total = budgetService.query(2023_y / 10 / 4, 2023_y / 10 / 25);

        ASSERT_EQ(0, total);
    }

}