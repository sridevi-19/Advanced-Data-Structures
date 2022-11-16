#include <stdio.h>
#include <stdlib.h>


void makeset(int n,int parent[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}


int find(int x,int parent[])
{
    if(parent[x] != x)
    {
        parent[x]=find(parent[x],parent);
    }
    return parent[x];
}


void Union(int x, int y, int parent[], int rank[])
{

    int x0 = find(x,parent);
    int y0 = find(y,parent);


    if(x0 == y0)
    {
        return;
    }


    if(rank[x0] < rank[y0])
    {
        parent[x0] = y0;
    }


    else if(rank[y0] < rank[x0])
    {
        parent[y0] = x0;
    }

    else
    {

        parent[y0] = x0;

        rank[x0] = rank[x0] + 1;
    }
}

int count_of_Islands(int arr[20][20],int a,int b,int n,int parent[], int rank[])
{
    int j,k;

    for(j = 0; j < a; j++)
    {
        for(k = 0; k < b; k++)
        {

            if(arr[j][k] == 0)
            {
                continue;
            }

            if(j + 1 < a && arr[j + 1][k] == 1)
            {
                Union(j * (b) + k, (j + 1) * (b) + k, parent, rank);
            }
            if(j - 1 >= 0 && arr[j - 1][k] == 1)
            {
                Union(j * (b) + k, (j - 1) * (b) + k, parent, rank);
            }
            if(k + 1 < b && arr[j][k + 1] == 1)
            {
                Union(j * (b) + k, (j) * (b) + k + 1, parent, rank);
            }
            if(k - 1 >= 0 && arr[j][k - 1] == 1)
            {
                Union(j * (b) + k,(j) * (b) + k - 1, parent, rank);
            }
            if(j + 1 < a && k + 1 < b && arr[j + 1][k + 1] == 1)
            {
                Union(j * (b) + k, (j + 1) * (b) + k + 1, parent, rank);
            }
            if(j + 1 < a && k - 1 >= 0 && arr[j + 1][k - 1] == 1)
            {
                Union(j * b + k, (j + 1) * (b) + k - 1, parent, rank);
            }
            if(j - 1 >= 0 && k + 1 < b && arr[j - 1][k + 1] == 1)
            {
                Union(j * b + k, (j - 1) * b + k + 1, parent, rank);
            }
            if(j - 1 >= 0 && k - 1 >= 0 && arr[j - 1][k - 1] == 1)
            {
                Union(j * b + k, (j - 1) * b + k - 1, parent, rank);
            }
        }
    }


    int freq[n],i;
    for(i=0;i<n;i++)
    {
        freq[i] = 0;
    }
    int num = 0;
    for(j = 0; j < a; j++)
    {
        for(k = 0; k < b; k++)
        {
            if(arr[j][k] == 1)
            {
                int x = find((j * b) + k, parent);

                if(freq[x] == 0)
                {
                    num = num + 1;
                    freq[x] = freq[x] + 1;
                }
                else
                {
                    freq[x] = freq[x] + 1;
                }
            }
        }
    }
    return num;
}
int  main()
{
    int r,c;
    int i,j,n,l;
    int total;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("\nEnter the number of columns: ");
    scanf("%d",&c);
    n = r*c;
    int parent[n];
    int rank[n];
    for(l = 0; l < n; l++)
    {
        rank[l] = 0;
    }
    makeset(n,parent);
    int arr[20][20];
    printf("\nEnter the elements of adjacency matrix(0's and 1's):\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    total = count_of_Islands(arr,r,c,n,parent,rank);
    printf("\nThe number of islands are: %d\n",total);
    return 0;
}

