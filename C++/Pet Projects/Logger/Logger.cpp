#include <array>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#define STR_(x) #x
#define STR(x) STR_(x)

#define LOG_TRACE(message) globalLogger().log(Logger::Logger::LVL::TRACE, __FILE__ ":" STR(__LINE__), (message))
#define LOG_DEBUG(message) globalLogger().log(Logger::Logger::LVL::DEBUG, __FILE__ ":" STR(__LINE__), (message))
#define LOG_INFO(message) globalLogger().log(Logger::Logger::LVL::INFO, __FILE__ ":" STR(__LINE__), (message))
#define LOG_ERROR(message) globalLogger().log(Logger::Logger::LVL::ERROR, __FILE__ ":" STR(__LINE__), (message))
#define LOG_FATAL(message) globalLogger().log(Logger::Logger::LVL::FATAL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_WARNING(message) globalLogger().log(Logger::Logger::LVL::WARNING, __FILE__ ":" STR(__LINE__), (message))

namespace Logger
{
class LoggerWorker
{
public:
public:
    LoggerWorker(std::string path, std::size_t buffer_size = 4096u)
        : _outfile(path), _vbuff(buffer_size), _offset(0u) {};

    void write(std::string& data)
    {
        const std::size_t data_size = data.size();

        if ((data_size + _offset) >= _vbuff.size())
            flush();

        std::copy(begin(data), end(data), begin(_vbuff) + _offset);
        _offset += data_size;
    }

    void flush()
    {
        _outfile.write(_vbuff.data(), _offset);
        _offset = 0u;
    }

private:
    std::ofstream _outfile;
    std::size_t _offset;
    std::vector<char> _vbuff;
};

class Logger
{
public:
    enum LVL
    {
        TRACE,
        DEBUG,
        INFO,
        FATAL,
        ERROR,
        WARNING
    };

    std::array<std::string, LVL::WARNING + 1u> error_lvl = {"TRACE", "DEBUG", "INFO", "FATAL", "ERROR", "WARNING"};

    void log(LVL lvl, const char* sour, const std::string& message)
    {
        std::string format_str = "[" + error_lvl[lvl] + "] - " + sour + ": " + message + "\n";
        _loggerWorker.write(format_str);
    }

public:
    Logger(std::string path) : _loggerWorker(path) {};

private:
    LoggerWorker _loggerWorker;
};

} // namespace Logger

inline Logger::Logger& globalLogger()
{
    static Logger::Logger logger("C:\\Users\\dimma\\Desktop\\Project1\\Project1\\logger_data.log");
    return logger;
}

int main(int argc, int* argv[])
{
    for (int i = 0; i < 100; ++i)
        LOG_DEBUG("Debug message");

    system("pause");
    return 0;
}