// Leetcode:- Time Needed to Buy Tickets
// Link:- https://leetcode.com/problems/time-needed-to-buy-tickets/description/
// Method2:- 
/*
Example 1:

Input: tickets = [2,3,2], k = 2
Output: 6
Explanation:
The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.

Example 2:

Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
The queue starts as [5,1,1,1], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<int> q;
    int time = 0;
    for (int i = 0; i < tickets.size(); i++) {
        if (k >= i) {
            time += min(tickets[k], tickets[i]);
        }
        else if (k < i) {
            time += min(tickets[k] - 1, tickets[i]);
        }
    }
    return time;
}

int main() {
    int n, k;

    cout << "Enter number of people in queue: ";
    cin >> n;

    vector<int> tickets(n);

    cout << "Enter the number of tickets each person wants: ";
    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }

    cout << "Enter the index (k) of the person you are checking for: ";
    cin >> k;

    int result = timeRequiredToBuy(tickets, k);

    cout << "Total time required for person at index " << k << " to finish buying tickets: " << result << endl;

    return 0;
}
