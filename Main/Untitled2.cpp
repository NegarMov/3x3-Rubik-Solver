#include <iostream>
#include <string>
using namespace std;

string b[9], d[9], u[9], l[9], r[9], f[9], h, co, a[1000] ,aa[1000];
int s, k, ca, cb, cc, cd, esn, esg, ean, eag, n, t, x;  // a= sa/g, b= sa/n, c= a/n, d=a/g 

//// Edge and corners position check
void echeck()
{
	if (u[1]=="a")
	{
		if (b[1]=="g") eag= 70;
		else if (b[1]=="n") ean= 71;
	}
	if (u[3]=="a")
	{
		if (l[1]=="g") eag= 80;
		else if (l[1]=="n") ean= 81;
	}
	if (u[5]=="a")
	{
		if (r[1]=="g") eag= 60;
		else if (r[1]=="n") ean= 61;
	}
	if (u[7]=="a")
	{
		if (f[1]=="g") eag= 50;
		else if (f[1]=="n") ean= 51;
	}
	if (u[1]=="sa")
	{
		if (b[1]=="g") esg= 71;
		else if (b[1]=="n") esn= 70;
	}
	if (u[3]=="sa")
	{
		if (l[1]=="g") esg= 81;
		else if (l[1]=="n") esn= 80;
	}
	if (u[5]=="sa")
	{
		if (r[1]=="g") esg= 61;
		else if (r[1]=="n") esn= 60;
	}
	if (u[7]=="sa")
	{
		if (f[1]=="g") esg= 51;
		else if (f[1]=="n") esn= 50;
	}
	if (u[1]=="g")
	{
		if (b[1]=="sa") esg= 70;
		else if (b[1]=="a") eag= 71;
	}
	if (u[3]=="g")
	{
		if (l[1]=="sa") esg= 80;
		else if (l[1]=="a") eag= 81;
	}
	if (u[5]=="g")
	{
		if (r[1]=="sa") esg= 60;
		else if (r[1]=="a") eag= 61;
	}
	if (u[7]=="g")
	{
		if (f[1]=="sa") esg= 50;
		else if (f[1]=="a") eag= 51;
	}
	if (u[1]=="n")
	{
		if (b[1]=="sa") esn= 71;
		else if (b[1]=="a") ean= 70;
	}
	if (u[3]=="n")
	{
		if (l[1]=="sa") esn= 81;
		else if (l[1]=="a") ean= 80;
	}
	if (u[5]=="n")
	{
		if (r[1]=="sa") esn= 61;
		else if (r[1]=="a") ean= 60;
	}
	if (u[7]=="n")
	{
		if (f[1]=="sa") esn= 51;
		else if (f[1]=="a") ean= 50;
	}
	if (f[5]=="a")
	{
		if (r[3]=="g") eag= 11;
		else if (r[3]=="n") ean= 10;
	}
	if (r[5]=="a")
	{
		if (b[3]=="g") eag= 21;
		else if (b[3]=="n") ean= 20;
	}
	if (b[5]=="a")
	{
		if (l[3]=="g") eag= 31;
		else if (l[3]=="n") ean= 30;
	}
	if (l[5]=="a")
	{
		if (f[3]=="g") eag= 41;
		else if (f[3]=="n") ean= 40;
	}
	if (f[5]=="sa")
	{
		if (r[3]=="g") esg= 10;
		else if (r[3]=="n") esn= 11;
	}
	if (r[5]=="sa")
	{
		if (b[3]=="g") esg= 20;
		else if (b[3]=="n") esn= 21;
	}
	if (b[5]=="sa")
	{
		if (l[3]=="g") esg= 30;
		else if (l[3]=="n") esn= 31;
	}
	if (l[5]=="sa")
	{
		if (f[3]=="g") esg= 40;
		else if (f[3]=="n") esn= 41;
	}
	if (f[5]=="g")
	{
		if (r[3]=="a") eag= 10;
		else if (r[3]=="sa") esg= 11;
	}
	if (r[5]=="g")
	{
		if (b[3]=="a") eag= 20;
		else if (b[3]=="sa") esg= 21;
	}
	if (b[5]=="g")
	{
		if (l[3]=="a") eag= 30;
		else if (l[3]=="sa") esg= 31;
	}
	if (l[5]=="g")
	{
		if (f[3]=="a") eag= 40;
		else if (f[3]=="sa") esg= 41;
	}
	if (f[5]=="n")
	{
		if (r[3]=="a") ean= 11;
		else if (r[3]=="sa") esn= 10;
	}
	if (r[5]=="n")
	{
		if (b[3]=="a") ean= 21;
		else if (b[3]=="sa") esn= 20;
	}
	if (b[5]=="n")
	{
		if (l[3]=="a") ean= 31;
		else if (l[3]=="sa") esn= 30;
	}
	if (l[5]=="n")
	{
		if (f[3]=="a") ean= 41;
		else if (f[3]=="sa") esn= 40;
	}
}

