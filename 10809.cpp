//
//  10809.cpp
//  BOJ
//
//  Created by 제갈윤 on 14/03/2019.
//  Copyright © 2019 제갈윤. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int a = 'a';
    int z = 'z';
    int res_size = z - a + 1;
    int * res;
    res = (int *) malloc(sizeof(int) * res_size);
    for (int i = 0; i < res_size; i++) {
        res[i] = -1;
    }
    
    string str;
    cin >> str;
    const char* cstr = str.c_str();
    for (int i = 0; i < str.length(); i++){
        int temp = cstr[i] - 97;
        if(res[temp] != -1){
            continue;
        }
        res[temp] = i;
    }
    
    for(int i = 0; i < res_size; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    free(res);
}
