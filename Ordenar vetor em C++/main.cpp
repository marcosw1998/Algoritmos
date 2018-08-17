#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,cont=0;
    scanf("%d %d",&n,&k);

    vector <int> vet(n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&vet[i]);
    }
    sort (vet.begin(), vet.end());

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
          int m = vet[i] - vet[j];
            if( m == k)
            {
                cont++;
            	break;
            }
            if (m>k)
                 break;
        }
    }
        printf("%d",cont);

    return 0;
}
