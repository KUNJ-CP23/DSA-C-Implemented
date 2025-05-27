// 100. Implace sorting Given an array nums with n objects colored red, white, or blue, sort them 
// in place so that objects of the same color are adjacent, with the colors in the order 
// red, white, and blue. We will use the integers 0, 1, and 2 to represent the color 
// red, white, and blue, respectively. 
// Sample Example-1: 
// Input: nums = [2,0,2,1,1,0]    
// Output: [0,0,1,1,2,2] 

#include <stdio.h>

void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

int main() {
    int nums[100], n;

    printf("Enter number of elements (only 0, 1, or 2): ");
    scanf("%d", &n);

    printf("Enter %d elements (0 = red, 1 = white, 2 = blue):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    sortColors(nums, n);

    printf("Sorted colors (0s, then 1s, then 2s):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
