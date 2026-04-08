ElementType Max( ElementType S[], int N )
{
    ElementType best = S[0];
    for (int i = 1; i < N; ++i) {
        if (S[i] > best) {
            best = S[i];
        }
    }
    return best;
}
