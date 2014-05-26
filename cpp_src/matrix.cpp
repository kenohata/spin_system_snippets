#include <iostream>
#include <bitset>
#define N 4

int main(){
  float m[N][N];

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      m[i][j] = i * 10 + j;
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      std::cout << i << ", " << j << " = " << m[i][j] << std::endl;
    }
  }

  return 0;
}
