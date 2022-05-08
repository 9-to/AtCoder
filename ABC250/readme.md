## A
場合分けはWAが発生しやすい（実際発生した）
上下左右にマスがあるものが真である数を数える
## B
縦横を間違えて出力してた
## C
O(NQ)の実装をしてTLE
`val[i]`で実際の配列だけでなく、`pos[v]`でボール`v`左から何番目かを管理する配列を用意すればO(Q)で計算できるようになる。

## D
###　素数リストの作り方
```C++
void construct_plist(){
  vector<bool> fl(MAXP,false);
  for(int i=2;i<MAXP;i++){
    if(fl[i]){continue;}//trueなら以下省略
    prime_list.push_back(i);
    for(int j=i;j<MAXP;j+=i){fl[j]=true;}//倍数を全てtrueにする
  }
}
```
### しゃくとり法で数え上げ
```C++
 long long res=0;
  int sz=prime_list.size();
  int q=sz-1;
  for(int p=0;p<sz;p++){
    while(p<q && f(prime_list[p],prime_list[q])>n){q--;}
    if(p>=q){break;}
    res+=(q-p);
  }
```