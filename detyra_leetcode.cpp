#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Kompleksiteti kohor: O(n), ku n është numri i elementeve në listë
// Kompleksiteti hapësinor: O(1), nuk krijohet hapësirë shtesë përveç tre pointerëve
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

//  Time complexity: O(n)
// Space complexity: O(1)
ListNode *removeElements(ListNode *head, int val)
{
    // Your implementation here
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy->next;
}
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//  Kompleksiteti kohor: O(n), ku n është numri i nyjeve në pemën binare.
// Kompleksiteti hapsinor: O(m), ku m është numri maksimal i nyjeve në çdo nivel të pemës binare.
int maxDepth(TreeNode *root)
{
    // Your implementation here
    if (root == nullptr)
    {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        depth++;
    }

    return depth;
}

// Kompleksiteti kohor: O(n), ku n është numri i nyjeve në pemën binare.
// Kompleksiteti hapsinor: O(h), ku h është lartësia e pemës binare.
// Në rastin më të keq, kur pemës binare është plotësisht e balancuar,
// lartësia h është log(n), ku n është numri i nyjeve në pemë.
bool isMirror(TreeNode *leftNode, TreeNode *rightNode)
{
    if (leftNode == nullptr && rightNode == nullptr)
    {
        return true;
    }

    if (leftNode == nullptr || rightNode == nullptr)
    {
        return false;
    }

    return (leftNode->val == rightNode->val) &&
           isMirror(leftNode->left, rightNode->right) &&
           isMirror(leftNode->right, rightNode->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    return isMirror(root->left, root->right);
}

// Kompleksiteti kohor: O(n)
// Kompleksiteti hapsinor: O(n),
class MyQueue
{
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int frontElement = outStack.top();
        outStack.pop();
        return frontElement;
    }

    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};

// Kompleksiteti kohor: O(n), ku n është numri i nyjeve në pema binare.
// Kompleksiteti hapsinor: O(h), ku h është lartësia e pemës binare.
// Në rastin më të keq, kur pemës binare është plotësisht e balancuar, lartësia h është log(n), ku n është numri i nyjeve në pemë.
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Kompleksiteti kohor: O(log(n)), ku n është numri i elementeve në vektor.
// Kompleksiteti hapsinor: O(1).
int search(vector<int> &nums, int target)
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

// Kompleksiteti kohor: O(n), ku n është numri i elementeve në vektor.
// Kompleksiteti hapsinor: O(1).
int missingNumber(vector<int> &nums)
{
    // Your implementation here
    int n = nums.size();
    int sum = n * (n + 1) / 2;

    for (int num : nums)
    {
        sum -= num;
    }

    return sum;
}

// Kompleksiteti kohor: O(nlog(n)),
// Kompleksiteti hapsinor: O(n)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            if (result.empty() || nums1[i] != result.back())
            {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }

    return result;
}
template <typename T>
void printVector(const vector<T> &vec)
{
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Kompleksiteti kohor: O(nlog(n)), ku n është numri i elementeve në vektor.
// Kompleksiteti hapsinor: O(1).
bool containsDuplicate(vector<int> &nums)
{
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
}

// Kompleksiteti kohor: O(d), ku d është numri i shifrave në numër.
// Kompleksiteti hapsinor: O(d), ku d është numri i shifrave në numër.
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

// Kompleksiteti kohor: O(n), ku n është gjatësia e stringut num.
// Kompleksiteti hapsinor: O(1).
string largestOddNumber(string num)
{
    // Your implementation here
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

// Kompleksiteti kohor: O(n log n), ku n është gjatësia e vektorit nums.
// Kompleksiteti hapsinor: O(1).
int maxProduct(vector<int> &nums)
{
    // Your implementation here
    int n = nums.size();

    // Rendit vargun ne rritje
    sort(nums.begin(), nums.end());

    // Kthe prodhimin e dy elementeve te fundit (elementet maksimale)
    return (nums[n - 1] - 1) * (nums[n - 2] - 1);
}

// Kompleksiteti kohor: O(n log n), ku n është gjatësia e vektorit nums.
// Kompleksiteti hapsinor: O(1).
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

// Kompleksiteti kohor: O(n^2), ku n është numri i fjalëve në vektorin words.
// Kompleksiteti hapsinor: O(n).
string sortSentence(string s)
{
    // ndaje fjaline ne fjale
    vector<string> words;
    string word;
    for (char c : s)
    {
        if (c == ' ')
        {
            words.push_back(word);
            word.clear();
        }
        else
        {
            word += c;
        }
    }
    words.push_back(word);

    // Sortimi i fjaleve
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (words[j].back() < words[i].back())
            {
                swap(words[i], words[j]);
            }
        }
    }

    // ndertimi i fjalise
    string sortedSentence;
    for (const string &word : words)
    {
        sortedSentence += word.substr(0, word.length() - 1);
        sortedSentence += ' ';
    }
    sortedSentence.pop_back(); // heqim hapsiren e fundit

    return sortedSentence;
}

// O(n) për kompleksitetin kohor dhe O(m) për kompleksitetin hapsinor.
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

//  O(n) për kompleksitetin kohor dhe O(m) për kompleksitetin hapsinor.
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

// Push: O(n), ku n është numri i elementeve aktual në stack.
// Hapësira e nevojshme për radhën është O(n), ku n është numri i elementeve aktual në stack.
class MyStack
{
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        while (size > 1)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop()
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
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
// Kompleksiteti kohor: O(n)
// Kompleksiteti hapësiror: O(n)
class RecentCounter
{
private:
    queue<int> pings;

public:
    RecentCounter() {}

