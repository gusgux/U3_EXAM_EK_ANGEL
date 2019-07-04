/*
 * File:          U3_EXAM_EK_TUN.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
 #include <webots/robot.h>
 #include <webots/motor.h>
 #include <webots/keyboard.h>
 #include <webots/distance_sensor.h>
 #include <webots/position_sensor.h>

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */

   WbDeviceTag wheel_1 = wb_robot_get_device("wheel1");
   WbDeviceTag wheel_2 = wb_robot_get_device("wheel2");
   WbDeviceTag wheel_3 = wb_robot_get_device("wheel3");

   


  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);

     */
     wb_motor_set_position(wheel_1,INFINITY);
     wb_motor_set_position(wheel_2,INFINITY);
     wb_motor_set_position(wheel_3,INFINITY);
     wb_motor_set_velocity(wheel_1,2);
     wb_motor_set_velocity(wheel_2,-1);
     wb_motor_set_velocity(wheel_3,-1);

  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
