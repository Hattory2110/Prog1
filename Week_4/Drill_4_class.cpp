#include "std_lib_facilities.h"


struct Person 
{
	
	Person() : f_name (""), l_name(""), age(0) {};
	Person(string fn, string ln, int a) : f_name(fn), l_name(ln), age(a) 
	{
		const string contraband_char =" ; : \" ' [ ] * & ^ % $ # @ !";
		for(int i=0; i<fn.size(); ++i)
			for(int j=0; j<contraband_char.size(); ++j)
				if (fn[i]==contraband_char[j])
					error("Illegal character in first name: ", string(1,fn[i]));
					
		for(int i=0; i<ln.size(); ++i)
			for(int j=0; j<contraband_char.size(); ++j)
				if (ln[i]==contraband_char[j])
					error("Illegal character in last name: ", string(1,ln[i]));
		if(age<0 || age>150)
			error("Age must be between 0-150.");
	};

	string get_fname() const {return f_name;}
	string get_lname() const {return l_name;}
	int get_age() const {return age;}
private:
	string f_name;
	string l_name;
	int age;
};

istream& operator>>(istream& is, Person& per)
{
	string fname;
	string lname;
	int age;
	is>> fname >> lname >> age;
	
	if (!is) 
		return is;

	per = Person(fname, lname, age);
	return is;

}

ostream& operator<<(ostream& os, const Person& per)
{
	return os<< "Name: " << per.get_fname() << " " << per.get_lname() <<" Age: " << per.get_age() << "\n";

}

int main()
try {
	/*		Private
	Person p;
	p.name="Goofy";
	p.age=63;
	
	cout << p.name <<" "<< p.age <<"\n";
	*/
	
	Person gof=Person("Goofy", "Goofiest", 63);
	cout << gof;
	
	Person person;
	cin >> person;
	
	cout<< person;

	vector<Person> people;
	Person persons;
	cout << "Write some example persons! Format: First_name Last_name Age \n";

	while(cin>>persons)
		people.push_back(persons);
		
	for(int i=0; i<people.size(); ++i)
		cout<< people[i] << "\n";


	keep_window_open();
} 
catch (exception& e) {
	cerr << "Exception: " << e.what() << "\n";
	keep_window_open();
}
catch (...) {
	cerr << "Exception \n";
	keep_window_open();
}

