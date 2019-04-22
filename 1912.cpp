//
//  1912.cpp
//  BOJ
//
//  Created by 제갈윤 on 22/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = arr[0];
    int tempSum = 0;
    
    for(int i = 0; i < n; i++) {
        tempSum = (tempSum + arr[i]) > arr[i] ? (tempSum + arr[i]) : arr[i];
        max = (tempSum > max) ? tempSum : max;
    }
    cout << max;
    delete[] arr;
}
