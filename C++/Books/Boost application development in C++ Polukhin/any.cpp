#include <iostream>
#include <boost/any.hpp>
#include <vector>
#include <algorithm>
#include <typeinfo>

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;

db_row_t get_row(const char* query)
{
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(std::string("hello again"));
    return row;
}

struct db_sum
{
private:
    double& _sum;

public:
    explicit db_sum(double& sum) :
    _sum(sum)
    {}

    void operator()(const cell_t& value)
    {
        const std::type_info& ti = value.type();
        if(ti == typeid(int))
        {
            _sum += boost::any_cast<int>(value);
        }
        else if(ti == typeid(float))
        {
            _sum += boost::any_cast<float>(value);
        }
    }
};

void example1()
{
    std::vector<boost::any> some_val;
    some_val.push_back(10);
    some_val.push_back("Hello world");
    some_val.push_back(std::string("Hello string"));

    std::string& s = boost::any_cast<std::string&>(some_val.back());
    s += " that is any string";
    std::cout << s << std::endl; 
    std::cout << "-------------------" << std::endl;
}

void example2()
{
    db_row_t row = get_row("Query: Five me some row, please.");
    double res = 0.0;
    std::for_each(row.begin(), row.end(), db_sum(res));
    std::cout << "Sum of arithmetic types in database row is: " << res << std::endl;
    std::cout << "-------------------" << std::endl;
}

int main(int argc, char* argv[])
{
    example1();
    example2();
    return 0;
}