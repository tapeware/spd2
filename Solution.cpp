//
// Created by mikolaj on 4/23/25.
//

#include "Solution.h"

#include "Problem.h"

Solution::Solution(const std::vector<Task>& solution_list) : solution_list(solution_list)
{
    Problem p(solution_list);
    c_max = p.simulate(true);
    has_vector = true;
}

void Solution::print_solution()
{
    if (!has_vector) return;

    for (auto task : solution_list)
        std::cout<<task.get_pj()<<" "<<task.get_rj()<<" "<<task.get_qj()<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Solution& s)
{
    std::stringstream formatted_string;
    Task tmp;
    unsigned int task_count = s.get_task_count();
    const bool print_task_list = false;

    formatted_string
    << "C_max = "
    << s.get_c_max();

    if (!s.has_task_list() || !print_task_list)
    {
        os << formatted_string.str();
        return os;
    }

    formatted_string << "\nTotal tasks: " << task_count << "\n";
    for (unsigned int i=0; i<task_count; i++)
    {
        tmp = s.get_task_by_index(i);
        formatted_string << i+1 << ") pj=" << tmp.get_pj()
                                << ", rj=" << tmp.get_rj()
                                << ", qj=" << tmp.get_qj()
                                << "\n";

    }

    os << formatted_string.str();
    return os;
}

int Solution::get_b() const
{
    if (!has_vector) return -1;

    std::vector<unsigned int> c_pi, cq_pi;

    for(unsigned int i=0; i<get_task_count(); i++)
    {
        if (i==0) c_pi.push_back(solution_list[i].get_rj() + solution_list[i].get_pj());
        else c_pi.push_back(std::max(solution_list[i].get_rj(), c_pi[i-1]) + solution_list[i].get_pj());

        cq_pi.push_back(c_pi[i] + solution_list[i].get_qj());

        if(c_max == cq_pi[i]) return static_cast<int>(i);
    }
    return -1;
}

int Solution::get_a() const
{
    if (!has_vector) return -1;

    unsigned int p_sum=0, a=0, b=get_b();
    std::vector<unsigned int> c_pi, cq_pi;

    for(unsigned int j=0; j<solution_list.size(); j++)
    {
        p_sum=0;
        for(unsigned int i=j; i<=b; i++) p_sum += solution_list[i].get_pj();
        a = solution_list[j].get_rj() + p_sum + solution_list[b].get_qj();
        if(c_max == a) return static_cast<int>(j);
    }
    return -1;
}

int Solution::get_c() const
{
    if (!has_vector) return -1;

    unsigned int a=get_a(), b=get_b();
    int c=-1;
    std::vector<unsigned int> c_pi, cq_pi;

    for(unsigned int j=a; j<b; j++)
        if(solution_list[j].get_qj() < solution_list[b].get_qj())
            c=static_cast<int>(j);

    return c;
}