//
// Created by mikolaj on 4/23/25.
//

#include "Problem.h"



Problem::Problem(const std::string& file_path)
{
    unsigned int task_count=0, machine_count, pj=0, machine_id=0;
    std::ifstream input(file_path);

    if(!input.is_open()) perror("File opening error");

    input >> task_count >> machine_count;
    num_of_machines = machine_count;


    for (unsigned int i=0; i<task_count; i++)
    {
        input >> pj >> machine_id;
        Task tmp(pj,i,machine_id);
        append_task(tmp);
    }
}

std::ostream& operator<<(std::ostream& os, const Problem& p)
{
    std::stringstream formatted_string;

    unsigned int task_count = p.get_task_count();

    formatted_string << "Task count: " << task_count << "\n";
    formatted_string << "Machine count: " << p.get_machine_count() << "\n";

    Task tmp;
    for (unsigned int i=0; i<task_count; i++)
    {
        tmp = p.get_task_by_index(i);
        formatted_string << i+1 << ") pj=" << tmp.get_pj() << "\n";
    }

    os << formatted_string.str();
    return os;
}


unsigned int Problem::simulate() const
{
    unsigned int time=0, max_time=0;
    //std::cout << "MACHINES: " << num_of_machines
    //<< "\nTASKS: " << get_task_count() << "\n";

    for(unsigned int machine_id=0; machine_id<num_of_machines; machine_id++)
    {
        //std::cout << "for machine nr" << machine_id <<":\n";
        for(unsigned int i=0; i<get_task_count(); i++)
        {
            if(to_do_list[i].get_machine_id() == machine_id) {

                //std::cout<< " + " << to_do_list[i].get_pj() << "\n";
                time+=to_do_list[i].get_pj();
            }

        }
        //std::cout << " = " << time <<"\n";
        if(time >= max_time) max_time = time;
        time=0;
        //std::cout<<"\n";
    }
    //std::cout << "MAX TIME: " << max_time<< "\n\n";
    return max_time;
}

void Problem::match_to_machines(const based_number& matching)
{
    //if (matching.size() != get_task_count()) return;

    for (unsigned int index=0; index<get_task_count(); index++)
    {
        to_do_list[index].match_to_machine(matching[index]);

        //std::cout << "matched task nr" << to_do_list[index].get_id()
        //<< " to machine nr" << to_do_list[index].get_machine_id() << "!\n";
    }
}



