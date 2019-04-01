//
//  1932.cpp
//  BOJ
//
//  Created by 제갈윤 on 01/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;
int save[501][501];
int main() {
    int n;
    cin >> n;
    int **p = new int*[n];
    
    for(int i = 0; i < n; i++) {
        p[i] = new int[n];
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> p[i][j];
        }
    }
    
    save[0][0] = p[0][0];
    
    if (n == 1) {
    } else {
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    save[i][j] = p[i][j] + save[i-1][j];
                }else if(j == i){
                    save[i][j] = p[i][j] + save[i-1][j-1];
                }else{
                    save[i][j] = p[i][j] + max(save[i-1][j-1], save[i-1][j]);
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        int cur = save[n-1][i];
        if(res <= cur) {
            res = cur;
        }
    }
    
    cout << res;

    for(int i = 0; i < n; i++) {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}
