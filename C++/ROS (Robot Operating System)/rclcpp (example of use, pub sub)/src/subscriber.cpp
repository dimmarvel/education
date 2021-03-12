#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
    MinimalSubscriber(std::string topic)
    : Node("some_subscriber")
    {
        std::cout << "Start listen publisher(Name: " << this->get_name() << ", Topic: " << topic << ")" << std::endl;
        _subscription = this->create_subscription<std_msgs::msg::String>(
                topic.c_str(), 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    };

private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(),"I heard: '%s'", msg->data.c_str());
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscription;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc,argv);

    std::string topic;
    std::cout << "Input topic: ";
    std::cin >> topic;

    std::shared_ptr<MinimalSubscriber> minimalSubscriber = std::make_shared<MinimalSubscriber>(topic);
    rclcpp::spin(minimalSubscriber);
    return 0;
}
