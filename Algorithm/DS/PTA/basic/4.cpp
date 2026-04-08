ElementType Average( ElementType S[], int N )
{
    ElementType total = 0;
    for (int i = 0; i < N; ++i) {
        total += S[i];
    }
    return total / N;
}
