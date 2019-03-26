//
//  2751.cpp
//  BOJ
//
//  Created by 제갈윤 on 23/03/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 1000001;

int len;
int tempArr[MAX];
int arr[MAX];

void merge(int st, int mi, int en){
    int start = st;
    int middle = mi + 1;
    
//    int tempArr[len];
    int tempIdx = st;
    
    while(start <= mi && middle <= en) {
        if(arr[start] <= arr[middle]){
            tempArr[tempIdx++] = arr[start++];
        } else {
            tempArr[tempIdx++] = arr[middle++];
        }
    }
    
    if(start <= mi) {
        for(int i = start; i <= mi; i++) {
            tempArr[tempIdx++] = arr[i];
        }
    }
    
    if(middle <= en) {
        for(int i = middle; i <= en; i++) {
            tempArr[tempIdx] = arr[i];
            tempIdx++;
        }
    }
    
    for(int i = st; i <= en; i++) {
        arr[i] = tempArr[i];
    }
}

void divide(int st, int en) {
    int mi;
    
    if(st < en) {
        mi = (st + en) / 2;
        divide(st, mi);
        divide(mi + 1, en);
        merge(st, mi, en);
    }
}


int main(){
    cin >> len;
    
//    int *arr = new int[len];
    
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    
    divide(0, len - 1);
    
    for(int i = 0; i < len; i++){
        cout << arr[i] << '\n';
    }
    
//    delete[] arr;
}
