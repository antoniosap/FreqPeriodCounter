#include <Streaming.h>
#include <FreqPeriodCounter.h>

const byte freqPin = 3;
#define debounceTime_ms 10

FreqPeriodCounter freqPeriodCounter(freqPin, millis, debounceTime_ms);

void setup(void) 
{ 
  Serial.begin(115200);
  Serial.println("MEASURE PERIOD 20141118");
}

void loop(void) 
{ 
  if (freqPeriodCounter.poll()) {
	Serial.print("period [ms]= ");
	Serial.println(freqPeriodCounter.period);
	Serial.print("high [ms]  = ");
	Serial.println(freqPeriodCounter.pulseWidth);
	Serial.print("low [ms]   = ");
	Serial.println(freqPeriodCounter.pulseWidthLow);
	Serial.print("hertz      = ");
	Serial.println(freqPeriodCounter.hertzf(5), 5);
  } 
}
