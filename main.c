#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
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
    printf("\033[22;34mHello, world!\033[0m");
    printf("\033[22;34m Enter your choice\033[0m\n" );
    printf("[1]register\n");
    printf("[2] number of students registered\n");
    printf("[3]register book\n") ;
    printf("[4]view all books\n");
    printf("[5]search for a book\n");
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

        printf("name :%s        id : %d          email : %s\n",arr[i].name,arr[i].id,arr[i].email);

    }
}
void show_books(struct book arr[],int place)
{
    printf("number of books registered = %d\n",place);
    int i=0;
    for(i=0; i<place; i++)
    {

        printf("name :%s        id : %d\n",arr[i].name,arr[i].id);

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
