#include <bits/stdc++.h>
using namespace std;

int main()
{
  int totalEmployees, totalConnections, targetAttendance, totalDays = 1, currentAttendance = 0;
  cin >> totalEmployees >> totalConnections;
  map<int, set<int>> employeeGraph;
  for (int i = 0, emp1, emp2; i < totalConnections; ++i)
  {
    cin >> emp1 >> emp2;
    employeeGraph[emp1].insert(emp2);
    employeeGraph[emp2].insert(emp1);
  }

  cin >> targetAttendance;
  vector<bool> previousDayStatus(totalEmployees, true);

  currentAttendance = totalEmployees;

  while (currentAttendance < targetAttendance)
  {
    vector<bool> currentDayStatus(totalEmployees, false);

    for (int i = 0; i < totalEmployees; ++i)
    {
      int activeConnections = 0;
      for (int connection : employeeGraph[i])
      {
        if (previousDayStatus[connection])
          activeConnections++;
      }

      if (previousDayStatus[i] && activeConnections == 3)
        currentDayStatus[i] = true;
      else if (!previousDayStatus[i] && activeConnections < 3)
        currentDayStatus[i] = true;
    }

    previousDayStatus = currentDayStatus;
    for (int i = 0; i < totalEmployees; i++)
    {
      if (previousDayStatus[i])
        currentAttendance++;
    }
    totalDays++;
  }
  cout << totalDays;
  return 0;
}