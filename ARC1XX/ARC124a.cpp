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

    ll N,K,ans=1, pro=998244353,first, tmp;
    vector<pair<ll, char>> KC;
    char second;
    ll num[1001];
    cin>>N>>K;
    rep(i,N) num[i+1]=0;
    rep(i,K){
        cin>>second>>first;
        KC.push_back({first,second});
    }
    sort(all(KC));
    rep(i,K){
        ll k = KC[i].first;
        char c = KC[i].second;
        if(num[k]== -1){
            cout<<0<<endl;
            return 0;
        }
        num[k] = -1;
    }
    rep(i,K){
        ll k = KC[i].first;
        char c = KC[i].second;
        if(c == 'L'){
            for(int j=k+1;j<=N;j++){
                if(num[j] != -1) num[j]++;
            }
        }else if(c == 'R'){
            for(int j=1;j<k;j++){
                if(num[j] != -1) num[j]++;
            }
        }
    }
    rep(i,N){
        if(num[i+1] == -1) num[i+1]=1;
    }
    rep(i,N){
        ans = ans*num[i+1]%pro;
    }
    cout<<ans<<endl;
    return 0;
}