    int ping(int t)
    {
        pings.push(t); // shton timestamp ne queue

        // largon timestamps qe jane me te vjetra se 3000 milisekonda
        while (!pings.empty() && pings.front() < t - 3000)
            pings.pop();

        return pings.size(); // kthen numrin e timestamps
    }
};

int main()
{
    // Reverse Linked List
    cout << "1.reverse linked list  " << endl;
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    cout << "Original List: ";
    printList(list);
    ListNode *reversed = reverseList(list);
    cout << "Reversed List: ";
    printList(reversed);

    // Remove Linked List Elements
    cout << "2.Remove Linked List Elements " << endl;
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(2);
    int val = 2;
    cout << "Original List: ";
    printList(list2);
    ListNode *filtered = removeElements(list2, val);
    cout << "List after removing elements with value " << val << ": ";
    printList(filtered);

    // Maximum Depth of Binary Tree
    cout << "3.maximum depth of binary tree " << endl;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int depth = maxDepth(root);
    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    // Symmetric Tree
    cout << "4.Symmetric Tree " << endl;
    TreeNode *symRoot = new TreeNode(1);
    symRoot->left = new TreeNode(2);
    symRoot->right = new TreeNode(2);
    symRoot->left->left = new TreeNode(3);
    symRoot->left->right = new TreeNode(4);
    symRoot->right->left = new TreeNode(4);
    symRoot->right->right = new TreeNode(3);
    bool isSymmetricResult = isSymmetric(symRoot);
    cout << "Is the tree symmetric? " << (isSymmetricResult ? "Yes" : "No") << endl;

    // Implement Queue using Stacks
    cout << "5.Implement Queue using Stacks " << endl;
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    int frontElement = queue.peek();
    cout << "Front element of the queue: " << frontElement << endl;
    queue.pop();
    bool isQueueEmpty = queue.empty();
    cout << "Is the queue empty? " << (isQueueEmpty ? "Yes" : "No") << endl;

    // Same Tree
    cout << "6.Same Tree " << endl;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    bool isSame = isSameTree(p, q);
    cout << "Are the trees the same? " << (isSame ? "Yes" : "No") << endl;

    // Binary Search
    cout << "7.Binary Search " << endl;
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;
    int index = search(nums, target);
    cout << "Index of target element in the array: " << index << endl;

    // Missing Number
    cout << "8.Missing Number " << endl;
    vector<int> nums2 = {0, 1, 3};
    int missing = missingNumber(nums2);
    cout << "Missing number in the array: " << missing << endl;

    // Intersection of Two Arrays
    cout << "9.Intersection of Two Arrays " << endl;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums3 = {2, 2};
    vector<int> intersectionResult = intersection(nums1, nums3);
    cout << "Intersection of the two arrays: ";
    printVector(intersectionResult);

    // Contains Duplicate
    cout << "10.Contains Duplicate " << endl;
    vector<int> nums4 = {1, 2, 3, 1};
    bool containsDuplicateResult = containsDuplicate(nums4);
    cout << "Does the array contain duplicates? " << (containsDuplicateResult ? "Yes" : "No") << endl;

    // Maximum 69 Number
    cout << "11.Maximum 69 Number " << endl;
    int num = 9669;
    int max69 = maximum69Number(num);
    cout << "Maximum 69 number: " << max69 << endl;

    // Largest Odd Number in String
    cout << "12.Largest Odd Number in String " << endl;
    string str = "35427";
    string largestOdd = largestOddNumber(str);
    cout << "Largest odd number in string: " << largestOdd << endl;

    // Maximum Product of Two Elements in an Array
    cout << "13.Maximum Product of Two Elements in an Array " << endl;
    vector<int> nums5 = {3, 4, 5, 2};
    int maxProductResult = maxProduct(nums5);
    cout << "Maximum product of two elements in the array: " << maxProductResult << endl;

    // Array Partition
    cout << "14.Array Partition " << endl;
    vector<int> nums6 = {1, 4, 3, 2};
    int sum = arrayPairSum(nums6);
    cout << "Sum of the minimum elements in each pair: " << sum << endl;

    // Sorting the Sentence
    cout << "15.Sorting the Sentence " << endl;
    string s = "is2 sentence4 This1 a3";
    string sorted = sortSentence(s);
    cout << "Sorted sentence: " << sorted << endl;

    // Make The String Great
    cout << "16.Make The String Great " << endl;
    string s2 = "leEeetcode";
    string greatString = makeGood(s2);
    cout << "The great string: " << greatString << endl;

    // Baseball Game
    cout << "17.Baseball Game " << endl;
    vector<string> ops = {"5", "2", "C", "D", "+"};
    int score = calPoints(ops);
    cout << "Final score in the baseball game: " << score << endl;

    // Implement Stack using Queues
    cout << "18.Implement Stack using Queues " << endl;
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    int topElement = stack.top();
    cout << "Top element of the stack: " << topElement << endl;
    stack.pop();
    bool isStackEmpty = stack.empty();
    cout << "Is the stack empty? " << (isStackEmpty ? "Yes" : "No") << endl;

    // First Unique Character in a String
    cout << "19.First Unique Character in a String " << endl;
    string s3 = "leetcode";
    int firstUnique = firstUniqChar(s3);
    cout << "Index of the first unique character: " << firstUnique << endl;

    // Number of Recent Calls
    cout << "20.Number of Recent Calls " << endl;
    RecentCounter recentCounter;
    int timestamps[] = {1, 100, 3001, 3002};
    int n = sizeof(timestamps) / sizeof(timestamps[0]);
    for (int i = 0; i < n; i++)
    {
        int count = recentCounter.ping(timestamps[i]);
        cout << "Number of recent calls within the last 3000 milliseconds: " << count << endl;
    }

    return 0;
}
