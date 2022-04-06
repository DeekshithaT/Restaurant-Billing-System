#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char again;
int total=0;
float gst,cgst;
int soupsrate[7][2]={  {0,0},{1,80},{2,100},{3,50},{4,15},{5,20},{6,30}};
int saladsrate[7][2]={{0,0},{1,80},{2,120},{3,20},{4,120},{5,150},{6,160}};
int startersrate[7][2]={{1,65},{2,50},{3,70},{4,80},{5,65},{6,70},{6,50}};
int purchased[][3]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
int temp[][3]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
void soups(char soupsmenu[][100]);
void salads( char saladsmenu[][100]);
void starters(char startersmenu[][100]);
void menu();
void display();
void soups_menucard();
void salads_menucard();
void starters_menucard();
void display_soups_bill(char soupsmenu[][100]);
void display_salads_bill(char saladsmenu[][100]);
void display_starters_bill(char startersmenu[][100]);
void repeatsoups(char soupsmenu[][100]);
void repeatsalads(char saladsmenu[][100]);
void repeatstarters(char startersmenu[][100]);
void main()
{
    char soupsmenu[][100]={"French Onion Soup","Chicken Tortilla Soup","Tomato Soup"};
    char saladsmenu[][100]={"Fruity Pasta Salas ","Potato Salad","Apple and Sprout Salad","Asian Chicken Salad"};
    char startersmenu[][100]={"Dahi Vada","Panneer Tikki","Sweet Potato Tikki","Sabudana Tikki","Bread Rolls"};
    int choice;
    do
    {
        enter:
        display();
        printf("Enter your choice here : ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1:
                printf("Soups\n");
                soups(soupsmenu);
                break;
            case 2:
                printf("Salads\n");
                salads(saladsmenu);
                break;
            case 3:
                printf("Starters\n");
                starters(startersmenu);
                break;
            default:
                printf("\nWrong choice entered Please enter the valid choice!!\n");
                goto enter;
        }
    }while(choice!=4);
}
void display()
{
    printf("                Welcome to Subbaiah Gari Hotel          \n ");
    printf("             -------------------------------------       \n");
    printf("Please select the type of food that you would like to purchase.  \n");
    printf("1.Soups\n");
    printf("2.Salads\n");
    printf("3.Starters\n");
}
void display_soupsmenu()
{
    printf("Soups Menu:\n");
    printf("-----------\n");
    printf("Please select the soup that you would like to purchase.\n");
    printf("1.French Onion Soup     - Rs 80.00\n");
    printf("2.Chicken Tortilla Soup - Rs 100.00\n");
    printf("3.Tomato Soup           - Rs 50.00\n");
}
void soups(char soupsmenu[][100]) 
{
    int choice = 0; 
    int quantity = 0;
    int code,i;
    display_soupsmenu();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    //printf("Total is %d\n",total);
    if(code>=1&&code<=4)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*soupsrate[code][1]; /*purchased[code][1]+ (quantity*bfrate[code][1]);*/
        total+=purchased[code][1];
       // printf("Total is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        soups(soupsmenu);
    }
    repeatsoups(soupsmenu);
}
void repeatsoups(char soupsmenu[][100])
{
    printf("Would you like to take anything else?Y for Yes and N for No\n");
    scanf(" %c",&again);
    if(again == 'Y')
    {
    soups(soupsmenu);
    }
    else if(again=='N')
    {
        display_soups_bill(soupsmenu);
        exit(0);
    }
    else
    {
        //printf("Sorry Invalid Decision Entered\n");
        repeatsoups(soupsmenu);
    }
}
void display_soups_bill(char soupsmenu[][100])
{
    int i;
    printf(" ===================================================   \n");
    printf("                 Subbaiah Gari Hotel                   \n");
    printf("                    BILL DETAILS               \n");
    printf("\t\t ITEMS\t\t\t\tPrice(in Rs.)\n");
    for(i=0;i<4;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",soupsmenu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tTotal=Rs.%d\n",total);
    printf("------------------------------------------        \n");

}
void display_salads_bill(char saladsmenu[][100])
{
    int i;
    printf("  -------------------------------------------         \n");
    printf("                     Subbaiah Gari Hotel                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",saladsmenu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tTotal=Rs.%d\n",total);
    printf("\n\n  ------------------------------------         \n\n");
}
void display_starters_bill(char startersmenu[][100])
{
    int i;
    printf("  --------------------------------------------         \n\n");
    printf("                      Subbaiah gari Hotel                   \n");
    printf("                    Bill Details                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",startersmenu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    printf("\n\n  -------------------------------------         \n\n");
}
void salads(char saladsmenu[][100]) // Lunch Screen Menu
{
    int choice = 0; //local variables
    int quantity = 0;
    //int again = 0,amt=0;
    int code,i;
    salads_menucard();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*lunchrate[code][1]);
        purchased[code][1]= quantity*saladsrate[code][1];
         total+=purchased[code][ 1];
        gst=total*0.12;
        cgst=gst/2;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        salads(saladsmenu);
    }
    repeatsalads(saladsmenu);
}
void starters(char startersmenu[][100]) 
{
    int choice = 0; 
    int quantity = 0;
    int code,i;
    starters_menucard();

    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*startersrate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        starters(startersmenu);
    }
    repeatstarters(startersmenu);
}
void salads_menucard()
{
    printf("                   Salads Menu\n");
    printf("             ------------------------------------         \n");
    printf("Please select the salad that you would like to purchase. && \n\n");
    printf("1.Fruity Pasta Salad- Rs 80.00\n");
    printf("2.Potato Salad- Rs 120.00\n");
    printf("3.Apple and Sprout Salad.- Rs 20.00\n");
    printf("4.Asian Chicken Salad - Rs 120.00\n");
}
void starters_menucard()
{
    printf("                    Starters Menu\n");
    printf("             --------------------------------------------\n");

    printf("Please select the starter that you would like to purchase. && \n\n");
    printf("1.Dahi Vada - Rs 65.00\n");
    printf("2.Panneer Tikka- Rs50\n");
    printf("3.Sweet Potato Tikki - Rs 70.00\n");
    printf("4.Sabudana Tikki- Rs 80.00\n");
    printf("5.Bread Rolls - Rs 65.00\n");
}
void repeatsalads(char saladsmenu[][100])
{
    printf("\nWould you like to buy anything else?Y or y"); // Allows user to choose whether to check-out or buy anything else.
    scanf(" %c",&again);
    if (again == 'Y')
    {
        salads(saladsmenu);
    }
    else
    {
        display_salads_bill(saladsmenu);
        exit(0);
    }
    /*else
    {
        //printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatsalads(saladsmenu);
    }*/
}
void repeatstarters(char startersmenu[][100])
{

    printf("Would you like to buy anything else?Y or y"); // Allows user to choose whether to check-out or buy anything else.
    scanf(" %c",&again);
    if (again == 'Y')
    {
        starters(startersmenu);
    }
    else
    {
        display_starters_bill(startersmenu);
        exit(0);
    }
    /*else
    {
        //printf("Sorry Invalid Decision Entered\n");
        repeatstarters(startersmenu);
    }*/
}









