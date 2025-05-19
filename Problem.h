//
// Created by mikolaj on 4/23/25.
//

#ifndef PROBLEM_H
#define PROBLEM_H



#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "utils.h"


#include "Task.h"


class Problem
{
    std::vector<Task> to_do_list;
    unsigned int num_of_machines=2;

    static bool task_comp(const Task& t1, const Task& t2) {return t1.get_pj() > t2.get_pj();}

public:
    explicit Problem(const std::string& file_path);
    explicit Problem(const std::vector<Task>& tasks, unsigned int num_of_machines)
            : num_of_machines(num_of_machines), to_do_list(tasks) {}


    Problem() = default;

    std::vector<Task> get_tasks() const {return to_do_list;}
    unsigned int get_machine_count() const {return  num_of_machines;}
    const Task& get_task_by_index(unsigned int index) const {return to_do_list[index];}
    unsigned int get_task_count() const {return to_do_list.size();}
    void append_task(Task t) {to_do_list.push_back(t);}
    unsigned int simulate() const;
    void match_to_machines(const based_number& matching);

    void pj_sort(){std::sort(to_do_list.begin(), to_do_list.end(), task_comp);}

};


std::ostream& operator<<(std::ostream& os, const Problem& p);

#endif //PROBLEM_H
