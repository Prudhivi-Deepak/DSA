
#include<bits/stdc++.h>
using namespace std;

class TaskManager1 {
public:
    //set ==> acs order
    // -priority, -taskId, userId => return highest priority, if tie returns highest taskId

    set<vector<int>> taskSet;
    unordered_map<int, pair<int,int>> taskIdPriorityUserIdMap;
    TaskManager1(vector<vector<int>>& tasks) {
        for(auto task : tasks){
            taskSet.insert({-task[2], -task[1], task[0]});
            taskIdPriorityUserIdMap[task[1]] = {task[2], task[0]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskSet.insert({-priority, -taskId, userId});
        taskIdPriorityUserIdMap[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskIdPriorityUserIdMap[taskId].second;
        int priority = taskIdPriorityUserIdMap[taskId].first;
        taskSet.erase({-priority, -taskId , userId });
        taskSet.insert({-newPriority, -taskId, userId});
        taskIdPriorityUserIdMap[taskId] = {newPriority, userId};
    }
    
    void rmv(int taskId) {
        int userId = taskIdPriorityUserIdMap[taskId].second;
        int priority = taskIdPriorityUserIdMap[taskId].first;
        taskSet.erase({-priority, -taskId , userId });
        taskIdPriorityUserIdMap.erase(taskId);
    }
    
    int execTop() {
        if(taskSet.empty()) return -1;
        auto highestPriorityTask = *taskSet.begin();
        taskSet.erase(taskSet.begin());
        taskIdPriorityUserIdMap.erase(-highestPriorityTask[1]);
        return highestPriorityTask[2];
    }
};

class TaskManager {
public:
    //set ==> acs order
    // -priority, -taskId, userId => return highest priority, if tie returns highest taskId

    priority_queue<tuple<int,int,int>> taksMaxHeap;
    unordered_map<int, pair<int,int>> taskIdPriorityUserIdMap;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task : tasks){
            taksMaxHeap.push({task[2], task[1], task[0]});
            taskIdPriorityUserIdMap[task[1]] = {task[2], task[0]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taksMaxHeap.push({priority, taskId, userId});
        taskIdPriorityUserIdMap[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskIdPriorityUserIdMap[taskId].second;
        int priority = taskIdPriorityUserIdMap[taskId].first;
        taksMaxHeap.push({newPriority, taskId, userId});
        taskIdPriorityUserIdMap[taskId] = {newPriority, userId};
    }
    
    void rmv(int taskId) {
        int userId = taskIdPriorityUserIdMap[taskId].second;
        int priority = taskIdPriorityUserIdMap[taskId].first;
        taskIdPriorityUserIdMap.erase(taskId);
    }
    
    int execTop() {

        while(!taksMaxHeap.empty()){
            auto [priority, taskId, userId] = taksMaxHeap.top(); taksMaxHeap.pop();
            if(taskIdPriorityUserIdMap.find(taskId)!=taskIdPriorityUserIdMap.end() && taskIdPriorityUserIdMap[taskId].first == priority){
                taskIdPriorityUserIdMap.erase(taskId);
                return userId;
            }
        }

        return -1;
    }
};
/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

//  https://leetcode.com/problems/design-task-manager/description/?envType=daily-question&envId=2025-09-18

// Input:
// ["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
// [[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]

// Output:
// [null, null, null, 3, null, null, 5]

// Explanation

// TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
// taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
// taskManager.edit(102, 8); // Updates priority of task 102 to 8.
// taskManager.execTop(); // return 3. Executes task 103 for User 3.
// taskManager.rmv(101); // Removes task 101 from the system.
// taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
// taskManager.execTop(); // return 5. Executes task 105 for User 5.
 