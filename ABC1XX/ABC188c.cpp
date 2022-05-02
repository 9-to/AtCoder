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

    int N,ans=0,tmp;
    cin>>N;
    vector<int> al,ar;
    rep(i,pow(2,N)/2){
        cin>>tmp;
        al.push_back(tmp);
    }
    rep(i,pow(2,N)/2){
        cin>>tmp;
        ar.push_back(tmp);
    }
    int lmax = *max_element(all(al));
    int rmax = *max_element(all(ar));//最大値を取得
    if(lmax>rmax){                   //二番目の値とインデックスを判定
        ans = max_element(all(ar))-ar.begin()+1+pow(2,N)/2;
    }else{
        ans = max_element(all(al))-al.begin()+1;//indexを取得
    }
    cout<<ans<<endl;
    return 0;
}