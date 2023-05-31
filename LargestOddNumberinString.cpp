#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        int idx = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            return "";
        }
        else
        {
            return num.substr(0, idx + 1);
        }
    }
};

int main()
{
    string num = "35462198";

    Solution solution;
    string result = solution.largestOddNumber(num);

    cout << "Largest Odd Number: " << result << endl;

    return 0;
}
