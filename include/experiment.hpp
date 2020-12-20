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
  void set_byte_sizes(const std::vector<unsigned int> &size_cash);
  void create_arr(const unsigned int &size_in_byte);
  void warm_up_cash(const unsigned int &size_in_byte);
  void main_experiment();
  void direct(const unsigned int& byte_size);
  void reverse(const unsigned int& byte_size);
  void random(const unsigned int& byte_size);
  void print_to_report(const unsigned& byte_size, double time);
  experiment();
 private:
  std::vector<unsigned int> byte_sizes;
  std::vector<unsigned int> arr;
  std::mt19937 engine;
  std::random_device rd;
  std::ostringstream out;

 public:
  const std::ostringstream &getOut() const;
 private:
  unsigned int number_exp;
};

#endif  // TEMPLATE_EXPERIMENT_HPP