void ccheck()
{
	if (u[0]=="s" || l[0]=="s" || b[2]=="s")
	{
		if (u[0]=="a" || l[0]=="a" || b[2]=="a")
		{
			if (u[0]=="n" || l[0]=="n" || b[2]=="n") cc=1;
			else cd=1;
		}
		else 
		{
			if (u[0]=="n" || l[0]=="n" || b[2]=="n") cb=1;
			else ca=1;
		}
	}
	if (u[2]=="s" || b[0]=="s" || r[2]=="s")
	{
		if (u[2]=="a" || b[0]=="a" || r[2]=="a")
		{
			if (u[2]=="n" || r[2]=="n" || b[0]=="n") cc=2;
			else cd=2;
		}
		else 
		{
			if (u[2]=="n" || b[0]=="n" || r[2]=="n") cb=2;
			else ca=2;
		}
	}
	if (u[6]=="s" || f[0]=="s" || l[2]=="s")
	{
		if (u[6]=="a" || f[0]=="a" || l[2]=="a")
		{
			if (u[6]=="n" || f[0]=="n" || l[2]=="n") cc=3;
			else cd=3;
		}
		else 
		{
			if (u[6]=="n" || f[0]=="n" || l[2]=="n") cb=3;
			else ca=3;
		}
	}
	if (u[8]=="s" || f[2]=="s" || r[0]=="s")
	{
		if (u[8]=="a" || f[2]=="a" || r[0]=="a")
		{
			if (u[8]=="n" || f[2]=="n" || r[0]=="n") cc=4;
			else cd=4;
		}
		else 
		{
			if (u[8]=="n" || f[2]=="n" || r[0]=="n") cb=4;
			else ca=4;
		}
	}
	if (d[0]=="s" || l[8]=="s" || f[6]=="s")
	{
		if (d[0]=="a" || l[8]=="a" || f[6]=="a")
		{
			if (d[0]=="n" || l[8]=="n" || f[6]=="n") cc=5;
			else cd=5;
		}
		else 
		{
			if (d[0]=="n" || l[8]=="n" || f[6]=="n") cb=5;
			else ca=5;
		}
	}
	if (d[2]=="s" || f[8]=="s" || r[6]=="s")
	{
		if (d[2]=="a" || f[8]=="a" || r[6]=="a")
		{
			if (d[2]=="n" || f[8]=="n" || r[6]=="n") cc=6;
			else cd=6;
		}
		else 
		{
			if (d[2]=="n" || f[8]=="n" || r[6]=="n") cb=6;
			else ca=6;
		}
	}
	if (d[6]=="s" || l[6]=="s" || b[8]=="s")
	{
		if (d[6]=="a" || l[6]=="a" || b[8]=="a")
		{
			if (d[6]=="n" || l[6]=="n" || b[8]=="n") cc=7;
			else cd=7;
		}
		else 
		{
			if (d[6]=="n" || l[6]=="n" || b[8]=="n") cb=7;
			else ca=7;
		}
	}
	if (d[8]=="s" || r[8]=="s" || b[6]=="s")
	{
		if (d[8]=="a" || r[8]=="a" || b[6]=="a")
		{
			if (d[8]=="n" || r[8]=="n" || b[6]=="n") cc=8;
			else cd=8;
		}
		else 
		{
			if (d[8]=="n" || r[8]=="n" || b[6]=="n") cb=8;
			else ca=8;
		}
	}
}

