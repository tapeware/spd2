//
// Created by mikolaj on 4/23/25.
//

#ifndef SOLVER_H
#define SOLVER_H
#include "Problem.h"


class Solver {

public:
    Solver(const Problem& p, unsigned int machines);
    void solve();
};



#endif //SOLVER_H
