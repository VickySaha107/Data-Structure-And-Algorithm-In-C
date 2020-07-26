//
//  main.c
//  Rotate_Array
//
//  Created by Bikramjit Saha on 26/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

// C program to rotate an array by
// d elements
#include <stdio.h>

/*void leftRotatebyOne(int arr[], int length)
{
    int temp = arr[0], i;
    for (i = 0; i < length - 1; i++)
        arr[i] = arr[i + 1];
    arr[i] = temp;
}*/
/*void leftRotate(int arr[], int d, int length)
{
    int i;
    for (i = 0; i < d; i++)
        leftRotatebyOne(arr, length);
}*/
void Reversal(int arr[], int length)
{
    int temp = arr[length-1], i;
    for (i =length-1; i>=0; i--)
        arr[i] = arr[i -1];
    arr[0] = temp;
}
void RightReversal(int arr[], int elements, int length)
{
    int i;
    for (i = 0;i<elements;i++)
        Reversal(arr, length);
}
void Display(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//    leftRotate(arr, 2, 7);
    RightReversal(arr,3,7);
    Display(arr, 7);
    printf("\n ");
    return 0;
}

