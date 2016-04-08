//#define LC140
#ifdef LC140
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	void dfs(int startPos, vector<string>& sol, string res, int* dp, string s, unordered_set<string>& wordDict){
		int length = s.length();
		for (auto word : wordDict){
			string tmp = res;
			if (startPos + word.length() <= length && dp[startPos + word.length()]){
				int i;
				for (i = 0; i < word.length(); i++){
					if (word[i] != s[startPos + i])
						break;
				}
				if (i == word.length()){
					if (startPos + word.length() == length){
						tmp += word;
						sol.push_back(tmp);
					}
					else{
						tmp += word;
						tmp += " ";
						dfs(startPos + word.length(), sol, tmp, dp, s, wordDict);
					}
				}
			}
		}
		return;
	}
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int length = s.length();
		int* dp = new int[length + 1];
		for (int i = 0; i <= length; i++)
			dp[i] = false;
		dp[0] = true;
		for (int i = 1; i <= length; i++){
			for (auto word : wordDict){
				if (word.length() <= i && dp[i - word.length()]){
					int j;
					for (j = 0; j < word.length(); j++){
						if (word[j] != s[i - word.length() + j])
							break;
					}
					if (j == word.length()){
						dp[i] = true;
						break;
					}
				}
			}
		}
		vector<string> result;
		string res = "";
		if (!dp[length])
			return result;
		dfs(0, result, res, dp, s, wordDict);
		return result;
	}
};
#endif