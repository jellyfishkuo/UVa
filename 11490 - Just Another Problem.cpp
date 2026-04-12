#include <bits/stdc++.h>
#define MOD 100000007
#define int long long
using namespace std;

int s;

main(){
    while(cin>>s,s){
        bool flag=false;
        // 從公式 S = 6x^2 + 7xy 推導
        // 因為 7xy > 0，所以 6x^2 必須小於 S，即 x < sqrt(S/6)
        int x=sqrt(s/6+0.1); 
        // 遍歷所有可能的遺失邊長 b (即公式中的 x)
        for(int b=1; b<=x; b++){ 
            // 移項整理：7xy = S - 6x^2
            int a = s - b * b * 6; 
            // 如果 (S - 6b^2) 能被 7b 整除，代表找到了整數解 y
            if(a > 0 && a % (7 * b) == 0){ 
                int ans = a / (7 * b) % MOD; // ans 即為 y，取模處理
                // 題目要求輸出遺失的士兵數
                // 根據推導，遺失兵力為 2 * x^2 (即 2 * y^2，這裡的 y 是厚度變數的替換)
                // 注意：輸出的格式為 y * y * 2
                cout << "Possible Missing Soldiers = " << ans * ans * 2 % MOD << endl;
                flag = true;
            }
        }
        if(!flag) cout << "No Solution Possible\n";
        cout << endl; 
    }
    return 0;
}
