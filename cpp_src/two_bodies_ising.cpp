#include <iostream>
#include <bitset>

int nthSpinZ(int vector, int n){
  return vector >> n & 1;
}

int productOfIthAndJthSigma(int vector, int i, int j){
  if(nthSpinZ(vector, i) == nthSpinZ(vector, j)){
    return 1;
  }else{
    return -1;
  }
}

int main(){

  int a = 0b00;
  int b = 0b01;
  int c = 0b10;
  int d = 0b11;

  std::cout << productOfIthAndJthSigma(a, 0, 1) << std::endl;
  std::cout << productOfIthAndJthSigma(b, 0, 1) << std::endl;
  std::cout << productOfIthAndJthSigma(c, 0, 1) << std::endl;
  std::cout << productOfIthAndJthSigma(d, 0, 1) << std::endl;

  return 0;
}
