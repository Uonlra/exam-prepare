int FactorialSum( List L )
{
	int sum = 0;
	for (List p = L; p != NULL; p = p->Next) {
		int fact = 1;
		for (int i = 2; i <= p->Data; ++i) {
			fact *= i;
		}
		sum += fact;
	}
	return sum;
}
