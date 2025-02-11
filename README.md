#include<stdio.h>
struct Product
{
    int id;
    char name[20];
    float price;
    int quantity;
}products[20];
int main()
{
    FILE *fptr;
    fptr=fopen("ELECTRONICS.txt","w");
    int n,i;
    printf("Enter the number of products:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the product ID: ");
        scanf("%d",&products[i].id);
        printf("Enter the name: ");
        scanf("%s",products[i].name);
        printf("Enter the price: ");
        scanf("%f",&products[i].price);
        printf("Enter the quantity: ");
        scanf("%d",&products[i].quantity);
    }
    for(i=0;i<n;i++)
    {
        fprintf(fptr,"%d\t %s\t\t %.2f\t %d\n",products[i].id,products[i].name,products[i].price,products[i].quantity);
    }
    fclose(fptr);

    printf("\n\nELECTRONICS AND APPLIANCE PRODUCTS\n\n");
    printf("ID\t NAME\t\t PRICE\t QUANTITY\n");
    fptr=fopen("ELECTRONICS.txt","r");
    if (fptr == NULL) {
        printf("File opening failed");
        return 1;
    }
    for(int j=0;j<n;j++){
        fscanf(fptr,"%d %s %f %d\n",&products[j].id,products[j].name,&products[j].price,&products[j].quantity);
        printf("%d\t %s\t\t %.2f\t %d\n",products[j].id,products[j].name,products[j].price,products[j].quantity);
    }
    fclose(fptr);
    printf("\n\nEnter the orders:");
    int choice,ID,q,flag=0;
    float total=0;
    do
    {
        printf("\n\nEnter the product ID: ");
        scanf("%d",&ID);
        for(int i=0;i<n;i++)
        {
            if(ID==products[i].id)
            {
                flag=1;
            }
            if(flag==1){
            printf("%d\t %s\t\t %.2f\t %d\n\n",products[i].id,products[i].name,products[i].price,products[i].quantity);
            printf("Enter the quantity: ");
            scanf("%d",&q);
            if(q>products[i].quantity)
            {
               printf("OUT OF STOCK\n");
            }
            else
            {
              flag=1;
              total=total+(products[i].price*q);
              products[i].quantity=products[i].quantity-q;
            }
        }
        if(flag==0)
        {
            printf("Product is not available\n");
        }
        }
        printf("\nIf you want to order more press 1 else press 0:\n");
        scanf("%d",&choice);
     } while(choice!=0);
    printf("\nThe total price is %.2f",total);
    return 0;
}
