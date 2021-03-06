#include <iostream>
#define BODY_N  3
#define STATE_N 8

int nthSigma(int state, int n){
  return state >> n & 1;
}

int productOfIthAndJthSigma(int state, int i, int j){
  if(nthSigma(state, i) == nthSigma(state, j)){
    return 1;
  }else{
    return -1;
  }
}

int main(){

  int hamiltonian[STATE_N][STATE_N];

  for(int i = 0; i < STATE_N; ++i){
    for(int j = 0; j < STATE_N; ++j){
      hamiltonian[i][j] = 0;
    }
  }

  for(int i = 0; i < STATE_N; ++i){
    for(int j = 0; j < STATE_N; ++j){
      if(i == j){
        for(int n = 0; n < BODY_N - 1; ++n){
          hamiltonian[i][j] += productOfIthAndJthSigma(i, n, n + 1);
        }
      }
    }
  }

  for(int i = 0; i < STATE_N; ++i){
    for(int j = 0; j < STATE_N; ++j){
      std::cout << i << ", " << j << " = " << hamiltonian[i][j] << std::endl;
    }
  }

  return 0;
}
