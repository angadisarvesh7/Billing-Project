#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct  list{

    char name[20];
    int acc;
    char phno[10];
    int bill;
    struct list *llink,*rlink;
};
typedef struct list *NODE;
//function to allocate memory to a node
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct list));
    if(x==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }
    return x;
}
//function to deallocate memory
void freenode(NODE x)
{
    free(x);
}
//function to add user
NODE adduser(NODE head,char name[],char phno[])
{


    NODE temp,cur;
    temp=getnode();
    strcpy(temp->name,name);
    strcpy(temp->phno,phno);
    temp->acc=head->bill+1;
    temp->bill=0;
    printf("\n%s\n",temp->phno);
    printf("%s\n",temp->name);
    if(head->bill==0)
    {
        head->rlink=temp;
        temp->llink=head;
        temp->rlink=head;
        head->bill++;
        return head;
    }
    cur=head->rlink;
    while(cur->rlink!=head)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    temp->rlink=head;
    head->bill++;
    return head;
}
//function to get user details based on account number or name
NODE view(NODE head)
{
    NODE cur;
    cur=head->rlink;
    char name[20];
    int ch,acc;
    printf("Search by \n \t1.NAME \n \t2.AC.NO\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\n\nEnter name\n");
                scanf("%s",name);
                if(head->bill==0)
                {
                    printf("NO accounts exist");
                    return head;
                }
                while(strcmp(cur->name,name)!=0)
                {
                    cur=cur->rlink;
                    if(cur->rlink==head&&strcmp(cur->name,name)!=0)
                    {
                        printf("Account Not Found");
                        return head;
                    }

                }

                    printf("NAME : %s\n",cur->name);
                    printf("Acc.No : %d\n",cur->acc);
                    printf("Ph.NO : %s\n",cur->phno);
                    printf("Bill : %d\n",cur->bill);
                    cur=head->rlink;
                    return head;

                break;
        case 2: printf("\n\nEnter Acc.No\n");
                scanf("%d",&acc);
                if(head->bill==0)
                {
                    printf("No accounts exist");
                    return head;
                }
                while(cur->acc!=acc)
                {
                    cur=cur->rlink;
                    if(cur->rlink==head)
                    {
                        break;
                    }
                }
                if(cur->acc==acc)
                {
                printf("NAME : %s\n",cur->name);
                printf("Acc.No : %d\n",cur->acc);
                printf("Ph.NO : %s\n",cur->phno);
                printf("Bill : %d\n",cur->bill);
                return head;
                }
                else
                {
                    printf("\n\nAccount not found\n");
                }
                    break;
    }return head;

}
//function to delete a user
NODE deluser(NODE head)
{
    NODE cur,prev,next;
    int ch;
    int c,acc;
    char name[20];
    printf("\nDELETE USER\n");
    printf("1.DELETE BY NAME\n2.DELETE BY ACC.NO");
    scanf("%d",&ch);
    cur=head->rlink;
        switch(ch)
        {
            case 1: printf("Enter name\n");
                    scanf("%s",name);
                    while(strcmp(cur->name,name)!=0)
                    {
                        cur=cur->rlink;
                    }
                    printf("NAME : %s\n",cur->name);
                    printf("Acc.No : %d\n",cur->acc);
                    printf("Ph.NO : %s\n",cur->phno);
                    printf("Bill : %d\n",cur->bill);
                    printf("***ACCOUNT DELETED***");
                    prev=cur->llink;
                    next=cur->rlink;
                    prev->rlink=next;
                    next->llink=prev;
                    freenode(cur);
                    break;
            case 2: printf("Enter Acc.NO\n");
                    scanf("%d",&acc);
                    while(cur->acc!=acc)
                    {
                        cur=cur->rlink;
                    }
                    printf("NAME : %s\n",cur->name);
                    printf("Acc.No : %d\n",cur->acc);
                    printf("Ph.NO : %s\n",cur->phno);
                    printf("Bill : %d\n",cur->bill);
                    printf("***ACCOUNT DELETED***");
                    prev=cur->llink;
                    next=cur->rlink;
                    prev->rlink=next;
                    next->llink=prev;
                    freenode(cur);
                    break;
        }return head;
    }
//function to go to usual billing
NODE ubill(NODE head,int acc)
{
    NODE cur;
    int bill;
    cur=head->rlink;
    while(cur->acc!=acc)
    {
        cur=cur->rlink;
        if(cur->rlink==head&&cur->acc!=acc)
        {
            printf("Account not found");
            break;
        }
    }
    printf("NAME : %s\n",cur->name);
    printf("Acc.No : %d\n",cur->acc);
    printf("\nEnter Amount\n");
    scanf("%d",&bill);
    cur->bill+=bill;
    return head;
}
//function to get bill summary
NODE bsumm(NODE head,int acc)
{
    NODE cur;
    int p;
    int paid;
    if(head==head&&head->bill==0)
    {
        printf("NOT FOUND");
        return head;
    }
    cur=head->rlink;
    while(cur->acc!=acc)
    {
        cur=cur->rlink;
        if(cur->rlink==head&&cur->acc!=acc)
        {
            printf("Account not found");
            break;

        }
    }
    printf("Amount payable = %d",cur->bill);
    printf("\nGo to payment(if yes press 1 else press anything)");
    scanf("%d",&p);
    if(p==1)
    {
        printf("\nAmount being paid");
        scanf("%d",&paid);
        cur->bill=cur->bill-paid;
        printf("\n\nNEW BALANCE = %d",cur->bill);
    }
}

int main()
{
    NODE head;
    char name[20];
    char phno[10];

    head=getnode();
    head->llink=head->rlink=NULL;
    head->bill=0;
    int ch,acc;
    int c,d;
    do
    {

    printf("\n\n************MENU***********\n");

    printf("ENTER \n1.ACCOUNT MANAGEMENT\n 2.BILLING\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\n\n---------------------ACCOUNT MANAGEMENT-------------\n");

                printf("ENTER \n\t 1.ADD ACCOUNT \n\t2.VIEW ACCOUNT INFO \n\t3.DELETE ACCOUNT\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1: printf("\n\n ADD USER\n");
                            printf("Enter phno\n");
                            scanf("%s",phno);
                            printf("Enter Name\n");
                            scanf("%s",name);
                            adduser(head,name,phno);
                            printf("added user account no:%d\n",head->bill);

                            break;
                    case 2: printf("\n\n VIEW USER INFO\n");
                            view(head);

                            break;
                    case 3: printf("\n\n DELETE USER\n");
                            deluser(head);

                            break;


                }break;

            case 2: printf("\n1. USUAl BILLING\n 2.BILL SUMMARY");
                    scanf("%d",&d);
                    switch(d)
                    {
                        case 1: while(1)
                                {
                                    printf("\nEnter 0 to end session ");
                                    printf("\nEnter acc.no\n");

                                    scanf("%d",&acc);
                                    if(acc==0)
                                        break;
                                    ubill(head,acc);

                                }
                                break;
                        case 2: printf("\n\nBILL SUMMARY\n\n");
                                printf("Enter Account NO\n");
                                scanf("%d",&acc);
                                bsumm(head,acc);
                                break;

                    }
        }
    }while(ch!=4);
}

