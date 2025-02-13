#include <stdio.h>

struct Item {           // Structure to store items
    int value;
    int weight;
    float ratio;            // ratio= value/weight, which helps sorting the items for GREEDY APPROACH
};


void sort(struct Item items[], int n) {              //to sort the items based on value/weight ratio in descending order, i used bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];              // Swap the items if the ratio of item i is less than item j
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item items[], int n) {             //n: number of items input

    sort(items, n);        // Sort items based on value/weight ratio in descending order

    int currentWeight = 0;                   //to keep track of the current weight of the knapsack
    float totalValue = 0.0;                        // to accumulate the total value of the items that are added to the knapsack

    for (int i = 0; i < n; i++) {
        // If adding the entire item doesn't exceed the capacity
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        // Otherwise take the fractional part of the item
        else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break; // Knapsack is full
        }
    }

   /* for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {                 // If the whole item can be taken
            currentWeight = currentWeight + items[i].weight;
            totalValue = totalValue + items[i].value;
        }
        else {                       //If the current item can't fit completely into the knapsack, we take the fractional part of the item that fits
            int remainingWeight = capacity - currentWeight;          //calculates how much more weight can be added to the knapsack
            totalValue = totalValue + items[i].value * ((float)remainingWeight / items[i].weight);  //This adds the fractional value of the item to knapsack
            break;                // The knapsack is now full, so break out of the loop
        }
    }*/
    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];                 //The array items[] is declared to store n items

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio = (float)items[i].value / items[i].weight;               // Calculate value/weight ratio for each item
    }

    float maxValue = fractionalKnapsack(capacity, items, n);               // Get the maximum value that knapsack is carrying

    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}

//Time Complexity= O(n^2)
//O(n^2) for the sorting step  (Dominates)
//Greedy selection of full or fractional part; occurs in single loop : O(n)

