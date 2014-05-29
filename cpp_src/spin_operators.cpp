#include <iostream>
#include <bitset>

int nthSpinZ(int state, int n){
  return state >> n & 1;
}

bool nthSpinIsAbleToApplyUp(int state, int n){
  return nthSpinZ(state, n) == 0;
}

bool nthSpinIsAbleToApplyDown(int state, int n){
  return nthSpinZ(state, n) == 1;
}

int nthSpinUpOperator(int state, int n){
  return state + (1 << n);
}

int nthSpinDownOperator(int state, int n){
  return state - (1 << n);
}

int main(){

  int state = 0b10101010;

  std::cout << std::bitset<8>(state) << std::endl;
  std::cout << std::bitset<8>(nthSpinIsAbleToApplyUp(state, 0)) << std::endl;
  std::cout << std::bitset<8>(nthSpinUpOperator(state, 0)) << std::endl;

  return 0;
}