//// Moves
void U()
{
	for (int i=0; i<3; i++) h= r[i], r[i]= b[i], b[i]= l[i], l[i]= f[i], f[i]= h;
	h=u[0], u[0]= u[6], u[6]= u[8], u[8]= u[2], u[2]= h, h= u[1], u[1]= u[3], u[3]= u[7], u[7]= u[5], u[5]= h;
	//cout << "U ";
	a[n++]= "U";
} 
void UP()
{
	for (int i=0; i<3; i++) h= r[i], r[i]= f[i], f[i]= l[i], l[i]= b[i], b[i]= h;
	h=u[0], u[0]= u[2], u[2]= u[8], u[8]= u[6], u[6]= h, h= u[1], u[1]= u[5], u[5]= u[7], u[7]= u[3], u[3]= h;
	//cout << "U' ";
	a[n++]= "U'";
}
void D()
{
	for (int i=6; i<9; i++) h= r[i], r[i]= f[i], f[i]= l[i], l[i]= b[i], b[i]= h;
	h=d[0], d[0]= d[6], d[6]= d[8], d[8]= d[2], d[2]= h, h= d[1], d[1]= d[3], d[3]= d[7], d[7]= d[5], d[5]= h;
	//cout << "D ";
	a[n++]= "D";
}
void DP()
{
	for (int i=6; i<9; i++) h= r[i], r[i]= b[i], b[i]= l[i], l[i]= f[i], f[i]= h;
	h=d[0], d[0]= d[2], d[2]= d[8], d[8]= d[6], d[6]= h, h= d[1], d[1]= d[5], d[5]= d[7], d[7]= d[3], d[3]= h;
	//cout << "D' ";
	a[n++]= "D'";
}
void R()
{
	for (int i=2; i<9; i+=3) h= f[i], f[i]= d[i], d[i]= b[8-i], b[8-i]= u[i], u[i]= h;
	h=r[0], r[0]= r[6], r[6]= r[8], r[8]= r[2], r[2]= h, h= r[1], r[1]= r[3], r[3]= r[7], r[7]= r[5], r[5]= h;
	//cout << "R ";
	a[n++]= "R";
}
void RP()
{
	for (int i=2; i<9; i+=3) h= f[i], f[i]= u[i], u[i]= b[8-i], b[8-i]= d[i], d[i]= h;
	h=r[0], r[0]= r[2], r[2]= r[8], r[8]= r[6], r[6]= h, h= r[1], r[1]= r[5], r[5]= r[7], r[7]= r[3], r[3]= h;
	//cout << "R' ";
	a[n++]= "R'";
}
void L()
{
	for (int i=0; i<7; i+=3) h= f[i], f[i]= u[i], u[i]= b[8-i], b[8-i]= d[i], d[i]= h;
	h=l[0], l[0]= l[6], l[6]= l[8], l[8]= l[2], l[2]= h, h= l[1], l[1]= l[3], l[3]= l[7], l[7]= l[5], l[5]= h;
	//cout << "L ";
	a[n++]= "L";
}
void LP()
{
	for (int i=0; i<7; i+=3) h= f[i], f[i]= d[i], d[i]= b[8-i], b[8-i]= u[i], u[i]= h;
	h=l[0], l[0]= l[2], l[2]= l[8], l[8]= l[6], l[6]= h, h= l[1], l[1]= l[5], l[5]= l[7], l[7]= l[3], l[3]= h;
	//cout<< "L' ";
	a[n++]= "L'";
}
void F()
{
	h= u[6], u[6]= l[8], l[8]= d[2], d[2]= r[0], r[0]= h, h= u[7], u[7]= l[5], l[5]= d[1], d[1]= r[3], r[3]= h, h= u[8], u[8]= l[2], l[2]= d[0], d[0]= r[6], r[6]= h;
	h=f[0], f[0]= f[6], f[6]= f[8], f[8]= f[2], f[2]= h, h= f[1], f[1]= f[3], f[3]= f[7], f[7]= f[5], f[5]= h;
	//cout<< "F ";
	a[n++]= "F";
}
void FP()
{
	h= u[6], u[6]= r[0], r[0]= d[2], d[2]= l[8], l[8]= h, h= u[7], u[7]= r[3], r[3]= d[1], d[1]= l[5], l[5]= h, h= u[8], u[8]= r[6], r[6]= d[0], d[0]= l[2], l[2]= h;
	h=f[0], f[0]= f[2], f[2]= f[8], f[8]= f[6], f[6]= h, h= f[1], f[1]= f[5], f[5]= f[7], f[7]= f[3], f[3]= h;
	//cout<< "F' ";
	a[n++]= "F'";
}
void B()
{
	h= u[0], u[0]= r[2], r[2]= d[8], d[8]= l[6], l[6]= h, h= u[1], u[1]= r[5], r[5]= d[7], d[7]= l[3], l[3]= h, h= u[2], u[2]= r[8], r[8]= d[6], d[6]= l[0], l[0]= h;
	h=b[0], b[0]= b[6], b[6]= b[8], b[8]= b[2], b[2]= h, h= b[1], b[1]= b[3], b[3]= b[7], b[7]= b[5], b[5]= h;
	//cout<< "B ";
	a[n++]= "B";
}
void BP()
{
	h= u[0], u[0]= l[6], l[6]= d[8], d[8]= r[2], r[2]= h, h= u[1], u[1]= l[3], l[3]= d[7], d[7]= r[5], r[5]= h, h= u[2], u[2]= l[0], l[0]= d[6], d[6]= r[8], r[8]= h;
	h=b[0], b[0]= b[2], b[2]= b[8], b[8]= b[6], b[6]= h, h= b[1], b[1]= b[5], b[5]= b[7], b[7]= b[3], b[3]= h;
	//cout<< "B' ";
	a[n++]= "B'";
}
void U2() {U(); U();}
void D2() {D(); D();}
void R2() {R(); R();}
void L2() {L(); L();}
void F2() {F(); F();}
void B2() {B(); B();}
void an1() {R(); UP(); RP(); F(); RP(); FP(); R();}
void an0() {FP(); U(); F(); U(); R(); UP(); RP();}
void ag1() {B(); UP(); BP(); R(); BP(); RP(); B();}
void ag0() {RP(); U(); R(); U(); B(); UP(); BP();}
void sg1() {L(); UP(); LP(); B(); LP(); BP(); L();}
void sg0() {BP(); U(); B(); U(); L(); UP(); LP();}
void sn1() {F(); UP(); FP(); L(); FP(); LP(); F();}
void sn0() {LP(); U(); L(); U(); F(); UP(); FP();}
 
