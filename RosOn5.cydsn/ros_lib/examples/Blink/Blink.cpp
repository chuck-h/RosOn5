/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
 
extern "C" {
  #include "project.h"
}

#include <ros.h>
#include <std_msgs/Empty.h>
extern ros::NodeHandle  nh;

namespace Blink {

uint8_t ledOn;
void messageCb( const std_msgs::Empty& toggle_msg){
  ledOn = 1-ledOn;
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageCb );

void setup()
{
  ledOn = 1;
  Port2_Write( Port2_ReadDataReg() | (ledOn<<Port2__1__SHIFT));
  nh.subscribe(sub);
}

void loop()
{  
  Port2_Write( (Port2_ReadDataReg() & ~(1<<Port2__1__SHIFT)) | (ledOn<<Port2__1__SHIFT));
}

} // namespace Blink
