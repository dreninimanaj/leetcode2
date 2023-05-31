#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
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
};

int main()
{
    // Test input
    string s = "is2 sentence4 This1 a3";

    // Create an instance of the Solution class
    Solution solution;

    // Call the sortSentence function
    string result = solution.sortSentence(s);

    // Print the sorted sentence
    cout << "Sorted Sentence: " << result << endl;

    return 0;
}
