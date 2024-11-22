#include<bits/stdc++.h>
using namespace std;

//tim phan tu nghich dao theo modulo
//a=3, m=11 timf a^-1 mod m
int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;
    if(m == 1) return 0;
    while (a > 1){
            //q la thuong
        int q = a / m;
        int t = m;
    //m la du cua hien tai
        m = a % m;
        a = t;
        t = y;
        //update x va y
        y = x - q*y;
        x = t;
    }
    if(x < 0){
        x += m0;
    }
    return x;
}

int main(){
    int a, m;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Modular multiplicative inverse is " << modInverse(a, m);
    return 0;
}
