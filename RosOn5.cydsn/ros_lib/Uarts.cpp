/* ========================================
 * PSoc4 "ROSOnAStick" Uart
 *
 * Copyright C. Harrison
 * BSD 2-clause license http://opensource.org/licenses/BSD-2-Clause
 *
 * ========================================
 */

#include "ros.h"

#include "Uarts.h"
extern "C" {
  #include "project.h"
}

void Uart::begin(unsigned long baud) {
  buf_current = buf_last = 0;
  ROSSerial_UART_Start(0, ROSSerial_UART_DWR_VDDD_OPERATION);
};

int Uart::read(void) {
  int32_t data = -1;
  if ( (buf_current==buf_last) && ROSSerial_UART_DataIsReady() ) {
    buf_last = ROSSerial_UART_GetData(read_buf, ROSSerial_UART_GetCount());
    buf_current = 0;
  }
  if (buf_current < buf_last) {
    data = read_buf[buf_current];
    buf_current += 1;
  }
  return data;
};

size_t Uart::write(uint8_t data) {
  if(ROSSerial_UART_GetConfiguration() != 0u) {
    while(ROSSerial_UART_CDCIsReady() == 0u);    /* Wait till component is ready to send */
    ROSSerial_UART_PutChar(data);
  }
  return 1;
};

void Uart::checkLineStatus() {
    if(ROSSerial_UART_IsConfigurationChanged() != 0u) /* Host could send double SET_INTERFACE request */
    {
        if(ROSSerial_UART_GetConfiguration() != 0u)   /* Init IN endpoints when device configured */
        {
            /* Enumeration is done, enable OUT endpoint for receive data from Host */
            ROSSerial_UART_CDC_Init();
        }
    }         
}

Uart Uart0;

