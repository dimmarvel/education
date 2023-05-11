#include <iostream>
#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <variant>

typedef boost::variant<int, const char*, std::string> var_t;
typedef std::variant<int, std::string> var2_t;

void example1()
{
    std::vector<var_t> vals;
    vals.push_back(10);
    vals.push_back("hello there!");
    vals.push_back(std::string("wow!"));

    std::string& s = boost::get<std::string>(vals.back());
    s += " That is great!\n";
    std::cout << s << std::endl;
    s = boost::get<int>(vals[0]);
    std::cout << s << std::endl;

    std::cout << "-----------------" << std::endl;
}

void example2()
{
    std::unordered_map<var2_t, int> mp;
    for(int i = 0; i < 5; ++i)
    {
        mp[std::string("str" + std::to_string(i))] = i;
    }

    mp[1] = 1;
    mp["1"] = 1;

    for(auto& it : mp)
    {
        if(std::holds_alternative<int>(it.first))
            std::cout << std::get<int>(it.first);
        else
            std::cout << std::get<std::string>(it.first);
        std::cout << " - " << "second: " << it.second << std::endl;
    }
    std::cout << "-----------------" << std::endl;
}


int main(int argc, char* argv[])
{
    example1();
    example2();
    return 0;
}