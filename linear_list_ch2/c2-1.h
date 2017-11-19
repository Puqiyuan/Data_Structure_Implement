// c2-1.h The dynamic store structre of linear list.
#define LIST_INIT_SIZE 10 // The initially store space of linear list.

#define LISTINCREMENT 2 // The increment of space.

struct SqList
{
	ElemType *elem; // the base address of space.
	int length; // current length of linear list.
	int listsize; // current malloced space(in sizeof(ElemType))
};
