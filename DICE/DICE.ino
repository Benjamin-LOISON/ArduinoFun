const byte PIN_INPUT = 2, PIN_WARN = 8, PIN_RUN = 9, PIN_INIT = 10;
const bool DEBUG = true;
#define PIN_LED_SIZE 5
byte PIN_LED[PIN_LED_SIZE];
bool printed;

void setup()
{
    pinMode(PIN_INIT, OUTPUT);

        digitalWrite(PIN_INIT, HIGH);
    
    Serial.begin(9600);
    Serial.println("INITIALIZING...");
    
    pinMode(PIN_INPUT, INPUT_PULLUP);
    
    for(byte led = 0; led < PIN_LED_SIZE; led++)
    {
        PIN_LED[led] = led + 3;
        pinMode(PIN_LED[led], OUTPUT);
    }
    pinMode(PIN_WARN, OUTPUT);
    pinMode(PIN_RUN, OUTPUT);
    
    printed = false;

    randomSeed(analogRead(0));

        delay(3000);
        digitalWrite(PIN_INIT, LOW);
        
    Serial.println("INITIALIZED !");
}


void loop()
{
    if(DEBUG)
    {
        delay(50);
        digitalWrite(PIN_RUN, HIGH);
        delay(50);
        digitalWrite(PIN_RUN, LOW);
    }
    
    if(!digitalRead(PIN_INPUT))
    {
        if(!printed)
        {
            loading();
            printed = true;
            Serial.println("PUSHED");
            light(random(1, 6));
        }
    }
    else if(printed)
        printed = false;
}

void setAll(bool state)
{
    for(byte led = 0; led < PIN_LED_SIZE; led++)
        digitalWrite(PIN_LED[led], state);
}

void loading()
{
    for(byte load = 1; load < 75; load++)
    {
        light(random(1, 6));
        delay(1500 / load);
    }
    setAll(LOW);
    delay(500);
}

void light(byte number)
{
    setAll(LOW);
    if(number == 1)
        digitalWrite(PIN_LED[2], HIGH);
    else if(number == 2)
    {
        digitalWrite(PIN_LED[1], HIGH);
        digitalWrite(PIN_LED[4], HIGH);
    }
    else if(number == 3)
    {
        light(2);
        digitalWrite(PIN_LED[2], HIGH);
    }
    else if(number == 4)
    {
        light(2);
        digitalWrite(PIN_LED[0], HIGH);
        digitalWrite(PIN_LED[3], HIGH);
    }
    else if(number == 5)
        setAll(HIGH);
    else
        warn();
}

void warn()
{
    while(1)
    {
        digitalWrite(PIN_WARN, HIGH);
        delay(50);
        digitalWrite(PIN_WARN, LOW);
        delay(50);
    }
}

