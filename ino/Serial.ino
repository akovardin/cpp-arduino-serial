/**
 * Простой пример коммуникации между сишной прогой и ардуинкой. 
 *
 * Используется либа LibSerial, которую нужно сперва установить.
 *
 * ```sh
 * sudo apt-get install libserial-dev
 * ```
 */

int ledPin = 4;
char incomingByte;

/**
 * 
 */
void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

/**
 * 
 */
void loop()
{
    if (Serial.available() > 0) {  //если есть доступные данные

        incomingByte = Serial.read();

        Serial.println(incomingByte);

        if (incomingByte == '1') {
            digitalWrite(ledPin, HIGH);
        } else if (incomingByte == '0') {
            digitalWrite(ledPin, LOW);
        }
    }
}