//
// Created by mikolaj on 4/23/25.
//

#ifndef UTILS_H
#define UTILS_H


#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <fstream>

//typedef std::vector<unsigned int> Range;
//Range get_range(unsigned int beginning, unsigned int end);
//std::ostream& operator<<(std::ostream& os, const Range& r);

typedef std::chrono::steady_clock::time_point time_measurement;
typedef std::vector<unsigned int> based_number;

class Timer
{
    time_measurement begin;
    time_measurement end;
    bool measured;

public:
    Timer() {measured=false;}
    long double get_measurement() const;
    void start() {begin=std::chrono::steady_clock::now();}
    void stop() {end=std::chrono::steady_clock::now(); measured=true;}
    void print_measurement() const;
    std::string get_measurement_with_unit() const;
};

based_number get_based_number(unsigned int number, unsigned int base, unsigned int length);
based_number digit_spam(unsigned int size, unsigned int digit);
based_number ones(unsigned int size);
based_number zeros(unsigned int size);

bool check_equivalence(const based_number& bn1, const based_number& bn2);
void add_if_not_equivalent(const based_number& what, std::vector<based_number>& where);

std::ostream& operator<<(std::ostream& os, const based_number& bn);

void generate_test_instance(unsigned int task_count, unsigned int machine_count,
    unsigned int pj_upper_bound, unsigned int pj_lower_bound,const std::string& filename);


int get_random_from_range(int upper_bound, int lower_bound);

#endif //UTILS_H
