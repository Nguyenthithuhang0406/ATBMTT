#include<bits/stdc++.h>
using namespace std;
//AFFINE

string encryptMessage(string msg, int a, int b){
    string cipher = "";
    for(int i = 0; i < msg.length(); i++){
        if(msg[i] != ' ')
            cipher = cipher + (char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        else
            cipher += msg[i];
    }
    return cipher;
}
string decryptCipher(string cipher, int a, int b){
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    for (int i = 0; i < 26; i++){
        flag = (a * i) % 26;
        if(flag == 1){
            a_inv = i;
        }
    }

    for(int i = 0; i < cipher.length(); i++){
        if(cipher[i] != ' ')
            msg = msg + (char) (((a_inv * ((cipher[i] + 'A' - b)) % 26)) + 'A');
        else
            msg += cipher[i];
    }
    return msg;
}

void solve(string msg, string msg2, int a, int b){
    if(encryptMessage(msg, a, b) == msg2){
        cout << "Ban da nhap dung!";
    }else{
    cout << "Ban da nhap sai!";
    }
}
int main(){
    int a, b;
    cout << "Moi ban nhap khoa k gom 2 so a, b cach nhau boi dau cach: ";
    cin >> a >> b;
    string msg;
    cout << "Moi ban nhap xau ly tu 1: ";
    cin.ignore();
    getline(cin, msg);
    string msg2;
    cout << "Moi ban nhap xau ky tu 2: ";
    getline(cin, msg2);
    solve(msg, msg2, a, b);
return 0;
}
