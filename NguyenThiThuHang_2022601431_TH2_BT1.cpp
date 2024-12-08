#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == b) return a;
    if(a > b) return gcd(a-b, b);
    return gcd(a, b-a);
}

int modInverse( int a, int m){
    int m0 = m;
    int y = 0, x = 1;
    if(m == 1) return 0;
    while(a > 1){
        int q = a/m;
        int t = m;
        m = a%m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if(x < 0){
        x += m0;
        return x;
    }
}
void solve(int a, int b, int n){
    if(gcd(a,n) != 1){
        cout << "khong ton tai khoa giai ma!";
    }else{
        cout << "Ton tai khoa giai ma! \n";
        cout << "Khoa giai ma la: " << modInverse(a, n) << ", " << b;
    }
}
int main(){
cout <<  "Nhap khoa k gom 2 so a, b cach nhau boi dau cach: ";
int a, b;
cin >> a >> b;
solve(a, b, 26);
return 0;
}