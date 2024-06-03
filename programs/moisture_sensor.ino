int sensor_pin = AO; // Soil Sensor input at Analog PIN AO
int output_value;
void setup(){

    Serial. begin(9600) ;
    Serial.println("Reading From the Sensor");
void loop() {
    output_value= analogRead(sensor_pin) ;
                        output_value=map(output_value,500,10,0,100) ;
    Serial.print ("Mositure : ");
    Serial. print (output_value) ;
    Serial.println("%");
    delay (1000);
}
 