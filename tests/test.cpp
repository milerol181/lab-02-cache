// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <experiment.hpp>
TEST(Example, EmptyTest) {
  std::cout << sizeof(unsigned int);
    EXPECT_TRUE(true);
}



TEST(Example, second) {
  cash_sizes sizes;
  sizes.size_l1d = 16 * 1024;
  sizes.size_l2 = 2048 * 1024;
  sizes.size_l3 = 4096 * 1024;
  experiment cash;
  cash.set_byte_sizes(sizes);
  std::cout << cash << std::endl;
  EXPECT_TRUE(true);
}
