#include <iostream>
#include <boost/program_options.hpp>
namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    opt::options_description desc("All options");
    desc.add_options()
        ("apples", opt::value<int>(), "how many apples do you have")
        ("oranges", opt::value<int>(), "how many oranges do you have")
        ("help", "produce help message");

    opt::variables_map vm;
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    opt::notify(vm);
    
    if(vm.count("help"))
    {
        std::cout << desc << "\n";
        return 0;
    }
    
    if(vm.size() == 0)
    {
        std::cout << "Error zero arguments" << std::endl;
        return 0;
    }

    std::cout 
    << "Args sum: "
    << vm["apples"].as<int>() + vm["oranges"].as<int>() 
    << std::endl;

    return 0;
}