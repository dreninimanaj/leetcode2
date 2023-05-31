#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    Solution solution;
    bool result = solution.containsDuplicate(nums);

    cout << "Does the array contain duplicate elements? " << (result ? "Yes" : "No") << endl;

    return 0;
}
