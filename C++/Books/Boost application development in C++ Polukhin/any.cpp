#include <iostream>
#include <boost/any.hpp>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<boost::any> some_val;
    some_val.push_back(10);
    some_val.push_back("Hello world");
    some_val.push_back(std::string("Hello string"));

    std::string& s = boost::any_cast<std::string&>(some_val.back());
    s += " that is any string";
    std::cout << s << std::endl;   
    return 0;
}