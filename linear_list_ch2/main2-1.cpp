// main2-1.cpp test the basic functions in bo2-1.cpp
#include "bigHeader.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.cpp"
using namespace std;


Status comp(ElemType c1, ElemType c2)
{
	// Judge the square relationship.
	if (c1 == c2 * c2)
		return TRUE;

	return FALSE;
}


int visit(ElemType &c)
{
	// Called by ListTraverse() function to output the value of c.
	cout<<c<<' ';

	return 0;
}


int dbl(ElemType &c)
{
	// Called by ListTraverse() function double the value of c.
	c *= 2;

	return 0;
}

int main(int argc, char *argv[])
{
	SqList L;

	ElemType e, e0;
	Status i;
	int j, k;
	i = InitList(L);
	printf("After initialization: L.elem = %u L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);

	for (j = 1; j <= 5; j++)
		i = ListInsert(L, 1, j);

	printf("After insert 1 ~ 5: *L.elem = ");

	for (j = 1; j <= 5; j++)
		cout<<*(L.elem + j - 2)<<' ';
	cout<<endl;

	printf("L.elem = %u L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);

		
	
	return 0;
}

