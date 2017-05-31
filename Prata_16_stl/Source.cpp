#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <ctype.h>
#include <conio.h>
#include <algorithm>
#include "Queues.h"

using namespace std;
string f_revert(const string &s);
string f_revert2(const string &s);

//sredni czas dostepu
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1 );
}

template<class T>
int reduce(T ar[],int n)
{
	vector<T>::iterator itLong;
	vector<T> array_vect(ar,ar+n);

	for(itLong = array_vect.begin();itLong < array_vect.end();++itLong)
		cout << "\n..... "<<*itLong ;
	std::sort(array_vect.begin(),array_vect.end());
	itLong = std::unique(array_vect.begin(),array_vect.end());
	//auto sorted = std::unique(array_vect.begin(),array_vect.end());

	array_vect.resize(std::distance(array_vect.begin(),itLong));
	//std::unique(array_vect.begin().array_vect.end(),myfunction);

	for(itLong = array_vect.begin();itLong < array_vect.end();++itLong)
		cout << "\n2..... "<<*itLong ;

	return 0;
}

/////////////// MAIN BEGIN //////////////
int main()
{
#ifdef pierwsze
	std::string inp("SRE Dlowol xx");
	std::string outp(inp);
	
	//outp =` std::string(inp);

	std::cout << inp << endl;
	std::reverse(outp.begin(), outp.end());

	std::cout << outp << endl;
	outp = f_revert(outp);
	std::cout << outp << endl;
	outp = f_revert2(outp);
	cout << "\n==========\n";
	std::cout << outp << endl;
	if(outp == inp)
		cout << "OK\n";
	else
		cout << "NOK\n";
	long array_[] = {1,2,3,4,5,1,2};
	int elems = sizeof(array_)/sizeof(array_[0]);
	cout << "\nSize:" << elems;
	reduce(array_,elems);
#endif 
///////////////////////////// QUEUES
#define queues_
#ifdef queues_
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
const int MIN_PER_HR = 60;
std::srand(std::time(0));
cout << "Bankomat\n";
cout << "Podaj max kolejki: ";
int qs;
//cin >> qs;
qs = 10;
Queue line(qs);
cout << "symulowany czas?";
int hours;
//
hours = 100;
//cin >> hours;
long cyclelimit = MIN_PER_HR * hours;

cout << "Podaj srednia liczbe klientow na godzine";
double perhour;
//cin >> perhour;
perhour = 15;
double min_per_cust;
min_per_cust = MIN_PER_HR / perhour;

Item temp; //dane nowego klienta
long turnways = 0;//liczba klientow odeslanych Z kolejki
long customers = 0;//liczba klientow przyjetych do kolejki
long served = 0;//
long sum_line = 0;//liczba oczekujacych
int wait_time = 0;
long line_wait = 0;

//start symulacji
for(int cycle = 0;cycle < cyclelimit;cycle++)
{
if(newcustomer(min_per_cust))//mamy nowego chetnego
{
	if(line.isfull())
		turnways++;
	else
	{
		customers++;
		temp.set(cycle);//cas przybycia = numer cyklu
		line.enqueue(temp);//dolaczanie klienta do kolejki
	}
}
if(wait_time <= 0 && !line.isempty())
{
	line.dequeue(temp);//nastepny do obsluzenia
	wait_time = temp.ptime();
	line_wait += cycle - temp.when();
	served++;
}
if(wait_time > 0)
	wait_time--;
sum_line +=line.queuecount();
	if(customers > 0)
	{
		cout << "liczba klientow przyjeteych: " << customers << endl;
		cout << "liczba klientow obsluzonych: " << served << endl;
		cout << "liczba klientow odeslanych: " << turnways << endl;
		cout << "srednia dlugosc kolejki: ";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double) sum_line / cyclelimit << endl;
		cout << (double) line_wait / served << " minut\n" ;
	}
	else
		cout << "brak klientow\n";
	cout << "Gotowe!\n";
	return 0;
}

#endif
cout << "=====END ======";
_getch();
_getch();
_getch();
_getch();
_getch();
_getch();
_getch();
_getch();

return 0;
}
/////////////////// END OF MAIN ///////////////////


string f_revert(const string &s)
{
string out_str;
	out_str = s;
	std::reverse(out_str.begin(), out_str.end());
return out_str;	
}
string f_revert2(const string &s)
{
string out_str;
for (int i = 0; i < s.length(); ++i)	
	{
		cout << s.at(i) << ".";
		if(s.at(i) != ' ')
			out_str += tolower(s.at(i));
}
return out_str;	
}

bool myfunction (int i, int j) {
  return (i==j);
}
//template<class T>
\