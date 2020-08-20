#include <bits/stdc++.h>
using namespace std;

bool comp(string &a, string &b) {
	return (a.length()>b.length());
}

bool sub(string &a, string &b) {
	int i=0,j=0;
	while(i < a.length() && j < b.length()) {
		if(a[i] == b[j]) {
			i++;
		}
		j++;
	}
	// cout<<i<<"\n";
	if(i == a.length()) return true;
	else return false;
}

int max(int x, int y) {
	if(x > y) return x;
	else return y;
}

int substring(string &s, vector<string> &words) {
	int n2 = words.size(), n1 = s.length();
	int i=0, j=0,ans=INT_MIN;
	sort(words.begin(), words.end(), comp);
	
	// for(int i=0;i<n2;i++) {
	// 	cout<<words[i]<<"\t";
	// }
	
	for(int i=0;i<n2;i++) {
		if(sub(words[i], s)) {
			ans = words[i].length();
			cout<<words[i]<<"\t"<<ans<<"\n";
			break;
		}
		else { 
			ans = -1;
		}
	}
	return ans;
}

int main() {
	// your code goes here
	string s = "abppplee";
	vector<string> words = {"able", "ale", "apple", "abpple" ,"bale", "kangaroo"};
	
	substring(s, words);
	
	return 0;
}