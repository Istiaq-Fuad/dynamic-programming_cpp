/*
1. count the number of ways it is possible to make the targeted string by
   joining the strings in the array
2. returns the number of ways it is possible to make the targeted string
3. otherwise return 0
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int countConstruct(string &target, const vector<string> &wordBank,
                   unordered_map<string, int> &memo) {
  if (memo.contains(target)) return memo[target];
  if (target == "") return 1;

  int totalCount = 0;
  for (auto &s : wordBank) {
    if (target.substr(0, s.size()) == s) {
      string subString = target.substr(s.size(), target.size() - s.size());
      int temp = countConstruct(subString, wordBank, memo);
      totalCount += temp;
      // gotta test the next line
      memo[target] = totalCount;
    }
  }

  memo[target] = totalCount;
  return totalCount;
}

int main() {
  string target = "abcdef";
  vector<string> wordBank = {"abc", "def", "de", "ef", "f"};
  unordered_map<string, int> memo;

  cout << countConstruct(target, wordBank, memo) << '\n';
}