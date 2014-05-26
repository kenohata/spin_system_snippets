#include <iostream>
#include <bitset>

int nthSpinZ(int vector, int n){
  return vector >> n & 1;
}

bool nthSpinIsAbleToApplyUp(int vector, int n){
  return nthSpinZ(vector, n) == 0;
}

bool nthSpinIsAbleToApplyDown(int vector, int n){
  return nthSpinZ(vector, n) == 1;
}

int nthSpinUpOperator(int vector, int n){
  return vector + (1 << n);
}

int nthSpinDownOperator(int vector, int n){
  return vector - (1 << n);
}

int main(){

  int vector = 0b10101010;

  std::cout << std::bitset<8>(vector) << std::endl;
  std::cout << std::bitset<8>(nthSpinIsAbleToApplyUp(vector, 0)) << std::endl;
  std::cout << std::bitset<8>(nthSpinUpOperator(vector, 0)) << std::endl;

  return 0;
}
