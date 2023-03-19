/*
    youbot.c

    version 2 (final version)
    
    CMI-TI 22 TINSIM01
    Student: Thijs Dregmans (1024272)
    Simulation & Modeling
    Last edited: 15-03-2023

*/

// include libs to communicate with robot
#include <webots/keyboard.h>
#include <webots/robot.h>

#include <arm.h>
#include <base.h>
#include <gripper.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIME_STEP 32

static void step() {
  if (wb_robot_step(TIME_STEP) == -1) {
    wb_robot_cleanup();
    exit(EXIT_SUCCESS);
  }
}

static void passive_wait(double sec) {
  double start_time = wb_robot_get_time();
  do {
    step();
  } while (start_time + sec > wb_robot_get_time());
}

// main function
int main(int argc, char **argv) {
  wb_robot_init();

  // setup the robot
  base_init();
  arm_init();
  gripper_init();
  passive_wait(2.0);

  passive_wait(2.0);
  gripper_release();
  
  // set robot arm to pick up item
  arm_set_height(ARM_FRONT_CARDBOARD_BOX);
  passive_wait(4.0);
  gripper_grip();
  passive_wait(1.0);
  
  // place item on plate
  arm_set_height(ARM_BACK_PLATE_LOW);
  passive_wait(3.0);
  gripper_release();
  passive_wait(1.0);
  arm_reset();
  
  // drive robot to the left
  base_strafe_left();
  passive_wait(10.0);
  base_reset();
  passive_wait(1.0);
  
  // drive robot forward
  base_forwards();
  passive_wait(14.0);
  
  // rotate robot
  base_turn_right();
  passive_wait(3.2);
  
  // drive robot forward
  base_forwards();
  passive_wait(3.0);
  base_reset();
  passive_wait(1.0);
  gripper_release();
  
  // set robot arm to pick up item from plate
  arm_set_height(ARM_BACK_PLATE_LOW);
  passive_wait(3.0);
  gripper_grip();
  passive_wait(1.0);
  
  // place item on conveyor belt
  arm_set_height(ARM_RESET);
  passive_wait(2.0);
  arm_set_height(ARM_FRONT_PLATE);
  passive_wait(4.0);
  arm_set_height(ARM_FRONT_CARDBOARD_BOX);
  passive_wait(4.0);
  gripper_release();
  passive_wait(1.0);
  arm_set_height(ARM_FRONT_PLATE);
  passive_wait(2.0);
  arm_set_height(ARM_RESET);
  passive_wait(2.0);
  
  // reset arm
  arm_reset();
  gripper_grip();
  passive_wait(2.0);
  
  
  // clean up; end of simulation
  wb_robot_cleanup();

  return 0;
}
