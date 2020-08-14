//motor ac 1 phase control plain
//written by : Muhammad Husni


int detected = 0;
int value=0;
int last_CH1_state = 0;

void setup() {  
  PCICR |= (1 << PCIE0);                                                    
  PCMSK0 |= (1 << PCINT0);  
  pinMode(3,OUTPUT);        

}

void loop() {
     
   value = map(analogRead(A0),0,1024,7200,0);
   //Serial.println(value);
    if (detected)
    {
      delayMicroseconds(value); 
      digitalWrite(3,HIGH);
      delayMicroseconds(100);
      digitalWrite(3,LOW);
      detected=0;
    } 
}





ISR(PCINT0_vect){

  if(PINB & B00000001){                               
    if(last_CH1_state == 0){                          
      detected=1;                                   
    }
  }
  else if(last_CH1_state == 1){                            
    detected=1;                                      
    last_CH1_state = 0;
    }
}
