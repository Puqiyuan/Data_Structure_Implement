// Filename: bo1-1.cpp. The 8 basic operations of abstract data type Triplet and ElemType(defined by c1-1.h)

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	// Operation results: construct triplet T, and set the three elements to v1, v2 and v3.
	if ( ! (T = (ElemType*) malloc(3 * sizeof(ElemType))) )
		exit(OVERFLOW);
	T[0] = v1, T[1] = v2, T[2] = v3;

	return OK;
}


Status DestroyTriplet(Triplet &T)
{
	// Operation results: The Triplet T has destroed.
	free(T);
	T = NULL;
	
	return OK;
}


Status Get(Triplet T, int i, ElemType &e)
{
	// Initial conditions: The Triplet T existed already.
	// Operation results: Return i'th element by e.

	if ( i < 1 || i > 3 )
		return ERROR;		

	e = T[i - 1];

	return OK;
}
