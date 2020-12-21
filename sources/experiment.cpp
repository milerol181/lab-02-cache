//
// Created by michael on 17.12.2020.
//

#include "experiment.hpp"
unsigned int iterations = 1000;
unsigned int nano_sec = 1000000000;

void experiment::set_byte_sizes(const std::vector<unsigned int>& size_cash) {
  unsigned int current_size = size_cash[0] / 2;
  byte_sizes.push_back(current_size);
  while (current_size < size_cash[2]){
    current_size *= 2;
    byte_sizes.push_back(current_size);
  }
  current_size *= 3;
  current_size /= 2;
  byte_sizes.push_back(current_size);
}
void experiment::create_arr(const unsigned int& size_in_byte) {
  arr.clear();
  unsigned int size = size_in_byte / sizeof(unsigned int);
  for (unsigned i = 0; i < size; ++i)
  {
    arr.push_back(engine());
  }
}
experiment::experiment() {
  engine.seed(static_cast<unsigned>(std::time(nullptr)));
}
void experiment::warm_up_cash(const unsigned int &size_in_byte) {
  unsigned int size = size_in_byte / sizeof(unsigned int);
  [[maybe_unused]] unsigned t = 0;
  for (unsigned i = 0; i < size; i+=16)
  {
    t = arr[i];
  }
}

void experiment::main_experiment()
{
  number_exp = 0;
  out << "investigation: " << std::endl
      << "  travel variant: \"random\"" << std::endl;
  for (unsigned i=0; i < byte_sizes.size(); ++i){
    number_exp++;
    random(byte_sizes.at(i));
  }

  out << "investigation: " << "\n"
         << "  travel variant: \"direct\"" << std::endl
         << "  experiments:" << std::endl;
  for (unsigned i=0; i < byte_sizes.size(); ++i){
    number_exp++;
    direct(byte_sizes[i]);
  }

  out << "investigation: " << std::endl
         << "  travel variant: \"reverse\"" << std::endl;
  for (unsigned i=0; i < byte_sizes.size(); ++i){
    number_exp++;
    reverse(byte_sizes.at(i));
  }
}
void experiment::direct(const unsigned int& byte_size) {
  unsigned size = byte_size/sizeof(unsigned int);
  [[maybe_unused]] unsigned t = 0;
  create_arr(byte_size);
  warm_up_cash(byte_size);
  std::chrono::system_clock::time_point start =
      std::chrono::system_clock::now();
  for (unsigned k = 0; k < iterations; k++){
    for (unsigned i = 0; i < size; i += 16)
    {
      t = arr[i];
    }
  }
  std::chrono::system_clock::time_point end =
      std::chrono::system_clock::now();
  std::chrono::duration<double> time = (end-start)/(iterations*(size/16));
  print_to_report(byte_size, time.count()/* total_time*/);
}

void experiment::print_to_report(const unsigned& byte_size, double time)
{
  std::string time_string = std::to_string(time*nano_sec);
  do{
    time_string.pop_back();
  } while (time_string[time_string.size()-1] == '0');
  time_string.pop_back();
  time_string += " nano seconds";
  out << "  - experiment" << std::endl
         << "    number: " << number_exp << std::endl
         << "    input data: " << std::endl
         << "      buffer_size: "
         << ((byte_size >= 1024*1024) ?
             (std::to_string(byte_size/(1024*1024)) + " MB") :
             (std::to_string(byte_size/1024) + " KB"))
         << std::endl << "    results: " << std::endl
         << "      duration: " << time_string << std::endl;
}
const std::ostringstream& experiment::get_out() const { return out; }
void experiment::reverse(const unsigned int& byte_size) {
  {
    unsigned size = byte_size/sizeof(unsigned int);
    [[maybe_unused]] unsigned t = 0;
    create_arr(byte_size);
    warm_up_cash(byte_size);
    std::chrono::system_clock::time_point start =
        std::chrono::system_clock::now();
    for (unsigned k=0; k < iterations; ++k){
      for (int i=static_cast<int>(size-1); i > 0; i -= 16)
      {
        t = arr[i];
      }
    }
    std::chrono::system_clock::time_point end =
        std::chrono::system_clock::now();
    std::chrono::duration<double> time = (end-start)/(iterations*(size/16));
    print_to_report(byte_size, time.count());
  }
}
void experiment::random(const unsigned int& byte_size) {
  unsigned size = byte_size/sizeof(unsigned int);
  [[maybe_unused]] unsigned t = 0;
  create_arr(byte_size);
  warm_up_cash(byte_size);
  std::chrono::system_clock::time_point start =
      std::chrono::system_clock::now();
  for (unsigned k = 0; k < iterations; ++k){
    for (int i=static_cast<int>(size-1); i > 0; i-=16)
    {
      t = arr[engine()%(size)];
    }
  }
  std::chrono::system_clock::time_point end =
      std::chrono::system_clock::now();
  std::chrono::duration<double> time = (end-start)/(iterations*(size/16));
  print_to_report(byte_size, time.count());
}
