# 🌱🎵 "Atelier des Plantes" - sonification of plant electrical activity

**Atelier des Plantes** is part of an educational device designed for *music practice workshops with children, allowing them to explore the relationship between nature and sound in an interactive way.

---

## 📌 Project Description

This project connects an **Arduino**, which detects variations in the electrical activity of plants, with a **Raspberry Pi** equipped with a sound card. The Raspberry Pi is responsible for sonifying the signal, enabling children to "hear" the bioelectrical activity of plants in real time.

The system is designed for educational workshops, encouraging musical creativity and scientific curiosity among children.

---

## 🛠️ Components and Technologies

- **Arduino** → Captures the plant's bioelectrical signal.  
- **Raspberry Pi** → Processes the signal and converts it into MIDI.  
- **Sound card** → Enhances audio output quality.  
- **RNBO and processing patches** → Implements the signal-to-audio conversion along with sound design.  

---

## 🚀 Installation and usage

### 1️⃣ Hardware setup
- Connect the electrode to the plant.  
- Connect the Arduino to the Raspberry Pi.  
- Connect the sound card to the Raspberry Pi.  

### 2️⃣ Software Configuration
- Upload the Arduino code to the microcontroller.  
- Run the RNBO patch on the Raspberry Pi.  

### 3️⃣ Workshop Interaction
- Children interact with the plants.  
- The bioelectrical signal is converted into sound.  
- Different sound responses can be explored based on touch and plant conditions.  

---

## 🎯 Educational objective

This device aims to:

✔️ Spark scientific curiosity in children.  
✔️ Explore the connection between biology and music.  
✔️ Foster creativity through interaction with nature.  

---

## 📂 Repository Structure

```
📂 Code_transcodage_Arduino/     # Arduino code
📂 RNBO_patch_Raspberry_Pi/      # Sonification patches for Raspberry Pi
📄 Sketch_Arduino.png           # Circuit diagram
📄 Construction_de_l_appareil.docx  # Device construction details

```

---

## 🏗️ Device Construction: Arduino and Raspberry Pi

### 🛠️ Required Materials

#### **Arduino Setup**
- 1x Arduino Uno  
- 1x Electrode + adapter  
- 1x Resistor (1MΩ)  
- 2x Resistors (220 Ω)  
- 1x Potentiometer (10 kΩ)  
- 1x LED  
- 1x MIDI 5 Pin Connector  
- 1x MIDI to USB Cable  
- Jumper wires for Arduino  
- 1x Breadboard  
- 1x Soldering board for Arduino UNO  
- Soldering wire  
- 1x USB Cable for Arduino  
- 1x Suitable enclosure for Arduino  

#### **Raspberry Pi Setup**
- Raspberry Pi 4  
- HifiBerry Sound Card  
- MicroSD Card  
- 2 RCA male to 3.5mm mini-jack cable  
- Speaker and 3.5mm mini-jack audio cable  
- Audio splitter  
- Headphones  
- Suitable enclosure for Raspberry Pi with HifiBerry  

#### **Additional Components**
- 2x Portable batteries  
- 1x Computer with Arduino IDE and RNBO installed  

---

## ⚡ Wiring Instructions for Arduino Circuit

### **1️⃣ Capacitive Sensor**
- Connect one terminal of the 1MΩ resistor to Arduino pin 4.
- Connect the other terminal of the resistor to Arduino pin 2.
- Connect Arduino pin 2 to an electrode (capacitive sensor) using its adapter.

### **2️⃣ LED**
- Connect the long leg (anode) of the LED to Arduino pin 13.
- Connect the short leg (cathode) of the LED to GND via a 220Ω resistor.

### **3️⃣ Potentiometer**
- Connect one outer leg of the potentiometer to 5V.
- Connect the other outer leg to GND.
- Connect the middle leg to Arduino analog pin A0.

### **4️⃣ MIDI Connector**
- Connect pin 5 of the MIDI connector to Arduino TX pin.
- Connect pin 4 of the MIDI connector to 5V via a 220Ω resistor.
- Connect pin 2 of the MIDI connector to GND.

---

## 🖥️ Arduino Code
```cpp
#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);
// Arduino code continues... in 📂 Code_transcodage_Arduino/ 
```

---

## 🔧 Raspberry Pi Configuration with RNBO

### **1️⃣ Preparing the MicroSD Card**
1. Download the ready-to-use RNBO image for Raspberry Pi from Cycling '74's website.
2. Use Raspberry Pi Imager to flash the image onto the microSD card.
3. Configure WiFi, hostname, and enable SSH + Wireless LAN setup during flashing.

### **2️⃣ Setting Up the HifiBerry Sound Card**
4. Connect the HifiBerry sound card to the Raspberry Pi's GPIO pins.
5. Connect the RCA cable to the HifiBerry audio outputs.
6. Plug the other end of the RCA cable into the audio splitter via the 3.5mm mini-jack.
7. Connect speakers and headphones to the audio splitter.

### **3️⃣ Integrating Raspberry Pi with Arduino**
8. Insert the microSD card into the Raspberry Pi.
9. Connect the MIDI-to-USB cable between the Arduino's 5-PIN female connector and one of the Raspberry Pi's USB ports.
10. Power on the Raspberry Pi using the portable battery.
11. From Max software, export the RNBO patch to the Raspberry Pi via the shared network.
12. Place the electrode on a plant leaf.
13. Turn on the Arduino by connecting it to a portable battery.
14. Test the setup by touching the plant and adjusting the potentiometer for sensitivity.

---

## 📜 Credits and lLicense

📌 Developed for educational workshops.  
📌 Created by **Romina S. Romay**.  
📌 Distributed under the **MIT License**.  
