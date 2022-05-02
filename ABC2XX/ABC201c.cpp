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

    string S;
    int ans=0;
    cin>>S;
    for(int i=0;i<=9999;i++){//0000~9999を試行する
        vector<bool> flag(10);//[0,9]のフラグ
        int X =i;//Xは試行中の番号
        for(int j=0;j<4;j++){
            flag[X%10] = true;//1の位->千の位の数字にフラグを立てる=試行中の番号に含まれる数字
            X/=10;
        }
        bool flag2 = true;
        for(int j=0;j<10;j++){//備忘録Sとフラグを照合
            if(S[j]=='o' && !flag[j]) flag2 = false;//iが確実に含まれるかつ試行中の番号に含まれない
            if(S[j]=='x' && flag[j]) flag2 = false;//iが確実に含まれないかつ試行中の番号に含まれる
        }
        ans +=flag2;
    }
    cout<<ans<<endl;
    return 0;//O(10^5)
}