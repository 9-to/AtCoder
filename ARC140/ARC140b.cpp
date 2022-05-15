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

ll N,ans=0;
string S;

int main() {
    cin>>N;
    cin>>S;
    ll xsum=0,m=0;
    for(ll i=1;i<N;i++){
        if(S.substr(i-1,3)=="ARC"){
            ll l = i-1;
            ll r = i+1;
            while(l-1>=0 && S[l-1]=='A')l--;
            while(r+1<N && S[r+1]=='C') r++;
            ll x = min(i-l,r-i);
            xsum += x;
            m++;
        }
    }
    cout<<min(xsum,m*2)<<endl;
    return 0;
}