#include<iostream>
#include "racional.cpp"
using namespace std;

int main(){

	racional rac1(-3,4);
	racional rac2(-4,12);
	racional rac_neg(-3,9);
	rac1 = rac2 + rac_neg; // 2/3
	rac2 = rac1 / rac1; // PREGUNTAR SI TIENE QUE ABORTAR la hacer 0/0
	racional rac3(rac1); //2/3
	int n1=rac1.num();
	int m1=rac1.denom();
	int n2=rac2.num();
	int m2=rac2.denom();
	int n3=rac_neg.num();
	int m3=rac_neg.denom();
	int n4=rac3.num();
	int m4=rac3.denom();
	
	racional resi = rac3.residu();
	int res1 = resi.num();
	int res2 = resi.denom();
	
	bool menor = rac1 < rac2;
	bool mayor = rac1 > rac2;
	bool igual = rac1 >= rac1;
	bool igual2 = rac1 <= rac1;
	
	
	cout << menor << ' ' << mayor << ' ' << igual << ' ' << igual2 << ' ' << endl;
	cout << n1 << '/' << m1 << endl;
	cout << n2 << '/' << m2 << endl;
	cout << n3 << '/' << m3 << endl;
	cout << n4 << '/' << m4 << endl;
	cout << rac3.part_entera() << endl;
	cout << res1 << '/' << res2 << endl;


}
