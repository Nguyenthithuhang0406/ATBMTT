#include<bits/stdc++.h>
using namespace std;

// khong de quy

long exponentiation(long base, long exp, long n){
    long t = 1L;
    while (exp > 0){
        if(exp % 2 != 0){
            t = (t * base) % n;
        }
        base = (base * base) % n;
        exp /= 2;
    }
    return t % n;
}

int main() {
   long a, n, m;
   cout << "Nhap 3 so a, n, m cach nhau boi dau cach: ";
   cin >> a >> n >> m;
    long modulo = exponentiation(a,n, m);
    cout << modulo;
    return 0;
}
