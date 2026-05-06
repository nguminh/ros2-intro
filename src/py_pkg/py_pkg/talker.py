#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
 
class Talker(Node):
    def __init__(self):
        super().__init__("talker") 
        self.get_logger().info("Talker has been started.")
        self._publisher = self.create_publisher(String, "sc_robo", 10)
        self._delay = 1.0
        self._timer = self.create_timer(self._delay, self.talk)

    def talk(self):
        msg = String()
        msg.data = "Hello, talker from ROS2 Python here."
        self._publisher.publish(msg)
 
def main(args=None):
    rclpy.init(args=args)
    node = Talker() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()