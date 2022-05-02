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
    int N;
    int A[300010];
    map<int,int> hoge;
    ll ans=0;
    cin>>N;
    rep(i,N) cin>>A[i];
    for(int j=0;j<N;j++){//数列Aの要素A[j]に対して操作を行う
        ans += j - hoge[A[j]];//(全体 - 条件を満たさない個数)はつまり以下の式に等しい
        hoge[A[j]]++;//\sum(j - A[i]==A[j]となるiの個数)
    }
    cout<<ans<<endl;
    return 0;
}