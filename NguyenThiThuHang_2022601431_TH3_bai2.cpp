#include<bits/stdc++.h>
using namespace std;

//a^-1 mod m
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
        y = x - q*y;
        x = t;
    }
    if(x < 0){
        x += m0;
    }
    return x;
}

int det(int a, int b, int c, int d){
	return a*d - c*b;
}

void solve(int a, int b, int c, int d){
	int detk = det(a, b, c, d);
	int modeInverseOfK = modInverse(detk, 26);
	if(modeInverseOfK < 0){
		modeInverseOfK += 26;
	}
	cout << "Khoa giai ma la: \n";
	cout << (d * modeInverseOfK) % 26 << " " << ((-b + 26) * modeInverseOfK) % 26 << "\n";
	cout << (a * modeInverseOfK) % 26 << " " << ((-c + 26) * modeInverseOfK) % 26 ;
}
int main(){
	cout << "Moi ban nhap lan luot cac so a, b, c, d cua ma tran k, moi so cach nhau 1 dau cach: ";
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	solve(a, b, c, d);
	return 0;
}
