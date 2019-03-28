//
//  1026.cpp
//  BOJ
//
//  Created by 제갈윤 on 26/03/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

const int MAX = 101;
int n;

int main() {
    cin >> n;
    
    int *a = new int[n];
    int *b = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    merge_sort(a, 0, n - 1);
    merge_sort(b, 0, n - 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[n - i - 1];
    }
    
    cout << res;
    delete[] a;
    delete[] b;
}

void merge_sort(int arr[], int l, int r) {
    int m = (l + r) / 2;
    
    if (l < r) {
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int _l = l;
    int _m = m + 1;
    int tempIdx = l;
    int tempArr[MAX];
    while(_l <= m && _m <= r) {
        if(arr[_l] < arr[_m]) {
            tempArr[tempIdx++] = arr[_l++];
        } else {
            tempArr[tempIdx++] = arr[_m++];
        }
    }
    
    if(_l <= m) {
        for(int i = _l; i <= m; i++) {
            tempArr[tempIdx++] = arr[i];
        }
    } else {
        for (int i = _m; i <= r; i++) {
            tempArr[tempIdx++] = arr[i];
        }
    }
    
    for(int i = l; i <= r; i++) {
        arr[i] = tempArr[i];
    }
}
