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
    ll N,t[2010],l[2010],r[2010],ans=0;
    cin>>N;
    rep(i,N) cin>>t[i]>>l[i]>>r[i];
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(l[j]<l[i] && r[j]<l[i]) continue;
            if(r[i]<l[j] && r[i]<r[j]) continue;
            if(l[i]==r[j]){
                if(t[j]==4 || t[j]==2) continue;
                if(t[i]==3 || t[i]==4) continue;
            }
            if(r[i]==l[j]){
                if(t[j]==3 || t[j]==4) continue;
                if(t[i]==2 || t[i]==4) continue;
            }
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}