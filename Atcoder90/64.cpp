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

int main() {
    cin>>N>>Q;
    vector<ll> A(100006);
    vector<ll> B(100006);
    ll ans = 0;
    rrep(i,N)cin>>A[i];//1~N
    rrep(i,N-1){//1~N-1
        B[i] = A[i+1]-A[i];
        ans += abs(B[i]);
    }
    rrep(i,Q){
        ll l,r,v;
        cin>>l>>r>>v;
        ll before = abs(B[l-1])+abs(B[r]);
        if(l>=2)B[l-1] += v;
        if(r<=N-1) B[r] -=v;
        ll after = abs(B[l-1])+abs(B[r]);
        ans += (after-before);
        cout<<ans<<endl;
    }
    return 0;
}