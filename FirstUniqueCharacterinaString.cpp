#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> count(26, 0);

        // Count the frequency of each character
        for (char c : s)
            count[c - 'a']++;

        // Find the first unique character
        for (int i = 0; i < s.length(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }

        return -1; // No unique character found
    }
};

int main()
{
    Solution sol;
    string input = "leetcode";

    int result = sol.firstUniqChar(input);

    cout << "Index of the first unique character: " << result << endl;

    return 0;
}
