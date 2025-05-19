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

//wersja funkcji ktora zwraca tylko cmax
unsigned int overview(const Problem& p);

//wersja funkcji ktora zwraca tez najlepsze poukladanie a nie tylko cmax
unsigned int overview(const Problem& p, based_number& best_matching);

unsigned int ptas(const Problem& p, unsigned int k);




#endif //ALGORITHMS_H
