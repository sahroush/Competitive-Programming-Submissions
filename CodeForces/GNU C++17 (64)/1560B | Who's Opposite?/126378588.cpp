#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int q, a, b, c;
 
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> q;
    while(q --){
        cin >> a >> b >> c;
        int x = abs(a - b);
        if(max({a, b, c}) > (x << 1))
            cout << -1 << endl;   
        else
            cout << ((c > x) ? c - x : c + x) << endl;
    }
    return 0;
}