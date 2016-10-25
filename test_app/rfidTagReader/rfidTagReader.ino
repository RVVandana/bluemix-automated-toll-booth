/*******************************************************************************************************
 Function Name            : setup
 Description              : Initializes the serial monitor with 9600 baud
 Parameters               : None
 *******************************************************************************************************/
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

/*******************************************************************************************************
 Function Name            : loop
 Description              : Reads the rifid tag data and prints on the serial monitor 
 Parameters               : None
 *******************************************************************************************************/
void loop() {
  if(Serial1.available()){
    Serial.print(Serial1.read());
    delay(10);
  }
}

//End of the Program 
