/*
This firmata script enable bonsai to trigger LED pulsation at a given frequency, separated by a given time interval
Trigger is made by inputing the string character 's' into the arduino

Hugo Gillet
17/01/23 
 */

/*=============================================
 * PUT YOUR INPUTS THERE : 
 *============================================*/
// string character used to trigger the whole sequence with bonsai 
char trigger_character = 's'; 
char read_character;

// insert here the frequency of LED pulsation
int frequency_Hz = 10 ; 

// inserte here the time interval where the LED is pulsing
int time_pulse_duration_ms = 2000; 

/*=============================================
 * SETUP (don't touch that) : 
 *============================================*/
int cycle_time_ms; //  
int time_on_ms ; // duration of a LED pulse
int time_off_ms ; // time interval between each LED pulse
int n_pulses; //number of pulse to do during the time_pulse_duration_ms
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cycle_time_ms = 1000 / frequency_Hz;
  time_on_ms = 5 ;
  time_off_ms = 95 ;
  n_pulses = (time_pulse_duration_ms / cycle_time_ms);
  
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(3, 0);
  analogWrite(5, 0);
  analogWrite(9, 0);
  analogWrite(6, 0);
  
}

/*=============================================
 * LOOP (don't touch that) : 
 *============================================*/
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    read_character = Serial.read();
    if (read_character == trigger_character){
      optogenetics_stimulation(n_pulses, time_on_ms, time_off_ms);
    }
    serialFlush(); // Just in case you send extra characters by mistake
  }
}

/*=============================================
 * Functions (don't touch that) : 
 *============================================*/
void serialFlush() {
  while (Serial.available() > 0) {
    char t = Serial.read();
  }
}

void optogenetics_stimulation(int n, int on, int off){
  for (int i = 0 ; i<n; i++){
    //turn the led ON
    analogWrite(11, 255);
    analogWrite(10, 255);
    analogWrite(3, 255);
    analogWrite(5, 255);
    analogWrite(9, 255);
    analogWrite(6, 255);
    delay(on);

    
    // turn the led OFF
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(9, 0);
    analogWrite(6, 0);
    delay(off);
  }
}
