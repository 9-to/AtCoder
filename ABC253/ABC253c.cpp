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

ll Q;
map<ll,ll> Map;

int main() {
    cin>>Q;
    rep(i,Q){
        ll ty;
        cin>>ty;
        if(ty==1){
            ll x;
            cin>>x;
            Map[x] += 1;
        }else if(ty==2){
            ll x,c;
            cin>>x>>c;
            ll minN = min(c,Map[x]);
            Map[x] -= minN;
            if(Map[x]==0)Map.erase(x);
        }else if(ty==3){
            cout<<Map.rbegin()->first-Map.begin()->first<<endl;
        }
    }
}