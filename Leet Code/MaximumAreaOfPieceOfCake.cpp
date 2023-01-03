#include<bits/stdc++.h>
#define MOD 1000000007
#define endl "\n"

using namespace std;

int maxAreaOfCake(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
    hCuts.push_back(0);
    hCuts.push_back(h);

    vCuts.push_back(0);
    vCuts.push_back(w);

    sort(hCuts.begin(), hCuts.end());
    sort(vCuts.begin(), vCuts.end());

    int horizontal = 0;
    for(int i = 0; i < (int)hCuts.size() - 1; i++) horizontal = max(horizontal, hCuts[i+1] - hCuts[i]);
    

    int vertical = 0;
    for(int i = 0; i < (int)vCuts.size() - 1; i++) vertical = max(vertical, vCuts[i+1] - vCuts[i]);
    
    return (int) ((long)horizontal%MOD * (long)vertical%MOD)%MOD;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--) {
        int h,w;
        cin >> h >> w;

        vector<int> hCuts(h);
        vector<int> vCuts(w);

        for (int i = 0; i < h; i++) cin >> hCuts[i];
        for (int i = 0; i < w; i++) cin >> vCuts[i];

        cout << maxAreaOfCake(h, w, hCuts, vCuts) << endl;
    }
}