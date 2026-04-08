#include<bits/stdc++.h>
using namespace std;

int main(){
    int k = 1;
    int n;
    cin >> n;

    while(n != 1){
        if( n % 2 == 0){
            n = n/2;
        }
        else{
            n = (3*n + 1)/2;
        }
        k++;
    }

    cout << k;
}