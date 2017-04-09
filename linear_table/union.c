/*
  pqy@sda1:~/.../linear_table$ gcc union.c 
  pqy@sda1:~/.../linear_table$ ./a.out 
  2 34 45 78 32 77
 */


#include "../c1.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.c"
#include "vi_int.c"
#include "compare.c"


int Union(SqList *La, SqList Lb)
{//insert all elements to linear table La that don't exist in linear table Lb
  int La_len = ListLength(*La), Lb_len = ListLength(Lb), i;
  ElemType *e;

  e = (ElemType*)malloc(1 * sizeof(ElemType));

  for (i = 1; i <= Lb_len; i++)
    {
      GetElem(Lb, i, e);

      if (!LocateElem(*La, *e, compare))
	ListInsert(La, ++La_len, *e);
    }

  return 0;
}


int main(int argc, char *argv[])
{
  SqList La, Lb;
  int i;

  ElemType la[] = {2, 34, 45, 78};
  ElemType lb[] = {2, 32, 34, 77, 78};

  InitList(&Lb);
  InitList(&La);
  
  for (i = 1; i <= 4; i++)
    ListInsert(&La, i, la[i - 1]);

  for (i = 1; i <= 5; i++)
    ListInsert(&Lb, i, lb[i - 1]);

  Union(&La, Lb);

  ListTraverse(La, vi_int);
  
  return 0;
}
