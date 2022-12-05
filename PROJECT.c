#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Product
{
    int ID;

    char name[50];

    int price[20];

    int self;

    struct Product *next;

}* head;
//Linked list insertion

void insert(int ID, char* name, int* price, int* self ) //pointer variable

{
    struct Product * product = (struct Product *) malloc(sizeof(struct Product));

    product->ID = ID;

    strcpy(product->name, name);

    strcpy(product->price, price);

    product->self = self;

    product->next = NULL;

    if(head==NULL)
    {
        // if head is NULL

        // set product as the new head

        head = product;
    }
    else
    {
        // if list is not empty

        // insert product in beginning of head

        product->next = head;

        head = product;
    }
}

//Search in linked list

void search(int ID)
{
    struct Product * temp = head;

    while(temp!=NULL)

    {
        if(temp->ID==ID)

        {
            printf("\n\t\t\tProduct ID Number : %d\n", temp->ID);

            system("COLOR 6");

            printf("\t\t\tProduct Name : %s\n", temp->name);

            printf("\t\t\tPrice : %s\n", temp->price);

            printf("\t\t\tself no. : %s\n", temp->self);

            return;
        }
        temp = temp->next;
    }

    printf("\n\t\t\t Product ID number %d is not found !!!\n", ID);
}

//Linked list updation

void update(int ID)

{
    system("COLOR 6");

    struct Product * temp = head;

    while(temp!=NULL)

    {
        if(temp->ID==ID)
        {
            printf("\n\t\t\tRecord with Product ID number %d Found !!!\n", ID);

            printf("\t\t\tEnter new Product name: ");

            scanf("%s", temp->name);

            printf("\t\t\tEnter new price number: ");

            scanf("%s", temp->price);

            printf("\t\t\tEnter product self no: ");

            scanf("%f",&temp->self);

            printf("\n\t\t\tUpdation Successful!!!\n");

            return;
        }
        temp = temp->next;
    }

    printf("\n\t\t\tProduct with ID number %d is not found !!!\n", ID);
}

// Delete elements in linked list

void Delete(int ID)

{

    system("COLOR 6");

    struct Product * temp1 = head;

    struct Product * temp2 = head;

    while(temp1!=NULL)
    {
        if(temp1->ID==ID)
        {
            printf("\n\t\t\tRecord with Product ID number %d found !!!\n", ID);

            if(temp1==temp2)
            {
                // this condition will run if

                // the record that we need to delete is the first node

                // of the linked list

                head = head->next;

                free(temp1);
            }
            else
            {
                // temp1 is the node we need to delete

                // temp2 is the node previous to temp1

                temp2->next = temp1->next;

                free(temp1);
            }
            printf("\n\t\t\tRecord Successfully Deleted !!!\n");

            return;
        }

        temp2 = temp1;

        temp1 = temp1->next;
    }

    printf("\n\t\t\tProduct with ID number %d is not found !!!\n", ID);

}
// Display function in linked list
void display()

{

    system("COLOR 6");

    struct Product * temp = head;

    while(temp!=NULL)

    {
        printf("\n\t\t\tProduct ID Number : %d\n", temp->ID);

        printf("\t\t\tName : %s\n", temp->name);

        printf("\t\t\tPrice : %s\n", temp->self);

        temp = temp->next;

    }

}
int main()

{
    head = NULL;

    int choice;

    char name[100];

    char self[10];

    char price[100];

    int ID;

    system("COLOR 6");

    printf("\t\t __________________________________________________________\n");

    printf("\t\t|                                                          |\n");

    printf("\t\t|                                                          |\n");

    printf("\t\t|                        Welcome                           |\n");

    printf("\t\t|                          to                              |\n");
printf("\t\t|                     OUR SMART SHOP                       |\n");

    printf("\t\t|                                                          |\n");

    printf("\t\t|__________________________________________________________|\n");

    printf("\n                                  Team Members            \n");

    printf("\n                          Name                   ID        ");

    printf("\n                 Shimul Chakraborty          202-15-3840");

    printf("\n                 MD.Saif Ibne Jahid          202-15-3847");

    printf("\n                 Ananna Saha                 202-15-3821");

    printf("\n\n\t\t\t|---------------------------------------|\n");

    printf("\t\t\t|      Press Any Digit From Below       |\n");

    printf("\t\t\t|---------------------------------------|\n");

    printf("\n\n\t\t\tPress : 1 To Insert new Product.\n\t\t\tPress : 2 To search Products.\n\t\t\tPress : 3 To Delete Product details.\n\t\t\tPress : 4 To update product details.\n\t\t\tPress : 5 To view all Products.\n\t\t\tPress : 6 To EXIT.");

    do
    {

        printf("\n\n\t\t\tEnter Your Choice: ");

        scanf("%d", &choice);

        // Switch case function

        switch (choice)

        {

        case 1:

            printf("\n\t\t\tEnter Product ID Number : ");

            scanf("%d", &ID);

            printf("\t\t\tEnter Product Name: ");

            scanf("%s", name);

            printf("\t\t\tEnter  Self No : ");

            scanf("%s", self);

            printf("\t\t\tEnter product price: ");

            scanf("%s", price);

            insert(ID, name, self, price);

            break;

        case 2:

            printf("\n\t\t\tEnter Product ID Number to search : ");

            scanf("%d", &ID);

            search(ID);

            break;

        case 3:

            printf("\n\t\t\tEnter Product ID number to delete : ");

            scanf("%d", &ID);

            Delete(ID);

            break;

        case 4:

            printf("\n\t\t\tEnter Product ID number to update : ");

            scanf("%d", &ID);

            update(ID);

            break;

        case 5:

            display();

            break;

        case 6:

            printf("\n\n\n\t\t\t\t\t\tExit ");

            printf("\n\n\t\t\t|********************************************|\n");

            printf("\t\t\t|        Thanks For Using Our Software       |\n");

            printf("\t\t\t|********************************************|\n");

            exit(0);

            break;

        default :

            printf("\n\t\t\tInvalid choice\n");
            printf("\n\t\t\tPlease enter a valid choice\n");
            break;
        }
    }
    while (choice != 0);
}
