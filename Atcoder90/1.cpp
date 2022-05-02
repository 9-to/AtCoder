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

ll N,L,K,tmp;
vector<ll> A;

bool solve(ll M){
    ll cnt=0, pre=0;//cnt:カウント,pre:左端の位置
    rep(i,N){
        if (A[i]-pre >= M && L-A[i]>=M){
            cnt += 1;
            pre = A[i];
        }
    }
    if(cnt >= K) return true;
    return false;
}

int main() {
    cin>>N>>L;
    cin>>K;

    rep(i,N){
        cin>>tmp;
        A.push_back(tmp);
    }
    //二分探索
    ll left = -1;
    ll right = L+1;
    while(right - left > 1){
        ll mid = left + (right -left)/2;
        if(solve(mid)==false)right = mid;
        else left = mid;
    }
    cout<<left<<endl;
    return 0;
}