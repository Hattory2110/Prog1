#include "std_lib_facilities.h"
#include <map>

//3
template<typename T>
void print(T v, char space = ' '){
	for(auto& a : v)
		cout << a.first << space << a.second << '\n';
}


//5
void read(map<string, int>& m)
{
    string s;
    int k = 0;
        for(int i=0; i<10; i++){
        	cin >> s >> k;
       	m.insert(make_pair(s, k));
        }
    }

int main(){
	//1
	map<string,int> msi;
	
	//2
	msi["Lecture"] = 21;
	msi["PC"] = 31;
	msi["Book"] = 41;
	msi["Pen"] = 51;
	msi["Laptop"] = 91;
	msi["Pendrive"] = 71;
	msi["Shirt"] = 29;
	msi["Game"] = 23;
	msi["Noise"] = 33;
	msi["etc"] = 55;
	
	
	//3
	print(msi);
	
	//4
	msi.erase(msi.begin(),msi.end());
	
	//6
	cout << "\nWrite data! (name, id):\n";
	read(msi);
	
	//7
	cout << "\n Inserted data:\n";
	print(msi);
	
	int sum = 0;
	for(auto& a : msi)
		sum +=  a.second;
	cout << "Sum of values: " << sum << '\n';
	
	map<int, string> mis;
	
	for (const auto& a : msi)
        mis[a.second] = a.first;
    	cout << "\nInverted map:\n";
    	print(mis);
}

