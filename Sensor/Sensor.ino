const int outputPin = 12; //Define the OUT Pin

void setup() {

  pinMode(outputPin, INPUT);  //Set Output Pin Pin as INPUT

  Serial.begin(9600);

}

void loop() {

  if(digitalRead(outputPin) > 0) {     //If no obstacle is detected

    Serial.println("No obstacle detected!");
    
  } else {                              //Otherwise (Obstacle Detected)
    
    Serial.println("Obstacle detected!");
    
  }
  
}
