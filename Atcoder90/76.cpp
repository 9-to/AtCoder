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

int main() {
    cin>>N;
    vector<ll> M(N+1,0);
    vector<ll> B(N*2+1,0);
    ll allsum = 0;
    rrep(i,N){
        cin>>M[i];
        allsum += M[i];
        B[i] = allsum;
    }
    ll tmp = allsum;
    rrep(i,N){
        tmp += M[i];
        B[i+N] = tmp;
    }
    if(allsum%10!=0){
        cout<<"No"<<endl;
        return 0;
    }
    ll part10 = allsum/10;
    rrep(i,N){
        decltype(B)::iterator it = lower_bound(all(B),B[i-1]+part10);
        if(*it-B[i-1]==part10){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}