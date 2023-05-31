#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            sum += nums[i];
        }

        return sum;
    }
};

int main()
{
    vector<int> nums = {1, 4, 3, 2};

    Solution solution;
    int result = solution.arrayPairSum(nums);

    cout << "Sum of Minimized Pairs: " << result << endl;

    return 0;
}
