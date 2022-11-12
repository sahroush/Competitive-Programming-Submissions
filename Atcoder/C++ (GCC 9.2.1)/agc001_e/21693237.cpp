#include<bits/stdc++.h>
using namespace std;

const int maxn = 410;

int n , a[maxn];
int dp[maxn][maxn][maxn];

int32_t main(){
  cin >> n;
  for(int i = 1; i <=n ; i ++)
    cin >> a[i];
  for(int l = n + 2 ; l >= 2 ; l --){
    for(int i = 0 ; i + l - 1 <= n + 1 ;  i ++){
      int j = i + l - 1;
      for(int k = 0 ; k <= n ; k ++){
       dp[i][j][k] = ( i and (j == n + 1 or a[i] > a[j]) ? dp[i - 1][j][k + 1] : dp[i][j + 1][k + 1]);
       if(k){
        if(i) 
          	dp[i][j][k] = max(dp[i][j][k], a[i]+dp[i-1][j][k-1]);
        if(j < n + 1)
          	dp[i][j][k] = max(dp[i][j][k], a[j]+dp[i][j+1][k-1]);
       }
      }
    }
  }
  for(int i = 0 ; i <= n ; i ++)
    	cout << dp[i][i + 1][1] << endl;
 return(0);
}