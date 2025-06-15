/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void evenOdd(int n) {
	if(n%2==0) {
		cout<<"Number is even";
	} else {
		cout<<"Number is odd";
	}
}

void Prime(int n) {
	int i;
	if(n<=1) {
		cout<<"Is Not Prime Number";
		return;
	}
	for(i=2; i<n; i++) {
		if(n%i==0) {
			cout<<"is Not Prime Number";
			return;
		}
	}
	cout<<"is Prime Number";
}

void factorial(int n) {
	int i,result;
	result=n;
	for(i=n-1; i>=n; i--) {
		result=result*i;
	}
	cout<<result;
}

void fibonacci(int n) {
	int i,a=0, b=1, c;
	for(i=0; i<n; i++) {
		cout<<a;
		c=a+b;
		a=b;
		b=c;
	}
}

void sumArr(int n) {
	int rows, columns;

	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of column: ";
	cin >> columns;
	int arr1[rows][columns];
	int arr2[rows][columns];
	int sum[rows][columns];

	cout << "1st array:"<<endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {

			cout << "arr1[" << i << "][" << j << "] = ";
			cin >> arr1[i][j];
		}
	}
	cout << "2nd Array:"<<endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << "arr2["<<i<<"]["<<j<<"]=";
			cin >> arr2[i][j];
		}
	}
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			sum[i][j] = arr1[i][j] + arr2[i][j];
		}
	}




	cout << "1st Array: "<<endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << arr1[i][j] << "\t";
		}
		cout <<endl;
	}

	cout << "2nd Array: "<<endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << arr2[i][j] << "\t";
		}
		cout <<endl;
	}
	cout << "Sum: "<<endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			cout << sum[i][j] << "\t";
		}
		cout <<endl;
	}

}
int main()
{
	int n,choice;
	cout << "1. Check Even/Odd" << endl;
	cout << "2. Calculate Factorial" << endl;
	cout << "3. Check Prime" << endl;
	cout << "4. Print Fibonacci Series" << endl;
	cout << "5. Sum of Arrays" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "Enter Number: ";
	cin >> n;
	switch(choice) {
	case 1:
		evenOdd(n);
		break;
	case 2:
		Prime(n);
		break;
	case 3:
		factorial(n);
		break;
	case 4:
		fibonacci(n);
		break;
	case 5:
		sumArr(n);
		break;
	default:
		cout<<"Invalid input";
	}

}
