//
// Created by mikolaj on 4/23/25.
//

#include "Solution.h"

#include "Problem.h"

Solution::Solution(const std::vector<Task>& solution_list) : solution_list(solution_list)
{
    Problem p(solution_list);
    c_max = p.simulate(true);
}


std::ostream& operator<<(std::ostream& os, const Solution& s)
{
    std::stringstream formatted_string;
    //Task tmp;
    //unsigned int task_count = s.get_task_count();
    //const bool print_task_list = false;

    formatted_string
    << "C_max = "
    << s.get_c_max();


    // formatted_string << "\nTotal tasks: " << task_count << "\n";
    // for (unsigned int i=0; i<task_count; i++)
    // {
    //     tmp = s.get_task_by_index(i);
    //     formatted_string << i+1 << ") pj=" << tmp.get_pj()
    //                             << ", rj=" << tmp.get_rj()
    //                             << ", qj=" << tmp.get_qj()
    //                             << "\n";
    //
    // }

    os << formatted_string.str();
    return os;
}



