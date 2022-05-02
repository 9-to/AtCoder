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

int main() {

    ll N,K,ans=0;
     vector<pair<ll, ll>>A,B;
    cin>>N>>K;
    rep(i,N){
        ll tmp;
        cin>>tmp;
        A.push_back({tmp,i});
    }
    sort(all(A));
    //rep(i,N)cout<<A[i].first<<A[i].second<<endl;
    ll cand = K/N,procand = K%N;
    rep(i,N){
        if(i<procand){
            B.push_back({A[i].second,cand+1});
        }else{
            B.push_back({A[i].second,cand});
        }
    }
    sort(all(B));
    rep(i,N) cout<<B[i].second<<endl;
    return 0;
}