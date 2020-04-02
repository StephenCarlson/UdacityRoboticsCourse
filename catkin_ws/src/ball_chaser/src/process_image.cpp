#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z){
    ball_chaser::DriveToTarget srv;

    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if (!client.call(srv))
        ROS_ERROR("Failed to call service command_robot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;
    int indexOfTarget = 0;

    int maxSeen = 0;

    // ROS_INFO("Height: %d Width: %d", img.height, img.step);

    for (int i = 0; i < img.height * img.step; i++) {
        // ROS_INFO("%d: %d", i, img.data[i]);
        int local = img.data[i];
        if (local>maxSeen) {
            maxSeen = local;
            indexOfTarget = (local >= white_pixel)? i : indexOfTarget;
            
            // break;
        }
    }

    int xCoord = indexOfTarget%img.step;
    int yCoord = indexOfTarget/img.step;
    // ROS_INFO("%d at %d,%d", maxSeen, xCoord, yCoord);
    // float turnAction = ((indexOfTarget % img.step)<(img.step/2)) ? 0.5f : -0.5f;

    float k_p = 0.0005;
    // float k_i = 0.001;
    // float k_d = 0.0;
    float error = (float)(1.0f * (indexOfTarget % img.step))-(1.0f * img.step/2.0f);

    float turnEffort = (-k_p) * error;
    float driveEffort = (maxSeen > 240) ? 
        (0.5f * ((img.step/2.0f) - abs(error))/1200.0f) : 
        0.0f;

    ROS_INFO("%d at %d,%d, %1.2f: %1.2f, %1.2f", maxSeen, xCoord, yCoord, error, turnEffort, driveEffort);

    drive_robot(driveEffort, turnEffort);
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}