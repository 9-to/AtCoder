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
deque<ll> A;

int main() {
    cin>>N>>Q;
    rep(i,N){
        ll tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    rep(i,Q){
        ll t,x,y;
        cin>>t>>x>>y;
        x--;y--;
        if(t==1){
            ll tmp = A[x];
            A[x] = A[y];
            A[y] = tmp;
        }else if(t==2){
            ll tmp = A[A.size()-1];
            A.pop_back();
            A.push_front(tmp);
        }else if(t==3){
            cout<<A[x]<<endl;
        }
    }
    return 0;
}