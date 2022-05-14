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

ll N,W;

int main() {
    cin>>N>>W;
    ll cnt=0;
    vector<ll> a(N);
    map<ll,ll> ans;
    rep(i,N)cin>>a[i];
    a.push_back(0);
    a.push_back(0);
    for(ll i=0; i<N+2; i++){
        for(ll j=i+1;j<N+2;j++){
            for(ll k=j+1;k<N+2;k++){
                if(a[i]+a[k]+a[j]<=W && a[i]+a[j]+a[k]>0){
                    //cout<<":"<<i+j+k<<endl;
                    ans.insert({a[i]+a[j]+a[k],a[i]+a[j]+a[k]});
                }
            }
        }
    }
    //rep(i,ans.size())cout<<ans[i]<<"hoge"<<endl;
    cout<<ans.size()<<endl;
    return 0;
}