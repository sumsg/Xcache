
#include "Xfun.h"
Xcache xcache;
void setup()
{
	Xcache.begin(128);
	//uint8_t
	uint8_t y1 = 1;
	if( xcache.setInt(1, y1) ){
	  uint16_t x1 = xcache.getInt(1,(uint8_t)0);
	  Serial.println(x1);
	}else{
		Serial.println("read fail");
	}
	//uint16_t
	uint16_t y2 = 10000;
	if( xcache.setInt(2, y2) ){
	  uint16_t x2 = xcache.getInt(2,(uint16_t)0);
	  Serial.println(x2);
	}else{
		Serial.println("read fail");
	}
	//uint32_t
 	uint32_t y3 = 10000;
	if( xcache.setInt(4, y2) ){
	  uint32_t x3 = xcache.getInt(2,(uint32_t)0);
	  Serial.println(x3);
	}else{
		Serial.println("read fail");
	}
	//int64_t
 	int64_t y4 = 888888;
	if( xcache.setInt(8, y4) ){
	  int64_t x4 = xcache.getInt(2,(int64_t)0);
	  Serial.println(x4);
	}else{
		Serial.println("read fail");
	}
	//String
 	String y5 = "hello";
	if( xcache.setString(5, 16, y5) ){
	  String x5 = xcache.getString(5, 16);
	  Serial.println(x5);
	}else{
		Serial.println("read fail");
	}
}

void loop()
{
}
