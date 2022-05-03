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

ll N,A,B,C;
//貪欲法っぽい
//->貪欲法では解けない->DP法っぽい？


int main() {
    cin>>N;
    cin>>A>>B>>C;
    ll L = 9999;
    ll minN=LLONG_MAX;
    for(ll a=0;a<=L;a++){
        for(ll b=0;a+b<=L;b++){
            ll c = (N-a*A-b*B)/C;
            if(a*A+b*B+c*C==N && c>=0)minN = min(a+b+c,minN);
        }
    }
    cout<<minN<<endl;
    return 0;
}