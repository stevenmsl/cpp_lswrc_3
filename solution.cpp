#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol1209;
using namespace std;

/*takeaways
  - the basic idea here is to use a sliding window
    to determine the length of the substring.
  - use a hash table to remember the last index
    of each char
    - each index is set to -1 so we can add different
      char to the window without shrinking the window
  - calculate the new start of the window each time
    you scan in a char
    -  start = max(start, lastIndx[s[j]] + 1);

  - take abca as an example.
    - the window will first grow to "abc" and then we when scan in the next 'a' char
      we know it will cause a repeat of 'a' in the substring so we have to slide
      the window to the right. The window will then become "bca", which still
      has a length of three.
    - the question here is how can we determine there is a repeat
      quickly to achieve O(n)?
      - remember the last index of each char, and look for the index of the next char
      - for 'a', the last index is 0 when you are scanning in the 'a' at position 3,
        so 0 (last index) + 1 (next position) = 1 which should be the new start
        for the window, after it slid, if there are no repeating chars between
        0 and 3.

      - consider another case "abba", when you are scanning the next 'a' at position 3,
        you would conclude that the new start of the window should be 0 + 1 = 1,
        however, before that we have updated the start of the window to 2 already while
        scanning the repeating 'b's. That's why you need to perform a max
        to check to get the right start of the window
*/

int Solution::lengthOf(string s)
{
  int n = s.size();
  auto maxLen = 0;

  /* initialize every element to -1 so we can
     scan in different char at least once
     without changing the start
  */
  auto lastIndx = vector<int>(128, -1);

  for (int start = 0, j = 0; j < n; j++)
  {
    /* set the new start of the window
       - shrink the window to the right
         by 1 to remove the repeating
         chars
       - but the window might have moved
         already if there are repeating
         chars between s[lastIndex]..s[j]
       - use max to find the right start
    */
    start = max(start, lastIndx[s[j]] + 1);
    maxLen = max(maxLen, j - start + 1);
    lastIndx[s[j]] = j;
  }

  return maxLen;
}