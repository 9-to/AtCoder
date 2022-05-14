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
string S;
char o = 'o';
char x = 'x';
//stringを扱う問題わからなすぎ

int main() {
    cin>>N;
    cin>>S;
    vector<ll> O,X;
    ll ans = 0;
    rep(i,N){
        if(S[i]==o)O.push_back(i);
        else X.push_back(i);
    }
    rep(i,N){
        char s = S[i];
        if(s==o){
            decltype(X)::iterator it = lower_bound(all(X),i);
            if(it!=X.end())ans += N- *it;
        }else{
            decltype(O)::iterator it = lower_bound(all(O),i);
            if(it!=O.end())ans += N- *it;
        }
    }
    cout<<ans<<endl;
    return 0;
}