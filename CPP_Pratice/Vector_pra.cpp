// CPP program to demonstrate working of Vector
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include<vector>
using namespace std;

int main() {

    vector<int> vc1 ;
    vc1 = {1,4,5,6};
    cout << vc1[0] << endl;

    cout << "---------" << endl;

     for (int i : vc1)
    {
        cout << i << endl;
    }

    cout << "---------" << endl;

    vc1.assign({10,20,30});
    vc1.resize(2);
    vc1.resize(3);
    cout << "---------" << endl;
    cout << vc1.capacity() << endl;
    cout << vc1.size() << endl;
    cout << vc1.max_size() << endl;
    vc1.push_back(100);
    vc1.erase(++vc1.begin(), --vc1.end());
    vc1.emplace(++vc1.begin(), 200);
    int c = 30;
    vc1.emplace_back(c);
    c = 300;
    vc1.push_back(c);
    c=400;
    cout << "---------" << endl;
    vc1.shrink_to_fit();
    cout << "---------" << endl;
    cout << vc1.capacity() << endl;
    cout << vc1.size() << endl;
    cout << vc1.max_size() << endl;
    cout << "---------" << endl;
    // vc1.


    for (int i : vc1)
    {
        cout << i << endl;
    }
    
    
    return 0;
};