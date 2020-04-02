# Workspace for the Udacity Robotics Engineering nanoDegree

## Project 2 Instructions (For Immediate Review)
For each invokation, prepare the terminal by `cd`ing to the `catkin_ws` folder and source the environment using `$ source devel/setup.bash`.
- Terminal 1: Execute `caktin_make` from inside the `catkin_ws` folder with the environment sourced as directed above. Proceed to start the simulation environment with `roslaunch mini_hawk world.launch`. If Gazebo and rVis come up correctly, you should be presented with a scene with a "shack", and the "mini_hawk" robot on the roof with a lumionous white ball nearby. There are unresolved issues on my system where Gazebo fails to come up, but the world is apperently still rendered per the camera view in RVis. Restart if this happens.
- Terminal 2: Execute the command `roslaunch ball_chaser ball_chaser.launch`. This is the node for driving the robot to find and ram the ball.
- Terminal 3: (Optional) As an alternate camera viewing method, execute `rosrun rqt_image_view rqt_image_view`.


## Project 1 Instructions (Completed, Not for Review)
The "Build Your World" Artwork is contained in the `model`, `script`, and `world` folders in the repo root. Disregard the `catkin_ws` folder, where all future Projects are created after this.

I've ignored just about all the silly "HelloWorld" basics and have used my own multi-modal robot design, the MiniHawk VTOL. This is a flying robot with hovering and forward flight capabilities, and soon-to-be-added ground locomotion in the form of a pair of wheels.

To get this working upon cloning the repo to your workspace, run the following commands at the UdacityRoboticsCourse folder:

```sh
mkdir build
cd build
cmake ../
make
```

Note that the GAZEBO_PLUGIN_PATH will likely need to be tweaked for variations between your setup and mine:
```sh
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/workspace/UdacityRoboticsCourse/build
```

To run this:
```sh
cd world
# gazebo MainWorld
gazebo Roost.sdf
```

