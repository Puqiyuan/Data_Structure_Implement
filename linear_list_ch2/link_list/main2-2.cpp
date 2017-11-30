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

	GetElem(L, 5, e);
	printf("The 5'th element is: %d\n", e);
	
		
	return 0;
}
