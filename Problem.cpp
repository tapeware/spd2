//
// Created by mikolaj on 4/23/25.
//

#include "Problem.h"



Problem::Problem(const std::string& file_path)
{
    unsigned int task_count=0, pj=0, rj=0, qj=0;
    std::ifstream input(file_path);
    //Task tmp;

    if(!input.is_open())
        perror("File opening error");

    input >> task_count;

    for (unsigned int i=0; i<task_count; i++)
    {
        input >> rj >> pj >> qj;
        Task tmp(pj,rj,qj);
        //std::cout << tmp << "\n";
        append_task(tmp);
        //std::cout << "pj: " << pj << ", rj: " << rj << ", qj: " << qj << "\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Problem& p)
{
    std::stringstream formatted_string;
    Task tmp;
    unsigned int task_count = p.get_task_count();

    formatted_string << "Total tasks: " << task_count << "\n";
    // for (unsigned int i=0; i<task_count; i++)
    // {
    //     tmp = p.get_task_by_index(i);
    //     formatted_string << i+1 << ") pj=" << tmp.get_pj()
    //                             << ", rj=" << tmp.get_rj()
    //                             << ", qj=" << tmp.get_qj()
    //                             << "\n";
    //
    // }

    os << formatted_string.str();
    return os;
}


unsigned int Problem::simulate() const
{
    unsigned int time=0, max_time=0;
    std::vector<unsigned int> c_pi, cq_pi;

    for(unsigned int i=0; i<get_task_count(); i++)
    {

        // //obliczenie c_pi dla pierwszego zadania
        // if (i==0) c_pi.push_back(to_do_list[i].get_rj() + to_do_list[i].get_pj());
        // else
        // {
        //     //std::cout << "max(" << to_do_list[i].get_rj() << ", " << c_pi[i-1] << ") + "
        //     //<< to_do_list[i].get_pj() << " + " << to_do_list[i].get_qj() << "\n";
        //
        //     //obliczenie c_pi dla nastepnych zadan
        //     c_pi.push_back(std::max(to_do_list[i].get_rj(), c_pi[i-1]) + to_do_list[i].get_pj());
        // }
        //
        // //obliczenie cq_pi czyli czasu z ogonkiem
        // cq_pi.push_back(c_pi[i] + to_do_list[i].get_qj());
        //
        // //pomiar "wirtualnego" czasu wykonywania zadania
        // time = cq_pi[i];
        //
        // //std::cout << "c_pi(" << i+1 << ") = " << c_pi[i] << "\n";
        // //std::cout << "cq_pi(" << i+1 << ") = " << time << "\n";
        //
        // //sprawdzenie czy jest mniejszy niz znaleziony dotychczas
        // //ten if ogolnie znajduje najmniejszy dotychczasowy wynikf
        // if (time > max_time) max_time=time;
    }
    //std::cout << "MAX TIME: " << max_time<< "\n\n";
    return max_time;
}