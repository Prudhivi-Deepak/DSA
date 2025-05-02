// CPP program to demonstrate working of array
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include<vector>
using namespace std;

int main() {

// construction uses aggregate initialization
// double-braces required
array<int, 5> ar1{{3, 4, 5, 1, 2}};
array<int, 5> ar2 = {1, 2, 3, 4, 5};
array<string, 2> ar3 = {{string("a"), "b"}};


cout << ar1.data() << endl;
cout << &ar1 << endl;
cout << &ar1[0] << endl;
cout << ar1.cbegin()  << endl;
cout << ar1.begin()  << endl;


cout << "Sizes of arrays are" << endl;
cout << ar1.size() << endl;
cout << ar2.size() << endl;
cout << ar3.size() << endl;

cout << "\nInitial ar1 : ";
for (auto i : ar1)
	cout << i << ' ';

// container operations are supported
sort(ar1.begin(), ar1.end());

cout << "\nsorted ar1 : ";
for (auto i : ar1)
	cout << i << ' ';

// Filling ar2 with 10
ar2.fill(10);

cout << "\nFilled ar2 : ";
for (auto i : ar2)
	cout << i << ' ';


// ranged for loop is supported
cout << "\nar3 : ";
for (auto &s : ar3)
	cout << s << ' ';

array <int , 3> arr={'G','f','G'};  // ASCII val of 'G' =71 
array <int , 3> arr1={'M','M','P'}; // ASCII val of 'M' = 77 and 'P' = 80
arr.swap(arr1);  // now arr = {M,M,P}
cout<<arr.front() <<" "<<arr.back();




int a=14, b=9;
// swap(a,b);
vector<int> sg (4,a), ss (6,b);
cout << endl;
cout << &sg << endl;
cout << &ss << endl;

cout << "Only values and size got changed not the address" << endl;
cout << "\nsg contains:";
for (vector<int>::iterator ti=sg.begin(); ti!=sg.end(); ti++)
	cout << ' ' << *ti;
cout << '\n';

cout << "ss contains:";
for (vector<int>::iterator ti=ss.begin(); ti!=ss.end(); ti++)
	cout << ' ' << *ti;
cout << '\n';
swap(sg,ss);
cout << &sg << endl;
cout << &ss << endl;
cout << "\nsg contains:";
for (vector<int>::iterator ti=sg.begin(); ti!=sg.end(); ti++)
	cout << ' ' << *ti;
cout << '\n';

cout << "ss contains:";
for (vector<int>::iterator ti=ss.begin(); ti!=ss.end(); ti++)
	cout << ' ' << *ti;
cout << '\n';

// ar2.

return 0;
}
