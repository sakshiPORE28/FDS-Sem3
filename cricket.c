#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;

typedef struct info
{
    char name[100];
    int age;
    char country[100];
    char category[100];
    int no_odi;
    int no_inter_20;
    int batscore;
    int wickets;
}info;

void read(struct info s[100])
{
    printf("Enter the number of players: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("\nEnter the details of player %d: ", i+1);
        printf("\nEnter name: ");
        scanf("%s",s[i].name);
        printf("\nEnter age: ");
        scanf("%d",&s[i].age);
        printf("\nEnter country: ");
        scanf("%s",s[i].country);
        printf("\nSelect the category of the player from the list given: ");
        printf("1. Batsman \t2. Bowler \t3. Wicket-keeper \t4. All-rounder \n(Enter as per mentioned in the list): ");
        scanf("%s",s[i].category);
        printf("\nEnter the number of ODI's played: ");
        scanf("%d",&s[i].no_odi);
        printf("\nEnter the number of International 20-20's played: ");
        scanf("%d",&s[i].no_inter_20);
        printf("\nEnter the average batting score: ");
        scanf("%d",&s[i].batscore);
        printf("\nEnter the number of wickets taken: ");
        scanf("%d",&s[i].wickets);
    }
}

void batsman(struct info s[100])
{
    int count=0;
    char cntry[100];
    printf("Enter country to display number of batsman: ");
    scanf("%s",cntry);
    for(int i=0; i<n; i++)
    {
        if((strcmp(cntry,s[i].country)==0) && ((strcmp("Batsman",s[i].category)==0)||(strcmp("All-rounder",s[i].category)==0)))
        {
            count++;
        }
    }
    printf("\nNumber of batsman of %s country are: %d", cntry, count);
}

void sorting(struct info s[100])
{
    struct info temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(s[j].batscore < s[j+1].batscore)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    printf("\nThe sorted order of batsman as per their average batting score ");
    printf("\n(Sorted in descending order): ");
    printf("\nName\t Avg. Batscore");
    for(int i=0; i<n; i++)
    {
        printf("\n%s\t %d\n", s[i].name, s[i].batscore);
    }
}

void average(struct info s[100])
{
    int index=0;
    int bscore=0;
    for(int i=0; i<n; i++)
    {
        if((strcmp("Batsman",s[i].category)==0) || (strcmp("All-rounder",s[i].category)==0))
        {
            if(s[i].batscore>bscore)
            {
                bscore=s[i].batscore;
                index=i;
            }
        }
    }
    printf("Name of batsman with highest average score: %s",s[index].name);
}

void bowlers(struct info s[100])
{
    int count=0;
    char cntry[100];
    printf("Enter country to display number of bowlers: ");
    scanf("%s",cntry);
    for(int i=0; i<n; i++)
    {
        if((strcmp(cntry,s[i].country)==0) && ((strcmp("Bowler",s[i].category)==0)||(strcmp("All-rounder",s[i].category)==0)))
        {
            count++;
        }
    }
    printf("\nNumber of bowlers of %s country are: %d", cntry, count);
}

void wickets(struct info s[100])
{
    int index=0;
    int wkt=0;
    for(int i=0; i<n; i++)
    {
        if((strcmp("Bowler",s[i].category)==0)|| (strcmp("All-rounder",s[i].category)==0))
        {
            if(s[i].wickets>wkt)
            {
                wkt=s[i].wickets;
                index=i;
            }
        }
    }
    printf("Name of bowler who has taken maximum wickets: %s",s[index].name);
}

void display(struct info s[100])
{
    for(int i=0; i<n; i++)
    {
        printf("\nName:- %s\t Age:- %d\t Country:- %s\t Category:- %s\nODI's:- %d\t Int.20-20's:- %d\t Batscore:- %d\t Wickets:- %d\n", 
        s[i].name, s[i].age, s[i].country, s[i].category, s[i].no_odi, s[i].no_inter_20, s[i].batscore, s[i].wickets);
        
    }
}



int main()
{
    struct info s[100];
    int ch;
    char co;
    read(s);
    printf("\n1. Number of batsman of a particular country \n2. Sorting the batsman as per the average batting score \n3. Batsman with highest average score \n4. Number of bowlers of a particular country \n5. The bowler that has taken maximum number of wickets \n6. Display board information\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            batsman(s);
        break;
        case 2:
            sorting(s);
        break;
        case 3:
            average(s);
        break;
        case 4:
            bowlers(s);
        break;
        case 5:
            wickets(s);
        break;
        case 6:
            display(s);
        break;
        default: printf("\nInvalid case");
    }
    for (;;)
    {
      printf("\nContinue [YN]? ");
      scanf(" %c",&co);
      if (co == 'Y')
          return main(); 
      else if (co == 'N')
          return 0;
    }

    return 0;
}
