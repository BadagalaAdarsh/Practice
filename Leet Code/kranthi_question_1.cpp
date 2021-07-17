#include<bits/stdc++.h>
#define endl "\n"
using namespace std;


string Palindrome(string s, int n)
{
    unordered_map<char, int> cnt;
    string R = "";

    for (int i = 0; i < n; i++) {
        char a = s[i];
        cnt[a]++;
    }
  

    for (char i = 'a'; i <= 'z'; i++) {
        if (cnt[i] % 2 != 0)
            R += i;
    }
  
    int l = R.length();
    int j = 0;
  

    for (int i = l - 1; i >= l / 2; i--) {

        cnt[R[i]]--;
        R[i] = R[j];
        cnt[R[j]]++;
        j++;
    }
  

    string first, middle, second;
  
    for (char i = 'a'; i <= 'z'; i++) {
        if (cnt[i] != 0) {
  
 
            if (cnt[i] % 2 == 0) {
                int j = 0;
  
                while (j < cnt[i] / 2) {
                    first += i;
                    j++;
                }
            }
  
        
            else {
                int j = 0;
  
                
                while (j < (cnt[i] - 1) / 2) {
                    first += i;
                    j++;
                }
  
                
                middle += i;
            }
        }
    }
  

    second = first;
    reverse(second.begin(), second.end());
    string resultant = first + middle + second;
    cout << resultant << endl;
    
    return resultant;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    
    map<pair<int,int>,string> check;
    
    while(test--) {
    	string s;
    	int q;
    	int L, R;
    
    	cin >> s >> q;
    
    	for(int query = 0; query < q; query++) {
        	cin >> L >> R;
        	
        	pair<int,int> a;
        	a.first = L;
        	a.second = R;
        	
        	if (check.find(a) != check.end()){
        		cout << check[a] << endl;
        		continue;
        	}
        	
        	
        	string temp;
        	temp = s.substr(L-1, R);
        	string rem;
        	rem = s.substr(R,s.length());
        
        	int n = temp.length();
        
        	string answer;
        	answer = Palindrome(temp, n);
        	cout << answer + rem << endl;
        	check[a] = answer + rem;
        
    	}
    }
}
