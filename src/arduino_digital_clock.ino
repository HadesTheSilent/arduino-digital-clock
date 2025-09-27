/*
 * Arduino Digital Clock with LCD Display
 * Custom large digit display with time/date setting functionality
 */

#include <LiquidCrystal.h>

// Initialize LCD with interface pins (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Time and date variables
int s = 0, m = 0, h = 0;      // seconds, minutes, hours
int dt = 1, mo = 1;           // date, month
int state = 1, state1 = 1, state2 = 1;  // Button states for debouncing
int dg = 0, cnt = 0;          // digit increment/decrement, counter for mode selection

// Month abbreviations for display
char months[13] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'o', 'n', 'd'};

// Days in each month (including leap year February)
int daysInMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Custom character definitions for large digits
// Each digit is made up of 8 custom characters arranged in a 3x2 grid

byte bar1[8] = {  // Top-right and bottom-right segments
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100
};

byte bar2[8] = {  // Top-left and bottom-left segments
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111
};

byte bar3[8] = {  // Middle horizontal segment (full width)
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte bar4[8] = {  // Top-right corner
  B11110,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11100
};

byte bar5[8] = {  // Top-left corner
  B01111,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00111
};

byte bar6[8] = {  // Bottom horizontal segment
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte bar7[8] = {  // Bottom-left corner
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01111
};

byte bar8[8] = {  // Top horizontal segment
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  // Create custom characters for the LCD
  lcd.createChar(1, bar1);
  lcd.createChar(2, bar2);
  lcd.createChar(3, bar3);
  lcd.createChar(4, bar4);
  lcd.createChar(5, bar5);
  lcd.createChar(6, bar6);
  lcd.createChar(7, bar7);
  lcd.createChar(8, bar8);

  // Initialize button states
  state = 1;
  state1 = 1;
  state2 = 1;
  
  // Initialize LCD display (16 columns, 2 rows)
  lcd.begin(16, 2);
  
  // Configure button pins as inputs
  pinMode(8, INPUT);   // Mode button
  pinMode(9, INPUT);   // Increment button
  pinMode(10, INPUT);  // Decrement button
  
  // Initialize time and date
  s = 0;
  m = 0;
  h = 0;
  dt = 1;
  mo = 1;
}

// Function to display custom digit 0
void custom0(int col) {
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(8); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

// Function to display custom digit 1
void custom1(int col) {
  lcd.setCursor(col, 0);
  lcd.write(32);  // Space character
  lcd.write(32);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

// Function to display custom digit 2
void custom2(int col) {
  lcd.setCursor(col, 0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(6);
}

// Function to display custom digit 3
void custom3(int col) {
  lcd.setCursor(col, 0);
  lcd.write(5);
  lcd.write(3);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1); 
}

// Function to display custom digit 4
void custom4(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

// Function to display custom digit 5
void custom5(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(6);
  lcd.write(1);
}

// Function to display custom digit 6
void custom6(int col) {
  lcd.setCursor(col, 0);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.setCursor(col, 1);
  lcd.write(2);
  lcd.write(6);
  lcd.write(1);
}

// Function to display custom digit 7
void custom7(int col) {
  lcd.setCursor(col, 0);
  lcd.write(8);
  lcd.write(8);
  lcd.write(1);
  lcd.setCursor(col, 1);
  lcd.write(32);
  lcd.write(32);
  lcd.write(1);
}

// Function to display custom digit 8
void custom8(int col) {
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(2);  
  lcd.write(6);  
  lcd.write(1);
}

// Function to display custom digit 9
void custom9(int col) {
  lcd.setCursor(col, 0); 
  lcd.write(2);  
  lcd.write(3); 
  lcd.write(1);
  lcd.setCursor(col, 1); 
  lcd.write(7);  
  lcd.write(6);  
  lcd.write(1);
}

// Function to print any number (0-9) at specified column
void printNumber(int value, int col) {
  switch(value) {
    case 0: custom0(col); break;
    case 1: custom1(col); break;
    case 2: custom2(col); break;
    case 3: custom3(col); break;
    case 4: custom4(col); break;
    case 5: custom5(col); break;
    case 6: custom6(col); break;
    case 7: custom7(col); break;
    case 8: custom8(col); break;
    case 9: custom9(col); break;
  }      
}

void loop() {
  // Handle mode button (cycles through: normal, hour set, minute set, date set, month set)
  if (digitalRead(8) && state == 1) {
    cnt++;
    state = 0;
    cnt = cnt % 5;  // 5 modes: 0=normal, 1=hour, 2=minute, 3=date, 4=month
  } else if (!digitalRead(8) && state == 0) {
    state = 1;
  }
  
  // Handle increment button
  if (digitalRead(9) && state1 == 1) {
    dg = 1;
    state1 = 0;
  } else if (!digitalRead(9) && state1 == 0) {
    state1 = 1;
  }

  // Handle decrement button
  if (digitalRead(10) && state2 == 1) {
    dg = -1;
    state2 = 0;
  } else if (!digitalRead(10) && state2 == 0) {
    state2 = 1;
  }
    
  // Process button input based on current mode
  switch(cnt) {
    case 1: // Hour setting mode
      h = h + dg;
      dg = 0;
      if (h > 23) h = 0;
      if (h < 0) h = 23;
      break;
     
    case 2: // Minute setting mode
      m = m + dg;
      dg = 0;
      if (m > 59) m = 0;
      if (m < 0) m = 59;
      break;
      
    case 3: // Date setting mode
      dt = dt + dg;
      dg = 0;
      if (dt > daysInMonth[mo]) dt = 1;
      if (dt < 1) dt = daysInMonth[mo];
      break;
      
    case 4: // Month setting mode
      mo = mo + dg;
      dg = 0;
      if (mo > 12) mo = 1;
      if (mo < 1) mo = 12;
      // Adjust date if it exceeds days in new month
      if (dt > daysInMonth[mo]) {
        dt = daysInMonth[mo];
      }
      break;
  }
  
  // Normal time progression (only in normal mode)
  if (cnt == 0) {
    // Time advancement logic
    if (s > 59) {
      s = 0;
      m++;
      
      if (m > 59) {
        m = 0;
        h++;
        
        if (h > 23) {
          h = 0;
          dt++;
          
          if (dt > daysInMonth[mo]) {
            dt = 1;
            mo++;
            
            if (mo > 12) {
              mo = 1;
            }
          } 
        }
      }
    }
  }
  
  // Display hours (positions 0-2)
  int digit = h / 10;
  printNumber(digit, 0);
  digit = h % 10;
  printNumber(digit, 3);

  // Display minutes (positions 7-9)
  digit = m / 10;
  printNumber(digit, 7);
  digit = m % 10;
  printNumber(digit, 10);
  
  // Display seconds (positions 14-15, top row)
  lcd.setCursor(14, 0);
  lcd.print(s / 10);
  lcd.print(s % 10);
        
  // Display date (bottom row, right side)
  lcd.setCursor(13, 1);
  lcd.print(months[mo]);
  lcd.print(dt / 10);
  lcd.print(dt % 10);
  
  // Blinking colon and time progression (only in normal mode)
  if (cnt == 0) {
    s++;
    
    // Clear separators
    lcd.setCursor(6, 0);
    lcd.print(" ");
    lcd.setCursor(6, 1);
    lcd.print(" ");
    lcd.setCursor(13, 0);
    lcd.print(" ");
    delay(500);
    
    // Show separators
    lcd.setCursor(6, 0);
    lcd.print(".");
    lcd.setCursor(6, 1);
    lcd.print(".");
    lcd.setCursor(13, 0);
    lcd.print(":");
    delay(500);
  }
}
