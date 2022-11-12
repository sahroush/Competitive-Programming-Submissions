#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10;

int a[maxn] , n , sum , ans;

bool chk(int mid){
	int a = 0 , b = 0;
	for(int i = 1 ; i < n ; i += 2){
		b += ::a[i];
		if(b >= a + mid)
			b -= ::a[i+1] , a = min(a , b);
		else b -= ::a[i+1];
	}
	return b + ::a[n] >= a + mid;
}

int32_t main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)cin >> a[i],
		ans += a[i] * (i&1) , sum += a[i];
	if(n % 2 == 0){
		if(ans < sum - ans)ans = sum - ans;
	}
	else{
		int l = 0 , r = sum+1;
		while(r - l > 1){
			int mid = (l + r) / 2;
			if(chk(mid))l = mid;
			else r = mid;
		}
		ans = max(ans , sum - ans + l);
	}
	cout << ans << ' ' << sum - ans;
	return 0;
}
