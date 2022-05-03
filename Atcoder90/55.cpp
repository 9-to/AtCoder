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

ll N,P,Q;
ll A[1<<18];
//何もわからん

int main() {
    ll ans = 0; 
    cin>>N>>P>>Q;
    rep(i,N)cin>>A[i];
    rep(i,N){
        ll a1 = A[i];
        reps(j,i+1,N){
            ll a2 = A[j];
            reps(k,j+1,N){
                ll a3 = A[k];
                reps(l,k+1,N){
                    ll a4 = A[l];
                    reps(m,l+1,N){
                        ll a5 = A[m];
                        if(a1*a2%P*a3%P*a4%P*a5%P == Q)ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}