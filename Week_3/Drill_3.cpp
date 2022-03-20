#include "std_lib_facilities.h"

class B1
{

public:
	void virtual pvf()=0;		//can't create an object, because of the pure virtual function
	void virtual vf() { cout<<"B1::vf"<<"\n"; } ;
	void f() { cout<<"B1::f"<<"\n"; };
};

class D1 : public B1		//D1 derived class of B1
{
public:
	void pvf() { cout<<"D1::pvf"<<"\n"; };
	void vf() { cout<<"D1::vf"<<"\n"; };
	void f() { cout<<"D1::f"<<"\n"; };		//without this it uses the B1's f() function

};

class D2 : public D1
{
public:
	void pvf() { cout<<"D2::pvf"<<"\n"; } ;
	void vf() { cout<<"D2::vf"<<"\n"; } ;
	void f() { cout<<"D2::f"<<"\n"; };	


};

class B2
{
public:
	void virtual pvf()=0;
};

class D21 : public B2
{
public:
	string s= "string";
	void pvf() {cout << s <<'\n';}
};

class D22 : public B2
{
public:
	int i= 6;
	void pvf() {cout << i <<'\n';}
};

void f(B2& b)
{
	b.pvf();
}

int main()
{
	/*B1 o1;		//can not declare B1 type, because it is abstact
	o1.vf();
	o1.f();
	*/
	
	D1 o2;
	o2.pvf();		//overwrites the function (it is nesesery)
	o2.vf();
	o2.f();		//because we overwritten it in D2 it displays that
	
	D1 o3;
	B1& bref {o3};
	bref.pvf();		//it is overwritten so it uses the D1
	bref.vf();		//try to use the default, but it is virtual and overwritten in D1 so it uses that
	bref.f();		//uses the default f() in B1
	
	D2 o4;
	o4.pvf();
	o4.vf();
	o4.f();
	
	D21 o5;
	D22 o6;
	
	f(o5);
	f(o6);
}
