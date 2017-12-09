// main2-2.cpp, the main prgram test for bo2-2.cpp (similar to main2-1.cpp)

#include "/home/pqy7172/Data_Structure_Implement/header/bigHeader.h"
typedef int ElemType;
#include "c2-2.h" // different from main2-1.cpp
#include "bo2-2.cpp" // different from main2-1.cpp

Status comp(ElemType c1, ElemType c2) // judge for data, TRUE if equal, otherwise FALSE.
{
	if (c1 == c2)
		return TRUE;

	else
		return FALSE;
}


void visit(ElemType c) // different from main2-1.cpp.
{
	printf("%d ",  c);
}


int main(int argc, char *argv[])
{
	LinkList L; // different from main2-1.
	ElemType e, e0;
	Status i;
	int j, k;

	i = InitList(L);

	printf("After execute InitList() function(0: failed, 1: success): %d\n ",  i);

	for (j = 1; j <= 5; j++)
		i = ListInsert(L, 1,  j);
	
	printf("After insert 1 ~ 5 at head of L: L = ");
	ListTraverse(L, visit); // Calling visit() by order, output elements value.
	i = ListEmpty(L);
	printf("Is L null?: i =  %d(1: yes 0: no)\n", i);
	
	i = ClearList(L);
	printf("After clear L: L=");
	ListTraverse(L, visit);
	i = ListEmpty(L);
	printf("Is L null? i = %d(1: yes 0: no)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(L, j,  j);
	printf("After insert 1 ~ 10 at end of L: L = ");
	ListTraverse(L, visit);

	GetElem(L, 5, e);
	printf("The 5'th element is: %d\n", e);

	for (j = 0; j <= 1; j++)
		{
			k = LocateElem(L, j, comp);

			if (k)
				printf("The value of %d'th element is %d.\n",  k,  j);
			else
				printf("There is no element its value is %d.\n", j);
		}
	
	for (j = 1; j <= 2; j++) // test the first two elements
		{
			GetElem(L, j, e0);
			
			i = PriorElem(L, e0, e);
			
			if (i == INFEASIBLE)
				printf("There is no precursor for %d.\n", e0);
			else
				printf("The precursor of %d is: %d.\n", e0, e);
		}

	for (j = ListLength(L) - 1; j <= ListLength(L); j++)
		{
			GetElem(L, j, e0);
			i = NextElem(L, e0, e);

			if (i == INFEASIBLE)
				printf("Threre is no succesor for %d.\n", e0);

			else
				printf("The successor of %d is %d.\n", e0, e);
		}

	k = ListLength(L); // k is the length of list.
	printf("Before delete the last element:\n");
	ListTraverse(L, visit);
	
	for (j = k + 1; j >= k; j--)
		{
			i = ListDelete(L, j, e); // delete the i'th element.

			if (i == ERROR)
				printf("Failed to delete the %d'th element.\n", j);
			else
				printf("The element have deleted: %d.\n", e);
		}

	printf("After delete an element:\n");
	ListTraverse(L, visit);

	DestroyList(L);
	printf("After destroy L: L = %u.\n", L);
	
	return 0;
}
