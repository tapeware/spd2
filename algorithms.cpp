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

    //std::cout << p << "\n";

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

unsigned int overview(const Problem& p, based_number& best_matching)
{
    unsigned int machine_count = p.get_machine_count(),
    task_count = p.get_task_count(),
    iterations = static_cast<unsigned int>(pow(machine_count, task_count-1)),
    current_time=0,
    min_time=0;
    std::vector<based_number> matchings;
    Problem tmp = p;

    //std::cout << p << "\n";

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
        if (current_time <= min_time || min_time==0)
        {
            min_time = current_time;
            best_matching = matching;
        }


        // if (current_time <= min_time || min_time==0)
        // {
        //     min_time = current_time;
        //     //std::cout << current_time << " seems less than " << min_time << "...\n";
        // }
    }

    //std::cout<<best_matching << " is the best matching for this problem.\n";
    return min_time;
}

void pj_sort(Problem& p)
{


}

unsigned int ptas(const Problem& pr, unsigned int k)
{
    if(pr.get_machine_count()!=2)
    {
        throw std::runtime_error(
        "ptas function is implemented only for 2-machine problems!"
        );
        return 0;
    }

    std::vector<Task> tasks;
    based_number matching;
    unsigned int time=0, max_time=0, min_pj_machine_id=0;
    std::array<unsigned int, 2> machines_pj_sum={0,0};

    for(unsigned int task_index=0; task_index<k; task_index++)
        tasks.push_back(pr.get_task_by_index(task_index));

    Problem p(tasks, pr.get_machine_count());

    overview(p, matching);
    p.match_to_machines(matching);

    for(unsigned int i=k; i<pr.get_task_count(); i++)
        p.append_task(pr.get_task_by_index(i));



    //std::cout << "MACHINES: " << p.get_machine_count()
    //<< "\nTASKS: " << p.get_task_count() << "\n";

    for(unsigned int machine_id=0; machine_id<p.get_machine_count(); machine_id++)
    {

        //std::cout << "for machine nr" << machine_id <<":\n";
        for(unsigned int i=0; i<k; i++)
        {
            //std::cout << "iteration nr" << i << "\n";
            if(p.get_tasks()[i].get_machine_id() == machine_id) {

                //std::cout<< " + " << p.get_task_by_index(i).get_pj()<< "\n";
                machines_pj_sum[machine_id]+=p.get_task_by_index(i).get_pj();
                time+=p.get_task_by_index(i).get_pj();
            }

        }
        //if(time >= max_time) max_time = time;
        //time=0;
    }

    if(machines_pj_sum[0] > machines_pj_sum[1])
        max_time = machines_pj_sum[0];
    else max_time = machines_pj_sum[1];

    //so_far = max_time;
    //std::cout << "================================\n";
    //std::cout << " SO FAR cmax = " << max_time << "\n";
    //std::cout << "================================\n";

    for(unsigned int i=k; i<p.get_task_count(); i++)
    {
        //std::cout << "iteration nr" << i << "\n";
        min_pj_machine_id = machines_pj_sum[0] > machines_pj_sum[1] ? 1 : 0;
        //std::cout << "min pj machine id = " << min_pj_machine_id <<
        //    ", bo (" << machines_pj_sum[0] << ">" << machines_pj_sum[1] << ") = " <<
        //    (machines_pj_sum[0] > machines_pj_sum[1]) << "\n";
        machines_pj_sum[min_pj_machine_id] += p.get_task_by_index(i).get_pj();

        //std::cout << "for machine nr" << min_pj_machine_id<<":\n";
        //std::cout<< " + " << p.get_task_by_index(i).get_pj()<< "\n";
    }

    if(machines_pj_sum[0] > machines_pj_sum[1])
        max_time = machines_pj_sum[0];
    else max_time = machines_pj_sum[1];


    //std::cout << "on machine 0: " << machines_pj_sum[0] <<
    //    "\non machine 1: " << machines_pj_sum[1] << "\n";
    //std::cout << "================================\n";
    //std::cout << " NOW cmax = " << max_time<< "\n";
    //std::cout << "================================\n";
    return max_time;


}
