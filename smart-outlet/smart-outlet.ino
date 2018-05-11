#define RELAY1  4
#define RELAY2  5
#define RELAY3  6
#define RELAY4  7

int input;
bool hardwareDebug = false; // Will write all sockets to HIGH 
bool R1Powered = true; // Will write HIGH in setup(), so these are true at start
bool R2Powered = true; 
bool R3Powered = true; 
bool R4Powered = true; 

void setup() {  
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(RELAY1,HIGH);
  digitalWrite(RELAY2,HIGH);
  digitalWrite(RELAY3,HIGH);
  digitalWrite(RELAY4,HIGH);   
}

void loop() {
  // For hardware testing the relay
  if(hardwareDebug) {
    digitalWrite(RELAY1,HIGH);
    digitalWrite(RELAY2,HIGH);
    digitalWrite(RELAY3,HIGH);
    digitalWrite(RELAY4,HIGH);
  } 
  else {
    if(Serial.available() > 0) {
      // printing entered info to console
      input = Serial.read();
      Serial.print("You entered ");
      Serial.print(input - 48);
      Serial.print(" (ASCII ");
      Serial.print(input);
      Serial.println(")");

      // RELAY1
      if(input == 49) {
        if(R1Powered) {
          digitalWrite(RELAY1,LOW);
        } else {
          digitalWrite(RELAY1,HIGH);
        }
        R1Powered = !R1Powered;
        
      }
      // RELAY2
      else if(input == 50) {
        if(R2Powered) {
          digitalWrite(RELAY2,LOW);
        } else {
          digitalWrite(RELAY2,HIGH);
        }
        R2Powered = !R2Powered;
      }
      // RELAY3
      else if(input == 51) {
        if(R3Powered) {
          digitalWrite(RELAY3,LOW);
        } else {
          digitalWrite(RELAY3,HIGH);
        }
        R3Powered = !R3Powered;
      }
      // RELAY4
      else if(input == 52) {
        if(R4Powered) {
          digitalWrite(RELAY4,LOW);
        } else {
          digitalWrite(RELAY4,HIGH);
        }
        R4Powered = !R4Powered;
      }
    }
  }
}

