#include<iostream>
using namespace std;
int a[100+1];
 
void print_array(int a[], int n){
    for (int i =0; i < n; i++ ){
        cout << a[i] << " ";
    }
}
 
bool tabe(int n, int k)
{
    int x;
    if (n < k)
        return false;
    if (n % k == 0){
            for (int i = 0 ; i < k ; i++){
                a[i] = n / k;
            }
            return true;  
        }
    if (n % 2 != 0 && k % 2 == 0)
        return false;
 
    else if (n % 2 == 0)
    {
        if (k % 2 == 0){
            a[k-1] = n - (k-1);
            for(int i = 0 ; i < k-1; i++){
                a[i] = 1;
            }
            return true;
        }
        if (k % 2 != 0){
           for(int i = 1 ; i < k ; i ++)a[i] = 2, n -= 2;
           if(n < 2)return 0;
           a[0] = n;
           return 1;
        }
    }
    else if (n % 2 != 0 && k % 2 != 0){
        a[0] = n - (k-1);
        for (int i = 1; i < k; i++)
            a[i] = 1;
        return true;
    }
    return false;
}
int main()
{
    int t, n, k;
    cin >> t;
    for (int i = 0 ; i < t ; i++){
        cin >> n >> k;
        if (tabe(n, k) == false)
            cout << "NO" << endl;
        if (tabe(n, k) == true){
            cout << "YES" << endl;
            print_array(a, k);
            cout << endl;
        }
    }
}