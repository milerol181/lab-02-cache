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
#include <ostream>

struct cash_sizes{
  unsigned int size_l1d;
  unsigned int size_l2;
  unsigned int size_l3;
};
class experiment {
 public:
  void main_experiment(std::ostream &out);
  //const std::ostringstream &get_out() const;
  experiment();
  void set_byte_sizes(const struct cash_sizes& sizes);
  friend std::ostream& operator<<(std::ostream& ostream_out, experiment& exp);
 private:
  std::vector<unsigned int> byte_sizes;
  std::vector<unsigned int> arr;
  std::mt19937 engine;
  //std::ostream out;
  void warm_up_cash(const unsigned int &size_in_byte);
  void create_arr(const unsigned int &size_in_byte);
  void direct(const unsigned int& byte_size,std::ostream &out);
  void reverse(const unsigned int& byte_size,std::ostream &out);
  void random(const unsigned int& byte_size,std::ostream &out);
  void print_to_report(const unsigned& byte_size, double time,
                       std::ostream &out);
  unsigned int number_exp;
};

#endif  // TEMPLATE_EXPERIMENT_HPP
