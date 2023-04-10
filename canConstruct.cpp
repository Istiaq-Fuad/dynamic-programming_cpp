/*
1. check if it is possible to make the targeted string by joining the strings in
   the array
2. returns true if the above task is possible
3. otherwise return false
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool canConstruct(string &target, const vector<string> &wordBank,
                  unordered_map<string, bool> &memo) {
  if (memo.contains(target)) return memo[target];
  if (target == "") return true;
  for (auto &s : wordBank) {
    if (target.substr(0, s.size()) == s) {
      string subString = target.substr(s.size(), target.size() - s.size());
      if (canConstruct(subString, wordBank, memo) == true) {
        memo[target] = true;
        return true;
      }
    }
  }

  memo[target] = false;
  return false;
}

int main() {
  string target = "abcdef";
  vector<string> wordBank = {"abc", "cdef", "de", "ef"};
  unordered_map<string, bool> memo;

  if (canConstruct(target, wordBank, memo))
    cout << "yes" << '\n';
  else
    cout << "no" << '\n';
}