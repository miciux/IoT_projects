#define NUMREADINGS 15

int senseLimit = 12;
int probePin = A5;
int val = 0;

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;

int buzzer = 13;

int buzzerTone = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

int readings[NUMREADINGS];
int index = 0;
int total = 0;
int average = 0;

void setup()
{

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(13, OUTPUT);

    Serial.begin(9600);

    for (int i = 0; i < NUMREADINGS; i++)
        readings[i] = 0;
}

void loop()
{
    val = analogRead(probePin);

    if (val >= 1)
    {

        val = constrain(val, 1, senseLimit);
        val = map(val, 1, senseLimit, 1, 255);

        total -= readings[index];
        readings[index] = val;
        total += readings[index];
        index = (index + 1);

        if (index >= NUMREADINGS)
            index = 0;

        average = total / NUMREADINGS;

        if (average > 15)
        {
            digitalWrite(LED1, HIGH);
        }
        else
        {
            digitalWrite(LED1, LOW);
            noTone(buzzer);
        }

        if (average > 65)
        {
            digitalWrite(LED2, HIGH);
        }
        else
        {
            digitalWrite(LED2, LOW);
        }

        if (average > 115)
        {
            digitalWrite(LED3, HIGH);
        }
        else
        {
            digitalWrite(LED3, LOW);
        }

        if (average > 165)
        {
            digitalWrite(LED4, HIGH);
        }
        else
        {
            digitalWrite(LED4, LOW);
        }

        if (average > 215)
        {
            digitalWrite(LED5, HIGH);
            
        }
        else
        {
            digitalWrite(LED5, LOW);
        }
        tone(buzzer, average*4);

        Serial.println(val);
    }
}
