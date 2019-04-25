//
//  11051.cpp
//  BOJ
//
//  Created by 제갈윤 on 26/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
    int n, k;
    cin >> n >> k;
    
    // init
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    
    for(int i = 2; i <=n; i++) {
        for(int j = 2; j <= n; j++) {
            if(dp[i][j] == 0) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
            } else {
                continue;
                
            }
        }
    }
    cout << dp[n][k] << endl;
}
