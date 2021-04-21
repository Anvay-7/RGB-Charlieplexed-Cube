#include "cubeplex.h"
#include <SoftwareSerial.h>
#include "string.h"
//#include "NoDelay.h"

char msg[25];
char msg_array[3][20];
char curr_msg[15];
char a_speed[20];
char msg_word[20];
char p_speed[20];
int pause;
int animation_speed;

SoftwareSerial mySerial(19, 20);
char last_msg[15];
int color = blue;
int _ = 0;

int a[4][4] = {

    {_, 1, 1, _},
    {1, _, _, 1},
    {1, 1, 1, 1},
    {1, _, _, 1}};

int b[4][4] = {

    {1, _, _, _},
    {1, 1, 1, _},
    {1, _, _, 1},
    {1, 1, 1, 1}};

int c[4][4] = {

    {_, 1, 1, 1},
    {1, _, _, _},
    {1, _, _, _},
    {_, 1, 1, 1}};

int d[4][4] = {

    {_, _, _, 1},
    {_, 1, 1, 1},
    {1, _, _, 1},
    {1, 1, 1, 1}};

//int e[4][4] = {
//
//    {1, 1, 1, 1},
//    {_, 1, _, _},
//    {_, 1, _, _},
//    {1, 1, 1, 1}};  Can't figure out the design for this letter

int f[4][4] = {

    {1, 1, 1, 1},
    {1, _, _, _},
    {1, 1, 1, _},
    {1, _, _, _}};

//int g[4][4] = {
//
//    {1, _, _, _},
//    {1, _, 1, 1},
//    {1, _, _, 1},
//    {1, 1, 1, 1}};  Can't figure out the design for this letter

int h[4][4] = {

    {1, _, _, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, _, _, 1}};

int i[4][4] = {

    {1, 1, 1, 1},
    {_, 1, 1, _},
    {_, 1, 1, _},
    {1, 1, 1, 1}};

int j[4][4] = {

    {_, 1, 1, 1},
    {_, _, _, 1},
    {_, 1, _, 1},
    {_, 1, 1, _}};

int k[4][4] = {

    {1, _, 1, _},
    {1, 1, _, _},
    {1, 1, _, _},
    {1, _, 1, _}};

int l[4][4] = {

    {1, _, _, _},
    {1, _, _, _},
    {1, _, _, _},
    {1, 1, 1, _}};

int m[4][4] = {

    {1, _, 1, _},
    {1, 1, 1, _},
    {1, _, 1, _},
    {1, _, 1, _}};

int n[4][4] = {

    {1, _, _, 1},
    {1, 1, _, 1},
    {1, _, 1, 1},
    {1, _, _, 1}};

int o[4][4] = {

    {_, 1, 1, _},
    {1, _, _, 1},
    {1, _, _, 1},
    {_, 1, 1, _}};

int p[4][4] = {

    {1, 1, _, _},
    {1, _, 1, _},
    {1, 1, _, _},
    {1, _, _, _}};

int q[4][4] = {

    {_, _, 1, 1},
    {_, 1, _, 1},
    {_, _, 1, 1},
    {_, _, _, 1}};

int r[4][4] = {

    {1, _, 1, 1},
    {1, 1, _, _},
    {1, _, _, _},
    {1, _, _, _}};

int s[4][4] = {

    {_, 1, 1, 1},
    {1, 1, _, _},
    {_, _, 1, 1},
    {1, 1, 1, _}};

int t[4][4] = {

    {1, 1, 1, 1},
    {_, 1, 1, _},
    {_, 1, 1, _},
    {_, 1, 1, _}};

int u[4][4] = {

    {1, _, _, 1},
    {1, _, _, 1},
    {1, _, _, 1},
    {1, 1, 1, 1}};

int v[4][4] = {

    {1, _, _, 1},
    {1, _, _, 1},
    {1, _, _, 1},
    {_, 1, 1, _}};

int w[4][4] = {

    {1, _, _, 1},
    {1, _, _, 1},
    {1, 1, 1, 1},
    {1, _, _, 1}};

int x[4][4] = {

    {1, _, _, 1},
    {_, 1, 1, _},
    {_, 1, 1, _},
    {1, _, _, 1}};

int y[4][4] = {

    {1, _, _, 1},
    {1, 1, 1, 1},
    {_, 1, 1, _},
    {_, 1, 1, _}};

int z[4][4] = {

    {1, 1, 1, 1},
    {_, _, 1, _},
    {_, 1, _, _},
    {1, 1, 1, 1}};

