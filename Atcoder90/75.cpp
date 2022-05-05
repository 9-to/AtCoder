#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/* alias */
using ull = unsigned long long;
using ll = long long;
/* define short */
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

ll N;
//素数判定機（素因数分解機）が必要 + 浅い木構造を作る？
//ceiling(log2(a+b+c+...))で解けそう
bool isPrime(ll n){
    ll rootN = floorl(sqrt(n));
    for(ll i=2;i<=rootN;i++){
        if(n%i==0)return false;
    }
    return true;
}
ll primeFactrize(ll n){
    ll outp = 0;
    for(ll i=2;i*i<=n;++i){
        if(n%i!=0)continue;
        while(n%i==0){
            outp++;
            n /=i;
        }
    }
    if(n!=1)outp++;
    return outp;
}

int main() {
    cin>>N;
    if(isPrime(N)){
        cout<<0<<endl;
        return 0;
    }
    cout<<ceill(log2l(primeFactrize(N)))<<endl;
    return 0;
}