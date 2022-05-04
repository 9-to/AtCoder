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
ll A[46]={0},B[46]={0},C[46]={0};

int main() {
    ll cnt=0;
    cin>>N;
    rep(i,N){
        ll tmp;
        cin>>tmp;
        tmp %= 46;
        A[tmp] += 1;
    }
    rep(i,N){
        ll tmp;
        cin>>tmp;
        tmp %= 46;
        B[tmp] += 1;
    }
    rep(i,N){
        ll tmp;
        cin>>tmp;
        tmp %= 46;
        C[tmp] += 1;
    }
    rep(a,46){
        rep(b,46){
            rep(c,46){
                if((a+b+c)%46==0){
                    cnt += A[a]*B[b]*C[c];
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}