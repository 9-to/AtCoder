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

ll f(ll a){
    int c[11]={};
    while(a!=0){
        c[a%10]++;//[0-9]の箱を用意してカウント
        a/=10;
    }
    ll g1=0, g2=0;
    for(int i=9;i>=0;i--){//高々100ループ
        for(int j=0;j<c[i];j++)g1=g1*10+i;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<c[i];j++)g2=g2*10+i;
    }
    return g1-g2;
}


int main() {
    ll N,K;
    cin>>N>>K;
    rep(i,K)N=f(N);//K<10^5なのでループは単純にできる
    cout<<N<<endl;
    return 0;
}