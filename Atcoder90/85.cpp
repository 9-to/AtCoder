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

ll K,ans=0;
vector<ll> v,p;
//全探索っぽいO(2^16*2^16)

int main() {
    //input
    cin>>K;
    //calc
    for(ll i=1;i*i<=K;i++){//10^6
        if(K%i==0)v.push_back(i);//約数を追加
    }
    for(auto x:v){
        p.push_back(x);
        if(K%x==0 && x!=K/x)p.push_back(K/x);
    }
    sort(all(p));
    //for(auto i:p)cout<<i<<endl;
    ll len = p.size();
    for(ll a=0;a<len;a++){
        for(ll b=a;b<len;b++){
            ll c = (K/p[a])/p[b];
            if(c<p[b] || (K/p[a])%p[b]!=0)continue;
            //auto it = lower_bound(all(p),c);
            //if(*it==c && it!=p.end()){
                ans++;
                //cout<<p[a]<<p[b]<<c<<endl;
            //}
        }
    }
    //output
    cout<<ans<<endl;
    return 0;
}