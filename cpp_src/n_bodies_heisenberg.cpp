#include <iostream>
#include <bitset>
#define BODY_N 2
#define STATE_N 4

int nthSigma(int state, int n){
  return state >> n & 1;
}

bool nthSpinIsAbleToApplyUp(int state, int n){
  return nthSigma(state, n) == 0;
}

bool nthSpinIsAbleToApplyDown(int state, int n){
  return nthSigma(state, n) == 1;
}

int nthSpinUpOperator(int state, int n){
  return state + (1 << n);
}

int nthSpinDownOperator(int state, int n){
  return state - (1 << n);
}

int main(){
  float hamiltonian[STATE_N][STATE_N];

  for(int i = 0; i < STATE_N; ++i){
    for(int j = 0; j < STATE_N; ++j){
      hamiltonian[i][j] = 0.0;
    }
  }


  for(int i = 0; i < STATE_N; ++i){
    for(int n = 0; n < BODY_N - 1; ++n){
      int state;

      if(nthSigma(i, n + 1) == nthSigma(i, n)){
        hamiltonian[i][i] += 0.25;
      }else{
        hamiltonian[i][i] -= 0.25;
      }

      if(nthSpinIsAbleToApplyUp(i, n + 1) && nthSpinIsAbleToApplyDown(i, n)){
        state = nthSpinUpOperator(i, n + 1);
        state = nthSpinDownOperator(state, n);

        hamiltonian[i][state] -= 0.5;
      }else if(nthSpinIsAbleToApplyDown(i, n + 1) && nthSpinIsAbleToApplyUp(i, n)){
        state = nthSpinDownOperator(i, n + 1);
        state = nthSpinUpOperator(state, n);

        hamiltonian[i][state] -= 0.5;
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
