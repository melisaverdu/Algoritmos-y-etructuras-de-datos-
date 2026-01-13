#include <iostream>
#include <string>

using namespace std;

int buscaBin(int db,int a[],int p,int f)
{
	if(p>f) return -1;
	int m=(p+f)/2;
	if (a[m]==db)return m;
	
	if (a[m]>db) return buscaBin(db,a,p,m-1);
	else		 return buscaBin(db,a,m+1,f);
}
int main()
{	int v[10]={1,5,9,10,15,17,22,25,26,30};
	
	int x=25;
	int pos=buscaBin(x,v,0,9);
	if (pos==-1)cout<<"El dato no esta"<<endl;
	else cout<<"el dato esta en "<<pos<<endl;
		
	return 0;
}