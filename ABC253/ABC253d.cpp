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

ull N,A,B;

int main() {
    cin>>N>>A>>B;
    if(A>B)swap(A,B);
    ull ans=0;
    if(A==1 || B==1){
        cout<<ans<<endl;
        return 0;
    }
    ans = (N*(N+1))/2;
    ull tmp=A;
    ull ansminus=0;
    while(tmp+A<=N){
        tmp +=A;
    }
    if(A<=N)ans -= (tmp+A)*(tmp/A)/2;
    //cout<<tmp<<endl;
    if(B%A!=0){
        ull c = lcm(A,B);
        tmp = c;
        while(tmp+c<=N){
            tmp +=c;
        }
        //cout<<tmp<<endl;
        if(c<=N)ans += (tmp+c)*(tmp/c)/2;

        tmp=B;
        while(tmp+B<=N){
            tmp +=B;
        }
        if(B<=N)ans -= (tmp+B)*(tmp/B)/2;
    }

    cout<<ans-ansminus<<endl;
    return 0;
}