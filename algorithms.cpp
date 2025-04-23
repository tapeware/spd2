//
// Created by mikolaj on 4/23/25.
//

#include "algorithms.h"


Solution my_algorithm(Problem& p)
{
    std::vector<Task> tasks = p.get_tasks();

    std::sort(tasks.begin(), tasks.end(),
        [](const Task& t1, const Task& t2)
        {
            double id1=0, id2=0;
            id1 = static_cast<double> ( t1.get_pj() + t1.get_rj() ) / t1.get_qj();
            id2 = static_cast<double> ( t2.get_pj() + t2.get_rj() ) / t2.get_qj();
            return id1 < id2;
        }
            );
    Solution s(tasks);

    return s;
}

Solution overview(Problem& p)
{
    std::vector<Task> tasks = p.get_tasks();
    Range task_order = get_range(0, p.get_task_count()-1);
    Problem tmp=p, optimally_aranged_problem;
    unsigned int time=0, minimal_time=0;

    do
    {
        tmp=p;
        tmp.rearrange(task_order);
        time = tmp.simulate(true);
        if(time < minimal_time || minimal_time==0)
        {
            minimal_time = time;
            optimally_aranged_problem = tmp;
        }

    }
    while (std::next_permutation(task_order.begin(), task_order.end()));

    Solution result(optimally_aranged_problem.get_tasks());
    return result;
}

Solution carlier(Problem &p)
{
    std::vector<Task> tasks = p.get_tasks();
    Schrage sch(tasks);
    Solution solution_by_schrage = sch.schrage_sort();
    tasks = solution_by_schrage.get_tasks();

    int a = solution_by_schrage.get_a(),
    b = solution_by_schrage.get_b(),
    c = solution_by_schrage.get_c();

    //std::cout <<"a=" << a << ", b=" << b << ", c=" << c <<"\n";

    unsigned int upper_bound = solution_by_schrage.get_c_max(),
    lower_bound = 0,
    c_max = solution_by_schrage.get_c_max();

    //std::cout <<"cmax=" << c_max <<"\n";

    if (c < 0) return solution_by_schrage;

    //Range K = get_range(c-1, b);
    unsigned int pk = get_pk(b,c, tasks), qk = get_qk(b,c,tasks), rk = get_rk(b,c, tasks),
    original_r_c = tasks[c].get_rj();

    //std::cout <<"rk=" << rk << ", pk=" << pk << ", qk=" << qk <<"\n";

    Schrage test_sch1(tasks);
    tasks[c].set_rj( std::max(original_r_c, rk+pk) );
    //std::cout <<"old r=" << original_r_c << ", new r=" << tasks[c].get_rj()<<"\n";

    lower_bound = test_sch1.schrage_with_div_sort().get_c_max();
    //lower_bound = sch.schrage_with_div_sort().get_c_max();
    //std::cout << "LB=" << lower_bound << "\n";
    Problem new_problem1(tasks);

    if (lower_bound < c_max)
        c_max = std::min(c_max ,carlier(new_problem1).get_c_max()) ;

    //std::cout <<"new cmax=" << c_max <<"\n";

    tasks[c].set_rj(original_r_c);

    Schrage test_sch2(tasks);

    unsigned int original_q_c = tasks[c].get_qj();
    //std::cout << qk << "+" << pk << "=" <<qk+pk << "\n";
    tasks[c].set_qj( std::max(original_q_c, qk+pk) );

    //std::cout <<"old q=" << original_q_c << ", new q=" << tasks[c].get_qj()<<"\n";

    lower_bound = test_sch2.schrage_with_div_sort().get_c_max();
    Problem new_problem2(tasks);

    //std::cout << "lower bound=" << lower_bound << "\n";

    if (lower_bound < c_max)
        c_max = std::min(c_max ,carlier(new_problem2).get_c_max()) ;

    //std::cout <<"new cmax=" << c_max <<"\n";
    tasks[c].set_qj(original_q_c);
    return Solution(c_max);
}

unsigned int get_rk(int b, int c, const std::vector<Task>& tasks)
{
    unsigned int rk = tasks[c+1].get_rj();

    for(unsigned int i=c+1; i<=b; i++)
        if(tasks[i].get_rj() < rk) rk = tasks[i].get_rj();
    return rk;
}

unsigned int get_qk(int b, int c, const std::vector<Task>& tasks)
{
    unsigned int qk = tasks[c+1].get_qj();

    for(unsigned int i=c+1; i<=b; i++)
        if(tasks[i].get_qj() < qk) qk = tasks[i].get_qj();
    return qk;
}

unsigned int get_pk(int b, int c, const std::vector<Task>& tasks)
{
    unsigned int pk=0;

    for(unsigned int i=c+1; i<=b; i++) pk+=tasks[i].get_pj();

    return pk;
}