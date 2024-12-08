#include<bits/stdc++.h>
using namespace std;
//AFFINE

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

int main(){
    int a, b;
    cout << "Moi ban nhap khoa k gom 2 so a, b cach nhau boi dau cach: ";
    cin >> a >> b;
    string msg;
    cout << "Moi ban nhap chuoi in hoa muon giai ma: ";
    cin.ignore();
    getline(cin, msg);
    cout << "Chuoi sau khi giai ma la: " << decryptCipher(msg, a, b);

return 0;
}
