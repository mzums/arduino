#include <Arduino.h>

// 2-dimensional array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

// 2-dimensional array of pixels:
int pixels[8][8];

typedef bool charMapType[8][8];

/*const charMapType heart = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};*/

// angry robot
const charMapType angryRobot = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 0, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 0, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1}
};

//squares
// const charMapType squares = {
//   {1, 1, 1, 1, 1, 1, 1, 1},
//   {1, 0, 0, 0, 0, 0, 0, 1},
//   {1, 0, 1, 1, 1, 1, 0, 1},
//   {1, 0, 1, 0, 0, 1, 0, 1},
//   {1, 0, 1, 0, 0, 1, 0, 1},
//   {1, 0, 1, 1, 1, 1, 0, 1},
//   {1, 0, 0, 0, 0, 0, 0, 1},
//   {1, 1, 1, 1, 1, 1, 1, 1}
// };

void setupMatrix(){
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      bool v = square[x][y];
      if(v){
        pixels[x][y] = LOW;
      }else{
        pixels[x][y] = HIGH;
      }
    }
  }
}

void setup() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
  }
  setupMatrix();
}

void displayLedPattern(){
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    digitalWrite(row[thisRow], HIGH);
    for (int thisCol = 0; thisCol < 8; thisCol++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisRow][thisCol];
      // when the row is HIGH and the col is LOW,
      // the LED where they meet turns on:
      digitalWrite(col[thisCol], thisPixel);
      // turn the pixel off:
      if (thisPixel == LOW) {
        digitalWrite(col[thisCol], HIGH);
      }
    }
    // take the row pin low to turn off the whole row:
    digitalWrite(row[thisRow], LOW);
  }
}

void loop() {
  displayLedPattern();
}

