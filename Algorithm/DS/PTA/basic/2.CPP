double f( int n, double a[], double x )
{
	double result = 0.0;
	for (int i = n; i >= 0; --i) {
		result = result * x + a[i];
	}
	return result;
}
