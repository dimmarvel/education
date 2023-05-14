#include <boost/variant.hpp>
#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;
typedef boost::variant<int, float, std::string> v_cell_t;
typedef std::vector<v_cell_t> v_db_row_t;

db_row_t get_row(const char* query)
{
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(std::string("hello again"));
    return row;
}

v_db_row_t v_get_row(const char* query) {
    v_db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back("hello again");
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

struct db_sum_visitor : public boost::static_visitor<double>
{
    double operator()(int value) const
    {
        return value;
    }

    double operator()(float value) const
    {
        return value;
    }

    double operator()(const std::string& value) const 
    {
        return 0.0;
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
    std::cout << "Sum of arithmetic any types in database row is: " << res << std::endl;
    std::cout << "-------------------" << std::endl;
}

void example3()
{
    v_db_row_t row = v_get_row("Query: Five me some row, please.");
    double res = 0.0;
    
    for (auto it = row.begin(), end = row.end(); it != end; ++it)
    {
        res += boost::apply_visitor(db_sum_visitor(), *it);
    }

    std::cout << "Sum of arithmetic variant types in database row is: " << res << std::endl;
    std::cout << "-------------------" << std::endl;
}

int main(int argc, char* argv[])
{
    example1();
    example2();
    example3();
    return 0;
}