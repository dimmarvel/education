#include <client.h>
#include <iostream>

int main()
{
    Client client(8888, "127.0.0.1", "dataJSONdata");
    std::cout << client.get_address() << std::endl;
    std::cout << "Data: " << client.get_data() << std::endl;
    return 0;
}
