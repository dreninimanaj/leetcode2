#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2;

    for (int num : nums)
    {
        sum -= num;
    }

    return sum;
}

int main()
{
    vector<int> nums = {3, 0, 1, 4, 2};

    int missing = missingNumber(nums);

    cout << "The missing number is: " << missing << endl;

    return 0;
}
