//
// Created by mikolaj on 4/23/25.
//

#ifndef TASK_H
#define TASK_H


#include <vector>
#include <iostream>


class Task
{
    unsigned int pj;
    unsigned int machine_id;
    unsigned int id;

public:

    Task(unsigned int pj, unsigned int id, unsigned int machine_id)
        : pj(pj), machine_id(machine_id), id(id) {}

    Task() {pj=0; id=0; machine_id=0;}

    unsigned int get_pj() const {return pj;}
    unsigned int get_id() const {return id;}
    unsigned int get_machine_id() const {return machine_id;}
    void set_id(unsigned int id) {this->id = id;}
    void set_machine_id(unsigned int machine_id) {this->machine_id = machine_id;}
};

std::ostream& operator<<(std::ostream& os, const Task& t);
//bool operator==(const Task& right, const Task& left);




#endif //TASK_H
