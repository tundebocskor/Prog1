 #include <iostream>
#include <iomanip>
#include <complex>
#include <algorithm>
#include <cerrno>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;
//Akkor használunk pointert, ha szükségünk van rá.. az int* pl

int main()
try{
	//1
cout <<"sizeof:\n";
cout <<"char\t" <<sizeof(char) << '\n';
cout <<"short\t" <<sizeof(short) << '\n';
cout <<"int\t" <<sizeof(int) << '\n';
cout <<"long\t" <<sizeof(long) << '\n';
cout <<"float\t" <<sizeof(float) << '\n';
cout <<"double\t" <<sizeof(double) << '\n';
cout <<"int*\t" <<sizeof(int*) << '\n';
cout <<"double*\t" <<sizeof(double*) << '\n';

//2
cout <<"Matrix size: \n";
Matrix<int> a(10);
Matrix<int> b(100);
Matrix<double> c(10);
Matrix<int, 2> d(10, 10);
Matrix<int, 3> e(10, 10, 10);

cout << "10 int, 10elem   \t\t" <<sizeof(a) <<'\n';
cout << "10 int, 100elem  \t\t" <<sizeof(b) <<'\n';
cout << "10 double, 10elem\t\t" <<sizeof(c) <<'\n';
cout << "2D int, 10x10    \t\t" <<sizeof(d) <<'\n';
cout << "3D int, 10x10x10 \t\t" <<sizeof(e) <<'\n';

//Matrix.h 64 sor funktorok... 
//320 aS sorok.. operátorok, amik funktorokat hívunk meg 
//INdex forciklus ... Matrix.h 37 long tipus a matrixon belül 

//3. feladat. 
cout << "\nNumber of elements:\n";
cout <<"a:\t" <<a.size() <<'\n';
cout <<"b:\t" <<b.size() <<'\n';
cout <<"c:\t" <<c.size() <<'\n';
cout <<"d:\t" <<d.size() <<'\n';
cout <<"e:\t" <<e.size() <<'\n';
//4. 
int beker =0;
cout <<"Enter a number: ";
cin >> beker ;

cout << "A szám négyzetgyöke: " << std::sqrt(beker) <<'\n';
double vissza = sqrt(beker);
cout << "Return values: " << vissza <<"*" << vissza <<" = " << vissza*vissza <<'\n';

	//5.
	cout << "Enter 10 float ";
	Matrix<double>  m(10);
	double f;
	for(int i=0; i< m.size(); i++){
		cin >> f;
		if(!cin) throw runtime_error("Problem reading from cin");
		m[i]=f;
	}
	cout << "Matrix: \n" << m << '\n';
	//6.
	cout << "mult table ";
	int n;
	cin >> n;
	cout<<"Enter m:";
	int m2;
	cin >> m2;
	Matrix<int,2> mtable(n,m2);
	for(Index i = 0 ;i<mtable.dim1();++i){ //Index-Matrix.h
		for(Index j = 0; j<mtable.dim2();++j){
		mtable(i,j) = (i+1)*(j+1);
		cout << setw(5) << mtable(i,j);		//setw width
		}
		cout<< '\n';
	}
	//7.
	Matrix <complex<double>> m3(10);
	cout << "\n enter 10 complex numbers (Re,Im):";
	complex<double> comp;
	for(int i=0;i<10;++i){
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading from cin");
		m3[i] = comp;
		
	}
	cout << m3;
	complex <double> sum;
	for(Index i=0; i<m3.size();++i){
		sum+=m3[i];
	
	}
	cout << "sum:" << sum <<'\n';
	//8.
	Matrix<int,2> m4(2,3);
	cout<< "\n Enter six ints";
	int num ;
	for (int i=0; i<m4.dim1();++i){
		for(int j=0; j<m4.dim2();++j){
			cin >>num;
			m4(i,j) =num; 
		}
	
		
	}
	cout << "Matrix: \n " <<m4 <<'\n';
	

	
	

	
	
}catch(std::exception& e){
	std::cerr << "exeption: " <<e.what() << '\n';
	return 1;
}catch (...){
	std::cerr << "unknow exception \n";
	return 2;
}
