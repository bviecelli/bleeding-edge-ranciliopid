#ifndef _scale_H
#define _scale_H

#include "Arduino.h"
#include "userConfig.h"

#if (SCALE_SENSOR_ENABLE)
#include "scaleConfigOverwrite.h"
#include <HX711_ADC.h>
extern HX711_ADC LoadCell;
#endif

bool scaleTareSuccess = false;
bool scaleRunning = false;

float currentWeight = 0.0;  // gram
float flowRate = 0.0;       // gram/second
float flowRateFactor = 0.5;  //moving average factor
unsigned long flowRateSampleTime = 0;
unsigned long flowRateEndTime = 0;

void initScale();
void tareAsync();
bool getTareAsyncStatus();  //returns true if tareAsync() has completed. else false
void updateWeight();
void scalePowerDown();
void scalePowerUp();
void scaleCalibration();

#endif