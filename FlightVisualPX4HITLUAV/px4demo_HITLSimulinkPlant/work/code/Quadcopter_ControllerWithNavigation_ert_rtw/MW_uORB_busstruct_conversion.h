#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/position_setpoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/vehicle_trajectory_waypoint.h>

typedef struct actuator_armed_s  px4_Bus_actuator_armed ;
typedef struct home_position_s  px4_Bus_home_position ;
typedef struct position_setpoint_s  px4_Bus_position_setpoint ;
typedef struct position_setpoint_triplet_s  px4_Bus_position_setpoint_triplet ;
typedef struct trajectory_waypoint_s  px4_Bus_trajectory_waypoint ;
typedef struct vehicle_attitude_s  px4_Bus_vehicle_attitude ;
typedef struct vehicle_local_position_s  px4_Bus_vehicle_local_position ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;
typedef struct vehicle_trajectory_waypoint_s  px4_Bus_vehicle_trajectory_waypoint ;

#endif
