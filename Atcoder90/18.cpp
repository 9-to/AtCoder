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

long double L,T,X,Y,Q;
long double E[1001];
long double pi = M_PI;
//7を思い出す.今回は二分探索とは関係なく全体の総和を求める

long double calcZ(long double t){
    long double omega = 2*pi/T;
    return L/2-((L/2)*cos(omega*t));
}
long double calcY(long double t){
    long double omega = 2*pi/T;
    return -(L/2)*sin(omega*t);
}

int main() {
    cin>>T;
    cin>>L>>X>>Y;
    cin>>Q;
    rep(i,Q){
        cin>>E[i];
        long double cy = calcY(E[i]);
        long double cz = calcZ(E[i]);
        long double x = sqrt(X*X+(Y-cy)*(Y-cy));
        long double y = cz;
        long double rad = atan2(y,x);
        cout<< fixed << setprecision(12) <<180.0/pi*rad<<endl;
    }
    return 0;
}