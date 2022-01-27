#include<stdio.h>
void accept(int arr[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t",arr[i][j]);
        printf("\n");    
    }
    
}

void display(int sm[50][3])
{

    int n=sm[0][2];
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n",sm[i][0],sm[i][1],sm[i][2]);
    }
}

void convert(int arr[100][100], int sm[50][3], int m, int n)
{
    int k = 1;
    sm[0][2]=0;
    sm[0][0] = m;
    sm[0][1] = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                //sm[0][2]++;
                sm[k][0] = i;
                sm[k][1] = j;
                sm[k][2] = arr[i][j];
                k++;
            }
        }
    }
    sm[0][2] = k-1;
    display(sm);
}

void transpose(int sm[50][3],int m,int n)
{
    int trans[50][3];
    trans[0][0]=n;
    trans[0][1]=m;
    int k=1;
    trans[0][2]=sm[0][2];
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=sm[0][2];j++)
        {
            if(i==sm[j][1])
            {
                trans[k][0]=sm[j][1];
                trans[k][1]=sm[j][0];
                trans[k][2]=sm[j][2];
                k++;
            }
        }
    }

    display(trans);
}

void addsm(int sm[50][3],int sm1[50][3],int add[50][3])
{
    int i,j,k,m,n;
    if((sm[0][0]!=sm1[0][0])&&(sm[0][1]!=sm1[0][1]))
    {
        printf("\nInvalid operation ");
        return;
    }
    
    add[0][0]=sm1[0][0];
    add[0][1]=sm1[0][1];
    i=1;j=1;k=0;
    m=sm[0][2];
    n=sm1[0][2];
    while(i<=m && j<=n)
    {
        k++;
        
        if(sm[i][0]==sm1[j][0])
        {
            if(sm[i][1]==sm1[j][1])
            {
                add[k][0]=sm[i][0];
                add[k][1]=sm[i][1];
                add[k][2]=sm[i][2]+sm1[j][2];
                i++;
                j++;
            }
            else if(sm[i][1]<sm1[j][1])
            {
                add[k][0]=sm[i][0];
                add[k][1]=sm[i][1];
                add[k][2]=sm[i][2];
                i++;
            }
            else
            {
                add[k][0]=sm1[j][0];
                add[k][1]=sm1[j][1];
                add[k][2]=sm1[j][2];
                j++; 
            }
        }
        
        else if(sm[i][0]<sm1[j][0])
        {
                add[k][0]=sm[i][0];
                add[k][1]=sm[i][1];
                add[k][2]=sm[i][2];
                i++;
        }
        else
        {
                add[k][0]=sm1[j][0];
                add[k][1]=sm1[j][1];
                add[k][2]=sm1[j][2];
                j++; 
        }
        
    }
    
    while(i<=m)
    {
        k++;
        add[k][0]=sm[i][0];
        add[k][1]=sm[i][1];
        add[k][2]=sm[i][2];
        i++;
    }
    
    while(j<=n)
    {
        k++;
        add[k][0]=sm1[j][0];
        add[k][1]=sm1[j][1];
        add[k][2]=sm1[j][2];
        j++;
    }
    add[0][2]=k;
    
    display(add);
}

int main(int argc, char const *argv[])
{
    int arr[100][100];
    int arr1[100][100];
    int m, n;
    int sm[50][3];
    int sm1 [50][3];
    int ch;
    int add[100][3];
    while(1)
    {
        printf("\nWelcome to matrix operations\n");
        printf("\n 0. Exit\n 1. Accept Matrix\n 2. Display sparse matrix\n 3. Addition of 2 sparse matrices\n 4. Transpose of sparse matrix");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the no. of rows ");
               scanf("%d", &m);
               printf("\nEnter the no. of columns ");
               scanf("%d", &n);
               accept(arr, m, n);
               break;
               
            case 2:
               printf("\nSparse matrix of first matrix is \n");
               convert(arr, sm, m, n);
               break;
               
            case 3:
                printf("\nEnter second matrix \n");
                printf("\nEnter the no. of rows ");
                scanf("%d", &m);
                printf("\nEnter the no. of columns ");
                scanf("%d", &n);
                accept(arr1, m, n);
                printf("\nSparse matrix of second matrix\n");
                convert(arr1, sm1, m, n);
                printf("\nAddition of two sparse matrices\n");
                addsm(sm,sm1,add);
                break;
                
            case 4:
                printf("\nTranspose of first entered matrix is\n");
                transpose(sm,m,n);
                break;
                
            case 0:
                printf("\nThank you ");
                return 0;
                
            default:
                printf("\nEnter valid choice ");
                
                
        }
    }
    return 0;
}
