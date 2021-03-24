#ifndef SHAREDLIBRARY_LIBRARY_H
#define SHAREDLIBRARY_LIBRARY_H

#include <iostream>
#include <string>

class Client
{
public:
    Client(int port, std::string ip, std::string data)
    :
    port_(port),
    data_(data),
    ip_(ip)
    {
        std::cout << "Debug: Client was created (" + get_address() + ")." << std::endl;
    };

    ~Client()
    {
        std::cout << "Debug: Client was destroyed." << std::endl;
    }

    std::string get_address();
    std::string get_data();
private:
    int port_;
    std::string ip_;
    std::string data_;
};

#endif //SHAREDLIBRARY_LIBRARY_H
