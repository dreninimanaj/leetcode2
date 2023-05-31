#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        string numStr = to_string(num);

        int pos = -1;
        for (int i = 0; i < numStr.length(); i++)
        {
            if (numStr[i] == '6')
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            numStr[pos] = '9';
        }

        return stoi(numStr);
    }
};

int main()
{
    int num = 9669;

    Solution solution;
    int result = solution.maximum69Number(num);

    cout << "Maximum 69 number: " << result << endl;

    return 0;
}
