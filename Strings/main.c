//
//  main.c
//  Strings
//
//  Created by Bikramjit Saha on 01/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void Stringlength(char S[]){
    int i;
    for (i=0; S[i]!='\0'; i++) {
    }
    printf("The Length of The String:%d\n",i);
}
void ChangeCase(char S[]){
    int i;
    for (i=0; S[i]!='\0'; i++) {
        S[i]+=32;
    }
     printf("The LowrCase Letters are:%s\n",S);
}
void TogglingCase(char A[]){
    int i;
    for (i=0; A[i]!='\0'; i++) {
        if(A[i]>='A'&&A[i]<='Z')
            A[i]+=32;
        else if(A[i]>='a'&&A[i]<='z')
            A[i]-=32;
    }
    printf("The TogglingCase Letters are:%s\n",A);
}
void CountViowelConsonents(char Str[]){
    int i,Vcount,Ccount;
    Vcount=Ccount=0;
    for (i=0; Str[i]!='\0'; i++) {
        if(Str[i]=='A'||Str[i]=='E'||Str[i]=='I'||Str[i]=='O'||Str[i]=='U'||Str[i]=='a'||Str[i]=='e'||Str[i]=='i'||Str[i]=='o'||Str[i]=='u'){
            Vcount++;
        }else if((Str[i]>='A'&&Str[i]<='Z')||(Str[i]>='a'&&Str[i]<='z')){
            Ccount++;
        }
    }
    printf("The Viowel Counts are:%d\nThe Consonents Counts are:%d\n",Vcount,Ccount);
}
void CountWords(char Str[]){
    int i,space;
    space=0;
    for (i=0; Str[i]!='\0'; i++) {
        if(Str[i]==' ')
            space++;
    }
    printf("The Count Of Words are:%d\n",space+1);
}
void CountWhiteSpaceWords(char Str1[]){
    int i,space;
    space=0;
    for (i=0; Str1[i]!='\0'; i++) {
        if(Str1[i]==' '&&Str1[i-1]!=' ')
            space++;
    }
    printf("The Count Of Continuous Space Words are:%d\n",space+1);
}
int Valid(char name[]){
    int i;
    for (i=0; name[i]!='\0'; i++) {
        if(!(name[i]>='A'&&name[i]<='Z')&&!(name[i]>='a'&&name[i]<='z')&&!(name[i]>=48&&name[i]<=57))
           return 0;/*false*/
    }
    return 1;/*true*/
}
void Reverse_String(char A1[],char B1[]){
    int i,j;
    for(i=0;A1[i]!='\0';i++){
    }
    i=i-1;
    for(j=0;i>=0;i--,j++){
        B1[j]=A1[i];
    }
    B1[j]='\0';
    printf("The Reverse String is:%s\n",B1);
}
void Reverse_String1(char A1[],int length){
    int i;
        int j,temp;
    for(j=0;j[A1]!='\0';j++){}
    j=j-1;
    for(i=0;i<j;i++,j--){
        temp=A1[i];
        A1[i]=A1[j];
        A1[j]=temp;
    }
    printf("The Reverse String is:%s\n",A1);
}
void Reverse_String2(char A2[],int length){
        int i,temp;
    for(i=0;i<length/2;i++){
        temp=A2[i];
        A2[i]=A2[length-1-i];
        A2[length-1-i]=temp;
    }
    printf("The Reverse String is:%s\n",A2);
}
void CompareString(char S1[],char S2[]){
    int i,j;
    for(i=0,j=0;S1[i]!='\0'&&S2[j]!='\0';i++,j++){
        if(S1[i]!=S2[j]){
            printf("Not Equal\n");
           break;
    }
    }
        if(S1[i]==S2[j]){
            printf("Equal\n");
    }
    else if(S1[i]<S2[j]){
            printf("Smaller\n");
    }
        else
            printf("Greater\n");

}
void Palindrome(char P[],int length){
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--){
        if(P[i]!=P[j]){
            printf("The given Sting is Not A Palindrome\n");
        break;
        }
     } if(P[i]==P[j]){
        printf("Yes, The String is a Palindrome\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    char S[]="VICKY";
//    char A[]="wELcOmE";
//    char Str[]="How are You";
//    char Str1[]="How are   You";
//    char A1[]="Python";
//    char A2[]="Bikramjit";
//    char S1[]="painter";
//    char S2[]="paintings";
//    char P[6]="MADAM";
//    char B1[7];
   /*   char name[]="Anil?321";
    if(Valid(name)){
        printf("Valid String\n");
    }
    else{
        printf("Invalid String\n");
    }
//    Stringlength(S);
//    ChangeCase(S);
//    TogglingCase(A);
//    CountViowelConsonents(Str);
//    CountWords(Str);
//    CountWhiteSpaceWords(Str1);*/
//    Reverse_String(A1,B1);
//    Reverse_String1(A1,7);
//    Reverse_String2(A2,9);
//    CompareString(S1, S2);
//    Palindrome(P,5);
    return 0;
}
