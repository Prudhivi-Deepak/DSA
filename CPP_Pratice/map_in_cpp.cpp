#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> m = {{1, "one"},
           {2, "two"}, {4, "three"}};
    m.insert({3,"gug"});

    // Printing all elements in the map
    for (auto it = m.begin(); it != m.end();
         ++it)
        cout << it->first << ": " << it->second
                  << endl;

    return 0;
}