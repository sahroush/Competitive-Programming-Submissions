#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("fma,popcnt,avx2,sse,sse2")
#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#define int uint32_t
 
const int maxn = 1024;
const int mod = 1e9 + 7;
const int seed = steady_clock::now().time_since_epoch().count();
 
mt19937 rng(seed);
 
#define ll uint64_t
typedef pair < int, int > pii;
 
#define endl '\n'
#define ms(x, y) memset(x, y, sizeof x)
#define dokme(x) cout << x, exit(0)
#define pb push_back
 
const int sz = 64;
const int bcnt = 1024/sz;
 
struct bit{
    ll block[bcnt];
    void set(bit &a){
        for(int i = 0 ; i < bcnt ; i ++)
            block[i] = a.block[i];
    }
    void Xor(bit &a){
        for(int i = 0 ; i < bcnt ; i ++)
            block[i] ^= a.block[i];
    }
    friend bool operator < (bit a, bit b){
        for(int i = 0 ; i < bcnt ; i ++)if(a.block[i] < b.block[i])
            return 1;
        else if(a.block[i] > b.block[i])
            return 0;
        return 0;
    }
    friend bool operator ==(bit a, bit b){
        for(int i = 0 ; i < bcnt ; i ++)if(a.block[i] ^ b.block[i])
            return 0;
        return 1;
    }
    void on(int x){
        block[x / sz] |= (1ll << (x % sz));
    }
 
};
 
const int mx = 1e6;
 
int n, s, d, k, p2[maxn];
bit lamp[32], q, tmp, zero, prep[mx];
 
 
struct maptrie{
    int sz = 0;
    unordered_map < ll, int > child[mx];
    int val[mx];
    bool count(bit &a){
        int cur = 0;
        for(int i = 0 ; i < bcnt ; i ++){
            if(child[cur].count(a.block[i])){
                cur = child[cur][a.block[i]];
            }
            else
                return 0;
        }
        return 1;
    }
    int at(bit &a){
        int cur = 0;
        for(int i = 0 ; i < bcnt ; i ++){
            cur = child[cur][a.block[i]];
        }
        return val[cur];
    }
    void set(bit &a, int x){
        int cur = 0;
        for(int i = 0 ; i < bcnt ; i ++){
            if(child[cur].count(a.block[i])){
                cur = child[cur][a.block[i]];
            }
            else
                child[cur][a.block[i]] = ++sz, cur = sz;
        }
        val[cur] = min(val[cur], x);
    }
}mp;
 
#define btstr(x) x
 
int32_t solve(){
    int ans = 40;
    for(int i = 0 ; i < (1 << k) ; i ++){
        tmp.set(q);
        tmp.Xor(prep[i]);
        if(mp.count(tmp)) ans = min(ans, __builtin_popcount(i) + mp.at(tmp));
    }
    if(ans == 40)return -1;
    return ans;
}
 
 
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(mp.val, 63);
    cin >> n >> s >> d;
    p2[0] = 1;
    for(int i = 1 ; i < maxn ; i ++)
        p2[i] = (p2[i - 1] * 2)%mod;
    k = s / 2;
    for(int i = 0 ; i < s ; i ++){
        int x;
        cin >> x;
        for(int j = 0 ; j < x ; j ++){
            int v;
            cin >> v;
            v --;
            lamp[i].on(v);
        }
    }
    for(int i = 0 ; i < (1 << k) ; i ++){
        tmp.set(zero);
        for(int j = 0 ; j < k ; j ++)if(i & (1 << j)){
            tmp.Xor(lamp[j]);
        }
        mp.set(tmp , __builtin_popcount(i));
    }
    k = s - k;
    for(int i = 0 ; i < (1 << k) ; i ++){
        tmp.set(zero);
        for(int j = 0,ind = s/2 ; j < k ; j ++ , ind ++)if(i & (1 << j)){
            tmp.Xor(lamp[ind]);
        }
        prep[i].set(tmp);
    }
    while(d --){
        int x;
        cin >> x;
        q.set(zero);
        for(int i = 0 ; i < x ; i ++){
            int v;
            cin >> v;
            v --;
            q.on(v);
        }   
        cout << solve() << endl;
    }
    return 0;
}
                              