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

ll A,B;
string L = "Large";

ll llsize(ll n){
    ll cnt=0;
    while(n!=0){
        n/=10;
        cnt++;
    }
    return cnt;
}

int main() {
    cin>>A>>B;
    if(B>A)swap(A,B);
    ll bsize = llsize(B);
    ll gcdN = gcd(A,B);
    ll tmp = A/gcdN;
    ll tmpsize = llsize(tmp);
    if(tmpsize+bsize>19 && tmp*B!=1000000000000000000){
        cout<<L<<endl;
    }else{
        ll sumN = tmp*B;
        if(sumN>1000000000000000000)cout<<L<<endl;
        else cout<<sumN<<endl;
    }
    return 0;
}