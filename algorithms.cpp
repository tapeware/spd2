//
// Created by mikolaj on 4/23/25.
//

#include "algorithms.h"


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

Solution lsg_alg(Problem& p)
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

