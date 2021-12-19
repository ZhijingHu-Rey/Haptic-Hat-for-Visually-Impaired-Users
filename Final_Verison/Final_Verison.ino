
//********************************************
//         Author: Zhijing(Rey) Hu
//            Date: 12/19/2021
//********************************************


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
  
    
    if(distance1 <= 120 && distance1 >= 80){

          if(distance2 <= 120 && distance2 >= 80){
              digitalWrite(motorPin1, HIGH); 
              delay(50);// making the motor on
              digitalWrite(motorPin1, LOW);// making the motor off
              delay(20);
              
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20);
          } 

          else if(distance2 < 80 && distance2 >= 40){
              digitalWrite(motorPin1, HIGH);
              delay(50);
              digitalWrite(motorPin1, LOW);
              delay(20);
              
              digitalWrite(motorPin2, HIGH);
              delay(300);
              digitalWrite(motorPin2, LOW);
              delay(100);
          }
    
          else if(distance2 < 40){
              digitalWrite(motorPin1, HIGH);
              delay(50);
              digitalWrite(motorPin1, LOW);
              delay(20);
              
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(300); 
          } 
          
          else 
          {
              Serial.println("Sensor 2: Out of range");
              digitalWrite(motorPin1, HIGH);
              delay(50);
              digitalWrite(motorPin1, LOW);
              delay(20);
              
              digitalWrite(motorPin2, LOW);
    
          }
    }

  
  //********************************************
  //                  Case 2
  //********************************************  


    else if(distance1 < 80 && distance1 >= 40){
          
         if(distance2 <= 120 && distance2 >= 80){
              digitalWrite(motorPin1, HIGH); 
              delay(300);
              digitalWrite(motorPin1, LOW);
              delay(100);
              
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20);
          } 

          else if(distance2 < 80 && distance2 >= 40){
              digitalWrite(motorPin1, HIGH);
              delay(300);
              digitalWrite(motorPin1, HIGH);
              delay(100);
              
              digitalWrite(motorPin2, LOW);
              delay(300);
              digitalWrite(motorPin2, LOW);
              delay(100);
          }
    
          else if(distance2 < 40){
              digitalWrite(motorPin1, HIGH); 
              delay(300);
              digitalWrite(motorPin1, LOW);
              delay(100);
              
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(300); 
          } 
          
          else 
          {
              Serial.println("Sensor 2: Out of range");
              digitalWrite(motorPin1, HIGH);
              delay(300);
              digitalWrite(motorPin1, LOW);
              delay(100);
              
              digitalWrite(motorPin2, LOW);
    
          }

    }


  //********************************************
  //                  Case 3
  //********************************************           
    
    
    else if(distance1 < 40){
          
         if(distance2 <= 120 && distance2 >= 80){
              digitalWrite(motorPin1, HIGH); 
              delay(1000);
              digitalWrite(motorPin1, LOW);
              delay(300);
              
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20);
          } 

          else if(distance2 < 80 && distance2 >= 40){
              digitalWrite(motorPin1, HIGH); 
              delay(1000);
              digitalWrite(motorPin1, LOW);
              delay(300);
              
              digitalWrite(motorPin2, HIGH);
              delay(300);
              digitalWrite(motorPin2, LOW);
              delay(100);
          }
    
          else if(distance2 < 40){
              digitalWrite(motorPin1, HIGH); 
               delay(1000);
                digitalWrite(motorPin1, LOW);
              delay(300);
              
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(300); 
               
          }
          
          else 
          {
              Serial.println("Sensor 2: Out of range");
              digitalWrite(motorPin1, HIGH); 
              delay(1000);
              digitalWrite(motorPin1, LOW);
              delay(300);
              
              digitalWrite(motorPin2, LOW);
    
          }

    }

    
  //********************************************
  //                  Case 4
  //********************************************   

  
  else{
          if(distance2 <= 120 && distance2 >= 80){
              Serial.println("Sensor 1: Out of range");
              
              digitalWrite(motorPin2, HIGH);
              delay(50);
              digitalWrite(motorPin2, LOW);
              delay(20);
          } 

          else if(distance2 < 80 && distance2 >= 50){
              Serial.println("Sensor 1: Out of range");
              
              digitalWrite(motorPin2, HIGH);
              delay(300);
              digitalWrite(motorPin2, LOW);
              delay(100);
          }
    
          else if(distance2 < 40){
              Serial.println("Sensor 1: Out of range");
               
              digitalWrite(motorPin2, HIGH);
              delay(1000);
              digitalWrite(motorPin2, LOW);
              delay(300); 
               
          }
          
          else 
          {
              Serial.println("Sensor 1: Out of range");
              Serial.println("Sensor 2: Out of range");
          }

    }
  
  
  }

//End Void Loop
