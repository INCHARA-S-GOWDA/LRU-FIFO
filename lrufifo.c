#include<stdio.h> 
#include<stdlib.h>
void FIFO(char S[],char F[],int l,int f)
 {
    int i,j=0,k,flag=0,cnt=0;
    printf("\n\tPAGE\tFRAMES\tFAULTS");
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
        {
            if(F[k]==S[i])
            flag=1;
        }
        if(flag==0)
        {
            printf("\n\t%c\t",S[i]);
            F[j]=S[i];
            j++;
            for(k=0;k<f;k++)
            {
                printf("%c",F[k]);
            }
            printf("\tPage-fault %d",cnt);
            cnt++;
        }
        else
        {
            flag=0;
            printf("\n\t%c\t",S[i]);
            for(k=0;k<f;k++)
            {
                printf("%c",F[k]);
            }
            printf("\tNo page-fault");
        }
        if(j==f)
        j=0;
    }
}
void lru(char S[],char F[],int l,int f)
{
    int i,j=0,k,m,flag=0,cnt=0,top=0;
    printf("\nPAGE\tFRAMES\tFAULTS");
    for(i=0;i<l;i++)
    {
        for(k=0;k<f;k++)
        {
            if(F[k]==S[i])
            {
                flag=1;
                break;
            }
        }
        printf("\n%c\t",S[i]);
        if(j!=f && flag!=1)
        {
            F[top]=S[i];
            j++;
            if(j!=f)
             top++;
        }
        else
        {
            if(flag!=1)
            {
            for(k=0;k<top;k++)
                {
                    F[k]=F[k+1];
                }
                F[top]=S[i];
            }
            if(flag==1)
            {
                for(m=k;m<top;m++)
                {
                    F[m]=F[m+1];
                }
            F[top]=S[i];
            }
        }
        for(k=0;k<f;k++)
        {
            printf("%c",F[k]);
        }
        if(flag==0)
        {
            printf("\tPage-fault %d",cnt);
            cnt++;
        }
        else
        printf("\tNo page fault");
        flag=0;
    }
}
int main()
{
    int ch,i,l,f;
    char F[10],S[25];
    printf("\nEnter the no of empty frames: "); 
    scanf("%d",&f);
    printf("\nEnter the length of the string: ");
    scanf("%d",&l);
    printf("\nEnter the string: ");
    scanf("%s",&S);
    for(i=0;i<f;i++)
    F[i]=-1;
        printf("\n1:FIFO\n2:LRU \n3:EXIT"); 
        printf("\nEnter your choice: "); 
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: for(i=0;i<f;i++)
                    { F[i]=-1; }
                    FIFO(S,F,l,f);
                    break;
            case 2: for(i=0;i<f;i++)
                    {F[i]=-1;}
                    lru(S,F,l,f);
                    break;
            case 3: exit(0);
        }
       
 }
 
