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
ll Q = 1000000000+7;
ll A[100][6];

int main() {
    ll ans = 1;
    cin>>N;
    rep(i,N){
        cin>>A[i][0]>>A[i][1]>>A[i][2]>>A[i][3]>>A[i][4]>>A[i][5];
        ll sumA = A[i][0]+A[i][1]+A[i][2]+A[i][3]+A[i][4]+A[i][5];
        ans = ans*sumA%Q;
    }
    cout<<ans<<endl;
    return 0;
}