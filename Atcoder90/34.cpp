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

ll N,K;
ll a[1<<18];
//しゃくとり法っぽい
ll maxlen = 0;
map<ll,ll> Map;


int main() {
    cin>>N>>K;
    rrep(i,N)cin>>a[i];
    ll r=1, cnt=0;
    rrep(i,N){
        while(r<=N){
            if(Map[a[r]]==0 && cnt==K)break;//参照位置の出現数が0(新しい数字)、かつ、部分列出現が既にK種類
            if(Map[a[r]]==0)cnt++;          //参照位置の出現数が0(新しい数字)
            Map[a[r]] +=1;
            r++;
        }
        maxlen = max(maxlen,r-i);
        if(Map[a[i]]==1)cnt--;
        Map[a[i]] -= 1;
    }
    cout<<maxlen<<endl;
    return 0;
}