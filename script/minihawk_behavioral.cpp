#include <gazebo/gazebo.hh>

namespace gazebo
{
  class WorldPluginMiniHawk : public WorldPlugin
  {
    public: WorldPluginMiniHawk() : WorldPlugin()
            {
              printf("MiniHawk Behavior Script\n");
            }

    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
            }
  };
  GZ_REGISTER_WORLD_PLUGIN(WorldPluginMiniHawk)
}
