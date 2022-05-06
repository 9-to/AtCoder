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

ll N;
ll Q = 1000000000+7;
string S;
ll ans =0;
ll dp[100001][8]={0};
char check[8]={'\t','a','t','c','o','d','e','r'};
/*dp[pos][state]=通り数
pos:Sのポジション
state:adcoderの何文字目まで保持しているか
dp[pos][state]+=dp[pos-1][state]//pos番目の文字を選ばない場合
dp[pos][state]+=dp[pos-1][state-1]//pos番目の文字を選ばない場合
*/
int main() {
    cin>>N;
    cin>>S;
    dp[0][0]=1;
    rep(i,N){//0~N-1
        char s = S[i]; //i番目の文字
        rep(j,8){//0~7
            dp[i+1][j] +=dp[i][j];//選ばなかった場合
            dp[i+1][j] %= Q;
            if(s == check[j]){
                dp[i+1][j] +=dp[i][j-1];
                dp[i+1][j] %=Q;
            }//選んだ場合
        }
    }
    cout<<dp[N][7]<<endl;
    return 0;
}