//
// Created by mikolaj on 4/23/25.
//

#include "utils.h"


// Range get_range(unsigned int beginning, unsigned int end)
// {
//     std::vector<unsigned int> result;
//
//     for (unsigned int i=beginning; i<=end; i++) result.push_back(i);
//
//     return result;
// }

// std::ostream& operator<<(std::ostream& os, const Range& r)
// {
//     std::stringstream formatted_string;
//     unsigned int counter=0;
//
//     for (unsigned int i : r)
//     {
//         if(++counter == 1) formatted_string << "[" << i << ", ";
//         else if(counter != r.size()) formatted_string << i << ", ";
//         else formatted_string << i << "]";
//     }
//
//     os << formatted_string.str();
//     return os;
// }


long double Timer::get_measurement() const
{
    if(!measured)
        return 0.0;

    return static_cast<long double> (std::chrono::duration_cast<std::chrono::nanoseconds>
    (end - begin).count());
}

std::string Timer::get_measurement_with_unit() const
{
    if (!measured) return "0s";

    long double duration = get_measurement();
    long double number_to_print;
    std::string unit;
    std::stringstream result;

    if(duration <= 1000.0)
    {
        unit = "ns";
        number_to_print = duration;
    }
    else if(duration <= 1000'000.0)
    {
        unit = "us";
        number_to_print = duration/1000.0;
    }
    else if(duration <= 1000'000'000.0)
    {
        unit = "ms";
        number_to_print = duration/1000'000.0;
    }
    else
    {
        unit = "s";
        number_to_print = duration/1000'000'000.0;
    }

    result << std::fixed << std::setprecision(3)<< number_to_print << unit;
    return result.str();
}

void Timer::print_measurement() const
{
    if (!measured) return;
    std::cout << "time: " << get_measurement_with_unit();
}

typedef std::vector<unsigned int> based_number;

based_number digit_spam(unsigned int size, unsigned int digit)
{
    based_number b;
    for (unsigned int d=0; d<size; d++) b.push_back(digit);
    return b;
}

based_number ones(unsigned int size)
{
    return digit_spam(size, 1);
}

based_number zeros(unsigned int size)
{
    return digit_spam(size, 0);
}

bool check_equivalence(const based_number& bn1, const based_number& bn2)
{
    if(bn1.size() != bn2.size()) return false;
    based_number merged = zeros(bn1.size());
    for (unsigned int index=0; index < bn1.size(); index++)
        merged[index] = bn1[index] + bn2[index];

    return merged==ones(bn1.size());
}


std::ostream& operator<<(std::ostream& os, const based_number& bn)
{
    std::stringstream stream;
    unsigned int length = bn.size();
    for (unsigned int i=0; i<length; i++) stream << bn.at((length-1)-i);
    os << stream.str();
    return os;
}






based_number get_based_number(unsigned int number, unsigned int base, unsigned int length)
{
    based_number number_in_base = zeros(length);
    //std::cout << "init with zeros sequence of length " << length << "...\n";



    unsigned int digit_index=0;
    if(number == 0) return number_in_base;

    //std::cout <<"       " <<number << "!=0\n";

    while (number!=0)
    {
        //std::cout << "      at index " << digit_index << " we place " << number%base;
        //std::cout << "\n        number /= base = " << number/base << "\n";
        number_in_base.at(digit_index) = number%base;
        number/=base;
        digit_index++;
    }

    //std::cout << "final result: " << number_in_base << "\n\n";
    return number_in_base;

}

void add_if_not_equivalent(const based_number& what, std::vector<based_number>& where)
{
    for (const based_number& bn : where) if(check_equivalence(bn, what)) return;
    where.push_back(what);
}

int get_random_from_range(int upper_bound, int lower_bound)
{
    int range = upper_bound-lower_bound+1;
    return rand()%range + lower_bound;
}


void generate_test_instance(unsigned int task_count, unsigned int machine_count,
    unsigned int pj_upper_bound, unsigned int pj_lower_bound,const std::string& filename)
{
    std::ofstream test_instance(filename);
    test_instance << task_count << " " << machine_count << "\n";
    unsigned int pj, machine_id;

    for(unsigned int i=0; i<task_count; i++)
    {
        pj = get_random_from_range(pj_upper_bound, pj_lower_bound);
        machine_id = rand()%machine_count;
        test_instance << pj << " " << machine_id << "\n";
    }
}