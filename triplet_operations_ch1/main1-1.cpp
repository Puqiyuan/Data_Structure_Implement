/*
  Test result:
  ~/.../triplet_operations_ch1$ g++ main1-1.cpp 
  ~/.../triplet_operations_ch1$ ./a.out 
  After call InitalTriplet function, i = 1(1: success). The three values of T: 
  5 7 9
  the second value: 7
  The three elements after change the second value of T to 6: 
  5 6 9
  After call IsAscending function, i = 1(0: is, 1: no)
  After call IsDescending function, i = 0(0: is, 1: no)
  The maximum is: 9
  The minimum is: 5
 */


// Filename: main1-1.cpp. Test the basic operations in bo1-1.cpp.
#include "bigHeader.h"
typedef int ElemType; // Abstract data type is defined as int type in this test program.
#include "c1-1.h"
#include "bo1-1.cpp"
using namespace std;

int main(int argc, char *argv[])
{
	Triplet T;
	ElemType m;
	Status i;

	i = InitTriplet(T, 5, 7, 9);
	printf("After call InitalTriplet function, i = %d(1: success). The three values of T: \n", i);
	cout<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;
	//For avoiding the impact of changes of type, using cout() function instead of printf(), notice the end is endl.

	i = Get(T, 2, m);
	if (i == OK)
		cout<<"the second value: "<<m<<endl;

	i = Put(T, 2, 6);
	cout<<"The three elements after change the second value of T to 6: \n"<<T[0]<<' '<<T[1]<<' '<<T[2]<<endl;

	i = IsAscending(T);

	printf("After call IsAscending function, i = %d(0: is, 1: no)\n", i);

	i = IsDescending(T);
	printf("After call IsDescending function, i = %d(0: is, 1: no)\n", i);

	if ( (i = Max(T, m)) == OK )// Firstly compare then assigment.
		cout<<"The maximum is: "<<m<<endl;

	if ( (i = Min(T, m)) == OK)
		cout<<"The minimum is: "<<m<<endl;

	DestroyTriplet(T); //Of course, a function does't have a returned value.
	
	return 0;
}
