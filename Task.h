//
// Created by mikolaj on 4/23/25.
//

#ifndef TASK_H
#define TASK_H


#include <vector>
#include <iostream>


class Task
{
    unsigned int pj, rj, qj;
    //static unsigned int current_max_index;

public:

    Task(unsigned int pj, unsigned int rj, unsigned int qj) : pj(pj), rj(rj), qj(qj) {}
    Task() {pj=0; rj=0; qj=0;}


    unsigned int get_c_pi(unsigned int index) const;
    unsigned int get_pj() const {return pj;}
    unsigned int get_qj() const {return qj;}
    unsigned int get_rj() const {return rj;}
    void set_pj(unsigned int pj_in) {pj = pj_in;}
    void set_qj(unsigned int qj_in) {qj = qj_in;}
    void set_rj(unsigned int rj_in) {rj = rj_in;}
};

std::ostream& operator<<(std::ostream& os, const Task& t);
bool operator==(const Task& right, const Task& left);




#endif //TASK_H
