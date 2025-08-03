
**ELECTRONICS AND APPLIANCES INVENTORY MANAGEMENT SYSTEM IN C**

This C program manages an inventory of electronics and appliances. It allows product registration, file storage, inventory display, and customer order processing with total billing.

**FEATURES**

1. PRODUCT ENTRY  
   - Input for each product:  
     - Product ID (int)  
     - Name (char array of size 20)  
     - Price (float)  
     - Quantity (int)  

2. FILE WRITING  
   - Product details are stored in ELECTRONICS.txt using fprintf.

3. FILE READING  
   - Reads stored data from ELECTRONICS.txt using fscanf.

4. ORDER PLACEMENT  
   - Users can place orders by entering product IDs and quantities.  
   - It checks for stock and updates total price.  
   - Shows messages if stock is insufficient or product ID is invalid.

5. BILLING  
   - Displays the final total cost after all orders.

**SAMPLE OUTPUT**

Enter the number of products: 2

Enter the product ID: 101  
Enter the name: Fan  
Enter the price: 1200  
Enter the quantity: 10

Enter the product ID: 102  
Enter the name: AC  
Enter the price: 25000  
Enter the quantity: 5

ELECTRONICS AND APPLIANCE PRODUCTS

ID    NAME        PRICE     QUANTITY  
101   Fan         1200.00   10  
102   AC          25000.00  5

Enter the orders:

Enter the product ID: 101  
101   Fan         1200.00   10

Enter the quantity: 2

If you want to order more press 1 else press 0:  
1

Enter the product ID: 102  
102   AC          25000.00  5

Enter the quantity: 1

If you want to order more press 1 else press 0:  
0

The total price is 27400.00

**DATA STRUCTURE USED**

struct Product  
{  
    int id;  
    char name[20];  
    float price;  
    int quantity;  
};

**LIMITATIONS**

- Only 20 products supported (can be increased)  
- Product names limited to 19 characters  
- Inventory is updated in memory, not saved back to file  
- No duplicate ID or input validation


      
