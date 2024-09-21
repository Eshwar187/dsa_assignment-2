#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to store product details
struct Product
{
    char name[100];
    char id[100];
    float price;
};

int main()
{
    int n;
    float totalCost = 0;
    struct Product *products;
    struct Product *mostExpensive = NULL;
    struct Product *leastExpensive = NULL;

    // Input number of products
    printf("Enter the number of products: ");
    scanf("%d", &n);
    printf("\n");

    // Allocate memory for n products
    products = (struct Product *)malloc(n * sizeof(struct Product));
    if (products == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input details for each product

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for product %d:\n", i + 1);
        printf("Product Name: ");
        scanf(" %[^\n]s", &products[i].name); // Read name with spaces
        printf("Product ID: ");
        scanf("%s", &products[i].id);
        printf("Price: ");
        scanf("%f", &products[i].price);

        printf("\n");

        totalCost += products[i].price;

        // Determine most expensive product
        if (mostExpensive == NULL || products[i].price > (*mostExpensive).price)
        {
            mostExpensive = &products[i];
        }

        // Determine lowest priced product
        if (leastExpensive == NULL || products[i].price < (*leastExpensive).price)
        {
            leastExpensive = &products[i];
        }
    }

    // Display Results
    printf("Product Details:\n");
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("Product Name: %s,Product ID: %s,Price: %.2f\n", products[i].name, products[i].id, products[i].price);
    }
    printf("\n");
    if (mostExpensive != NULL)
    {
        printf("Most Expensive Product:\n");
        printf("Product Name: %s\n", (*mostExpensive).name);
        printf("Product ID: %s\n", (*mostExpensive).id);
        printf("Price: %.2f\n", (*mostExpensive).price);
    }
    printf("\n");
    if (leastExpensive != NULL)
    {
        printf("Least Expensive Product:\n");
        printf("Product Name: %s\n", (*leastExpensive).name);
        printf("Product ID: %s\n", (*leastExpensive).id);
        printf("Price: %.2f\n", (*leastExpensive).price);
    }
    printf("\n");
    printf("Total Cost of all Products: %.2f\n", totalCost);
    // Free allocated memory
    free(products);

    return 0;
}