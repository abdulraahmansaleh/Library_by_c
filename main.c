#include <stdio.h>
#include <stdlib.h>

int menu();
struct student
{
    int id;
    char name[30];
    char email[30];
    char pass[100];
};
struct book
{
    int id;
    char name[50];
};
void get_data(struct student arr[],int blace);
void show_data(struct student arr[],int place);
void get_books(struct book arr[],int place);
int menu()
{
    printf("Enter your choice \n" );
    printf("[1]Register\n");
    printf("[2]Students registered\n");
    printf("[3]Register book\n") ;
    printf("[4]View all books\n");
    printf("[5]Search for a book\n");
    printf("[6]Exit\n");
    int n;
    scanf("%d",&n);
    return n;
}
void get_books(struct book arr[],int place)
{
    printf("Enter name of book\n");
    scanf("%s",arr[place].name);
 printf("Enter book id\n");
    scanf("%d",&arr[place].id);

}
void get_data(struct student arr[],int place)
{
    printf("Enter Your name\n");
    scanf("%s",arr[place].name);
    printf("Enter Your email\n");
    scanf("%s",arr[place].email);
    printf("Enter Your id\n");
    scanf("%d",&arr[place].id);
    printf("Enter Your password\n");
    scanf("%s",arr[place].pass);
}
void show_data(struct student arr[],int place)
{
    printf("number of student registered = %d\n",place);
    int i=0;
    for(i=0; i<place; i++)
    {

        printf("\tname :%s   id :%d   email :%s\n",arr[i].name,arr[i].id,arr[i].email);

    }
}
void show_books(struct book arr[],int place)
{
    printf("number of books registered = %d\n",place);
    int i=0;
    for(i=0; i<place; i++)
    {

        printf("\tname:%s   id :%d\n",arr[i].name,arr[i].id);

    }
}
void search(struct book arr[],int place)
{
    printf("Enter the name of the book\n");
    char name [50];
    scanf("%s",name);
    int i=0,u=0;
   int f=0;
    for(i=0;i<place;i++)
    {
        f=0;
        for( u=0;u<50;u++)
        {
            if(name[u]=='\0'||arr[i].name[u]=='\0')
            {
                break;
            }
            printf("%c   %c\n",name[u],arr[i].name[u]);
          if(arr[i].name[u]!=name[u])
          {
              f=1;
              break;
          }

        }
         if(!f)
          {
             printf("book is found id %d\n",arr[i].id);
             break;
          }

    }
     if(f)
            printf("not found\n");
}
int main()
{
    int m=0,number_of_student=0,number_of_books=0;
    struct student arr[1000]= {};
    struct book array [1000]={};
    for(;;)
    {
        int m=menu();
        if(m>6||m<1)
            printf("Enter a valid number\n");
        else if(m==1)
        {
            get_data(arr,number_of_student);
            number_of_student++;

        }
        else if(m==2)
        {
            show_data(arr,number_of_student);
        }
        else if(m==3)
        {
        get_books(array,number_of_books);
        number_of_books++;
        }
        else if(m==4)
        {
            show_books(array,number_of_books);
        }
        else if (m==5)
        {
          search(array,number_of_books);
        }
        else if(m==6)
        {
             int n;
            for(;;){
            printf("Enter your feedback from 1 to 5 \n");

            scanf("%d",&n);
            if(n<=5&&n>=1)
                break;
            else
                printf("Enter a valid number");
            }
             printf("Your feedback %d",n);
           printf("thanks :)");
            break;
        }
    }
    return 0;
}
