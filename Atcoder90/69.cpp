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

ll N,K;
ll Q = 1000000000+7;
//K*(K-1)*(K-2)*...*(K-2)となりそう
//powについて効率よくループを回したい(10^18はTLEになる)

ll powQ(ll x, ll n){
    if(n==0) return 1;
    if(n%2==0)return powQ(x*x%Q,n/2);
    else return x*powQ(x*x%Q,n/2)%Q;
}

int main() {
    cin>>N>>K;
    if(N==1)cout<<K<<endl;
    else if(N==2){
        cout<<K*(K-1)%Q<<endl;
    }else{
        cout<<K*(K-1)%Q*powQ(K-2,N-2)%Q<<endl;
    }
    return 0;
}