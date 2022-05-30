#include "std_lib_facilities.h"
#include <list>

//1.
struct Item { 
	string name; 
	int iid; 
	double value;

};

istream& operator>>(istream& is, Item& it){
	is >> it.name >> it.iid >> it.value;
	Item {it.name,it.iid,it.value};
	return is;
}

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << ' '
              << it.iid << ' '
              << it.value;
}


template<typename T>
void print(T v, char space = ' '){
	for(auto& a : v){
		cout << a << space << '\n';
	}
}


//2
struct sort_by_name{
	bool operator()(Item& it1, Item& it2)
			{ return it1.name < it2.name;}
};

//3
struct sort_by_id{
	bool operator()(Item& it1, Item& it2)
			{ return it1.iid < it2.iid;}
};

//4
struct sort_by_value{
	bool operator()(Item& it1, Item& it2)
			{ return it1.value > it2.value;}
};


// 6.
class erase_name {
    string name;
public:
    erase_name(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};


// 7.
class erase_iid {
    int iid;
public:
    erase_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};


int main(){
	//1
	vector<Item> vi;
	
	ifstream ifile {"things.txt"};
	for(Item it; ifile >> it;){
		vi.push_back(it);
	}
	cout << "Base vector:\n";
	print(vi);

	
	
	//2
	sort(vi.begin(),vi.end(),[](const Item& it1, const Item& it2) { return it1.name < it2.name;});
	cout << "\nSort by name:\n";
	print(vi);
	
	//3
	sort(vi.begin(),vi.end(),[](const Item& it1, const Item& it2) { return it1.iid < it2.iid;});
	cout << "\nSort by iid:\n";
	print(vi);

	//4
	sort(vi.begin(),vi.end(),[](const Item& it1, const Item& it2) { return it1.value > it2.value;});
	cout << "\nSort by value desc:\n";
	print(vi);

	//5
	vi.push_back(Item {"horse shoe",99,12.34}); 
	vi.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nAfter addition:\n";
	//print(vi);
	
	
	// 6.
	vi.erase(find_if(vi.begin(), vi.end(), erase_name("salt")));
	vi.erase(find_if(vi.begin(), vi.end(), erase_name("aple")));
	
	// 7.
	vi.erase(find_if(vi.begin(), vi.end(), erase_iid(12)));
	vi.erase(find_if(vi.begin(), vi.end(), erase_iid(2002)));
	
	cout << "\nAfter erasure:\n";
	//print(vi);
	
	ifile.close();
	
	
	//8
	
	
	list<Item> li;
	ifile.open("things.txt");
	for(Item it; ifile >> it;) li.push_back(it);
	cout << "\nBase list\n";
	//print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
	cout << "\nSort by name:\n";
	//print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
	cout << "\nSort by iid:\n";
	//print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
	cout << "\nSort by value desc:\n";
	//print(li);
	
	li.push_back(Item {"horse shoe",99,12.34}); 
	li.push_back(Item {"Canon S400", 9988,499.95});
	
	cout << "\nAfter addition:\n";
	//print(li);
	
	li.erase(find_if(li.begin(), li.end(), erase_name("salt")));
	li.erase(find_if(li.begin(), li.end(), erase_name("aple")));

	li.erase(find_if(li.begin(), li.end(), erase_iid(12)));
	li.erase(find_if(li.begin(), li.end(), erase_iid(2002)));
	
	cout << "\nAfter erasure:\n";
	//print(li);
	
	ifile.close();
}

