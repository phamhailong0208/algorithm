/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    // int getImportance(vector<Employee*> employees, int id) {
    //     map<int, Employee*> empMap;
    //     for (auto e: employees) {
    //         empMap[e->id] = e;
    //     }
    //     int total =0;
    //     queue<int> queue;
    //     queue.push(id);
    //     while (!queue.empty()) {
    //         int empId = queue.front();
    //         queue.pop();
    //         Employee* emp = empMap[empId];
    //         total += emp->importance;
    //         for (int subId: emp->subordinates) {
    //             queue.push(subId);
    //         }
    //     }
    //     return total;
    // }
    int dfs(map <int, Employee*> mp, int id) {
         Employee* emp = mp[id];
         int total = emp->importance;
         for (int subId: emp->subordinates) {
            total += dfs(mp, subId);
         }
         return total;
    }
    int getImportance(vector<Employee*> employees, int id) {
        map <int, Employee*> empMap;
        for (auto e: employees){
            empMap[e->id] = e;
        }
        return dfs(empMap, id);
    }
};