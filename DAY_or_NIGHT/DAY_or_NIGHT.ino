const byte PIN_INPUT = 4, PIN_LED[2] = {5, 6};
bool last_state;

void setup()
{
    Serial.begin(9600);
    Serial.println("BEGINNING");
    pinMode(PIN_INPUT, INPUT_PULLUP);
    pinMode(PIN_LED[0], OUTPUT);
    pinMode(PIN_LED[1], OUTPUT);
    last_state = false;
}

void loop()
{
    bool actual_state = digitalRead(PIN_INPUT);
    if(actual_state != last_state)
    {
        last_state = actual_state;
        digitalWrite(PIN_LED[0], last_state);
        digitalWrite(PIN_LED[1], !last_state);
        Serial.println("CHANGED");
    }
}
