#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class Listener : public rclcpp::Node 
{
public:
    Listener() : Node("cpp_talker") 
    {
        publisher = this->create_publisher<example_interfaces::msg::String>("sc_robo", 10);
        timer = this->create_wall_timer(1s, std::bind(&Listener::talk, this));
        RCLCPP_INFO(this->get_logger(), "C++ talker has been started.");
    }
 
private:
    void talk()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hello, talker from ROS2 C++ here!");
        publisher->publish(msg);
    }

    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Listener>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}