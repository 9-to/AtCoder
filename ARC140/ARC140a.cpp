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

ll N,K,ans=2001;
string S;
vector<ll> V[100002];

int main() {
    cin>>N>>K;
    cin>>S;
    rrep(len,N/2){//1000, i=length
        ll cnt=0;
        for(ll i=0;i<len;i++){
            vector<ll> s(255,0);
            ll jcnt=0;
            for(ll j=0;j<N/len;j++){
                jcnt++;
                s[S[j*len+i]] += 1;
            }
            auto p = minmax_element(all(s));
            cnt += jcnt - *p.second;
        }
        if(cnt<=K && N%len==0)ans = min(ans,len);
        else ans = min(ans,N);
    }
    if(N!=1)cout<<ans<<endl;
    else cout<<1<<endl;
    return 0;
}