#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/* alias */
using ll = unsigned long long;
//using ll = long long;
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

ll L,R;
ll Q = 1000000000+7;
ll A[102][102],B[102][102],V[102][102];

ll llsize(ll n){
    ll cnt=0;
    while(n!=0){
        n/=10;
        cnt++;
    }
    return cnt;
}

ll div2(ll a,ll b){
    if(a%2==0){
        a /=2;
    }else b /=2;
    return (a%Q)*(b%Q)%Q;
}

int main() {
    cin>>L>>R;
    ll lsize = llsize(L);
    ll rsize = llsize(R);
    ll ans = 0;
    if(rsize-lsize==0){
        //cout<<L+R<<" "<<R-L+1<<endl;
        ans = lsize*div2(L+R,R-L+1)%Q;
    }else if(rsize-lsize==1){
        ll m = powl(10,lsize)-1;
        ans += lsize*div2(L+m,m-L+1)%Q;
        ans += rsize*div2((m+1)+R,R-(m+1)+1)%Q;
        ans %= Q;
    }else{
        ll m = powl(10,lsize)-1;
        ll mr = powl(10,rsize-1);
        //cout<<m<<"|"<<mr<<endl;
        ans += (lsize*div2(L+m,m-L+1))%Q;
        //cout<<ans<<endl;
        ans += (rsize*div2(mr+R,R-mr+1))%Q;
        ans %= Q;
        //cout<<ans<<endl;
        for(ll i =lsize+1;i<=rsize-1;i++){
            ll first = powl(10,i-1);
            ll last = powl(10,i)-1;
            ans += (i*div2(first+last,last-first+1))%Q;
            ans %=Q;
            //cout<<first<<" "<<last<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}