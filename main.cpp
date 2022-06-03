#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1209;

/*
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

tuple<string, int>
testFixture1()
{
  return make_tuple("abcabcbb", 3);
}

/*
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

tuple<string, int>
testFixture2()
{
  return make_tuple("bbbbb", 1);
}

/*
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

tuple<string, int>
testFixture3()
{
  return make_tuple("pwwkew", 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.lengthOf(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.lengthOf(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.lengthOf(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}