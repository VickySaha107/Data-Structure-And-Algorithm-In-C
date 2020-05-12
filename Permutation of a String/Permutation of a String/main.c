//
//  main.c
//  Permutation of a String
//
//  Created by Bikramjit Saha on 08/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//
#include <stdio.h>
//Method 1
void perm(char s[],int k){
    int i;
    static char A[4]={0};
    static char res[4];
    if(s[k]=='\0'){
        res[k]='\0';
        printf("%s\n",res);
    }else{
    for(i=0;s[i]!='\0';i++){
        if(A[i]==0){
            res[k]=s[i];
            A[i]=1;
            perm(s,k+1);
            A[i]=0;
        }
     }
   }
}
//METHOD 2
void swap(char *x,char *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void perm1(char S[],int low, int high){
    int i;
    if(low==high){
        printf("%s\n",S);
    }else{
    for(i=low;i<=high;i++){
       swap(&S[low],&S[i]);
       perm1(S,low+1,high);
        swap(&S[low],&S[i]);
    }
  }
}
int main(int argc, const char * argv[]) {
//     insert code here...
    char s[]="ABC";
    perm(s,0);
    char S[4]="ABC";
    perm1(S, 0, 2);
    return 0;
}
