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
    const std::string filename = "test8";
    const std::string test_file_path = "../" + filename;
    based_number b;


    //generate_test_instance(11,
    //    2, 32,
    //    1, test_file_path);



    Problem p("../overview_test1");
    Problem r("../overview_test2");

    std::cout << overview(p) << "\n";

    //std::cout << p << "\n";
    ptas(r, 10);
    //std::cout << overview(p) << "\n";

    // std::cout << p.simulate() << "\n";
    //
    // //overview(2, 5);
    //
    // //std::cout << p;
    //
    // // std::cout << p.simulate();
    // //
    // // p.match_to_machines({1,0,1,1,1,0});
    // //
    // // //std::cout << p;
    //
    // Timer t;
    // t.start();
    // time = overview(p,b);
    // t.stop();
    //
    // std::cout << time << " (time elapsed: " << t.get_measurement_with_unit() << ")\n";
    //std::cout << check_equivalence({0,0,0,0,0,0,0}, {1,1,1,1,1,1,1});

    return 0;
}
