//HILL
#include<bits/stdc++.h>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][50], int n){
    int k = 0;
    for (int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
                //ma Ascii
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][50], int messageVector[][1], int n){
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

void encryption(int cipherMatrix[][1],int Keymatrix[][3], int inputVector[][1]){
    
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;
           
            for (int x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] += 
                     Keymatrix[i][x] * inputVector[x][j];
            }
          
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

void HillCipher(string message, string key, int n){
    int keyMatrix[50][50];
    getKeyMatrix(key, keyMatrix, n);
    int messageVector[n][1];
    for(int i = 0; i < n; i++){
        messageVector[i][0] = (message[i]) % 65;
    }
    int cipherMatrix[n][1];
    encrypt(cipherMatrix, keyMatrix, messageVector, n);
    string CipherText;

    for(int i = 0; i < n; i++){
        CipherText += cipherMatrix[i][0] + 65;
    }
    cout << "CipherText: " << CipherText;
}

int main(){
    string key, message;
    cout << "Moi ban nhap key: ";
    cin >> key;
    cout << "Moi ban nhap message: ";
    cin >> message;
    int n = message.length();
    HillCipher(message, key, n);
return 0;
};
