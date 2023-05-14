#include <iostream>
#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include <variant>
#include <memory>

struct type_t
{
    std::string a;
    std::string b;

}typedef type_t;


typedef boost::variant<int, const char*, std::string> var_t;
typedef std::variant<int, std::string> var2_t;
typedef std::variant<std::shared_ptr<type_t>, std::string> var3_t;

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

void example3()
{
    std::unordered_map<var3_t, int> mp;
    std::shared_ptr<type_t> smth_val = std::make_shared<type_t>();
    std::shared_ptr<type_t> smth_val2 = std::make_shared<type_t>();
    smth_val->a = "qwe";
    smth_val->b = "qwe";
    smth_val2->a = "qwe2";
    smth_val2->b = "qwe2";
    std::string smth_val3 = "str";

    //mp.insert(smth_val, 1);
    mp.insert({smth_val, 1});
    
    for(const auto& it : mp)
    {
        if(std::holds_alternative<std::shared_ptr<type_t>>(it.first))
        {
            auto ptr = std::get<std::shared_ptr<type_t>>(it.first);
            std::cout   << "its ptr type_t key - " << ptr->a << ":" << ptr->b
                        << " - " << it.second << std::endl; 
        }
        else
        {
            std::cout << "its str key - " << it.second << std::endl;
        }
    }

    std::cout << "-----------------" << std::endl;
}

int main(int argc, char* argv[])
{
    example1();
    example2();
    example3();
    return 0;
}