#include "std_lib_facilities.h"

template<typename T> struct S
{
	S(T t) : val(t) {};
	
	T& get_val();
	const T& get_val() const;
	void operator=(const T& t);
	//void set_val(T& t) {val=t;}
	void read_val();
	
private:
	T val;	
};
//template<typename T> void S<T>::set_val(T t){val=t;}
template<typename T> void S<T>::operator=(const T& t){val=t;}

template<typename T> const T& S<T>::get_val() const {return val;}
template<typename T> T& S<T>::get_val() {return val;}

template<typename T> void S<T>::read_val() {cin >> val;}


ostream& operator<<(ostream& os, const vector<int>& v)
{
	os << '{';

	for (int i = 0; i < v.size(); ++i)
	{
		if(i<v.size()-1)
			os << v[i]<<", ";
		else
			os << v[i];
	}

	os << '}' << "\n";

	return os;
}

istream& operator>>(istream& is, vector<int>& v)
{
	char c1, c2, c3, c4;
	int i1, i2, i3;
	
	is>>c1>>i1>>c2>>i2>>c3>>i3>>c4;
	
	if (!(c1=='{' && c4=='}' && c2==',' && c3==',' ))
	{
		error("bad format for vector");
		return is;
	}
		
	v.push_back(i1);
	v.push_back(i2);
	v.push_back(i3);
	return is;
}

int main()
try{
	S<int> si(1);
	S<char> sc('a');
	S<double> sd(6.6);
	S<string> sstr("alma");
	S<vector<int>> sv(vector<int> {10,20,30});

	cout << "int: " << si.get_val() << "\n";
	cout << "char: " << sc.get_val() << "\n";
	cout << "double: " << sd.get_val() << "\n";
	cout << "string: " << sstr.get_val() << "\n";
	cout<< "vector<int>: "<< sv.get_val() << "\n";	
	
	cout<< "Enter a int values in {int, int, int} format: ";
	cin >> sv.get_val();

	cout<< "vector<int>: "<< sv.get_val() << endl;
}catch(exception&e){
	cerr << "Exception: " << e.what() << "\n";
}catch (...) {
	cerr << "Exception \n";
}
