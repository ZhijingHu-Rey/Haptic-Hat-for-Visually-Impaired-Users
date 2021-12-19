#define trigPin1 7 //motor 1 
#define echoPin1 6
#define motorPin1 5

#define trigPin2 10 //motor 2
#define echoPin2 9
#define motorPin2 8


//********************************************
//                  Set Up
//********************************************


void setup()
{ 
  Serial.begin(38400);// to use the serial monitor
  
  pinMode(trigPin1, OUTPUT); //motor 1 set up
  pinMode(echoPin1, INPUT);
  pinMode(motorPin1, OUTPUT);

  pinMode(trigPin2, OUTPUT); //motor 2 set up
  pinMode(echoPin2, INPUT);
  pinMode(motorPin2, OUTPUT);
}


//********************************************
//                Main Loop
//********************************************


void loop()
{ 
  
  // to make the motor vibrate depending on the distance
  // if the ultrasonic sensor is too far from the obstacle it will vibrate slowly
  // if the ultrasonic sensor is very close to the obstacle it will vibrate very fast

  int duration1,distance1;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2)/29.1;
  Serial.print("Sensor 1 ");
  Serial.print(distance1); //to print the distance on the serial monitor 1
  Serial.println("cm");

  int duration2,distance2;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2)/29.1;
  Serial.print("Sensor 2 ");
  Serial.print(distance2); //to print the distance on the serial monitor 2
  Serial.println("cm");

  
  //********************************************
  //                  Case 1
  //********************************************
  
    
  if(distance1 <= 600 && distance1 >= 400){
      
      // to make the motor vibrate
      
          if(distance2 <= 600 && distance2 >= 400){
              
              digitalWrite(motorPin1, HIGH); // making the motor on
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              
              digitalWrite(motorPin1, LOW);// making the motor off
              digitalWrite(motorPin2, LOW);
              delay(500);
          } 

          else if(distance2 < 400 && distance2 >= 200){
              
              digitalWrite(motorPin1, HIGH);
              delay(1000);
              digitalWrite(motorPin1, LOW);
              delay(500);
              
              digitalWrite(motorPin2, HIGH);
              delay(500);
              digitalWrite(motorPin2, LOW);
              delay(200);
          }
    
          else if(distance2 < 200){
              
              digitalWrite(motorPin1, HIGH);
              delay(1000);
              digitalWrite(motorPin1, LOW);
              delay(500);
              
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20); 
          } 
          
          else{
              
              digitalWrite(motorPin1, HIGH);
              delay(1000);
              digitalWrite(motorPin1, LOW);
              delay(500);

              Serial.println("Sensor 2: Out of range");
              digitalWrite(motorPin2, LOW);
    
          }
    }

  
  //********************************************
  //                  Case 2
  //********************************************  


  else if(distance1 < 400 && distance1 >= 200){
          
         if(distance2 <= 600 && distance2 >= 400){
              
              digitalWrite(motorPin1, HIGH); 
              delay(500);
              digitalWrite(motorPin1, LOW);
              delay(200);
              
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(500);
          } 

          else if(distance2 < 400 && distance2 >= 200){
              
              digitalWrite(motorPin1, HIGH);
              digitalWrite(motorPin2, LOW);
              delay(500);
              
              digitalWrite(motorPin1, HIGH);
              digitalWrite(motorPin2, LOW);
              delay(200);
          }
    
          else if(distance2 < 200){
              digitalWrite(motorPin1, HIGH); 
              delay(500);
              digitalWrite(motorPin1, LOW);
              delay(200);
              
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20); 
          } 
          
          else{
              
              digitalWrite(motorPin1, HIGH);
              delay(500);
              digitalWrite(motorPin1, LOW);
              delay(200);

              Serial.println("Sensor 2: Out of range");
              digitalWrite(motorPin2, LOW);
    
          }

    }


  //********************************************
  //                  Case 3
  //********************************************           
    
    
  else if(distance1 < 200){
          
         if(distance2 <= 600 && distance2 >= 400){
              
              digitalWrite(motorPin1, HIGH); 
              delay(50);
              digitalWrite(motorPin1, LOW);
              delay(20);
              
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(500);
          } 

          else if(distance2 < 400 && distance2 >= 200){
              
              digitalWrite(motorPin1, HIGH); 
              delay(50);
              digitalWrite(motorPin1, LOW);
              delay(20);
              
              digitalWrite(motorPin2, HIGH);
              delay(500);
              digitalWrite(motorPin2, LOW);
              delay(200);
          }
    
          else if(distance2 < 200){
              
              digitalWrite(motorPin1, HIGH); 
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin1, LOW);
              digitalWrite(motorPin2, LOW);
              delay(20); 
               
          }
          
          else{
              
              digitalWrite(motorPin1, HIGH); 
              delay(50);
              digitalWrite(motorPin1, LOW);
              delay(20);

              Serial.println("Sensor 2: Out of range");
              digitalWrite(motorPin2, LOW);
    
          }

    }

    
  //********************************************
  //                  Case 4
  //********************************************   

  
  else{
          if(distance2 <= 600 && distance2 >= 400){
              
              Serial.println("Sensor 1: Out of range");
              
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(500);
          } 

          else if(distance2 < 400 && distance2 >= 200){
              
              Serial.println("Sensor 1: Out of range");
              
              digitalWrite(motorPin2, HIGH);
              delay(500);
              digitalWrite(motorPin2, LOW);
              delay(200);
          }
    
          else if(distance2 < 200){
              
              Serial.println("Sensor 1: Out of range");
               
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20); 
               
          }
          
          else{
              
              Serial.println("Sensor 1: Out of range");
              Serial.println("Sensor 2: Out of range");
              
          }

    }
  
  
  }

