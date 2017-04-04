/*
  this main function is for test all base operations.
  test result:
  pqy@sda1:~/.../linear_table$ ./a.out 
  Test for Init_List function:
  Before initialization: L.elem = 0x400f70, L.length = 4195808, L.list_size = 0
  After initialization: L.elem = 0xddb420, L.length = 0, L.list_size = 10

  The status code of initialization function: 1

  Test for List_Traverse function:
  a b c d e 

  Test for List_Length function:
  The length of the linear table is: 5

  Test for Get_Elem function:
  The third element: c 

  Test for List_Insert function:
  a b c f d e 

  Test for List_Delete function:
  a b f d e 

  Test for Locate_Elem function, the test element is 'b': 
  the index of first element equal b is: 2

  Test for Next_Elem function, the test cur_e is 'b':
  The successor of 'b' is: f

  Test for Prior_Elem function, the test cur_e is 'b':
  The prior of 'b' is: a

  Test for Clear List function:
  L.elem: 0xddb420, L.length: 0, L.list_size: 10

  Test for Destroy List function:
  L.elem: (nil), L.length: 0, L.list_size: 0
 */


#include "../c1.h"
typedef char ElemType;
#include "c2-1.h"
#include "bo2-1.c"
#include "vi.c"
#include "compare.c"


int main(int argc, char *argv[])
{
  SqList L;

  ElemType *e, a[5] = {'a', 'b', 'c', 'd', 'e'};

  int i, j;

  printf("Test for Init_List function:\n");
  printf("Before initialization: L.elem = %p, L.length = %d, L.list_size = %d\n",
	 L.elem, L.length, L.listsize);

  i = InitList(&L);

  printf("After initialization: L.elem = %p, L.length = %d, L.list_size = %d\n\n",
	 L.elem, L.length, L.listsize);

  printf("The status code of initialization function: %d\n\n", i);

  for (j = 1; j <= 5; j++)
    i = ListInsert(&L, j, a[j - 1]);

  
  printf("Test for List_Traverse function:\n");
  ListTraverse(L, vi);

  printf("\n");
  printf("Test for List_Length function:\n");
  printf("The length of the linear table is: %d\n\n", ListLength(L));

  printf("Test for Get_Elem function:\n");
  GetElem(L, 3, e);
  printf("The third element: ");
  vi(e);
  printf("\n\n");

  printf("Test for List_Insert function:\n");
  *e = 'f';
  ListInsert(&L, 4, *e);
  ListTraverse(L, vi);

  printf("\n");
  printf("Test for List_Delete function:\n");
  ListDelete(&L, 3, e);
  ListTraverse(L, vi);
  
  printf("\n");
  *e = 'b';
  printf("Test for Locate_Elem function, the test element is 'b': \n");
  printf("the index of first element equal b is: %d\n", LocateElem(L, *e, compare));

  char next_e = 'c';
  printf("\n");
  printf("Test for Next_Elem function, the test cur_e is 'b':\n");
  NextElem(L, *e, &next_e);
  printf("The successor of 'b' is: %c\n", next_e);
  
  char pre_e;
  pre_e = 'a';
  printf("\n");
  printf("Test for Prior_Elem function, the test cur_e is 'b':\n");
  PriorElem(L, *e, &pre_e);
  printf("The prior of 'b' is: %c\n", pre_e);

  printf("\n");
  printf("Test for Clear List function:\n");
  ClearList(&L);
  printf("L.elem: %p, L.length: %d, L.list_size: %d\n", L.elem, L.length, L.listsize);

  printf("\n");
  printf("Test for Destroy List function:\n");
  DestroyList(&L);
  printf("L.elem: %p, L.length: %d, L.list_size: %d\n", L.elem, L.length, L.listsize);
    
  return 0;

}

