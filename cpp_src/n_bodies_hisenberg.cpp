#include <iostream>
#include <bitset>
#define BODY_N 2
#define STATE_N 4

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
  int hamiltonian[STATE_N][STATE_N];

  for(int i = 0; i < STATE_N; ++i){
    for(int j = 0; j < STATE_N; ++j){
      hamiltonian[i][j] = 0;
    }
  }


  for(int i = 0; i < STATE_N; ++i){
    for(int n = 0; n < BODY_N - 1; ++n){
      int state;

      if(nthSpinZ(i, n + 1) == nthSpinZ(i, n)){
        hamiltonian[i][i] += 1;
      }else{
        hamiltonian[i][i] -= 1;
      }

      if(nthSpinIsAbleToApplyUp(i, n + 1) && nthSpinIsAbleToApplyDown(i, n)){
        state = nthSpinUpOperator(i, n + 1);
        state = nthSpinDownOperator(state, n);

        hamiltonian[i][state] -= 2;
      }else if(nthSpinIsAbleToApplyDown(i, n + 1) && nthSpinIsAbleToApplyUp(i, n)){
        state = nthSpinDownOperator(i, n + 1);
        state = nthSpinUpOperator(state, n);

        hamiltonian[i][state] -= 2;
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
