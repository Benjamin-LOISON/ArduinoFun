const byte PIN_LED = 5;

void setup()
{
    Serial.begin(9600);
    Serial.println("BEGINNING");
    pinMode(PIN_LED, OUTPUT);
}


void loop()
{
    digitalWrite(PIN_LED, 0);
    Serial.println("PUSHED");
}
