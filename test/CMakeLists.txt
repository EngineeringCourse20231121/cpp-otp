set(Test_SRCS AuthenticationServiceTest.cc
        BudgetServiceTest.cc)

add_executable(cpp_otp_test ${Test_SRCS})
target_link_libraries(cpp_otp_test gtest gmock gtest_main core)
