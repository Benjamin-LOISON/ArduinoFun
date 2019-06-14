void setup()
{
    Serial.begin(9600);
    Serial.println("INITIALIZING...");
    pinMode(2, INPUT_PULLUP);
}

void loop()
{
    Serial.println(digitalRead(2));
    delay(100);
}
