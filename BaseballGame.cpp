#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> pointsStack;
        int totalScore = 0;

        for (const string &op : ops)
        {
            if (op == "C")
            {
                totalScore -= pointsStack.top();
                pointsStack.pop();
            }
            else if (op == "D")
            {
                int doubledScore = 2 * pointsStack.top();
                totalScore += doubledScore;
                pointsStack.push(doubledScore);
            }
            else if (op == "+")
            {
                int prev1 = pointsStack.top();
                pointsStack.pop();
                int prev2 = pointsStack.top();
                int currentScore = prev1 + prev2;
                totalScore += currentScore;
                pointsStack.push(prev1);
                pointsStack.push(currentScore);
            }
            else
            {
                int score = stoi(op);
                totalScore += score;
                pointsStack.push(score);
            }
        }

        return totalScore;
    }
};

int main()
{
    // Create an instance of the Solution class
    Solution solution;

    // Test case 1
    vector<string> ops1 = {"5", "2", "C", "D", "+"};
    int result1 = solution.calPoints(ops1);
    cout << "Result 1: " << result1 << endl;

    // Test case 2
    vector<string> ops2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int result2 = solution.calPoints(ops2);
    cout << "Result 2: " << result2 << endl;

    return 0;
}
