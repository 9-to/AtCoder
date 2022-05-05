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
ll A[102][102],B[102][102],V[102][102];


int main() {
    cin>>H>>W;
    ll p=0,m=0;
    rep(i,H){
        rep(j,W)cin>>A[i][j];
    }
    rep(i,H){
        rep(j,W){
            cin>>B[i][j];
            V[i][j] = A[i][j]-B[i][j];//V=A-B
        }
    }
    ll cnt =0;
    rep(i,H-1){
        rep(j,W-1){
            if(V[i][j]!=0){
                ll tmp = V[i][j];
                V[i+1][j+1] -= tmp;
                V[i+1][j]   -= tmp;
                V[i][j+1]   -= tmp;
                V[i][j]     -= tmp;
                cnt += abs(tmp);
            }
        }
    }
    bool flag = true;
    rep(i,H){
        if(V[i][W-1]!=0)flag = false;
    }
    rep(i,W){
        if(V[H-1][i]!=0)flag = false;
    }
    if(flag){
        cout<<"Yes"<<endl;
        cout<<cnt<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}