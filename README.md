# Arduino Digital Clock 🕐

A digital clock built with Arduino Uno and a 16x2 LCD display, featuring custom large digit display, time/date setting functionality, and blinking separators. Originally designed and tested in Tinkercad simulator.

![Project Status](https://img.shields.io/badge/Status-WIP-8A2BE2)
![Arduino](https://img.shields.io/badge/Arduino-Uno-8A2BE2)
![Tinkercad](https://img.shields.io/badge/Designed_in-Tinkercad-8A2BE2)

## 📸 Project Overview

This Arduino-based digital clock displays time in large, custom-designed digits on a 16x2 LCD screen. The project includes time and date setting capabilities through push buttons, making it a fully functional desktop clock.

### ✨ Key Features

- **Large Custom Digits**: Time displayed in big, easy-to-read custom characters
- **Time Setting**: Adjustable hours and minutes via push buttons  
- **Date Display**: Shows month and day with settable values
- **Blinking Separators**: Visual time separator with blinking colon
- **Multiple Modes**: Cycle through normal display and setting modes
- **Real-time Updates**: Accurate timekeeping with second precision

## 🛠️ Hardware Requirements

### Core Components
- Arduino Uno R3 (or compatible)
- 16x2 LCD Display (HD44780 compatible)
- 3x Push Buttons (momentary, normally open)
- 10kΩ Potentiometer (for LCD contrast)
- Resistors: 3x 10kΩ, 1x 220Ω
- Breadboard and jumper wires

### Complete component list available in [`circuit/components.md`](circuit/components.md)

## 🔌 Circuit Connections

### LCD Connections
| LCD Pin | Function | Arduino Pin |
|---------|----------|-------------|
| RS | Register Select | Pin 2 |
| Enable | Enable Signal | Pin 3 |
| D4-D7 | Data Lines | Pins 4-7 |
| VSS, V0, A, K | Power/Backlight | 5V/GND/Contrast |

### Button Connections
- **Button Set**: Pin 8 (cycles through settings)
- **Button Up**: Pin 9 (increases values)
- **Button Down**: Pin 10 (decreases values)

## 🚀 Getting Started

1. **Simulation (Optional)**
   - The project was originally designed in Tinkercad
   - You can simulate the circuit before building physically

2. **Hardware Assembly**
   - Follow the circuit diagram in `circuit/Digital clock.pdf`
   - Wire components according to the connection tables in `circuit/README.md`

3. **Software Setup**
   - Open `src/arduino_digital_clock.ino` in Arduino IDE
   - Upload the code to your Arduino

4. **Configuration**
   - Adjust LCD contrast using the potentiometer
   - Set the time using the buttons

## 🎮 Usage Instructions

### Operation Modes
The clock has 5 operating modes, accessed by pressing the Mode button:

1. **Normal Mode (0)**: Clock runs and displays time
2. **Hour Setting (1)**: Adjust hour value
3. **Minute Setting (2)**: Adjust minute value  
4. **Date Setting (3)**: Adjust day of month
5. **Month Setting (4)**: Adjust month value

### Button Functions
- **Button Set**: Cycles through the 5 modes
- **Button Up**: Increases the current setting
- **Button Down**: Decreases the current setting

### Display Layout
```
HH.MM    SS
M DD
```
- `HH.MM`: Hours and minutes in large digits
- `SS`: Seconds in small digits (top right)
- `M DD`: Month and date (bottom right)

## 📁 Project Structure

```
arduino-digital-clock/
├── src/
│   └── arduino_digital_clock.ino    # Main Arduino code
├── circuit/
│   ├── README.md                    # Circuit documentation
│   ├── components.md                # Component list
│   └── Digital clock.pdf            # Circuit schematic
└── docs/
    └── troubleshooting.md           # Common issues and fixes
```

## 🐛 Troubleshooting

### Common Issues

**LCD shows no display:**
- Check power connections (5V and GND)
- Adjust contrast potentiometer
- Verify data pin connections

**Buttons not responding:**
- Check pull-down resistor connections
- Verify button wiring to correct pins
- Test with multimeter for continuity

**Time keeping inaccurate:**
- Arduino crystal tolerance affects accuracy
- Consider using RTC module for precision
- Check for interference from other circuits

For detailed troubleshooting, see [`docs/troubleshooting.md`](docs/troubleshooting.md)