//
//  main.c
//  Sum_Of_n_Natural_Nos
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
int sum(int n){
    int s=0;
    for (int i=0; i<n; i++) {
        s=s+i;
    }
    return s;
}
int main(){
    sum(11);
    printf("%d ",sum(11));
    return 0;
}
 
/*int sum(int n){
    return n*(n-1)/2;
}
int main(){
    int n=11;
    printf("%d ",sum(n));
return 0;
}
*/
/**int sum(int n){
    if(n==0)
        return 0;
    return sum(n-1)+n;
}
int main(int argc, const char * argv[]) {
    int r;
    r=sum(10);
    printf("%d ",r);
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
*/
