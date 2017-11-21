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

	i = ListEmpty(L);

	cout<<"Is L empty? i = "<<i<<"(1:yes 0:no)"<<endl; //note that you defined the return value of function is Status, although it's int type, but you cannot output it by %d formate useing printf function.j

	i = ClearList(L);

	printf("After clear L: L.elem = %u L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);

	i = ListEmpty(L);

	cout<<"Is L empty? i = "<<i<<"(1:yes 0:no)"<<endl;

	for (j = 1; j <= 10; j++)
		ListInsert(L, j, j);
	printf("After inserted 1 ~ 10 at tail of L: *L.elem=");

	for (j = 1; j <= 10; j++)
		cout<<*(L.elem + j - 1)<<' ';
	cout<<endl;

	printf("L.elem = %u L.length = %d L.listsize = %d\n", L.elem, L.length, L.listsize);

	ListInsert(L, 1, 0);

	printf("Insert 0 at head of L: *L.elem=");
	for (j = 1; j <= ListLength(L); j++)// ListLength(L) is the number of L.
		cout<<*(L.elem + j - 1)<<' ';
	cout<<endl;

	printf("L.elem = %u(maybe changed) L.length=%d(changed) L.listsize=%d(changed)\n", L.elem, L.length, L.listsize);

	GetElem(L, 5, e);

	printf("The 5'th of L is: %d\n", e);

	for (j = 3; j <= 4; j++)
		{
			k = LocateElem(L, j, comp);
			if (k)
				printf("The %d'th element is the square of %d.\n", k, j);
			
			else
				printf("No value is the square of %d.\n", j);
		}
	GetElem(L, 10, e);
	printf("The value of 10'th element is: %d\n", e);

	for (j = 1; j <= 2; j++) // test the first and second elements.
		{
			GetElem(L, j, e0); // assign the j'th element to e0.

			i = PriorElem(L, e0, e);
			if (i == INFEASIBLE)
				printf("There is no precursor for %d.\n", e0);

			else
				printf("The precursor of %d is: %d.\n", e0, e);
				
		}
	
	return 0;
}
