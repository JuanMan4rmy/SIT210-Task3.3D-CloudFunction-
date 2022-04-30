int led = D7; 

void setup() 
{
    // LED pin = OUTPUT
    pinMode(led, OUTPUT); 
    // Subscribe will listen for the event Deakin_RIOT_SIT210_Photon_Buddy, when the event is found it will run the Handler method
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", Handler); 
}

void Blink() 
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}

void Handler(const char *event, const char *data)
{
    // strcmp() compares two chars if they are the same strcmp will return 0
    if (strcmp(data, "wave") == 0)
    { 
        Blink();
        Blink();
        Blink();
    }
    else if (strcmp(data, "pat") == 0)
    {
        Blink();
        Blink();
        Blink();
        Blink();
    }
}

void loop()
{
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave");
    delay(15000);
    Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat");
    delay(15000);
}