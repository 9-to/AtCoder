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
ll lx[100000],ly[1000000],rx[100000],ry[100000];
ll ans[1000000]={};//
ll f[1003][1003]={};//field

int main() {
    cin>>N;
    rep(i,N)cin>>lx[i]>>ly[i]>>rx[i]>>ry[i];
    rep(i,N){
        f[lx[i]][ly[i]] += 1;
        f[rx[i]][ry[i]] += 1;
        f[lx[i]][ry[i]] -= 1;
        f[rx[i]][ly[i]] -= 1;
    }
    rep(i,1001){//累積和をとる
        rrep(j,1000){
            f[i][j] += f[i][j-1];
        }
    }
    rep(i,1001){//累積和をとる
        rrep(j,1000){
            f[j][i] += f[j-1][i];
        }
    }
    rep(i,1001){
        rep(j,1001){
            if (f[i][j] >= 1) ans[f[i][j]] +=1;
        }
    }
    
    
    rrep(i,N)cout<<ans[i]<<endl;
    return 0;
}