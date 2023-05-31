#include <iostream>
#include <queue>

using namespace std;

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
    RecentCounter obj;

    // Perform ping operations and print the number of recent pings
    cout << obj.ping(1) << endl;    // Output: 1
    cout << obj.ping(100) << endl;  // Output: 2
    cout << obj.ping(3001) << endl; // Output: 3
    cout << obj.ping(3002) << endl; // Output: 3

    return 0;
}
