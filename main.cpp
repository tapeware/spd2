#include <iostream>
#include "Problem.h"
#include "Solution.h"
#include "Task.h"


int main()
{
    //std::cout << "Hello, World!" << std::endl;

    const std::string test_file_path = "../sample_tasks";
    Problem p(test_file_path);

    std::cout << p.simulate() << "\n";




    return 0;
}
