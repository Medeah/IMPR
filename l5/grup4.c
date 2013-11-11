#include <stdio.h>
#include <assert.h>

unsigned int make_pixel(int red, int green, int blue){
  assert(0 <= red && red <= 255);
  assert(0 <= blue && blue <= 255);
  assert(0 <= blue && blue <= 255);
  unsigned int out = 0;
  out += blue;
  out += green << 8;
  out += red << 16;
  out += 0x01 << 24;
  return out;
}


int get_red(unsigned int p) {
  return (p & 0xFF0000) >> 16;
}
int get_green(unsigned int p){
  return (p & 0x00FF00) >> 8;
}
int get_blue(unsigned int p) {
  return p & 0x0000FF;
}

int main(void) {
  assert(sizeof(unsigned int) == 4);
  assert(make_pixel(0, 0, 0) == 0x1000000);
  assert(make_pixel(0, 64, 64) == 0x1004040);
  assert(make_pixel(128, 0, 0) == 0x1800000);
  assert(make_pixel(0xba, 0xda, 0x55) == 0x1BADA55);
  assert(get_red(make_pixel(0, 0, 0)) == 0);
  assert(get_blue(make_pixel(255, 255, 0)) == 0);
  assert(get_green(make_pixel(1, 0, 1)) == 0);
  assert(get_red(make_pixel(34, 56, 78)) == 34);
  assert(get_green(make_pixel(34, 198, 0)) == 198);
  assert(get_blue(make_pixel(34, 172, 235)) == 235);

  //printf("0x%x\n", make_pixel(0, 0, 0));
  return 0;
}