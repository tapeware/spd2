//
// Created by danie on 29.03.2025.
//

#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "Task.h"


class Solution {
  std::vector<Task> solution_list;
  unsigned int c_max;
  bool has_vector;
public:
  explicit Solution(const std::vector<Task> &solution_list);
  explicit Solution(unsigned int c_max) : c_max(c_max) {has_vector=false;}
  void print_solution();

  unsigned int get_c_max() const {return c_max;}
  std::vector<Task> get_tasks() const {return solution_list;}
  const Task& get_task_by_index(unsigned int index) const {return solution_list[index];}
  unsigned int get_task_count() const {return solution_list.size();}
  bool has_task_list() const {return has_vector;}
  int get_b() const;
  int get_a() const;
  int get_c() const;
};

std::ostream& operator<<(std::ostream& os, const Solution& s);

#endif //SOLUTION_H