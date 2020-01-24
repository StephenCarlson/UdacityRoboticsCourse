# Workspace for the Udacity Robotics Engineering nanoDegree

This git repo is composed toward the first project requirement for the Udacity Robotics Engineering nanoDegree, with the twist that I've ignored just about all the silly "HelloWorld" basics and have used my own multi-modal robot design, the MiniHawk VTOL. This is a flying robot with hovering and forward flight capabilities, and soon-to-be-added ground locomotion in the form of a pair of wheels.

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
gazebo MainWorld
```

