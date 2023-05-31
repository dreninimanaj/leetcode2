#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && (st.top() == s[i] + 32 || st.top() == s[i] - 32))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string result;
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

int main()
{
    // Test input
    string s = "leEeetcode";

    // Create an instance of the Solution class
    Solution solution;

    // Call the makeGood function
    string result = solution.makeGood(s);

    // Print the modified string
    cout << "Modified String: " << result << endl;

    return 0;
}
