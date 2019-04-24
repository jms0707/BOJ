//
//  2643.cpp
//  BOJ
//
//  Created by 제갈윤 on 23/04/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100];

bool comp1 (pair<int, int> a, pair<int, int> b) {
    // 내림차순
//    return a.first > b.first;

//     오름차순
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    vector<pair<int, int>> input;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) {
            input.push_back(make_pair(a, b));
        } else {
            input.push_back(make_pair(b, a));
        }
    }
    sort(input.begin(), input.end(), comp1);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if((input[j].first <= input[i].first && input[j].second <= input[i].second) ||
               (input[j].first <= input[i].second && input[j].second <= input[i].first)) {
                dp[i] = (dp[i] < dp[j]) ? dp[j] : dp[i];
            }
        }
        dp[i]++;
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    
    cout << ans << endl;;
}
