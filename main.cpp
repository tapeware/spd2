#include <iostream>
#include "Problem.h"
#include "Solution.h"
#include "Task.h"
#include "algorithms.h"
#include <cstdlib>
#include "utils.h"

int main()
{
    //std::cout << "Hello, World!" << std::endl;
    srand(time(nullptr));

    unsigned int time=0;
    const std::string filename = "test1";
    const std::string test_file_path = "../" + filename;


    //generate_test_instance(5, 4, 50, 2, test_file_path);



    Problem p(test_file_path);

    std::cout << p.simulate() << "\n";

    //overview(2, 5);

    //std::cout << p;

    // std::cout << p.simulate();
    //
    // p.match_to_machines({1,0,1,1,1,0});
    //
    // //std::cout << p;

    Timer t;
    t.start();
    time = overview(p);
    t.stop();

    std::cout << time << " (time elapsed: " << t.get_measurement_with_unit() << ")\n";
    //std::cout << check_equivalence({0,0,0,0,0,0,0}, {1,1,1,1,1,1,1});

    return 0;
}
