#include <exception>
#include <iostream>
#include <string>
using namespace std;

string AskTimeServer() {}

class TimeServer
{
public:
    string GetCurrentTime()
    {
        try
        {
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        }
        catch (system_error& ex)
        {
            if (ex.code() != error_code())
            {
                throw ex;
            }
            return last_fetched_time;
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main()
{

    TimeServer ts;
    try
    {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e)
    {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
