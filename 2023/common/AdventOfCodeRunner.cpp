#include "AdventOfCodeRunner.hpp"

int AdventOfCodeRunner::run(int argc, char* argv[])
{
    int task;

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " 'input-file' 'task number'" << std::endl;
        return 1;
    }

    std::istringstream(argv[1]) >> task;
    std::ifstream file;
    file.open(argv[2]);

    if (process_input(file) != 0) {
        return 0;
    }

    switch (task) {
    case 1:
        task1();
        return 0;
    case 2:
        task2();
        return 0;
    default:
        std::cerr << "invalid task number: " << task << std::endl;
        return 1;
    }
}

int AdventOfCodeRunner::process_input(std::ifstream& file)
{
    // Default implementation does nothing
    (void)file; // Suppress unused warning
    return 0;
}
