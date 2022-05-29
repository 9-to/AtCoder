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

ll N,ans;
vector<ll> X,Y;//座標
//重心になる？


int main() {
    //input
    cin>>N;
    rep(i,N){
        ll x,y;
        cin>>x>>y;
        X.push_back(x);
        Y.push_back(y);
    }
    sort(all(X));
    sort(all(Y));
    //calc
    ans = 0;
    ll wx,wy;
    if(N%2==1){
        wx = X[N/2];
        wy = Y[N/2];
    }else{
        wx = (X[N/2]+X[N/2-1])/2;
        wy = (Y[N/2]+Y[N/2-1])/2;
    }
    //cout<<wx<<wy<<endl;
    rep(i,N){
        ans += abs(wx-X[i]);
        ans += abs(wy-Y[i]);
    }
    //output
    cout<<ans<<endl;
    return 0;
}