# Sign Language Converter using Arduino Nano

## Overview

This project is a wearable sign language converter designed to translate predefined hand gestures into text and audio output.

The system uses an Arduino Nano as the main controller and flex sensors attached to a glove to detect finger movements. Based on the detected finger positions, the corresponding gesture is identified and displayed on an LCD while an audio output is generated through a speaker.

## Features

* Wearable glove-based gesture detection
* Real-time finger movement detection
* Flex sensor-based gesture recognition
* Arduino Nano as the main controller
* LCD display for text output
* Audio output for detected gestures
* Sensor calibration for reliable gesture detection
* Standalone embedded system without requiring a camera or computer

## Hardware Components

* Arduino Nano
* Flex Sensors
* Glove
* 16×2 LCD Display
* DFPlayer Mini
* Micro SD Card
* Speaker
* Connecting wires
* Power supply

## Software & Tools

* Arduino IDE
* Arduino C/C++
* TinkerCAD
* Arduino Nano

## Working Principle

The system detects finger movements using flex sensors attached to the glove.

When a finger bends, the resistance of the corresponding flex sensor changes. The Arduino Nano reads these sensor values through its analog input pins and uses predefined threshold values to identify the performed gesture.

The detected gesture is then converted into a corresponding text and audio output.

### System Workflow

```text
Hand Gesture
     ↓
Flex Sensor Movement
     ↓
Analog Sensor Values
     ↓
Arduino Nano
     ↓
Gesture Identification
     ↓
 ┌───────────────┐
 ↓               ↓
LCD Display    DFPlayer Mini
 ↓               ↓
Text Output    Audio Output
                 ↓
              Speaker
```

## Gesture Detection

Four flex sensors are used to detect the movement of the fingers.

The Arduino continuously reads the analog values from the sensors. During calibration, sensor readings for bent and unbent finger positions are observed and suitable threshold values are defined.

The combination of detected finger states is then mapped to a predefined gesture.

## Audio Output

The detected gesture is sent to a DFPlayer Mini module.

The DFPlayer Mini reads the corresponding audio file stored on a Micro SD card and plays it through the connected speaker.

This allows the user to communicate the detected gesture as spoken audio.

## Text Output

A 16×2 LCD is used to display the detected gesture or corresponding message.

This provides immediate visual feedback along with the audio output.

## Demonstration

The working demonstration shows:

1. Wearing the glove and performing a predefined gesture
2. Flex sensors responding to finger movement
3. Arduino Nano processing the sensor readings
4. Detected gesture appearing on the LCD
5. Corresponding audio being played through the speaker

## What I Learned

Through this project, I gained practical experience in:

* Arduino Nano programming
* Analog sensor interfacing
* Flex sensor calibration
* Real-time gesture detection
* LCD interfacing
* DFPlayer Mini integration
* Audio file handling using a Micro SD card
* Embedded system debugging
* Hardware and software integration
* Building and testing a wearable electronics prototype

## Future Improvements

Possible improvements include:

* Increasing the number of recognizable gestures
* Improving gesture recognition accuracy
* Wireless communication with a smartphone
* Adding more sensors for complex gestures
* Developing a machine-learning-based gesture recognition system
* Designing a compact custom PCB
* Improving power management for portable operation

## Author

**Jayesh Kumar**
B.Tech – Electronics and Communication Engineering
SRM University-AP
