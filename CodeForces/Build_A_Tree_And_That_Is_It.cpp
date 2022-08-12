#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> d(3);
        forn(i, 3)
            cin >> d[i];
        int sum = d[0] + d[1] + d[2];
        if (sum % 2 == 0) {
            vector<int> w(3);
            forn(i, 3)
                w[i] = sum / 2 - d[(i + 1) % 3];
            vector<int> sw(w.begin(), w.end());
            sort(sw.begin(), sw.end());
            if (sw[0] >= 0 && sw[1] >= 1) {
                vector<pair<int,int>> edges;
                int num = 3;
                int center;
                if (sw[0] == 0)
                    center = min_element(w.begin(), w.end()) - w.begin();
                else
                    center = num++;
                forn(i, 3) {
                    int before = center;
                    forn(j, w[i] - 1) {
                        edges.push_back({before, num});
                        before = num++;
                    }
                    if (w[i] > 0)
                        edges.push_back({before, i});
                }
                if (num <= n) {
                    while (num < n)
                        edges.push_back({center, num++});
                    cout << "YES" << endl;
                    for (auto& [u, v]: edges)
                        cout << u + 1 << " " << v + 1 << endl;
                    continue;
                }
            }
        }
        cout << "NO" << endl;
    }
}