const int SIZE = 4;
int new_z[SIZE] = {1, 2, 3, 0}; // this is a workaround as I messed up wiring and hence the z axis was shifted by one layer
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  initCube();

  animationMax = 10;
}
void loop()
{

  if (mySerial.available() > 0)
  {
    //Serial.println(mySerial.readString());
    mySerial.readString().toCharArray(msg, 25);
    //Serial.println(msg);
    //remove_white_spaces(msg);

    //Serial.println(msg);
    // if(strlen(msg)!=0){
    //Serial.println("if entered");
    char *token = strtok(msg, "~");
    for (int i = 0; token != NULL; i++)
    {

      strcpy(msg_array[i], token);
      token = strtok(NULL, "~");
    }
  }
  strcpy(curr_msg, msg_array[0]);
  //  Serial.print("curr_msg = ");
  //  Serial.println(curr_msg);
  strcpy(a_speed, msg_array[1]);
  //  Serial.print("a speed= ");
  //  Serial.println(a_speed);
  strcpy(msg_word, msg_array[2]);
  //  Serial.print("msg_word = ");
  //  Serial.println(msg_word);
  animation_speed = atoi(a_speed);
  strcpy(p_speed, msg_array[3]);
  pause = atoi(p_speed);
  // Serial.println(animation_speed);
  //}
  //  else{
  //    Serial.println("else entered");
  //    strcpy(curr_msg,last_msg);}

  //Serial.print("curr_msg outside = ");
  //Serial.println(curr_msg);
  if (!strcmp(curr_msg, "clear"))
  {
    if (strcmp(curr_msg, last_msg))
    {
      blank();
    }
  }
  if (!strcmp(curr_msg, "fountain"))
  {
    fountain(animation_speed);
  }
  if (!strcmp(curr_msg, "trifade"))
  {
    trifade(animation_speed);
  }
  if (!strcmp(curr_msg, "planar_spin"))
  {
    planarSpin(animation_speed);
  }
  if (!strcmp(curr_msg, "raindrop"))
  {
    raindrop(animation_speed);
  }
  if (!strcmp(curr_msg, "atom"))
  {
    atom(animation_speed);
  }

  if (!strcmp(curr_msg, "snake"))
  {
    snake(animation_speed);
  }

  if (!strcmp(curr_msg, "orbit"))
  {
    orbit(animation_speed);
  }
  if (!strcmp(curr_msg, "planar_spin1"))
  {
    planar_spin1(animation_speed);
  }
  if (!strcmp(curr_msg, "orbit1"))
  {
    orbit1(animation_speed);
  }

  if (!strcmp(curr_msg, "lines"))
  {
    random_lines(animation_speed);
  }
  if (!strcmp(curr_msg, "squares"))
  {
    shiftSquares(animation_speed);
  }
  if (!strcmp(curr_msg, "print_word"))
  {
    //    Serial.print("curr_msg inside func = ");
    //    Serial.println(curr_msg);
    //    Serial.print("msg_word = ");
    //    Serial.println(msg_word);
    print_word(msg_word, animation_speed, pause);
  }
  strcpy(last_msg, curr_msg);

  //print_word("anvay",0)
  //print_letter(n);
  //bright_test();
  //test();
  // planarSpin(120);
  //fountian();
  //trifade();
  //shiftSquares();
  //tunnel();
  //chaseTheDot();
  // planarFlop3D();
}

//void new_delay(int animation_speed)
//{
//  int i = 1;
//  unsigned long previousMillis = 0;
//  while (i == 1)
//  {
//    unsigned long currentMillis = millis();
//    if (currentMillis - previousMillis >= animation_speed)
//    {
//      // save the last time you blinked the LED
//      previousMillis = currentMillis;
//      i = 2;
//    }
//  }
//}
//int check_char(char str[])
//{
//  int char_present = 0;
//  if (strchr(str, '!') != NULL)
//  {
//    char_present = 1;
//  }
//  return char_present;
//}

//char *remove_white_spaces(char *str)
//{
//  int i = 0, j = 0;
//  while (str[i])
//  {
//    if (str[i] != '`')
//      str[j++] = str[i];
//    i++;
//  }
//  str[j] = '\0';
//  return str;
//}
void raindrop(int animation_speed)
{

  int x = 0;
  int y = 0;
  int z = 4;
  int a = 1;
  for (a = 100; a > 0; a--)
  {
    x = (random(0, 4));
    y = (random(0, 4));
    z = 4;
    delay(250);
    for (int i = 4; i > 0; i--)
    {
      z = z - 1;
      drawLed(color, 8, x, y, new_z[z]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    color = nextColor(color);
  }
}

void blank()
{

  int p = 1;
  if (p == 1)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        for (int k = 0; k < 4; k++)
        {

          flushBuffer();
          clearBuffer();
        }
      }
    }
    p = 2;

    drawLed(off, 4, 0, 0, new_z[0]);
  }
}

