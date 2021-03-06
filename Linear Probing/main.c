//
//  main.c
//  Linear Probing
//
//  Created by Bikramjit Saha on 17/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
# define SIZE 10
int Hash(int key){
    return key%SIZE;
}
// inserting in next free space index
int probe(int HT[],int key){
    int index=Hash(key);
    int i=0;
    while (HT[(index+i)%SIZE]!=0) {
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int HT[],int key){
    int index=Hash(key);// when place is vacant directly insert the element by its last unit place
    if (HT[index]!=0) {
        index=probe(HT, key);// when place is not vacant check next vacant place to insert the element by its last unit
        
    }
   
    HT[index]=key;

}
// searching for key element and if found return that index
int searching(int HT[],int key){
    int index=Hash(key);
    int i=0;
    while (HT[(index+i)%SIZE]!=key) {
        i++;
    }
    return (index+i)%SIZE;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int HT[10]={0};
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);
   
    printf("Key is found at index:%d\n",searching(HT,35));

    return 0;
}
