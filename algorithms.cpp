//
// Created by mikolaj on 4/23/25.
//

#include "algorithms.h"

unsigned int overview(const Problem& p)
{
    unsigned int machine_count = p.get_machine_count(),
    task_count = p.get_task_count(),
    iterations = static_cast<unsigned int>(pow(machine_count, task_count-1)),
    current_time=0,
    min_time=0;
    std::vector<based_number> matchings;
    Problem tmp = p;

    std::cout << p << "\n";

    for(unsigned int i=0; i<iterations; i++)
    {
        based_number bn = get_based_number(i,machine_count, task_count);
        //std::cout << bn << "\n";
        add_if_not_equivalent(bn, matchings);
    }

    //std::cout << "================\n";
    //std::cout << "Potential matchings: " << iterations <<
    //    "\nGood: " << matchings.size() << "\nBad: " <<
    //        iterations - matchings.size()<<"\n" << "These are:\n";
    //for (const based_number& bn : matchings) std::cout << bn << "\n";
    //std::cout << "================\n";

    for (auto& matching : matchings)
    {
        tmp.match_to_machines(matching);
        current_time = tmp.simulate();
        //std::cout << "for matching " << matching << ", time=" << current_time <<"!"
        //<< "(min=" << min_time << ")\n";
        if (current_time <= min_time || min_time==0) min_time = current_time;


        // if (current_time <= min_time || min_time==0)
        // {
        //     min_time = current_time;
        //     //std::cout << current_time << " seems less than " << min_time << "...\n";
        // }
    }

    return min_time;


}