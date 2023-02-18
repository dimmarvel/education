#include "client.h"

std::string Client::get_address() { return std::to_string(port_) + ":" + ip_; }

std::string Client::get_data() { return data_; }
