/*
  test result:

  pqy@sda1:~/.../linear_table$ ./a.out 
  Before merge:
  La:2 34 45 78 
  Lb;2 32 34 77 78 
  After merge:Lc:2 2 32 34 34 45 77 78 78
 */


#include "../c1.h"
typedef int ElemType;
#include "c2-1.h"
#include "bo2-1.c"
#include "vi_int.c"
#include "compare.c"


int MergeList(SqList La, SqList Lb, SqList *Lc)
{
  // initial condition: the elements in La and Lb are non-decreasing.
  // operation result: merge the elements in La and Lb for obtaining new linear table Lc, the Lc
  // is also non-decreasing.

  InitList(Lc);

  ElemType *ai, *bj;
  ai = (ElemType*)malloc(1 * sizeof(ElemType));
  bj = (ElemType*)malloc(1 * sizeof(ElemType));
  
  int i = 1, j = 1, k = 0;

  int La_len = ListLength(La), Lb_len = ListLength(Lb);

  while ( (i <= La_len) && (j <= Lb_len))
    {
      GetElem(La, i, ai); GetElem(Lb, j, bj);

      if (*ai <= *bj)
	{
	  ListInsert(Lc, ++k, *ai);
	  ++i;
	}

      else
	{
	  ListInsert(Lc, ++k, *bj);
	  ++j;
	}
    }

  while (i <= La_len)
    {
      GetElem(La, i++, ai);
      ListInsert(Lc, ++k, *ai);
    }

  while (j <= Lb_len)
    {
      GetElem(Lb, j++, bj);
      ListInsert(Lc, ++k, *bj);
    }


  return 0;
}


int main(int argc, char *argv[])
{
  SqList La, Lb, Lc;
  int i;

  ElemType la[] = {2, 34, 45, 78};
  ElemType lb[] = {2, 32, 34, 77, 78};

  InitList(&La);
  InitList(&Lb);

  for (i = 1; i <= 4; i++)
    ListInsert(&La, i, la[i - 1]);

  for (i = 1; i <= 5; i++)
    ListInsert(&Lb, i, lb[i - 1]);

  MergeList(La, Lb, &Lc);

  printf("Before merge:\n");

  printf("La:");
  ListTraverse(La, vi_int);

  printf("Lb;");
  ListTraverse(Lb, vi_int);

  printf("After merge:\n");

  printf("Lc:");
  ListTraverse(Lc, vi_int);
  
  
  return 0;
}
