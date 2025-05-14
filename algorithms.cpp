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

Solution lsa_alg(Problem& p)
{
    //std::vector<Task> tasks = p.get_tasks();
    std::vector<Task> tasks;
    tasks.push_back(Task(50,0,10));
    tasks.push_back(Task(7,1,0));
    tasks.push_back(Task(12,2,0));
    tasks.push_back(Task(2,3,0));
    tasks.push_back(Task(5,4,0));

    bool found;
    int num_of_machines=2;
    int found_machine_id;
    std::vector<int> machines;
    std::vector <Task> solution;
    machines.reserve(num_of_machines);
    solution.reserve(tasks.size());
    for (int i=0;i<num_of_machines;i++) {
        machines.push_back(0);
    }
    while(!tasks.empty())
     {
         found=false;
           for (int j = 0; (j < machines.size() && !found); j++)
             {
               if (machines[j]==0)
                 {
                 	found_machine_id=j;
                    found = true;
                   tasks.front().set_machine_id(found_machine_id);
                   machines[found_machine_id]=tasks.front().get_pj();
                   solution.push_back(tasks.front());
                   tasks.erase(tasks.begin());
                 }
             }

        for (int j = 0; (j < machines.size()); j++)
          {
          	if (machines[j]>0)
            	machines[j]--;
          }
     }

    Solution s(solution,num_of_machines);

    return s;
}

Solution lpt_alg(Problem& p)
{
    //std::vector<Task> tasks = p.get_tasks();
    std::vector<Task> tasks;
    tasks.push_back(Task(50,0,10));
    tasks.push_back(Task(7,1,0));
    tasks.push_back(Task(12,2,0));
    tasks.push_back(Task(2,3,0));
    tasks.push_back(Task(5,4,0));

    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
    return a.get_pj() < b.get_pj();
});

    bool found;
    int num_of_machines=2;
    int found_machine_id;
    std::vector<int> machines;
    std::vector <Task> solution;
    machines.reserve(num_of_machines);
    solution.reserve(tasks.size());
    for (int i=0;i<num_of_machines;i++) {
        machines.push_back(0);
    }
    while(!tasks.empty())
    {
        found=false;
        for (int j = 0; (j < machines.size() && !found); j++)
        {
            if (machines[j]==0)
            {
                found_machine_id=j;
                found = true;
                tasks.front().set_machine_id(found_machine_id);
                machines[found_machine_id]=tasks.front().get_pj();
                solution.push_back(tasks.front());
                tasks.erase(tasks.begin());
            }
        }

        for (int j = 0; (j < machines.size()); j++)
        {
            if (machines[j]>0)
                machines[j]--;
        }
    }

    Solution s(solution,num_of_machines);

    return s;
}

Solution PDP2(Problem& p) {
    std::vector<Task> tasks;
    tasks.push_back(Task(0,0,0));
    tasks.push_back(Task(2,1,0));
    tasks.push_back(Task(7,2,0));
    tasks.push_back(Task(6,3,0));
    tasks.push_back(Task(1,4,0));
    tasks.push_back(Task(3,5,0));
    tasks.push_back(Task(4,6,0));


    std::vector<int> machines;
    std::vector <Task> solution;
    machines.reserve(2);

    Solution sol(tasks,2);
    int pj_sum=0;
    for (int i=0;i<tasks.size();i++) {
        pj_sum=pj_sum+tasks[i].get_pj();
    }
    int n=tasks.size();
    int Kl=((pj_sum+1)/2)+1;
    int T[n][Kl]={};
    for (int i=0;i<n;i++) {
        T[i][0]=1;
    }
    for(int j=1; j<n; j++) {
        for(int k=1; k<Kl; k++) {
            if ((T[j-1][k]==1)||((k>=tasks[j].get_pj())&&(T[j-1][k-tasks[j].get_pj()]==1)))
            {
                T[j][k]=1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < Kl; ++j) {
            std::cout << T[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    int Kl_assist=Kl-1;
    int n_assist=n-1;
    if (Kl_assist==0 || n_assist==0) {
        return sol;
    }

    if (T[n_assist][Kl_assist]!=1 ) {
        do {
            Kl_assist--;
        }while (T[n_assist][Kl_assist]!=1 );
    }
    while (n_assist>0 && Kl_assist>0) {
        while (n_assist>0 && T[n_assist-1][Kl_assist]==1) {
            n_assist--;
        }
        solution.push_back(tasks[n_assist]);
        Kl_assist=Kl_assist-tasks[n_assist].get_pj();
    }
    for (int i=0;i<solution.size();i++) {
        solution.at(i).set_machine_id(1);
    }
    bool found=false;
    int ctn=solution.size();

    for (int i=0;i<tasks.size();i++)
        {
        found=false;
        for (int j=0;j<ctn;j++) {
            if (tasks[i].get_id()==solution[j].get_id()) {
                found=true;
            }
        }
        if (!found) {
            if (tasks[i].get_pj()!=0) {
                solution.push_back(tasks[i]);
                solution.back().set_machine_id(0);
            }

        }
    }
    Solution final_sol(solution,2);
    return final_sol;
}