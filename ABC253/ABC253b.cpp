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

ll H,W;
string S[110];

int main() {
    cin>>H>>W;
    rep(i,H)cin>>S[i];
    vector<ll> X,Y;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='o'){
                X.push_back(i);
                Y.push_back(j);
            }
        }
    }
    cout<<abs(X[0]-X[1])+abs(Y[0]-Y[1])<<endl;
    return 0;
}