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

ll N,M;
ll A[100001],B[100001];
vector<ll> check;
set<ll> dup;

int main() {
    cin>>N>>M;
    rep(i,M)cin>>A[i]>>B[i];
    rep(i,M){
        ll a = A[i];
        ll b = B[i];
        if(a<b)swap(a,b);//a>bに揃える
        auto it = find(all(check),a);
        if(it != check.end()){
            dup.insert(a);
        }else{
            check.push_back(a);
        }
    }
    cout<<check.size()-dup.size()<<endl;
    return 0;
}