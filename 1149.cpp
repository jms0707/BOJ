//
//  1149.cpp
//  BOJ
//
//  Created by 제갈윤 on 01/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int minarr[1001][3];

int main() {
    cin >> n;
    int **p = new int*[n];
    for(int i = 0; i < n; i++){
        p[i] = new int[3];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> p[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++){
            if(i == 0) {
                minarr[i][j] = p[i][j];
            } else {
                if( j == 0) {
                    minarr[i][j] = p[i][j] + min(minarr[i-1][1], minarr[i-1][2]);
                } else if(j == 1) {
                    minarr[i][j] = p[i][j] + min(minarr[i-1][0], minarr[i-1][2]);
                } else {
                    minarr[i][j] = p[i][j] + min(minarr[i-1][0], minarr[i-1][1]);
                }
            }
        }
    }
    
    cout << min(min(minarr[n-1][0], minarr[n-1][1]), minarr[n-1][2]);
    
    for(int i = 0; i < n; i++) {
        delete[] p[i];
    }
    delete[] p;
}
