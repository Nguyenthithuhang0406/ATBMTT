#include<bits/stdc++.h>
using namespace std;

#define N 101

//de quy
//long int exponentiation( long int base, long int exp){
//    if(exp == 0){
        //return 1;
    //}

    //if(exp == 1){
      //  return base % N;
    //}

   // long int t = exponentiation(base, exp / 2);
  //  t = (t * t) % N;

   // if(exp % 2 == 0){
    //    return t;
    //}else{
    //return ((base % N) * t) % N;
   // }
//}

//int main(){
  //  long int base = 37;
   // long int exp = 27;

  //  long int modulo = exponentiation(base, exp);
   // cout << modulo << endl;
  //  return 0;
//}


// khong de quy

long exponentiation(long base, long exp){
    long t = 1L;
    while (exp > 0){
        if(exp % 2 != 0){
            t = (t * base) % N;
        }
        base = (base * base) % N;
        exp /= 2;
    }
    return t % N;
}

int main() {
    long base = 37;
    long exp = 27;
    long modulo = exponentiation(base, exp);
    cout << modulo;
    return 0;
}
