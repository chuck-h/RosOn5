/* 
 * Button Example for Rosserial on PSoC5
 *  demo board SW1 button is on P2.2
 */

#include <ros.h>
#include <std_msgs/Bool.h>
#include "button_example.h"

extern ros::NodeHandle  nh;

namespace Button {

std_msgs::Bool pushed_msg;
ros::Publisher pub_button("pushed", &pushed_msg);

bool last_reading;
long last_debounce_time=0;
long debounce_delay=50;
bool published = true;

void setup()
{
  nh.advertise(pub_button);
  
  //Enable the pullup resistor on the button
  CyPins_SetPinDriveMode(Port2_2, Port2_DM_RES_UP); 
  //The button is a normally open button
  last_reading = !( (Port2_Read()>>Port2__2__SHIFT) & 0x01 );
 
}

void loop()
{
  
  bool reading = !( (Port2_Read()>>Port2__2__SHIFT) & 0x01 );
  
  if (last_reading!= reading){
      last_debounce_time = SysTimer::millis();
      published = false;
  }
  
  //if the button value has not changed for the debounce delay, we know its stable
  if ( !published && ((int32_t)SysTimer::millis() - last_debounce_time)  > debounce_delay) {
    pushed_msg.data = reading;
    pub_button.publish(&pushed_msg);
    published = true;
    if (reading) {
      nh.loginfo("button pushed");
    }
  }

  last_reading = reading;
}

} //namespace
