//
//  2750.cpp
//  BOJ
//
//  Created by 제갈윤 on 23/03/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++){
        cout << arr[i] << endl;
    }
}

void sort(int arr[], int len){
    int curIdx, cur;
    
    for(int i = 0; i < len-1; i++){
        cur = arr[i];
        curIdx = i;
        for (int j = i + 1; j < len; j++){
            if(cur > arr[j]){
                curIdx = j;
                cur = arr[j];
            }
        }
        arr[curIdx] = arr[i];
        arr[i] = cur;
    }
    printArr(arr, len);
}

int main(void) {
    int N;
    cin >> N;
    int *arr = new int[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr , N);
    
    delete[] arr;
}
