//
// Created by user on 12.03.21.
//
#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include <memory>
void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
            std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
{
    response->sum = request->a + request->b;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\n a: %ld" " b: %ld", request->a, request->b);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sending back response: [%ld]" " b: %ld", (long int)response->sum);

}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_two_inits_server");


    std::cout << "Server." << std::endl;
    return 0;
}