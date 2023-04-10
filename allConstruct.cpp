/*
1. find the number of ways it is possible to make the targeted string by
   joining the strings in the array
2. returns a 2d array of string containing all the ways it is possible to make
   the targeted string
3. otherwise return empty array
*/
// TODO: finish the code
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<vector<string>> vvs;

vvs allConstruct(string &target, const vector<string> &wordBank,
                 unordered_map<string, vvs> &memo) {
  if (target == "") return vector<vector<string>>{{}};

  const vector<vector<string>> result = {};
  for (auto &word : wordBank) {
    if (target.substr(0, word.size()) == word) {
      string subString =
          target.substr(word.size(), target.size() - word.size());
      vvs subWays = allConstruct(target, wordBank, memo);
    }
  }
}

int main() {
  string target = "abcdef";
  vector<string> wordBank = {"abc", "def", "de", "ef", "f"};
  unordered_map<string, vvs> memo;

  // cout << allConstruct(target, wordBank, memo) << '\n';
}