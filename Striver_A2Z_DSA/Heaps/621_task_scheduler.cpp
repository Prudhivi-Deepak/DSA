#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // auto compare = [](pair<int,int> p1, pair<int,int> p2){
        //     return p1.first < p2.first;
        // };
        // priority_queue<pair<int,int>, vector<pair<int,int>>,
        // decltype(compare)> maxheap(compare);

        priority_queue<int> maxheap;

        vector<int> store;

        map<int, int> freq;
        for (char i : tasks) {
            freq[i]++;
        }

        for (auto i : freq) {
            // cout << "freq : " << i.second << endl;
            maxheap.push(i.second);
        }

        int time = 0, cycle;

        while (!maxheap.empty()) {
            cycle = n+1;
            store.clear();
            // cout << "\n---------------------\n";
            while (cycle > 0 && !maxheap.empty()) {
                // cout << "max heap : "<< maxheap.top() << endl;
                cycle--;
                if(maxheap.top() >1)
                    store.push_back(maxheap.top() - 1);
                maxheap.pop();
                time++;
            }
            // cout << "end of cycle " << endl;

            for(int i : store){
                // cout << "stroe : " << i << endl;
                maxheap.push(i);
            }
            if(maxheap.empty() && store.empty()) return time;
            time += cycle;
            // cout << "time : " << time << endl;
        }

        return time;
    }
    int leastIntervaltemp(vector<char>& tasks, int n) {

        auto compare = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(compare)>
            maxheap(compare);

        queue<pair<int, int>> q;
        pair<int, int> curr;

        map<int, int> freq;
        for (char i : tasks) {
            freq[i]++;
        }

        for (auto i : freq) {
            cout << i.first << " : " << i.second << endl;
            maxheap.push({i.second, 0});
            // cout << i.second << "-:-" << 0 << endl;
        }
        int t = 0;
        while (!maxheap.empty()) {
            curr = maxheap.top();
            if (curr.first > 0 && t - curr.second >= 0) {
                // cout << curr.first << " : " << curr.second << " - " << t <<
                // endl;
                curr.first--;
                maxheap.pop();
                if (curr.first > 0)
                    maxheap.push({curr.first, t + n + 1});
            } else {
                // cout << curr.first << " : " << curr.second << " idle : " << t
                // << endl;
            }
            t++;
        }

        // while(!q.empty()){
        //     curr = q.front();
        //     if(curr.first>0 && t-curr.second >=0){
        //         cout << curr.first << " : " << curr.second << " - " << t <<
        //         endl; curr.first--; q.pop(); if(curr.first>0){
        //             cout << "a : " << curr.first << " : " << t+n+1 << " - "
        //             << t << endl; q.push({curr.first, t+n+1});
        //         }
        //     }
        //     else{
        //         cout << curr.first << " : " << curr.second << " idle : " << t
        //         << endl;
        //     }
        //     t++;
        // }

        return t;
    }
    int leastInterval1(vector<char>& tasks, int n) {
        int freq[26], max = 0, maxcount = 0;

        for (char i : tasks) {
            freq[i - 'A']++;

            if (freq[i - 'A'] > max) {
                max = freq[i - 'A'];
                maxcount = 1;
            } else if (freq[i - 'A'] == max) {
                maxcount++;
            }
        }

        // _ _ _ _ _ _ _ _ _ _
        // AB   AB   AB
        //

        // no of max slots
        int maxslots = max * maxcount;
        // total no. of tasks

        int blankseq = max - 1;
        int blankseqlen = n - (maxcount - 1);
        // calculate blank slots
        int emptyslots = blankseq * blankseqlen;

        // no. of non max tasks = totaltaks-maxslots
        int nonmaxtasks = tasks.size() - maxslots;

        int idleslots = std::max(0, emptyslots - nonmaxtasks);

        return tasks.size() + idleslots;
    }
};