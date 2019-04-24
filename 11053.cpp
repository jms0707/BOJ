//
//  11053.cpp
//  BOJ
//
//  Created by 제갈윤 on 24/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
int main() {
    int dp[1001];
    fill_n(dp, 1001, 0);
//    cout << "입력하세요" << endl;
    int n;
    cin >> n;
    
    vector<int> seq;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }
    int ans = numeric_limits<int>::lowest();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(seq[i] > seq[j]) {
                dp[i] = (dp[i] < dp[j]) ? dp[j] : dp[i];
            }
        }
        dp[i]++;
        if(ans < dp[i]) {
            ans = dp[i];
        }
    }
    
    cout << ans << endl;
}
