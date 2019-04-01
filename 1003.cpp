//
//  1003.cpp
//  BOJ
//
//  Created by 제갈윤 on 01/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

int cnt0 = 0;
int cnt1 = 0;
int arr[40];
int savecnt[41][2];

int fibo(int n);

int main() {
    int n;
    cin >> n;
    
    int *p = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    arr[0] = 1;
    arr[1] = 1;
    savecnt[0][0] = 1;
    savecnt[1][1] = 1;
    for(int i =0; i < n; i++) {
        int cur = p[i];
        int res = fibo(cur);
        cout << savecnt[cur][0] << " " << savecnt[cur][1] << endl;
        cnt0 = 0;
        cnt1 = 0;
    }

    delete[] p;
}

int fibo(int n){
    int res = 0;
    if( n == 0){
        return arr[0];
    }
    if( n == 1){
        return arr[1];
    }
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        savecnt[i][0] = savecnt[i-1][0] + savecnt[i-2][0];
        savecnt[i][1] = savecnt[i-1][1] + savecnt[i-2][1];
    }
    return arr[n];
}
