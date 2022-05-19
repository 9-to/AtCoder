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

ll K;
ll a[1<<18];
ll Q = 1000000000+7;
//9の倍数は各桁の和が9の倍数になる
//格桁の合計はKになる
//->9の倍数かつKになれば良い

int main() {
    cin>>K;
    ll dp[K+1]={0};//DP[各桁の数字の和]=通り数
    dp[0]=1;
    if(K%9!=0){
        cout<<0<<endl;
        return 0;
    }
    rrep(i,K){
        ll B = min(i,9LL);
        rrep(j,B){
            dp[i] += dp[i-j];
            dp[i] %= Q;
        }
    }
    cout<<dp[K]<<endl;
    return 0;
}