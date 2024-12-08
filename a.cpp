//HILL
#include<bits/stdc++.h>
using namespace std;

int keyMatrix[50][50];

void encrypt(int cipherMatrix[][1], int messageVector[][1], int n){
    int x, i, j;
    //i: hang ma tran key
    for(i = 0; i < n; i++){
            //j: cot ma tran message
        for(j = 0; j < 1; j++){
            cipherMatrix[i][j] = 0;
    //x: hang ma tran ket qua cipher
            for(x = 0; x < n; x++){
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

string HillCipher(string message, int n){
    int messageVector[n][1];
    for(int i = 0; i < n; i++){
        messageVector[i][0] = (message[i]) - 'A';
    }
    int cipherMatrix[n][1];
    encrypt(cipherMatrix, messageVector, n);
    string CipherText;

    for(int i = 0; i < n; i++){
        CipherText += cipherMatrix[i][0] + 'A';
    }
    return CipherText;
}

int main(){
    string msg1, msg2;
    cout << "Moi ban nhap key lan luot gom cac so a, b, c, d cach nhau boi dau cach.";
    for(int i = 0; i < 4; i++){
    	int a; cin >> a;
    	keyMatrix[i/2][i%2] = a;
	}
    cout << "Moi ban nhap xau ky tu 1: ";
    cin >> msg1;
    cout << "Moi ban nhap xau ky tu 2: ";
    cin >> msg2;
    int n = 2;
    string cipher = "";
    int k = 0;
    while(k < (msg1.length() / n)){
    	string msg = "";
    	for(int i = k *n; i < (k+1) * n; i++){
    		msg += msg1[i];
		}
		cipher += HillCipher(msg, n);
		k++;
	} 
    cout << cipher;
    if(cipher == msg2){
    	cout << "Ban da nhap dung: ";
	}else{
		cout << "Ban da nhap sai: ";
	}
return 0;
};
