//
// Created by michael on 17.12.2020.
//

#ifndef TEMPLATE_EXPERIMENT_HPP
#define TEMPLATE_EXPERIMENT_HPP
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <sstream>

class experiment {
 public:
  void main_experiment();
  const std::ostringstream &get_out() const;
  experiment();
  void set_byte_sizes(const std::vector<unsigned int> &size_cash);

 private:
  std::vector<unsigned int> byte_sizes;
  std::vector<unsigned int> arr;
  std::mt19937 engine;
  std::ostringstream out;
  void warm_up_cash(const unsigned int &size_in_byte);
  void create_arr(const unsigned int &size_in_byte);
  void direct(const unsigned int& byte_size);
  void reverse(const unsigned int& byte_size);
  void random(const unsigned int& byte_size);
  void print_to_report(const unsigned& byte_size, double time);
  unsigned int number_exp;
};

#endif  // TEMPLATE_EXPERIMENT_HPP
