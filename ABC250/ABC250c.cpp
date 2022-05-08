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

ll N,Q;
//ABC_C


int main() {
    cin>>N>>Q;
    vector<ll> val(N+1),pos(N+1);
    rrep(i,N){
        pos[i] = i;
        val[i] = i;
    }
    rep(i,Q){
        ll x;
        cin>>x;
        ll p0 = pos[x];
        ll p1 = p0;
        if(p0!=N)p1++;
        else p1--;
        ll v0 = val[p0];//v0==x
        ll v1 = val[p1];
        swap(val[p0],val[p1]);
        swap(pos[v0],pos[v1]);
    }
    rrep(i,N){
        if(i!=1)cout<<" ";
        cout<<val[i];
    }
    cout<<endl;
    return 0;
}