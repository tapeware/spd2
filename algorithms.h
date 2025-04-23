//
// Created by mikolaj on 4/23/25.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Problem.h"
#include "Solution.h"
#include <algorithm>


Solution my_algorithm(Problem& p);
Solution overview(Problem& p);
Solution carlier(Problem& p);

unsigned int get_rk(int b, int c, const std::vector<Task>& tasks);
unsigned int get_qk(int b, int c, const std::vector<Task>& tasks);
unsigned int get_pk(int b, int c, const std::vector<Task>& tasks);



std::vector<unsigned int> number_range(unsigned int beginning, unsigned int end);


#endif //ALGORITHMS_H
