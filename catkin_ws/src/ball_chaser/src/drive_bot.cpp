#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
#include <std_msgs/Empty.h>



class SubPubHandler
{
public:
    SubPubHandler(){
        motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
        // sub_ = n.subscribe("/ball_chaser/command_robot", 1, &SubPubHandler::callback, this);
        server = n.advertiseService("/ball_chaser/command_robot", &SubPubHandler::callback, this);

    }

    // void callback(const std::string& message)
    // void callback(const std_msgs::Empty& message)
    void callbackUsedToFindProblem(const std_msgs::Empty::ConstPtr& message)
    {
    }

    // void callbackBroken(const ball_chaser::DriveToTarget::Request& req, ball_chaser::DriveToTarget::Response& res){
    bool callback(ball_chaser::DriveToTarget::Request& req, ball_chaser::DriveToTarget::Response& res){
        // So, main lesson learned here after an entire late afternoon of headsmashing: Why must the callback only have a single parameter? Why can't the callback have a request and response as was first implemented? The whole point of the DriveToTarget.srv message definition is to provide the means for both requests and response exchange.
        geometry_msgs::Twist motor_command;
        
        motor_command.linear.x = req.linear_x;
        motor_command.angular.z = req.angular_z;

        motor_command_publisher.publish(motor_command);
        res.msg_feedback = "TODO: Indicate metrics asserted.";
        return true;
    }

private:
    ros::NodeHandle n;
    ros::Publisher motor_command_publisher;
    // ros::Subscriber sub_;
    ros::ServiceServer server;
};


int main(int argc, char** argv)
{
    ros::init(argc, argv, "drive_bot");

    SubPubHandler SAPObject;

    ros::spin();

    return 0;
}