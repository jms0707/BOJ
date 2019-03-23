//
//  1342.cpp
//  BOJ
//
//  Created by 제갈윤 on 23/03/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int cnt[26];
int ans = 0;

void result(int remain, int cur){
    if(remain == 0) {
        ans++;
        return;
    } else{
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0 && cur != i) {
                cnt[i]--;
                result(remain-1, i);
                cnt[i]++;
            }
        }
    }
}

int main() {
    string str;
    cin >> str;
    
    int len = str.length();
    for(int i = 0; i < len; i++) {
        cnt[str[i] - 'a']++;
    }
    
    result(len, -1);
    cout << ans;
}
