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
 #include <math.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define AUTONOMOUS 0
#define MANUAL 1

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
 int KEY;
 double encoder1_value;
 double encoder2_value;
 double encoder3_value;
 double degrees=1.727875959;
 double encoderpos;
 double value_angle;
 float ultra_sensor1,ultra_sensor2;
 int MODE=0;
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

   WbDeviceTag encoder_1=wb_robot_get_device("Encoder1");
   WbDeviceTag encoder_2=wb_robot_get_device("Encoder2");
   WbDeviceTag encoder_3=wb_robot_get_device("Encoder3");

   WbDeviceTag ultrasonic1= wb_robot_get_device("distance_sensor1");
   WbDeviceTag ultrasonic2= wb_robot_get_device("distance_sensor2");

   wb_distance_sensor_enable(ultrasonic1,TIME_STEP);
   wb_distance_sensor_enable(ultrasonic2,TIME_STEP);

   wb_keyboard_enable(TIME_STEP);

   wb_position_sensor_enable(encoder_1,TIME_STEP);
   wb_position_sensor_enable(encoder_2,TIME_STEP);
   wb_position_sensor_enable(encoder_3,TIME_STEP);


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

     encoder1_value=wb_position_sensor_get_value(encoder_1);
     encoder2_value=wb_position_sensor_get_value(encoder_2);
     encoder3_value=wb_position_sensor_get_value(encoder_3);
     KEY=wb_keyboard_get_key();

     if (KEY=='G')
     MODE=0;
     else if (KEY=='W')
     MODE=1;

if(MODE==AUTONOMOUS ) {

  ultra_sensor1=wb_distance_sensor_get_value(ultrasonic1)/(1659*.2);
  ultra_sensor2=wb_distance_sensor_get_value(ultrasonic2)/(1659*.2);

  wb_motor_set_velocity(wheel_1,-2);
  wb_motor_set_velocity(wheel_2,2);
  wb_motor_set_velocity(wheel_3,0);}

  if(ultra_sensor1<=0.4 || ultra_sensor2<=0.4){
  if(ultra_sensor1<ultra_sensor2){
    wb_motor_set_velocity(wheel_1,0);
    wb_motor_set_velocity(wheel_2,0);
    wb_motor_set_velocity(wheel_3,0);
  }
  else if (ultra_sensor2<ultrasonic1){
    wb_motor_set_velocity(wheel_1,0);
    wb_motor_set_velocity(wheel_2,0);
    wb_motor_set_velocity(wheel_3,0);
  }
  else {

}
}
if(MODE==MANUAL) {
  switch (KEY) {
     case WB_KEYBOARD_LEFT:{

       wb_motor_set_velocity(wheel_1,2);
       wb_motor_set_velocity(wheel_2,-1);
       wb_motor_set_velocity(wheel_3,-1);
     }
     break;
     case WB_KEYBOARD_RIGHT:{
       wb_motor_set_velocity(wheel_1,-2);
       wb_motor_set_velocity(wheel_2,1);
       wb_motor_set_velocity(wheel_3,1);
     }
     break;
     case WB_KEYBOARD_UP:{
       wb_motor_set_velocity(wheel_1,0);
       wb_motor_set_velocity(wheel_2,-1);
       wb_motor_set_velocity(wheel_3,1);
     }
     break;
     case WB_KEYBOARD_DOWN:{
       wb_motor_set_velocity(wheel_1,0);
       wb_motor_set_velocity(wheel_2,1);
       wb_motor_set_velocity(wheel_3,-1);

     }
     break;

     case 'A': {

       value_angle=fabs(encoder1_value);

       if(value_angle>degrees) {
       wb_motor_set_velocity(wheel_1,0);
       wb_motor_set_velocity(wheel_2,0);
       wb_motor_set_velocity(wheel_3,0);

     }
     else if (value_angle<degrees){

       wb_motor_set_velocity(wheel_1,-2);
       wb_motor_set_velocity(wheel_2,-2);
       wb_motor_set_velocity(wheel_3,-2);
     }

     }
     break;
     case 'S': {

       value_angle=fabs(encoder1_value);

       if(value_angle>degrees) {
       wb_motor_set_velocity(wheel_1,0);
       wb_motor_set_velocity(wheel_2,0);
       wb_motor_set_velocity(wheel_3,0);
       }
       else if (value_angle<degrees){

       wb_motor_set_velocity(wheel_1,2);
       wb_motor_set_velocity(wheel_2,2);
       wb_motor_set_velocity(wheel_3,2);
       }

     }
     break;

   }


   if (KEY==-1) {
     wb_motor_set_velocity(wheel_1,0);
     wb_motor_set_velocity(wheel_2,0);
     wb_motor_set_velocity(wheel_3,0);
  }

}


     printf("sensor encoder1 %lf\n",encoder1_value );
     printf("sensor encoder2 %lf\n",encoder2_value );
     printf("sensor encoder3 %lf\n",encoder3_value );
     printf("angle %lf \n",value_angle );
     printf("angle %i \n",KEY );
     printf("ultra1 %f \n",ultra_sensor1);
     printf("ultra2 %f \n",ultra_sensor2);

  };

  /* Enter your cleanup code here */




  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
