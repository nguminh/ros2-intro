#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class Listener : public rclcpp::Node 
{
public:
    Listener() : Node("cpp_listener") 
    {
        subscriber = this->create_subscription<example_interfaces::msg::String>("sc_robo", 10,
        std::bind(&Listener::callbackScRobo, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "C++ listener has been started.");   
    }
 
private:
    void callbackScRobo(example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    };
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Listener>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}