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

ll N,Q,B;
vector<ll>  A;

int main() {
    cin>>N;
    rep(i,N){
        ll tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    sort(all(A));
    cin>>Q;
    rep(i,Q){
        cin>>B;
        decltype(A)::iterator it = lower_bound(all(A),B);
        ll ans;
        if(it !=A.end()){
            ll pos = distance(A.begin(),it);
            ll a = abs(B- *it);
            if(pos!=0){
                ll b = abs(B-A[pos-1]);
                if(b<a) a = b;
            }
            ans = a;
        }else{
            ans = abs(B-A[N-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}