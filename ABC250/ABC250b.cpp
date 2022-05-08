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

ll N,A,B;
char d = '.';//true;
char s = '#';//false;

int main() {
    cin>>N>>A>>B;
    bool flag = true;
    if(N==1){
        rep(i,A){
            rep(j,B){
                cout<<d;
            }
            cout<<endl;
        }
        return 0;
    }
    string D = "",S = "",Mtrue = "",Mfalse = "";
    rep(i,B){
        D = D + d;
        S = S + s;
    }
    rep(j,N){
        if(j%2==0){
            Mtrue = Mtrue + D;
            Mfalse = Mfalse + S;
        }else{
            Mtrue = Mtrue + S;
            Mfalse = Mfalse + D;
        }
    }
    ll cnt = 0;
    rep(i,N*A){
        if(flag){
            cout<<Mtrue<<endl;
        }else{
            cout<<Mfalse<<endl;
        }
        cnt++;
        if(cnt == A){
            cnt=0;
            flag = !flag;
        }

    }
    return 0;
}