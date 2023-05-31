#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    int index = binarySearch(nums, target);

    if (index != -1)
    {
        cout << "Target found at index: " << index << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
