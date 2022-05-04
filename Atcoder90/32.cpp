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
ll A[11][11];

int main() {
    ll ans =LLONG_MAX;
    cin>>N;
    vector<vector<ll>> X(N);
    vector<ll> P;
    rep(i,N){
        rep(j,N){
            cin>>A[i][j];
        }
        P.push_back(i);
    }
    cin>>M;
    rep(i,M){
        ll tmpx,tmpy;
        cin>>tmpx>>tmpy;
        tmpx--; tmpy--;
        X[tmpx].push_back(tmpy);
        X[tmpy].push_back(tmpx);
    }
    do{
        ll tmp = 0;
        bool flag=true;
        rep(i,N){
            //cout<<P[i]<<" ";
            tmp += A[P[i]][i];
            if(i!=0){
                if(X[P[i]].size()!=0){
                    for(auto x:X[P[i]]){
                        if(x==P[i-1])flag=false;
                    }
                }
            }
        }
        //cout<<endl;
        if(flag==true)ans=min(tmp,ans);
    }while(next_permutation(all(P)));
    if(ans==LLONG_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}