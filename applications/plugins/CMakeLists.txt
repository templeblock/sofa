cmake_minimum_required(VERSION 2.8.12)

find_package(SofaFramework)

sofa_add_plugin(SofaSimpleGUI SofaSimpleGUI)
sofa_add_plugin(image image)
sofa_add_plugin(Compliant Compliant)
sofa_add_plugin(CGALPlugin CGALPlugin) # Depends on image
sofa_add_plugin(Flexible Flexible)     # Depends on image
sofa_add_plugin(Registration Registration) # Depends on image, SofaPython, SofaSimpleGUI
sofa_add_plugin(BulletCollisionDetection BulletCollisionDetection) # Depends on Compliant
sofa_add_plugin(ColladaSceneLoader ColladaSceneLoader) # Depends on Flexible and image
sofa_add_plugin(PreassembledMass PreassembledMass) # Depends on Flexible and Compliant
sofa_add_plugin(ARTrack ARTrack)
sofa_add_plugin(ExternalBehaviorModel ExternalBehaviorModel)
sofa_add_plugin(InvertibleFVM InvertibleFVM)
sofa_add_plugin(MeshSTEPLoader MeshSTEPLoader)
sofa_add_plugin(MultiThreading MultiThreading)
sofa_add_plugin(PluginExample PluginExample)
sofa_add_plugin(ManifoldTopologies ManifoldTopologies)
sofa_add_plugin(OptiTrackNatNet OptiTrackNatNet)
sofa_add_plugin(SixenseHydra SixenseHydra)
sofa_add_plugin(SofaOpenCL SofaOpenCL)
sofa_add_plugin(Xitact Xitact)
sofa_add_plugin(EmptyCmakePlugin EmptyCmakePlugin)
sofa_add_plugin(Haption Haption)
sofa_add_plugin(ManualMapping ManualMapping)
sofa_add_plugin(PersistentContact PersistentContact)
# sofa_add_plugin(SofaPML SofaPML)
sofa_add_plugin(Sensable Sensable)
sofa_add_plugin(SensableEmulation SensableEmulation)
sofa_add_plugin(SofaCUDA SofaCUDA)
sofa_add_plugin(SofaHAPI SofaHAPI)
sofa_add_plugin(THMPGSpatialHashing THMPGSpatialHashing)
sofa_add_plugin(SofaCarving SofaCarving)