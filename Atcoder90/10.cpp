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
ll C[100003],P[100003],L[100003],R[100003];
//累積和を取る?
ll C1[100003]={0},C2[100003]={0};


int main() {
    cin>>N;
    for(ll i=1;i<=N;i++){//1~N
        cin>>C[i]>>P[i];
        C1[i] = C1[i-1];
        C2[i] = C2[i-1];
        if(C[i]==1)C1[i] += P[i];
        else C2[i] += P[i];
    }
    cin>>Q;
    rep(i,Q)cin>>L[i]>>R[i];//0~Q-1
    rep(i,Q){
        cout<<C1[R[i]]-C1[L[i]-1]<<" "<<C2[R[i]]-C2[L[i]-1]<<endl;
    }
    return 0;
}