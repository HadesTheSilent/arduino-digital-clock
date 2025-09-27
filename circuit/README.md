# Circuit Documentation

## Components Required

### Main Components
- **Arduino Uno R3** (or compatible microcontroller)
- **16x2 LCD Display** (HD44780 compatible)
- **3x Push Buttons** (momentary, normally open)
- **Potentiometer** (10kΩ for LCD contrast adjustment)

### Additional Components
- **Resistors:**
  - 3x 10kΩ (pull-down resistors for buttons)
  - 1x 220Ω (LCD backlight current limiting)
- **Breadboard** (half-size or full-size)
- **Jumper Wires** (male-to-male, various lengths)
- **Power Supply** (9V battery or USB power)

## Pin Connections

### LCD to Arduino Connections
| LCD Pin | LCD Function | Arduino Pin | Wire Color (Suggested) |
|---------|--------------|-------------|------------------------|
| 1 (VSS) | Ground | GND | Black |
| 2 (VDD) | +5V Power | 5V | Red |
| 3 (V0) | Contrast | Potentiometer wiper | Yellow |
| 4 (RS) | Register Select | Digital Pin 2 | Orange |
| 5 (Enable) | Enable | Digital Pin 3 | Green |
| 6 (D0) | Data 0 | Not connected | - |
| 7 (D1) | Data 1 | Not connected | - |
| 8 (D2) | Data 2 | Not connected | - |
| 9 (D3) | Data 3 | Not connected | - |
| 10 (D4) | Data 4 | Digital Pin 4 | Blue |
| 11 (D5) | Data 5 | Digital Pin 5 | Purple |
| 12 (D6) | Data 6 | Digital Pin 6 | Gray |
| 13 (D7) | Data 7 | Digital Pin 7 | White |
| 14 (A) | Backlight Anode | 5V (through 220Ω resistor) | Red |
| 15 (K) | Backlight Cathode | GND | Black |

### Button Connections
| Button Function | Arduino Pin | Connection |
|----------------|-------------|------------|
| Mode Select | Digital Pin 8 | One terminal to pin 8, other to +5V |
| Increment | Digital Pin 9 | One terminal to pin 9, other to +5V |
| Decrement | Digital Pin 10 | One terminal to pin 10, other to +5V |

**Note:** Each button should have a 10kΩ pull-down resistor connected from the Arduino pin to ground.

### Potentiometer Connection
- **Left terminal:** Ground (GND)
- **Right terminal:** +5V
- **Center terminal (wiper):** LCD Pin 3 (V0)

## Circuit Assembly Instructions

**Note: This project was originally designed and tested in Tinkercad simulator before physical implementation.**

### Step 1: Set up the Breadboard
1. Place the Arduino Uno and breadboard on your work surface
2. Connect power rails on the breadboard to Arduino 5V and GND

### Step 2: Mount the LCD
1. Place the 16x2 LCD on the breadboard or use a separate mounting
2. Connect all LCD pins according to the pin connection table above
3. Install the contrast potentiometer and connect to LCD pin 3

### Step 3: Install Buttons
1. Place three push buttons on the breadboard
2. Connect each button with pull-down resistors as specified
3. Wire buttons to digital pins 8, 9, and 10

### Step 4: Power Connections
1. Connect Arduino GND to breadboard ground rail
2. Connect Arduino 5V to breadboard power rail
3. Ensure all ground connections are common

### Step 5: Final Checks
1. Double-check all connections against the pin table
2. Verify power connections (5V and GND)
3. Test continuity with a multimeter if available

## Circuit Diagram
Refer to `Digital clock.pdf` in this directory for the complete circuit schematic.

## Troubleshooting

### Common Issues
1. **LCD shows no display:**
   - Check power connections (5V and GND)
   - Adjust contrast potentiometer
   - Verify all data pin connections

2. **Buttons not responding:**
   - Verify pull-down resistor connections
   - Check button wiring to correct pins
   - Ensure buttons are normally open type

3. **Scrambled display:**
   - Check data pin connections (D4-D7)
   - Verify Enable and RS pin connections
   - Reset Arduino and reload code

4. **Dim or no backlight:**
   - Check backlight power connections
   - Verify 220Ω current limiting resistor
   - Test backlight LED with direct power

### Testing Steps
1. Upload a simple "Hello World" LCD test first
2. Test each button individually with serial monitor
3. Verify time keeping accuracy over several minutes
4. Test all setting modes (hour, minute, date, month)

## Notes
- This circuit operates at 5V logic levels
- Total current consumption is approximately 100mA
- LCD contrast may need adjustment based on viewing angle
- Buttons include debouncing in software
- Uses 4-bit LCD interface to save Arduino pins