//End Void Loop



//********************************************
//                Main Loop End
//********************************************









//analogWrite(0) means a signal of 0% duty cycle
//analogWrite(127) means a signal of 50% duty cycle
//analogWrite(255) means a signal of 100% duty cycle


//********************************************
//               Back Up Define
//********************************************

//#define trigPin3 13 //motor 3
//#define echoPin3 12
//#define motorPin3 11

//#define trigPin4 16 //motor 4
//#define echoPin4 15
//#define motorPin4 14



//********************************************
//             Back Up Variables
//********************************************

  
  //pinMode(trigPin3, OUTPUT); //motor 3 set up
  //pinMode(echoPin3, INPUT);
  //pinMode(motorPin3, OUTPUT);

  //pinMode(trigPin4, OUTPUT); //motor 4 set up
  //pinMode(echoPin4, INPUT);
  //pinMode(motorPin4, OUTPUT);


//********************************************
//               Back Up Motors
//********************************************



//Loop 2
    
    //if(distance2 <= 600 && distance2 >= 400)
    //{
      // to make the motor vibrate
      // Initializing Motor Pin 2
      // int motorPin2 = 6;
    
    //digitalWrite(motorPin2, HIGH); // making the motor on
    //analogWrite(motorPin2, 255);
    //delay(1000);
    //digitalWrite(motorPin2, LOW);// making the motor off
    //analogWrite(motorPin2, 255);
    //delay(500);
    //} 

    //else if(distance2 < 400 && distance2 >= 200)
    //{
    //digitalWrite(motorPin2, HIGH);
    //analogWrite(motorPin2, 127);
    //delay(500);
    //digitalWrite(motorPin2, LOW);
    //analogWrite(motorPin2, 127);
    //delay(200);
   //}
    //else if(distance2 < 200){

    //digitalWrite(motorPin2, HIGH);
    //analogWrite(motorPin2, 64);
    //delay(50);
    //digitalWrite(motorPin2, LOW);
    //analogWrite(motorPin2, 64);
    //delay(20); 
  //} 
  //else 
  //{
    //Serial.println("Out of range");
    //digitalWrite(motorPin2, LOW);
    //analogWrite(motorPin2, 0);
  //}
  //delay(10);

  
  
  
//}

//Loop 3

  //int duration3,distance3;
  //digitalWrite(trigPin3, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin3, LOW);
  //duration3 = pulseIn(echoPin3, HIGH);
  //distance3 = (duration3/2)/29.1;
  //Serial.print("Sensor 3 ");
  //Serial.print(distance3); //to print the distance on the serial monitor 3
  //Serial.println("cm");
    
    //if(distance3 <= 600 && distance3 >= 400)
    //{
      // to make the motor vibrate
      // Initializing Motor Pin 3
      // int motorPin3 = 6;
    
    //digitalWrite(motorPin3, HIGH); // making the motor on
    //analogWrite(motorPin3, 255);
    //delay(500);
    //digitalWrite(motorPin3, LOW);// making the motor off
    //analogWrite(motorPin3, 255);
    //delay(500);
    //} 

    //else if(distance3 < 400 && distance3 >= 200)
    //{
    //digitalWrite(motorPin3, HIGH);
    //analogWrite(motorPin3, 127);
    //delay(200);
    //digitalWrite(motorPin3, LOW);
    //analogWrite(motorPin3, 127);
    //delay(200);
   //}
    //else if(distance3 < 200){

    //digitalWrite(motorPin3, HIGH);
    //analogWrite(motorPin3, 64);
    //delay(50);
    //digitalWrite(motorPin3, LOW);
    //analogWrite(motorPin3, 64);
    //delay(50); 
  //} 
  //else 
  //{
    //Serial.println("Out of range");
    //digitalWrite(motorPin3, LOW);
    //analogWrite(motorPin3, 0);
  //}
  //delay(10);




// Loop 4

  //int duration4,distance4;
  //digitalWrite(trigPin4, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin4, LOW);
  //duration4 = pulseIn(echoPin4, HIGH);
  //distance4 = (duration4/2)/29.1;
  //Serial.print("Sensor 4 ");
  //Serial.print(distance4); //to print the distance on the serial monitor 2
  //Serial.println("cm");

    
    //if(distance4 <= 600 && distance4 >= 400)
    //{
      // to make the motor vibrate
      // Initializing Motor Pin 4
      // int motorPin4 = 6;
    
    //digitalWrite(motorPin4, HIGH); // making the motor on
    //analogWrite(motorPin4, 255);
    //delay(500);
    //digitalWrite(motorPin4, LOW);// making the motor off
    //analogWrite(motorPin4, 255);
    //delay(500);
    //} 

    //else if(distance4 < 400 && distance4 >= 200)
    //{
    //digitalWrite(motorPin4, HIGH);
    //analogWrite(motorPin4, 127);
    //delay(200);
    //digitalWrite(motorPin4, LOW);
    //analogWrite(motorPin4, 127);
    //delay(200);
   //}
    //else if(distance4 < 200){

    //digitalWrite(motorPin4, HIGH);
    //analogWrite(motorPin4, 64);
    //delay(50);
    //digitalWrite(motorPin4, LOW);
    //analogWrite(motorPin4, 64);
    //delay(50); 
  //} 
  //else 
  //{
    //Serial.println("Out of range");
    //digitalWrite(motorPin4, LOW);
    //analogWrite(motorPin4, 0);
  //}
  //delay(10);
