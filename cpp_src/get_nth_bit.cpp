#include <iostream>

int getNthBit(int i, int n){
  return i >> n & 0b1;
}

int main(){

  int a = 0b0001;
  int b = 0b0010;
  int c = 0b0011;
  int d = 0b0100;
  int e = 0b0101;
  int f = 0b0110;
  int g = 0b0111;

  std::cout << getNthBit(a, 2) << std::endl;

  return 0;
}
