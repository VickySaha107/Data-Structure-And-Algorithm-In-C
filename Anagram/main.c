//
//  main.c
//  Anagram
//
//  Created by Bikramjit Saha on 06/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void Anagram(char a[],char b[]){
    int i, h[26]={0};
    for(i=0;a[i]!='\0';i++)
    {
    h[a[i]-97]++;
    }
    for(i=0;b[i]!='\0';i++)
    {
    h[b[i]-97]--;
    if(h[b[i]-97]<0)
    {
    printf("not anagram\n");
    break;
    }
    }
    if(b[i]=='\0')
    printf("anagram\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char a[]="decimal";
    char b[]="medical";
    Anagram(a, b);
    return 0;
}
