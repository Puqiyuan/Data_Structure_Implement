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
	//for avoiding the impact of changes of type, using cout() function instead of printf(), notice the end is endl.

	i = Get(T, 2, m);
	cout<<"the second value: "<<m<<endl;
	
	return 0;
}
