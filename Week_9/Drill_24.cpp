#include "std_lib_facilities.h"
#include "matrix.h"
#include <complex>

using Numeric_lib::Matrix;

void print_sqrt(){
	int v;
	cin >> v;
	if(v<0){
		cout << "\nNegative sqrt is invalid\n";
	}
	else{
		cout << sqrt(v) << "\n";
	}
}


int main(){

    // 1.
    cout << "Size of containers:\n"
         << "char: " << sizeof(char) << '\n'
         << "short: " << sizeof(short) << '\n'
         << "int: " << sizeof(int) << '\n'
         << "long: " << sizeof(long) << '\n'
         << "float: " << sizeof(float) << '\n'
         << "double: " << sizeof(double) << '\n'
         << "int*: " << sizeof(int*) << '\n'
         << "double*: " << sizeof(double*) << "\n\n";
    
    //2
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "Size of matricies:\n"
              << "Matrix<int>(10): " << sizeof(a) << '\n'
              << "Matrix<int>(100): " << sizeof(b) << '\n'
              << "Matrix<double>(10): " << sizeof(c) << '\n'
              << "Matrix<int,2>(10,10): " << sizeof(d) << '\n'
              << "Matrix<int,3>(10,10,10): " << sizeof(e) << "\n\n";
    
    // 3
    cout << "Number of elements in matricies:\n"
              << "Matrix<int>(10): " << a.size() << '\n'
              << "Matrix<int>(100): " << b.size() << '\n'
              << "Matrix<double>(10): " << c.size() << '\n'
              << "Matrix<int,2>(10,10): " << d.size() << '\n'
              << "Matrix<int,3>(10,10,10): " << e.size() << "\n\n";
    
    //4
    cout << "Wrire an int for sqrt:\n";
    for(int i=0; i<8; i++){
    	print_sqrt();
    }
	
    //5
    cout << "\nWrite 10 float:\n";
    Matrix<double> num(10);
    for(int i=0; i<10; i++){
    	cin >> num[i];
    }
    
    cout << "\nValues of the matrix:\n";
    for (int i = 0; i < num.size(); ++i)
	{
		cout << num[i] << "\n";
	}
	
    //6
    cout << "\nSize of the dimension of the matrix (dim1, dim2):\n";
    int d1, d2;
    cin >> d1 >> d2;
    cout << "\n";
    
    
    Matrix<double,2> md2(d1,d2);

    for (int i = 0; i < d1; ++i)
        for (int j = 0; j < d2; ++j)
            md2(i,j) = i*10+j;
            
    for(int i = 0; i < md2.dim1(); i++){
    	for(int j = 0; j < md2.dim2(); j++){
    		cout << "\t" << md2(i,j);
    	}
    	cout << "\n";
    }
    
    
    //7
    cout << "\nEnter 10 complex numbers:\n";
    Matrix<complex<double>> cmatrix(10);
    for(int i=0; i<cmatrix.size();i++){
    	cin >> cmatrix[i];
    }
    
    cout << "\nSum:\n" << accumulate(cmatrix.data(), cmatrix.data() + cmatrix.size(),complex<double>{}) << "\n"; 
    
    	
    	
    // 8.
    cout << "\nWrite 6 ints for matrix (2-by-3)\n";
    Matrix<int,2> mi2 (2,3);
    for (int i = 0; i < mi2.dim1(); ++i)
        for (int j = 0; j < mi2.dim2(); ++j)
            std::cin >> mi2[i][j];

    for(int i = 0; i < mi2.dim1(); i++){
    	for(int j = 0; j < mi2.dim2(); j++){
    		cout << "\t" << mi2(i,j);
    	}
    	cout << "\n";
    }
}