int main()
{
	for (int i=0; i<9; i++) cin>> d[i];
	for (int i=0; i<9; i++) cin>> f[i];
	for (int i=0; i<9; i++) cin>> r[i];
	for (int i=0; i<9; i++) cin>> b[i];
	for (int i=0; i<9; i++) cin>> l[i];
	for (int i=0; i<9; i++) cin>> u[i];
	cout<< endl;
	
	//// Cross
	for (int i=1; i<8; i+=2) 
	{
		if (d[i] != "s") 
		{
			if (i==1) D();
			else if (i==3) D2();
			else if (i==7) DP();
			for (int j=1; j<8; j+=2) 
				if (u[j] == "s") 
				{ 
					while (u[5] != "s") U();
					R2();
					goto n;
				}
			if (f[5]=="s") RP();
			else if (r[5]=="s") {D(); BP(); DP();}
			else if (l[5]=="s") {DP(); FP(); D();}
			else if (b[5]=="s") {D2(); LP(); D2();}
			else if (f[3]=="s") {D2(); L(); D2();}
			else if (l[3]=="s") {D(); B(); DP();}
			else if (b[3]=="s") R();
			else if (r[3]=="s") {DP(); F(); D();}
			else if (f[1]=="s") {F(); RP(); FP();}
			else if (r[1]=="s") {U(); F(); RP(); FP();}
			else if (b[1]=="s") {U2(); F(); RP(); FP();}
			else if (l[1]=="s") {UP(); F(); RP(); FP();}
			else if (f[7]=="s") {FP(); RP();}
			else if (r[7]=="s") {R2(); U(); F(); RP(); FP();}
			else if (b[7]=="s") {B(); R();}
			else if (l[7]=="s") {L2(); UP(); F(); RP(); FP();}
			n :
			if (i==1) DP();
			else if (i==3) D2();
			else if (i==7) D();
		}
	}
	
	//// Match Cross Colors
	if ((f[7]=="n" && b[7]=="g" && r[7]!="a") || (f[7]=="g" && b[7]=="n" && r[7]!="sa") || (r[7]=="g"  && l[7]=="n" && b[7]!="sa") || (r[7]=="n"  && l[7]=="g" && b[7]!="a")) {R(); LP(); D2(); RP(); L(); D2();}
	else 
	{
		while (s<2)
		{
			s=0;
			D();
			if (f[7]=="n") s++;
			if (r[7]=="a") s++;
			if (b[7]=="g") s++;
			if (l[7]=="sa") s++;
		}
		if (!(r[7]=="a" && b[7]=="g" && l[7]=="sa" && f[7]=="n"))
		{
			if (f[7]=="n" && r[7]=="a") {B(); DP(); BP(); D(); B();}
			else if (r[7]=="a" && b[7]=="g") {F(); D(); FP(); DP(); F();}
			else if (b[7]=="g" && l[7]=="sa") {F(); DP(); FP(); D(); F();}
			else if (l[7]=="sa" && f[7]=="n") {R(); DP(); RP(); D(); R();}
		}
	}
	while (f[7] != "n") D();  
	//// Complete white corners
	ccheck();
	//cout<< ca<<" "<< cb<< " "<< cc<<" "<< cd;
	if (cc==1)
	{
		U2();
		ccheck();
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==2)
	{
		U();
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==3)
	{
		UP();
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==4)
	{
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==5)
	{
		LP(); UP(); L();
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==6)
	{
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==7)
	{
		L(); U2(); LP();
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cc==8)
	{
		B(); U(); BP();
		while (d[2]!="s" || cc!=6)
		{
			if (k==0) {R(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {RP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	ccheck();
	
	if (cd==1)
	{
		U();
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==2)
	{
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==3)
	{
		U2();
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==4)
	{
		UP();
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==5)
	{
		LP(); U2(); L();
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==6)
	{
		FP(); UP(); F();
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==7)
	{
		L(); U(); LP();
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cd==8)
	{
		k=0;
		while (d[8]!="s" || cd!=8)
		{
			if (k==0) {B(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {BP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	ccheck();
	if (ca==1)
	{
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==2)
	{
		UP();
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==3)
	{
		U();
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==4)
	{
		U2();
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==5)
	{
		F(); U(); FP();
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==6)
	{
		R(); U2(); RP();
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==7)
	{
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (ca==8)
	{
		RP(); UP(); R();
		k=0;
		while (d[6]!="s" || ca!=7)
		{
			if (k==0) {L(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {LP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	ccheck();
	if (cb==1)
	{
		UP();
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==2)
	{
		U2();
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==3)
	{
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==4)
	{
		U();
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==5)
	{
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==6)
	{
		R(); U(); RP();
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==7)
	{
		BP(); UP(); B();
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	else if (cb==8)
	{
		RP(); U2(); R();
		k=0;
		while (d[0]!="s" || cb!=5)
		{
			if (k==0) {F(); k++;}
			else if (k==1) {U(); k++;}
			else if (k==2) {FP(); k++;}
			else if (k==3) {UP(); k=0;}
			ccheck();
		}
	}
	
	//// Second layer
	echeck();
	//cout<< ean<< " "<< eag<<" "<< esg<<" " << esn;
	if (ean==10) {R(); U2(); RP(); U(); R(); U2(); RP(); U(); FP(); UP(); F();}
	else if (ean==20) {B(); U(); BP(); U2(); an1(); RP(); U2(); R(); U(); RP(); UP(); R();}
	else if (ean==21) {D(); B(); U2(); BP(); DP(); R(); UP(); RP();}
	else if (ean==30) {L(); UP(); LP(); U(); an1(); U(); BP(); UP(); B();}
	else if (ean==31) {D2(); L(); U2(); LP(); D2(); U(); R(); UP(); RP();}
	else if (ean==40) {F(); L(); F2(); LP(); U2(); FP(); UP(); F(); U(); FP();}
	else if (ean==41) {DP(); F(); U(); FP(); D(); UP(); R(); UP(); RP();}
	else if (ean==50 || ean==60 || ean==70 || ean==80)
	{
		while (ean != 70) 
		{
			U();
			echeck();
		}
		an0();
	}
	else if (ean != 11)
	{
		while (ean != 81)
		{
			UP();
			echeck();
		}
		an1();
	}
	echeck();
	//cout<< ean<< " "<< eag<<" "<< esg<<" " << esn;
	if (eag==10) {R(); F(); R2(); FP(); U2(); RP(); UP(); R(); U(); RP();}
	else if (eag==11) {DP(); R(); U(); RP(); D(); UP(); B(); UP(); BP();}
	else if (eag==20) {B(); U2(); BP(); U(); B(); U2(); BP(); U(); RP(); UP(); R();}
	else if (eag==30) {L(); U(); LP(); U2(); ag1(); L(); U2(); LP(); UP(); L(); U(); LP();}
	else if (eag==31) {D(); L(); U2(); LP(); DP(); B(); UP(); BP();}
	else if (eag==40) {F(); UP(); FP(); U(); ag1(); U(); LP(); UP(); L();}
	else if (eag==41) {D2(); F(); U2(); FP(); D2(); U(); B(); UP(); BP();}
	else if (eag==50 || eag==60 || eag==70 || eag==80)
	{
		while (eag != 80) 
		{
			U();
			echeck();
		}
		ag0();
	}
	else if (eag != 21)
	{
		while (eag != 51)
		{
			UP();
			echeck();
		}
		ag1();
	}
	echeck();
	//cout<< ean<< " "<< eag<<" "<< esg<<" " << esn;
	if (esg==10) {R(); UP(); RP(); U(); sg1(); U2(); R(); UP(); RP();}
	else if (esg==11) {D2(); R(); U2(); RP(); D2(); U(); L(); UP(); LP();}
	else if (esg==20) {B(); R(); B2(); RP(); BP(); RP(); R(); U(); RP(); UP(); R();}
	else if (esg==21) {DP(); B(); U(); BP(); D(); UP(); L(); UP(); LP();}
	else if (esg==30) {L(); U2(); LP(); U(); L(); U2(); LP(); U(); BP(); UP(); B();}
	else if (esg==40) {F(); U(); FP(); U2(); sg1(); LP(); U2(); L(); U(); LP(); UP(); L();}
	else if (esg==41) {D(); F(); U2(); FP(); DP(); L(); UP(); LP();}
	else if (esg==50 || esg==60 || esg==70 || esg==80)
	{
		while (esg != 50) 
		{
			U();
			echeck();
		}
		sg0();
	}
	else if (esg != 31)
	{
		while (esg != 61)
		{
			UP();
			echeck();
		}
		sg1();
	}
	echeck();
	//cout<< ean<< " "<< eag<<" "<< esg<<" " << esn;
	if (esn==10) {R(); U(); RP(); U2(); sn1(); R(); U2(); RP(); UP(); R(); U(); RP();}
	else if (esn==11) {D(); R(); U2(); RP(); DP(); F(); UP(); FP();}
	else if (esn==20) {B(); UP(); BP(); U(); sn1(); U(); RP(); UP(); R();}
	else if (esn==21) {D2(); B(); U2(); BP(); D2(); U(); F(); UP(); FP();}
	else if (esn==30) {L(); B(); L2(); BP(); LP(); L(); U2(); LP(); UP(); L(); U(); LP();}
	else if (esn==31) {DP(); L(); U(); LP(); D(); UP(); F(); UP(); FP();}
	else if (esn==40) {F(); U2(); FP(); U(); F(); U2(); FP(); U(); LP(); UP(); L();}
	else if (esn==50 || esn==60 || esn==70 || esn==80)
	{
		while (esn != 60) 
		{
			U();
			echeck();
		}
		sn0();
	}
	else if (esn != 41)
	{
		while (esn != 71)
		{
			UP();
			echeck();
		}
		sn1();
	}
	
	////OLL
	if (u[1]!="z" || u[3]!="z" || u[5]!="z" || u[7]!="z")
	{
		if ((u[1]=="z" && u[3]=="z") || (u[3]=="z" && u[7]=="z") || (u[7]=="z" && u[5]=="z") || (u[5]=="z" && u[1]=="z"))
		{
			while (u[1]!="z" || u[3]!="z") U();
			F(); U(); R(); UP(); RP(); FP();
		}
		else if ((u[1]=="z" && u[7]=="z") || (u[3]=="z" && u[5]=="z"))
		{
			while (u[5]!="z" || u[3]!="z") U();
			F(); R(); U(); RP(); UP(); FP();
		}
		else {F(); R(); U(); RP(); UP(); FP(); U2(); F(); U(); R(); UP(); RP(); FP();}
	}
	
	if ((u[0]=="z" && r[2]=="z" && f[2]=="z" && l[2]=="z") || (f[2]=="z" && u[2]=="z" && l[2]=="z" && b[2]=="z") || (b[2]=="z" && r[2]=="z" && u[6]=="z" && f[2]=="z") || (r[2]=="z" && b[2]=="z" && l[2]=="z" && u[8]=="z"))
	{
		while (u[6] != "z") U();
		R(); U(); RP(); U(); R(); U2(); RP();
	}
	else if ((u[0]=="z" && r[0]=="z" && f[0]=="z" && b[0]=="z") || (f[0]=="z" && u[2]=="z" && l[0]=="z" && r[0]=="z") || (b[0]=="z" && r[0]=="z" && u[6]=="z" && l[0]=="z") || (b[0]=="z" && f[0]=="z" && l[0]=="z" && u[8]=="z"))
	{
		while (u[2] != "z") U();
		R(); U2(); RP(); UP(); R(); UP(); RP();
	}
	else if ((u[0]=="z" && u[2]=="z" && r[0]=="z" && l[2]=="z") || (u[8]=="z" && u[2]=="z" && f[0]=="z" && b[2]=="z") || (u[8]=="z" && u[6]=="z" && l[0]=="z" && r[2]=="z") || (u[6]=="z" && u[0]=="z" && f[2]=="z" && b[0]=="z"))
	{
		while (u[0] != "z" || u[2] != "z") U();
		F(); R(); BP(); RP(); FP(); R(); B(); RP();
	}
	else if ((u[0]=="z" && u[2]=="z" && f[0]=="z" && f[2]=="z") || (u[8]=="z" && u[2]=="z" && l[0]=="z" && l[2]=="z") || (u[8]=="z" && u[6]=="z" && b[0]=="z" && b[2]=="z") || (u[6]=="z" && u[0]=="z" && r[2]=="z" && r[0]=="z"))
	{
		while (u[0] != "z" || u[2] != "z") U();
		R2(); D(); RP(); U2(); R(); DP(); RP(); U2(); RP();
	}
	else if ((u[0]=="z" && u[8]=="z" && ((r[2]=="z" && f[0]=="z") || (b[0]=="z" && l[2]=="z"))) || (u[2]=="z" && u[6]=="z" && ((b[2]=="z" && r[0]=="z") || (f[2]=="z" && l[0]=="z"))))
	{
		while (b[2]!="z" || r[0]!="z") U();
		R(); BP(); RP(); F(); R(); B(); RP(); FP();
	}
	else if ((l[0]=="z" && l[2]=="z" && f[2]=="z" && b[0]=="z") || (l[2]=="z" && r[0]=="z" && b[0]=="z" && b[2]=="z") || (b[2]=="z" && r[0]=="z" && r[2]=="z" && f[0]=="z") || (l[0]=="z" && r[2]=="z" && f[2]=="z" && f[0]=="z"))
	{
		while (l[0]!="z" || b[0]!="z") U();
		R(); U2(); R2(); UP(); R2(); UP(); R2(); U2(); R();
	}
	else if ((l[0]=="z" && l[2]=="z" && r[2]=="z" && r[0]=="z") || (f[2]=="z" && b[0]=="z" && f[0]=="z" && b[2]=="z"))
	{
		while (l[0]!="z" || r[0]!="z") U();
		R(); U(); RP(); U(); R(); UP(); RP(); U(); R(); U2(); RP();
	}
	
	////PLL
	if (!(f[0]==f[2] && r[0]==r[2]))
	{
		if (f[0]==f[2] || r[0]==r[2] || b[0]==b[2] || l[0]==l[2])
		{
			while (f[0] != f[2]) U();
			R(); BP(); R(); F2(); RP(); B(); R(); F2(); R2();
		}
		else if (f[0]!=f[2] && r[0]!=r[2] && b[0]!=b[2] && l[0]!=l[2]) {F(); R(); UP(); RP(); UP(); R(); U(); RP(); FP(); R(); U(); RP(); UP(); RP(); F(); R(); FP();}
	}
	while (f[0] != "n") U();
	if (!(f[1]=="n" && r[1]=="a" && b[1]=="g" && l[1]=="sa"))
	{
		if (!(f[1]!="n" && r[1]!="a" && b[1]!="g" && l[1]!="sa"))
		{
			if (f[1] == "n") U2();
			else if (r[1] == "a") UP();
			else if (l[1] == "sa")  U();
			left:
			R(); UP(); R(); U(); R(); U(); R(); UP(); RP(); UP(); R2();
			if (f[1]!=f[0] || r[1]!=r[0] || b[1]!=b[0] || l[1]!=l[0]) goto left;
		}
		else if (f[1]=="g" && b[1]=="n") {a[n++]= "M2"; a[n++]= "U"; a[n++]= "M2"; a[n++]= "U2"; a[n++]= "M2"; a[n++]= "U"; a[n++]= "M2";}
		else 
		{
			while (f[0]!=l[1] || l[0]!=f[1]) U();
			a[n++]= "M2"; a[n++]= "U'"; a[n++]= "M2"; a[n++]= "U'"; a[n++]= "M'"; a[n++]= "U2"; a[n++]= "M2"; a[n++]= "U2"; a[n++]= "M'"; a[n++]= "U2";
		}	
		while (f[0] != "n") U();
	}
	
	for (int i=0; i<n; i++)
	{
		x=0;
		if (a[i]==a[i+1])
		{
			x=1;
			while (a[i]==a[i+1]) i++, x++;
		}
		if (x!=0)
		{
			if (x%4==1) aa[t++]= a[i];
			else if (x%4==2) aa[t++]= a[i]+"2";
			else if (x%4==3) aa[t++]= a[i] + "'"; 
		}
		else aa[t++]= a[i];
	}
	for (int i=0; i<t; i++) cout<< aa[i]<<" ";
	
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
