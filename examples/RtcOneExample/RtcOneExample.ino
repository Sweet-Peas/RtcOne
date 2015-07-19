/*
 * ----------------------------------------------------------------------------
 *            _____ _           _                   _
 *           | ____| | ___  ___| |_ _ __ ___  _ __ (_) ___
 *           |  _| | |/ _ \/ __| __| '__/ _ \| '_ \| |/ __|
 *           | |___| |  __/ (__| |_| | | (_) | | | | | (__
 *           |_____|_|\___|\___|\__|_|  \___/|_| |_|_|\___|
 *            ____                   _   ____
 *           / ___|_      _____  ___| |_|  _ \ ___  __ _ ___
 *           \___ \ \ /\ / / _ \/ _ \ __| |_) / _ \/ _` / __|
 *            ___) \ V  V /  __/  __/ |_|  __/  __/ (_| \__ \
 *           |____/ \_/\_/ \___|\___|\__|_|   \___|\__,_|___/
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <pontus@sweetpeas.se> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return - Pontus Oldberg
 * ----------------------------------------------------------------------------
 */
#include <Wire.h>
#include <RtcOne.h>

RTC_MCP7940X RTC;
char buf[9];
uint8_t mac[6];

void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    
    // following line sets the RTC to the date & time this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop () {
  
    print_mac();
    DateTime now = RTC.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    sprintf(buf,"%02d:%02d:%02d", now.hour(), now.minute(), now.second());
    Serial.println(buf);
   
    delay(3000);
}

void print_mac(void)
{
    RTC.getmac(mac);
    Serial.print(mac[0],HEX);
    Serial.print(mac[1],HEX);
    Serial.print(mac[2],HEX);
    Serial.print(mac[3],HEX);
    Serial.print(mac[4],HEX);
    Serial.print(mac[5],HEX);
    Serial.print(mac[6],HEX);
    Serial.println();
}
