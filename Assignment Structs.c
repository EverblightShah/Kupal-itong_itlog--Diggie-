#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Inner structure template for PRODUCT
struct PRODUCT {
    char Prod_code[8];              
    char Product_Description[15];    
    float unit_price;
    int quantity;
};

// Outer structure template for CUSTOMER (Structure within Structure)
struct CUSTOMER {
    char CustomerName[30];           
    char Cust_Address[30];           
    struct PRODUCT purchases[MAX_ITEMS]; // Array of product structures nested inside
    int item_count;                      // Dynamically tracks total items purchased
};

// Function Prototypes
void safe_get_string(char *buffer, int size);
void RECORD(struct CUSTOMER *customer);
float KOMPUTE(const struct CUSTOMER *customer, float amounts[]);
void display_receipt(const struct CUSTOMER *customer, const float amounts[], float total_billing);

int main() {
    struct CUSTOMER customer;
    float individual_amounts[MAX_ITEMS] = {0.0f};
    
    // Call function RECORD to capture info
    RECORD(&customer);
    
    // Call function KOMPUTE to handle calculations
    float total_billing = KOMPUTE(&customer, individual_amounts);
    
    // Display the blended aesthetic official receipt
    display_receipt(&customer, individual_amounts, total_billing);
    
    return 0;
}

// Safely captures input, strips newline, and flushes leftover stream data if truncation occurs
void safe_get_string(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        char *nl = strchr(buffer, '\n');
        if (nl) {
            *nl = '\0'; // Strip the newline cleanly
        } else {
            // Input exceeded buffer size; flush the leftover characters up to the newline
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

// Accepts user parameters safely and controls input buffer clears
void RECORD(struct CUSTOMER *customer) {
    printf("Enter Customer Name: ");
    safe_get_string(customer->CustomerName, sizeof(customer->CustomerName));
    
    printf("Enter Customer Address: ");
    safe_get_string(customer->Cust_Address, sizeof(customer->Cust_Address));
    
    printf("Enter number of items to purchase: ");
    {
        char line[64];
        safe_get_string(line, sizeof(line));
        if (sscanf(line, "%d", &customer->item_count) != 1) {
            customer->item_count = 0;
        }
    }
    
    if (customer->item_count > MAX_ITEMS) {
        customer->item_count = MAX_ITEMS;
    }
    
    for (int i = 0; i < customer->item_count; i++) {
        printf("\n[Item #%d]\n", i + 1);
        
        printf("          Enter product code: ");
        safe_get_string(customer->purchases[i].Prod_code, sizeof(customer->purchases[i].Prod_code));
        
        printf("          Enter product description: ");
        safe_get_string(customer->purchases[i].Product_Description, sizeof(customer->purchases[i].Product_Description));
        
        printf("          Enter unit price: ");
        {
            char line[64];
            safe_get_string(line, sizeof(line));
            if (sscanf(line, "%f", &customer->purchases[i].unit_price) != 1) {
                customer->purchases[i].unit_price = 0.0f;
            }
        }

        printf("          Enter number quantity : ");
        {
            char line[64];
            safe_get_string(line, sizeof(line));
            if (sscanf(line, "%d", &customer->purchases[i].quantity) != 1) {
                customer->purchases[i].quantity = 0;
            }
        }
    }
}

// Processes calculation items through the dynamic customer array
float KOMPUTE(const struct CUSTOMER *customer, float amounts[]) {
    float total = 0.0f;
    for (int i = 0; i < customer->item_count; i++) {
        amounts[i] = customer->purchases[i].unit_price * customer->purchases[i].quantity;
        total += amounts[i];
    }
    return total;
}

// Renders the official receipt layout
void display_receipt(const struct CUSTOMER *customer, const float amounts[], float total_billing) {
    printf("\n================================================================================\n");
    printf("==============================ABC Hardware Company==============================\n");
    printf("================================OFFICIAL RECEIPT================================\n");
    printf("================================================================================\n");
    
    printf("Customer Information:\n");
    printf("  Customer Name:    %s\n", customer->CustomerName);
    printf("  Customer Address: %s\n", customer->Cust_Address);
    
    printf("================================================================================\n");
    printf("=======================Below are the details of your purchase===================\n");
    printf("================================================================================\n");
    
    printf("%-15s%-30s%-12s%-10s%-10s\n", 
           "Product code", "Product Description", "Unit Price", "Quantity", "Amount");
    printf("--------------------------------------------------------------------------------\n");
           
    for (int i = 0; i < customer->item_count; i++) {
        printf("%-15s%-30s%-12.2f%-10d%-10.2f\n",
               customer->purchases[i].Prod_code,
               customer->purchases[i].Product_Description,
               customer->purchases[i].unit_price,
               customer->purchases[i].quantity,
               amounts[i]);
    }
    
    printf("================================================================================\n");
    printf("%70s\n", "Total Billing");
    printf("%60s%.2f\n", ":   Php ", total_billing);
    printf("================================================================================\n");
}