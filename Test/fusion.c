#include <stdio.h>

void fusion(int *A,int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    int i = 1;
    int j = 1;
    int k = p;
    while(i<n1)
    {
        L[i] = A[p+i-1];
        i +=1;
    }
    while(j<n2)
    {
        R[j] = A[q+j];
        j +=1;
    }
    L[n1+1] = 198978;
    R[n2+1] = 198978;
    i = 1;
    j = 1;
    while(k < r)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i = i+1;;
        }
        else {
            j = j+ 1;
        }
      k+=1;
    }
    return;
}

void tri_fusion(int *A, int p,int r)
{
    if (p < r)
    {
        int q = (p+r)/2;
        tri_fusion(A,p,q);
        tri_fusion(A,q+1,r);
        fusion(A,p,q,r);
    }
    return;
}

int main(void)
{
    int A[13] = {99,2,5,9,3,43,2,53,86,12,92,1,283};
    tri_fusion(A,1,13);
    int i = 1;
    /*while(i<13)
    {
        printf("%d ,",A[i]);
        i +=1;
    }*/
    printf("%d",(6+9)/2);
    printf("\n");
    return 0;

}