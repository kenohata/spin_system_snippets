# n_bodies_ising

n体イジング模型を実装する。

nthSigma関数、productOfIthAndJthSigma関数は2体イジングの時からコピペで持ってきてもよい。

2^n次の正方行列を定義して、2重ループの中で、ボンドの数だけproductOfIthAndJthSigma関数を適用していく。

イジング模型には状態ベクトルの方向を変化させる演算子が無いので、つきつめれば行列にする必要はないが、あとでハイゼンベルク模型の計算もするので、同じ方法が適用できるように、このように行列を用いる。

行列操作のためにi, jの2重ループをまず作り、その中でイジング模型のサムネーションのためのnのループがある。

状態を表す整数がどこにも無いように見えるかもしれないが、実は行列の添字のiが系の状態を表している。例えば2体系で考えると、行列は4次の正方行列となり、添字は0, 1, 2, 3となるが、これらの添字は2進数表記では00, 01, 10, 11となるので、この数を状態を表す量として利用する。