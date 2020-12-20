// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <experiment.hpp>
TEST(Example, EmptyTest) {
  std::cout << sizeof(unsigned int);
    EXPECT_TRUE(true);
}

const unsigned int size_l1d = 16 * 1024;
const unsigned int size_l2 = 2048 * 1024;
const unsigned int size_l3 = 4096 * 1024;

TEST(Example, second) {
  std::vector<unsigned int> cash_size;
  cash_size.push_back(size_l1d);
  cash_size.push_back(size_l2);
  cash_size.push_back(size_l3);
  experiment cash;
  cash.set_byte_sizes(cash_size);
  cash.print_size();
  cash.main_experiment();
  std::cout << cash.getOut().str() << std::endl;
  EXPECT_TRUE(true);
}
