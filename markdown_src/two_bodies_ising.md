# two_bodies_ising

ここでは実際の物理的な意味とか価値とかは考えないことにして、2体のイジング模型の固有値を求めてみる。

前項のnthSigma関数を使って、イジング模型の中身の隣接シグマ演算子の積に対応する関数を定義する。それが、productOfIthAndJthSigma関数だ。状態とiとjを引数にとり、i番目とj番目のシグマ演算子の値が同じなら1、違えば-1を返す関数である。(今回は2体問題なので、iとjは0, 1にしかならないのだが)

2体のスピン系の状態として、00, 01, 10, 11を用意して、それぞれにproductOfIthAndJthSigmaを適用すると、答えは1, -1, -1, 1となるはずである。

こんなものは手で計算しても全く問題ないので、系をもっと大きくしたいが、その前に行列の操作を次項で練習する。その後、n体のイジング模型を計算する。
