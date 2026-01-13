#include <iostream>
#include <string>

using namespace std;

int size(string x)
{	
	if (x=="" ){
		cout<<endl<<"llegue al Caso Base"<<endl;
		return 0;
    }
	else{// caso recursivo
		cout<<endl<<"yendo "<<x;
		int a=size(x.substr(1));
		cout<<"volviendo "<<a<<endl;
		return 1 + a;
	}
}

int main()
{	string a="Hola mundo";
	
	cout<<"longitud del string= "<<size(a)<<a<<endl;
	
	return 0;
}