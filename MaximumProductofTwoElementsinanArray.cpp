#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        // Rendit vargun ne rritje
        sort(nums.begin(), nums.end());

        // Kthe prodhimin e dy elementeve te fundit (elementet maksimale)
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

int main()
{
    vector<int> nums = {3, 4, 5, 2};

    Solution solution;
    int result = solution.maxProduct(nums);

    cout << "Maximum Product of Two Elements: " << result << endl;

    return 0;
}
