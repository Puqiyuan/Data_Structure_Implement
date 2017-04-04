/*
  this file define structure of linear table
 */

#define LIST_INIT_SIZE 10 
#define LISTINCREMENT 2

typedef struct
{
  ElemType *elem;
  int length;
  int listsize;
}SqList;