void print_word(char string[20], int animation_speed, int pause)
{

  for (int ii = 0; string[ii] != '\0'; ii++)
  {

    if (string[ii] == 'a')
    {
      print_letter(a, animation_speed);

      delay(pause);
    }
    if (string[ii] == 'b')
    {
      print_letter(b, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'c')
    {
      print_letter(c, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'd')
    {
      print_letter(d, animation_speed);
      delay(pause);
    }
    //    if (string[ii] == 'e')
    //    {
    //      print_letter(e, animation_speed);
    //      delay(pause);
    //    }
    if (string[ii] == 'f')
    {
      print_letter(f, animation_speed);
      delay(pause);
    }
    //    if (string[ii] == 'g')
    //    {
    //      print_letter(g, animation_speed);
    //      delay(pause);
    //    }
    if (string[ii] == 'h')
    {
      print_letter(h, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'i')
    {
      print_letter(i, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'j')
    {
      print_letter(j, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'k')
    {
      print_letter(k, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'l')
    {
      print_letter(l, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'm')
    {
      print_letter(m, animation_speed);
      delay(pause);
    }

    if (string[ii] == 'n')
    {
      print_letter(n, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'o')
    {
      print_letter(o, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'p')
    {
      print_letter(p, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'q')
    {
      print_letter(q, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'r')
    {
      print_letter(r, animation_speed);
      delay(pause);
    }
    if (string[ii] == 's')
    {
      print_letter(s, animation_speed);
      delay(pause);
    }
    if (string[ii] == 't')
    {
      print_letter(t, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'u')
    {
      print_letter(u, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'v')
    {
      print_letter(v, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'w')
    {
      print_letter(w, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'x')
    {
      print_letter(x, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'y')
    {
      print_letter(y, animation_speed);
      delay(pause);
    }
    if (string[ii] == 'z')
    {
      print_letter(z, animation_speed);
      delay(pause);
    }
  }
}

void print_letter(int letter[4][4], int animation_speed)
{
  for (int j = 0; j < 4; j++)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int k = 0; k < 4; k++)
      {
        if (letter[3 - k][i] == 0)
        {
          continue;
        }

        drawLed(color, 1, i, j, new_z[k]);
      }
    }
    flushBuffer();
    clearBuffer();
    color = nextColor(color);
    delay(animation_speed);
  }
}
//void bright_test()
//{
//  drawLed(blue, 8, 0, 2, new_z[1]);
//  drawLed(blue, 8, 1, 0, new_z[0]);
//
//  flushBuffer();
//  clearBuffer();
//}
//void test()
//{
//  continuePattern = true;
//  while (continuePattern)
//  {
//    for (int i = 0; i < 4; i++)
//    {
//      for (int j = 0; j < 4; j++)
//      {
//        for (int k = 0; k < 2; k++)
//        {
//          drawLed(green, 3, i, j, new_z[k]);
//        }
//      }
//    }
//    flushBuffer();
//    clearBuffer();
//  }
//}
void planarSpin(int animation_speed)
{

  int spinsPerColor = 5; // a spin is actually half a revolution
  {
    int x = 0;
    int y = 0;
    for (int i = 0; i < spinsPerColor; i++)
    {
      for (int x = 0; x < 3; x++)
      {
        drawLine(color, x, 0, 0, 3 - x, 3, 0);
        drawLine(color, x, 0, 1, 3 - x, 3, 1);
        drawLine(color, x, 0, 2, 3 - x, 3, 2);
        drawLine(color, x, 0, 3, 3 - x, 3, 3);
        flushBuffer();
        clearBuffer();
        delay(animation_speed);
      }
      for (int y = 0; y < 3; y++)
      {
        drawLine(color, 3, y, 0, 0, 3 - y, 0);
        drawLine(color, 3, y, 1, 0, 3 - y, 1);
        drawLine(color, 3, y, 2, 0, 3 - y, 2);
        drawLine(color, 3, y, 3, 0, 3 - y, 3);
        flushBuffer();
        clearBuffer();
        delay(animation_speed);
      }
    }
    color = nextColor(color);
  }
}

void fountain(int animation_speed)
{

  for (int z = 0; z <= 3; z++)
  {
    drawBoxWalls(color, 8, 1, 1, new_z[z], 2, 2, new_z[z]);
    flushBuffer();
    clearBuffer();

    delay(animation_speed);
  }
  for (int z = 3; z >= 0; z--)
  {
    drawBoxWalls(color, 8, 0, 0, new_z[z], 3, 3, new_z[z]);
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
  color = nextColor(color);
}

void trifade(int animation_speed)
{

  // blue fade out, red fade in
  for (int i = 1; i <= 8; i++)
  {
    drawBox(blue, 9 - i, 0, 0, 0, 3, 3, 3);
    drawBox(red, i, 0, 0, 0, 3, 3, 3);
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
  // red fade out, green fade in
  for (int i = 1; i <= 8; i++)
  {
    drawBox(red, 9 - i, 0, 0, 0, 3, 3, 3);
    drawBox(green, i, 0, 0, 0, 3, 3, 3);
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
  // green fade out, blue fade in
  for (int i = 1; i <= 8; i++)
  {
    drawBox(green, 9 - i, 0, 0, 0, 3, 3, 3);
    drawBox(blue, i, 0, 0, 0, 3, 3, 3);
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
}

void shiftSquares(int animation_speed)
{

  int blx = 2; // blue x
  int bly = 0; // blue y
  int blz = 0; // blue z

  int rdx = 0; // red x
  int rdy = 2; // red y
  int rdz = 0; // red z

  int gnx = 0; // green x
  int gny = 0; // green y
  int gnz = 2; // green z

  int *mover = &blx;

  switch (random(0, 9))
  {
  case 0:
    mover = &blx;
    break;
  case 1:
    mover = &bly;
    break;
  case 2:
    mover = &blz;
    break;
  case 3:
    mover = &rdx;
    break;
  case 4:
    mover = &rdy;
    break;
  case 5:
    mover = &rdz;
    break;
  case 6:
    mover = &gnx;
    break;
  case 7:
    mover = &gny;
    break;
  case 8:
    mover = &gnz;
    break;
  }
  *mover = (((*mover) + 2) % 4) - 1;
  drawBox(blue, abs(blx), abs(bly), new_z[abs(blz)], abs(blx) + 1, abs(bly) + 1, new_z[abs(blz) + 1]);
  drawBox(red, abs(gnx), abs(gny), new_z[abs(gnz)], abs(gnx) + 1, abs(gny) + 1, new_z[abs(gnz) + 1]);
  drawBox(green, abs(rdx), abs(rdy), new_z[abs(rdz)], abs(rdx) + 1, abs(rdy) + 1, new_z[abs(rdz) + 1]);
  flushBuffer();
  clearBuffer();
  delay(animation_speed);
  *mover = (((*mover) + 2) % 4) - 1;
  drawBox(blue, abs(blx), abs(bly), new_z[abs(blz)], abs(blx) + 1, abs(bly) + 1, new_z[abs(blz) + 1]);
  drawBox(red, abs(gnx), abs(gny), new_z[abs(gnz)], abs(gnx) + 1, abs(gny) + 1, new_z[abs(gnz) + 1]);
  drawBox(green, abs(rdx), abs(rdy), new_z[abs(rdz)], abs(rdx) + 1, abs(rdy) + 1, new_z[abs(rdz) + 1]);
  flushBuffer();
  clearBuffer();
  delay(animation_speed * 2);
}

//void tunnel()
//{
//  continuePattern = true;
//  int animationSpeed = 100;
//
//  int color1[] = {R, R, R, R, B, B, B, B};
//  int bright1[] = {2, 4, 6, 8, 2, 4, 6, 8};
//  int color2[] = {B, B, B, B, R, R, R, R};
//  //int bright2[] = {6,4,2,0,6,4,2,0};
//  int bright2[] = {8, 6, 4, 2, 8, 6, 4, 2};
//
//  int index[] = {0, 1, 2, 3, 4, 5, 6, 7};
//
//  while (continuePattern)
//  {
//    drawBoxWalls(color1[index[0]], bright1[index[0]], 1, 1, new_z[0], 2, 2, new_z[0]);
//    drawBoxWalls(color2[index[0]], bright2[index[0]], 1, 1, new_z[0], 2, 2, new_z[0]);
//    drawBoxWalls(color1[index[1]], bright1[index[1]], 1, 1, new_z[1], 2, 2, new_z[1]);
//    drawBoxWalls(color2[index[1]], bright2[index[1]], 1, 1, new_z[1], 2, 2, new_z[1]);
//    drawBoxWalls(color1[index[2]], bright1[index[2]], 1, 1, new_z[2], 2, 2, new_z[2]);
//    drawBoxWalls(color2[index[2]], bright2[index[2]], 1, 1, new_z[2], 2, 2, new_z[2]);
//    drawBoxWalls(color1[index[3]], bright1[index[3]], 1, 1, new_z[3], 2, 2, new_z[3]);
//    drawBoxWalls(color2[index[3]], bright2[index[3]], 1, 1, new_z[3], 2, 2, new_z[3]);
//
//    drawBoxWalls(color1[index[4]], bright1[index[4]], 0, 0, new_z[3], 3, 3, new_z[3]);
//    drawBoxWalls(color2[index[4]], bright2[index[4]], 0, 0, new_z[3], 3, 3, new_z[3]);
//    drawBoxWalls(color1[index[5]], bright1[index[5]], 0, 0, new_z[2], 3, 3, new_z[2]);
//    drawBoxWalls(color2[index[5]], bright2[index[5]], 0, 0, new_z[2], 3, 3, new_z[2]);
//    drawBoxWalls(color1[index[6]], bright1[index[6]], 0, 0, new_z[1], 3, 3, new_z[1]);
//    drawBoxWalls(color2[index[6]], bright2[index[6]], 0, 0, new_z[1], 3, 3, new_z[1]);
//    drawBoxWalls(color1[index[7]], bright1[index[7]], 0, 0, new_z[0], 3, 3, new_z[0]);
//    drawBoxWalls(color2[index[7]], bright2[index[7]], 0, 0, new_z[0], 3, 3, new_z[0]);
//
//    flushBuffer();
//    clearBuffer();
//    for (int i = 0; i < 8; i++)
//    {
//      //index[i] = index[i]==7?0:index[i]+1;
//      index[i] = (index[i] + 1) % 8;
//    }
//    delay(animationSpeed);
//  }
//}

//void chaseTheDot()
//{
//  continuePattern = true;
//  int animationSpeed = 100;
//
//  int xpos = 0;
//  int ypos = 0;
//  int zpos = 0;
//
//  while (continuePattern)
//  {
//    switch (random(0, 6))
//    {
//    case 0:
//      if (xpos > 0)
//      {
//        xpos--;
//        break;
//      }
//      else
//        color = nextColor(color);
//    case 1:
//      if (xpos < 3)
//      {
//        xpos++;
//        break;
//      }
//      else
//        color = nextColor(color);
//      xpos--;
//      break;
//
//    case 2:
//      if (ypos > 0)
//      {
//        ypos--;
//        break;
//      }
//      else
//        color = nextColor(color);
//    case 3:
//      if (ypos < 3)
//      {
//        ypos++;
//        break;
//      }
//      else
//        color = nextColor(color);
//      ypos--;
//      break;
//
//    case 4:
//      if (zpos > 0)
//      {
//        zpos--;
//        break;
//      }
//      else
//        color = nextColor(color);
//    case 5:
//      if (zpos < 3)
//      {
//        zpos++;
//        break;
//      }
//      else
//        color = nextColor(color);
//      zpos--;
//      break;
//    }
//    drawLed(color, xpos, ypos, new_z[zpos]);
//    flushBuffer();
//    clearBuffer();
//    delay(animationSpeed);
//  }
//}
//
//void planarFlop3D()
//{
//  continuePattern = true;
//  int animationSpeed = 100;
//  while (continuePattern)
//  {
//
//    for (int y = 3; y > 0; y--)
//    {
//      for (int z = 0; z < 4; z++)
//        drawLine(color, 0, 3, new_z[z], 3, y, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    for (int x = 3; x > 0; x--)
//    {
//      for (int z = 0; z < 4; z++)
//        drawLine(color, 0, 3, new_z[z], x, 0, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//
//    for (int x = 0; x < 3; x++)
//    {
//      for (int y = 0; y < 4; y++)
//        drawLine(color, 0, y, new_z[0], x, y, new_z[3]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    for (int z = 3; z > 0; z--)
//    {
//      for (int y = 0; y < 4; y++)
//        drawLine(color, 0, y, new_z[0], 3, y, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//
//    for (int z = 0; z < 3; z++)
//    {
//      for (int x = 0; x < 4; x++)
//        drawLine(color, x, 0, new_z[0], x, 3, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    for (int y = 3; y > 0; y--)
//    {
//      for (int x = 0; x < 4; x++)
//        drawLine(color, x, 0, new_z[0], x, y, new_z[3]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//
//    for (int y = 0; y < 3; y++)
//    {
//      for (int z = 0; z < 4; z++)
//        drawLine(color, 3, 0, new_z[z], 0, y, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    for (int x = 0; x < 3; x++)
//    {
//      for (int z = 0; z < 4; z++)
//        drawLine(color, 3, 0, new_z[z], x, 3, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//
//    for (int x = 3; x > 0; x--)
//    {
//      for (int y = 0; y < 4; y++)
//        drawLine(color, 3, y, new_z[3], x, y, new_z[0]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    for (int z = 0; z < 3; z++)
//    {
//      for (int y = 0; y < 4; y++)
//        drawLine(color, 3, y, new_z[3], 0, y, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//
//    for (int z = 3; z > 0; z--)
//    {
//      for (int x = 0; x < 4; x++)
//        drawLine(color, x, 3, new_z[3], x, 0, new_z[z]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    for (int y = 0; y < 3; y++)
//    {
//      for (int x = 0; x < 4; x++)
//        drawLine(color, x, 3, new_z[3], x, y, new_z[0]);
//      flushBuffer();
//      clearBuffer();
//      delay(animationSpeed);
//    }
//    color = nextColor(color);
//  }
//}

void atom(int animation_speed)
{

  int nxs = 1;
  int nys = 1;
  int nzs = 2;
  int nxf = 2;
  int nyf = 2;
  int nzf = 1;
  int b = 0;
  int s = 0;

  for (int n = 0; n < 12; n++)
  {
    if (s == 0 && b < 8)
    {
      b = b + 1;
      drawBox(color, b, nxs, nys, new_z[nzs], nxf, nyf, new_z[nzf]);
      flushBuffer();
      delay(animation_speed);
      if (b == 8)
      {
        s = 1;
      }
    }
    if (s == 1 && b > 0)
    {
      b = b - 1;
      drawBox(color, b, nxs, nys, new_z[nzs], nxf, nyf, new_z[nzf]);
      flushBuffer();
      delay(animation_speed);
      if (b == 1)
      {
        s = 0;
      }
    }
    clearBuffer();
    if (n == 0)
    {
      drawLed(blue, 1, 0, 0, new_z[1]);
      drawLed(blue, 8, 0, 1, new_z[1]);
      drawLed(green, 1, 3, 3, new_z[1]);
      drawLed(green, 8, 3, 2, new_z[1]);
      flushBuffer();
    }
    if (n == 1)
    {
      drawLed(blue, 1, 0, 1, new_z[1]);
      drawLed(blue, 8, 0, 2, new_z[2]);
      drawLed(green, 1, 3, 2, new_z[1]);
      drawLed(green, 8, 3, 1, new_z[2]);
      flushBuffer();
    }
    if (n == 2)
    {
      drawLed(blue, 1, 0, 2, new_z[2]);
      drawLed(blue, 8, 0, 3, new_z[2]);
      drawLed(green, 1, 3, 1, new_z[2]);
      drawLed(green, 8, 3, 0, new_z[2]);
      flushBuffer();
    }
    if (n == 3)
    {
      drawLed(blue, 1, 0, 3, new_z[2]);
      drawLed(blue, 8, 1, 3, new_z[3]);
      drawLed(green, 1, 3, 0, new_z[2]);
      drawLed(green, 8, 2, 0, new_z[3]);
      flushBuffer();
    }
    if (n == 4)
    {
      drawLed(blue, 1, 1, 3, new_z[3]);
      drawLed(blue, 8, 2, 3, new_z[3]);
      drawLed(green, 1, 2, 0, new_z[3]);
      drawLed(green, 8, 1, 0, new_z[3]);
      flushBuffer();
    }
    if (n == 5)
    {
      drawLed(blue, 1, 2, 3, new_z[3]);
      drawLed(blue, 8, 3, 3, new_z[2]);
      drawLed(green, 1, 1, 0, new_z[3]);
      drawLed(green, 8, 0, 0, new_z[2]);
      flushBuffer();
    }
    if (n == 6)
    {
      drawLed(blue, 1, 3, 3, new_z[2]);
      drawLed(blue, 8, 3, 2, new_z[2]);
      drawLed(green, 1, 0, 0, new_z[2]);
      drawLed(green, 8, 0, 1, new_z[2]);
      flushBuffer();
    }
    if (n == 7)
    {
      drawLed(blue, 1, 3, 2, new_z[2]);
      drawLed(blue, 8, 3, 1, new_z[1]);
      drawLed(green, 1, 0, 1, new_z[2]);
      drawLed(green, 8, 0, 2, new_z[1]);
      flushBuffer();
    }
    if (n == 8)
    {
      drawLed(blue, 1, 3, 1, new_z[1]);
      drawLed(blue, 8, 3, 0, new_z[1]);
      drawLed(green, 1, 0, 2, new_z[1]);
      drawLed(green, 8, 0, 3, new_z[1]);
      flushBuffer();
    }
    if (n == 9)
    {
      drawLed(blue, 1, 3, 0, new_z[1]);
      drawLed(blue, 8, 2, 0, new_z[0]);
      drawLed(green, 1, 0, 3, new_z[1]);
      drawLed(green, 8, 1, 3, new_z[0]);
      flushBuffer();
    }
    if (n == 10)
    {
      drawLed(blue, 1, 2, 0, new_z[0]);
      drawLed(blue, 8, 1, 0, new_z[0]);
      drawLed(green, 1, 1, 3, new_z[0]);
      drawLed(green, 8, 2, 3, new_z[0]);
      flushBuffer();
    }
    if (n == 11)
    {
      drawLed(blue, 1, 1, 0, new_z[0]);
      drawLed(blue, 8, 0, 0, new_z[1]);
      drawLed(green, 1, 2, 3, new_z[0]);
      drawLed(green, 8, 3, 3, new_z[1]);
      flushBuffer();
    }
    if (n == 12)
    {
      drawLed(blue, 1, 0, 0, new_z[1]);
      drawLed(blue, 8, 0, 1, new_z[1]);
      drawLed(green, 1, 3, 3, new_z[1]);
      drawLed(green, 8, 2, 3, new_z[1]);
      flushBuffer();
    }
  }
}
void snake(int animation_speed)
{

  int xpos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int ypos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int zpos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int countx = 0;
  int county = 0;
  int led = 0;

  for (int y = 0; y < 100; y++)
  {
    countx = 10;
    county = 9;
    for (int arr = 10; arr > 1; arr--)
    {
      countx = countx - 1;
      county = county - 1;
      xpos[countx] = xpos[county];
      ypos[countx] = ypos[county];
      zpos[countx] = zpos[county];
      drawLed(color, xpos[countx], ypos[countx], new_z[zpos[countx]]);
    }
    switch (random(0, 6))
    {
    case 0:
      if (xpos[0] > 0)
      {
        xpos[0]--;
        break;
      }
    case 1:
      if (xpos[0] < 3)
      {
        xpos[0]++;
        break;
      }
      xpos[0]--;
      break;
    case 2:
      if (ypos[0] > 0)
      {
        ypos[0]--;
        break;
      }
    case 3:
      if (ypos[0] < 3)
      {
        ypos[0]++;
        break;
      }
      ypos[0]--;
      break;
    case 4:
      if (zpos[0] > 0)
      {
        zpos[0]--;
        break;
      }
    case 5:
      if (zpos[0] < 3)
      {
        zpos[0]++;
        break;
      }
      zpos[0]--;
      break;
    }
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
  color = nextColor(color);
}

void orbit(int animation_speed)
{

  int a = 0;
  int b = 0;

  for (a = 0; a < 13; a++)
    ;
  {
    if (a = 1)
    {
      drawBoxWalls(color, 8, 1, 0, new_z[0], 1, 0, new_z[3]);
      drawBoxWalls(color - 1, 8, 0, 0, new_z[0], 0, 2, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 2)
    {
      drawBoxWalls(color, 8, 1, 0, new_z[0], 2, 0, new_z[3]);
      drawBoxWalls(color - 1, 8, 0, 0, new_z[0], 0, 1, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 3)
    {
      drawBoxWalls(color - 1, 8, 0, 0, new_z[0], 0, 0, new_z[3]);
      drawBoxWalls(color, 8, 1, 0, new_z[0], 3, 0, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 4)
    {
      drawBoxWalls(color, 8, 3, 1, new_z[0], 3, 1, new_z[3]);
      drawBoxWalls(color, 8, 1, 0, new_z[0], 3, 0, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 5)
    {
      drawBoxWalls(color, 8, 3, 1, new_z[0], 3, 2, new_z[3]);
      drawBoxWalls(color, 8, 2, 0, new_z[0], 3, 0, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 6)
    {
      drawBoxWalls(color, 8, 3, 0, new_z[0], 3, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 7)
    {
      drawBoxWalls(color, 8, 2, 3, new_z[0], 2, 3, new_z[3]);
      drawBoxWalls(color, 8, 3, 1, new_z[0], 3, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 8)
    {
      drawBoxWalls(color, 8, 2, 3, new_z[0], 1, 3, new_z[3]);
      drawBoxWalls(color, 8, 3, 2, new_z[0], 3, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 9)
    {
      drawBoxWalls(color, 8, 3, 3, new_z[0], 0, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 10)
    {
      drawBoxWalls(color, 8, 0, 2, new_z[0], 0, 2, new_z[3]);
      drawBoxWalls(color, 8, 2, 3, new_z[0], 0, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 11)
    {
      drawBoxWalls(color, 8, 0, 1, new_z[0], 0, 2, new_z[3]);
      drawBoxWalls(color, 8, 1, 3, new_z[0], 1, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 12)
    {
      drawBoxWalls(color, 8, 0, 0, new_z[0], 0, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
  }
  color = nextColor(color);
}
void planar_spin1(int animation_speed)
{

  int a = 1;
  int b = 0;
  int c = 3;
  int d = 2;
  int e = 3;
  int f = 3;
  int u = 3;
  int v = 1;
  int w = 0;
  int x = 0;
  int y = 2;
  int z = 0;
  for (int one = 1; one < 4; one++)
  {
    drawLine(color, a, b, new_z[c], d, e, new_z[f]);
    drawLine(color, u, v, new_z[w], x, y, new_z[z]);
    drawLine(color, a, b, new_z[c], u, v, new_z[w]);
    drawLine(color, d, e, new_z[f], x, y, new_z[z]);
    a = a + 1;
    d = d - 1;
    v = v + 1;
    y = y - 1;
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
  a = 3;
  b = 1;
  c = 3;
  d = 0;
  e = 2;
  f = 3;
  u = 2;
  v = 3;
  w = 0;
  x = 1;
  y = 0;
  z = 0;
  for (int two = 1; two < 4; two++)
  {
    drawLine(color, a, b, new_z[c], d, e, new_z[f]);
    drawLine(color, u, v, new_z[w], x, y, new_z[z]);
    drawLine(color, a, b, new_z[c], u, v, new_z[w]);
    drawLine(color, d, e, new_z[f], x, y, new_z[z]);
    b = b + 1;
    e = e - 1;
    u = u - 1;
    x = x + 1;
    flushBuffer();
    clearBuffer();
    delay(animation_speed);
  }
  color = nextColor(color);
}

void orbit1(int animation_speed)
{
  int a = 0;
  int b = 0;

  for (a = 0; a < 12; a++)
    ;
  {
    clearBuffer();
    if (a = 0)
    {
      drawBoxWalls(red, 5, 0, 0, new_z[0], 0, 3, new_z[3]);
      drawBoxWalls(blue, 5, 3, 0, new_z[0], 0, 3, new_z[0]);
      drawBoxWalls(green, 5, 0, 3, new_z[0], 3, 3, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 1)
    {
      drawBoxWalls(red, 5, 1, 0, new_z[0], 1, 0, new_z[3]);
      drawBoxWalls(red, 5, 0, 0, new_z[0], 0, 2, new_z[3]);
      drawBoxWalls(blue, 5, 3, 0, new_z[1], 3, 3, new_z[1]);
      drawBoxWalls(blue, 5, 1, 0, new_z[0], 3, 3, new_z[0]);
      drawBoxWalls(green, 5, 0, 2, new_z[0], 3, 2, new_z[0]);
      drawBoxWalls(green, 5, 0, 3, new_z[0], 3, 3, new_z[2]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 2)
    {
      drawBoxWalls(red, 5, 1, 0, new_z[0], 2, 0, new_z[3]);
      drawBoxWalls(red, 5, 0, 0, new_z[0], 0, 1, new_z[3]);
      drawBoxWalls(blue, 5, 3, 0, new_z[2], 3, 3, new_z[1]);
      drawBoxWalls(blue, 5, 2, 0, new_z[0], 3, 3, new_z[0]);
      drawBoxWalls(green, 5, 0, 1, new_z[0], 3, 2, new_z[0]);
      drawBoxWalls(green, 5, 0, 3, new_z[0], 3, 3, new_z[1]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 3)
    {
      drawBoxWalls(red, 5, 0, 0, new_z[0], 3, 0, new_z[3]);
      drawBoxWalls(blue, 5, 3, 0, new_z[3], 3, 3, new_z[0]);
      drawBoxWalls(green, 5, 0, 0, new_z[0], 3, 3, new_z[0]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 4)
    {
      drawBoxWalls(red, 5, 3, 1, new_z[0], 3, 1, new_z[3]);
      drawBoxWalls(red, 5, 1, 0, new_z[0], 3, 0, new_z[3]);
      drawBoxWalls(blue, 5, 2, 0, new_z[3], 2, 3, new_z[3]);
      drawBoxWalls(blue, 5, 3, 0, new_z[3], 3, 3, new_z[1]);
      drawBoxWalls(green, 5, 0, 0, new_z[1], 3, 0, new_z[1]);
      drawBoxWalls(green, 5, 0, 0, new_z[0], 3, 2, new_z[0]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 5)
    {
      drawBoxWalls(red, 5, 3, 1, new_z[0], 3, 2, new_z[3]);
      drawBoxWalls(red, 5, 2, 0, new_z[0], 3, 0, new_z[3]);
      drawBoxWalls(blue, 5, 1, 0, new_z[3], 2, 3, new_z[3]);
      drawBoxWalls(blue, 5, 3, 0, new_z[3], 3, 3, new_z[2]);
      drawBoxWalls(green, 5, 0, 0, new_z[2], 3, 0, new_z[1]);
      drawBoxWalls(green, 5, 0, 0, new_z[0], 3, 1, new_z[0]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 6)
    {
      drawBoxWalls(red, 5, 3, 0, new_z[0], 3, 3, new_z[3]);
      drawBoxWalls(blue, 5, 0, 0, new_z[3], 3, 3, new_z[3]);
      drawBoxWalls(green, 5, 0, 0, new_z[3], 3, 0, new_z[0]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 7)
    {
      drawBoxWalls(red, 5, 2, 3, new_z[0], 2, 3, new_z[3]);
      drawBoxWalls(red, 5, 3, 1, new_z[0], 3, 3, new_z[3]);
      drawBoxWalls(blue, 5, 0, 0, new_z[2], 0, 3, new_z[2]);
      drawBoxWalls(blue, 5, 0, 0, new_z[3], 2, 3, new_z[3]);
      drawBoxWalls(green, 5, 0, 1, new_z[3], 3, 1, new_z[3]);
      drawBoxWalls(green, 5, 0, 0, new_z[3], 3, 0, new_z[1]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 8)
    {
      drawBoxWalls(red, 5, 2, 3, new_z[0], 1, 3, new_z[3]);
      drawBoxWalls(red, 5, 3, 2, new_z[0], 3, 3, new_z[3]);
      drawBoxWalls(blue, 5, 0, 0, new_z[1], 0, 3, new_z[2]);
      drawBoxWalls(blue, 5, 0, 0, new_z[3], 1, 3, new_z[3]);
      drawBoxWalls(green, 5, 0, 2, new_z[3], 3, 1, new_z[3]);
      drawBoxWalls(green, 5, 0, 0, new_z[3], 3, 0, new_z[2]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 9)
    {
      drawBoxWalls(red, 5, 3, 3, new_z[0], 0, 3, new_z[3]);
      drawBoxWalls(blue, 5, 0, 0, new_z[0], 0, 3, new_z[3]);
      drawBoxWalls(green, 5, 0, 3, new_z[3], 3, 0, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 10)
    {
      drawBoxWalls(red, 5, 0, 2, new_z[0], 0, 2, new_z[3]);
      drawBoxWalls(red, 5, 2, 3, new_z[0], 0, 3, new_z[3]);
      drawBoxWalls(blue, 5, 1, 0, new_z[0], 1, 3, new_z[0]);
      drawBoxWalls(blue, 5, 0, 0, new_z[2], 0, 3, new_z[0]);
      drawBoxWalls(green, 5, 0, 3, new_z[2], 3, 3, new_z[2]);
      drawBoxWalls(green, 5, 0, 3, new_z[3], 3, 1, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
    if (a = 11)
    {
      drawBoxWalls(red, 5, 0, 1, new_z[0], 0, 2, new_z[3]);
      drawBoxWalls(red, 5, 1, 3, new_z[0], 1, 3, new_z[3]);
      drawBoxWalls(blue, 5, 2, 0, new_z[0], 1, 3, new_z[0]);
      drawBoxWalls(blue, 5, 0, 0, new_z[1], 0, 3, new_z[0]);
      drawBoxWalls(green, 5, 0, 3, new_z[1], 3, 3, new_z[2]);
      drawBoxWalls(green, 5, 0, 3, new_z[3], 3, 2, new_z[3]);
      flushBuffer();
      clearBuffer();
      delay(animation_speed);
    }
  }
}

void random_lines(int animation_speed)
{

  int x;
  int y;
  int z;

  for (int tt = random(4, 8); tt > 0; tt--)
  {
    x = random(0, 4);
    y = random(0, 4);
    z = random(0, 4);
    switch (random(0, 6))
    {
    case 0:
      z = 4;
      if (z = 4)
      {
        delay(300);
      }
      for (int i = 4; i > 0; i--)
      {
        z = z - 1;
        drawLed(color, 5, x, y, new_z[z]);
        flushBuffer();
        delay(animation_speed);
      }
      break;
    case 1:
      z = -1;
      if (z = -1)
      {
        delay(300);
      }
      for (int i = 4; i > 0; i--)
      {
        z = z + 1;
        drawLed(color, 5, x, y, new_z[z]);
        flushBuffer();
        delay(animation_speed);
      }
      break;
    case 2:
      y = 4;
      if (y = 4)
      {
        delay(300);
      }
      for (int i = 4; i > 0; i--)
      {
        y = y - 1;
        drawLed(color, 5, x, y, new_z[z]);
        flushBuffer();
        delay(animation_speed);
      }
      break;
    case 3:
      y = -1;
      if (y = -1)
      {
        delay(300);
      }
      for (int i = 4; i > 0; i--)
      {
        y = y + 1;
        drawLed(color, 5, x, y, new_z[z]);
        flushBuffer();
        delay(animation_speed);
      }
      break;
    case 4:
      x = 4;
      if (x = 4)
      {
        delay(300);
      }
      for (int i = 4; i > 0; i--)
      {
        x = x - 1;
        drawLed(color, 5, x, y, new_z[z]);
        flushBuffer();
        delay(animation_speed);
      }
      break;
    case 5:
      x = -1;
      if (x = -1)
      {
        delay(300);
      }
      for (int i = 4; i > 0; i--)
      {
        x = x + 1;
        drawLed(color, 5, x, y, new_z[z]);
        flushBuffer();
        delay(animation_speed);
      }
      break;
    }
    color = nextColor(color);
  }
  flushBuffer();
  clearBuffer();
}