#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

string b[9], d[9], u[9], l[9], r[9], f[9], h;
int k;

//// Moves
void U()
{
	for (int i=0; i<3; i++) h= r[i], r[i]= b[i], b[i]= l[i], l[i]= f[i], f[i]= h;
	h=u[0], u[0]= u[6], u[6]= u[8], u[8]= u[2], u[2]= h, h= u[1], u[1]= u[3], u[3]= u[7], u[7]= u[5], u[5]= h;
	cout << "U ";
} 
void UP()
{
	for (int i=0; i<3; i++) h= r[i], r[i]= f[i], f[i]= l[i], l[i]= b[i], b[i]= h;
	h=u[0], u[0]= u[2], u[2]= u[8], u[8]= u[6], u[6]= h, h= u[1], u[1]= u[5], u[5]= u[7], u[7]= u[3], u[3]= h;
	cout << "U' ";
}
void D()
{
	for (int i=6; i<9; i++) h= r[i], r[i]= f[i], f[i]= l[i], l[i]= b[i], b[i]= h;
	h=d[0], d[0]= d[6], d[6]= d[8], d[8]= d[2], d[2]= h, h= d[1], d[1]= d[3], d[3]= d[7], d[7]= d[5], d[5]= h;
	cout << "D ";
}
void DP()
{
	for (int i=6; i<9; i++) h= r[i], r[i]= b[i], b[i]= l[i], l[i]= f[i], f[i]= h;
	h=d[0], d[0]= d[2], d[2]= d[8], d[8]= d[6], d[6]= h, h= d[1], d[1]= d[5], d[5]= d[7], d[7]= d[3], d[3]= h;
	cout << "D' ";
}
void R()
{
	for (int i=2; i<9; i+=3) h= f[i], f[i]= d[i], d[i]= b[8-i], b[8-i]= u[i], u[i]= h;
	h=r[0], r[0]= r[6], r[6]= r[8], r[8]= r[2], r[2]= h, h= r[1], r[1]= r[3], r[3]= r[7], r[7]= r[5], r[5]= h;
	cout << "R ";
}
void RP()
{
	for (int i=2; i<9; i+=3) h= f[i], f[i]= u[i], u[i]= b[8-i], b[8-i]= d[i], d[i]= h;
	h=r[0], r[0]= r[2], r[2]= r[8], r[8]= r[6], r[6]= h, h= r[1], r[1]= r[5], r[5]= r[7], r[7]= r[3], r[3]= h;
	cout << "R' ";
}
void L()
{
	for (int i=0; i<7; i+=3) h= f[i], f[i]= u[i], u[i]= b[8-i], b[8-i]= d[i], d[i]= h;
	h=l[0], l[0]= l[6], l[6]= l[8], l[8]= l[2], l[2]= h, h= l[1], l[1]= l[3], l[3]= l[7], l[7]= l[5], l[5]= h;
	cout << "L ";
}
void LP()
{
	for (int i=0; i<7; i+=3) h= f[i], f[i]= d[i], d[i]= b[8-i], b[8-i]= u[i], u[i]= h;
	h=l[0], l[0]= l[2], l[2]= l[8], l[8]= l[6], l[6]= h, h= l[1], l[1]= l[5], l[5]= l[7], l[7]= l[3], l[3]= h;
	cout<< "L' ";
}
void F()
{
	h= u[6], u[6]= l[8], l[8]= d[2], d[2]= r[0], r[0]= h, h= u[7], u[7]= l[5], l[5]= d[1], d[1]= r[3], r[3]= h, h= u[8], u[8]= l[2], l[2]= d[0], d[0]= r[6], r[6]= h;
	h=f[0], f[0]= f[6], f[6]= f[8], f[8]= f[2], f[2]= h, h= f[1], f[1]= f[3], f[3]= f[7], f[7]= f[5], f[5]= h;
	cout<< "F ";
}
void FP()
{
	h= u[6], u[6]= r[0], r[0]= d[2], d[2]= l[8], l[8]= h, h= u[7], u[7]= r[3], r[3]= d[1], d[1]= l[5], l[5]= h, h= u[8], u[8]= r[6], r[6]= d[0], d[0]= l[2], l[2]= h;
	h=f[0], f[0]= f[2], f[2]= f[8], f[8]= f[6], f[6]= h, h= f[1], f[1]= f[5], f[5]= f[7], f[7]= f[3], f[3]= h;
	cout<< "F' ";
}
void B()
{
	h= u[0], u[0]= r[2], r[2]= d[8], d[8]= l[6], l[6]= h, h= u[1], u[1]= r[5], r[5]= d[7], d[7]= l[3], l[3]= h, h= u[2], u[2]= r[8], r[8]= d[6], d[6]= l[0], l[0]= h;
	h=b[0], b[0]= b[6], b[6]= b[8], b[8]= b[2], b[2]= h, h= b[1], b[1]= b[3], b[3]= b[7], b[7]= b[5], b[5]= h;
	cout<< "B ";
}
void BP()
{
	h= u[0], u[0]= l[6], l[6]= d[8], d[8]= r[2], r[2]= h, h= u[1], u[1]= l[3], l[3]= d[7], d[7]= r[5], r[5]= h, h= u[2], u[2]= l[0], l[0]= d[6], d[6]= r[8], r[8]= h;
	h=b[0], b[0]= b[2], b[2]= b[8], b[8]= b[6], b[6]= h, h= b[1], b[1]= b[5], b[5]= b[7], b[7]= b[3], b[3]= h;
	cout<< "B' ";
}
void U2() {U(); U();}
void D2() {D(); D();}
void R2() {R(); R();}
void L2() {L(); L();}
void F2() {F(); F();}
void B2() {B(); B();}
 
int main()
{
	srand(time(0));
	for (int i=0; i<9; i++) d[i]="s";
	for (int i=0; i<9; i++) f[i]="n";
	for (int i=0; i<9; i++) r[i]="a";
	for (int i=0; i<9; i++) b[i]="g";
	for (int i=0; i<9; i++) l[i]="sa";
	for (int i=0; i<9; i++) u[i]="z";
	cout<< endl;	
	
	for (int i=0; i<50; i++)
	{
		k= rand()%13;
		if (k==1) U();
		else if (k==2) D();
		else if (k==3) R();
		else if (k==4) L();
		else if (k==5) B();
		else if (k==6) F();
		else if (k==7) UP();
		else if (k==2) DP();
		else if (k==3) RP();
		else if (k==4) LP();
		else if (k==5) BP();
		else if (k==6) FP();
		
	}
	
	
	cout<< endl;
	for (int i=0; i<9; i++) cout<< d[i]<<" ";
	cout<< endl;
	for (int i=0; i<9; i++) cout<< f[i]<<" ";
	cout<< endl;
	for (int i=0; i<9; i++) cout<< r[i]<<" ";
	cout<< endl;
	for (int i=0; i<9; i++) cout<<  b[i]<<" ";
	cout<< endl;
	for (int i=0; i<9; i++) cout<<  l[i]<<" ";
	cout<< endl;
	for (int i=0; i<9; i++) cout<<  u[i]<<" ";
	cout<< endl;
	
	return 0;
}
