//
// Created by mikolaj on 4/23/25.
//

#include "Task.h"



std::ostream& operator<<(std::ostream& os, const Task& t)
{
    os << "pj=" << t.get_pj() << ", rj=" << t.get_rj() << ", qj=" << t.get_qj() << "\n";
    return os;
}

bool operator==(const Task& right, const Task& left)
{
    return
    right.get_pj() == left.get_pj() &&
    right.get_qj() == left.get_qj() &&
    right.get_rj() == left.get_rj();
}