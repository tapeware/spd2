//
// Created by mikolaj on 4/23/25.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Problem.h"
#include "Solution.h"
#include <algorithm>
#include "utils.h"
#include <cmath>

unsigned int overview(const Problem& p);
Solution lsa_alg(Problem& p);
Solution lpt_alg(Problem& p);
Solution PDP2(Problem& p);

#endif //ALGORITHMS_H
