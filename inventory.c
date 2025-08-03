#include <stdio.h>
struct Product {
    int id;
    char name[20];
    float price;
    int quantity;
} products[20];
int main() {
    FILE *fptr;
    fptr = fopen("ELECTRONICS.txt", "w");
    int n, i;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter the product ID: ");
        scanf("%d", &products[i].id);
        printf("Enter the name: ");
        scanf("%s", products[i].name);
        printf("Enter the price: ");
        scanf("%f", &products[i].price);
        printf("Enter the quantity: ");
        scanf("%d", &products[i].quantity);
        fprintf(fptr, "%d %s %.2f %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    fclose(fptr);

    printf("\n\nELECTRONICS AND APPLIANCE PRODUCTS\n\n");
    printf("ID\tNAME\t\tPRICE\tQUANTITY\n");
    fptr = fopen("ELECTRONICS.txt", "r");
    if (fptr == NULL) {
        printf("File opening failed\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        fscanf(fptr, "%d %s %f %d", &products[i].id, products[i].name, &products[i].price, &products[i].quantity);
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    fclose(fptr);
    int choice, ID, q;
    float total = 0;
    do {
        int found = 0;
        printf("\n\nEnter the product ID: ");
        scanf("%d", &ID);
        for (i = 0; i < n; i++) {
            if (ID == products[i].id) {
                found = 1;
                printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
                printf("Enter the quantity: ");
                scanf("%d", &q);
                if (q > products[i].quantity) {
                    printf("OUT OF STOCK\n");
                } else {
                    total += products[i].price * q;
                    products[i].quantity -= q;
                }
                break;
            }
        }
        if (!found) {
            printf("Product is not available\n");
        }
        printf("\nIf you want to order more press 1 else press 0: ");
        scanf("%d", &choice);
    } while (choice != 0);
    printf("\nThe total price is %.2f\n", total);
    return 0;
}

