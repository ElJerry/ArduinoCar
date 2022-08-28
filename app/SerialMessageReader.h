#ifndef JERRY_SERIAL_READER_H
#define JERRY_SERIAL_READER_H

#include "Arduino.h"

const char MESSAGE_DELIMITER = ';';

String readSerialMessage()
{
    String message = "";

    if (Serial.available() > 0)
    {
        // read until next delimiter
        char nextByte;

        while ((nextByte = Serial.read()) && nextByte != MESSAGE_DELIMITER)
        {
            message.concat(nextByte);
        }
    }

    if (message.length() > 0)
    {

        Serial.print("Message received:");
        Serial.println(message);
    }
    return message;
}

#endif //JERRY_SERIAL_READER_H