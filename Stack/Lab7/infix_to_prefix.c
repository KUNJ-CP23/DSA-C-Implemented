#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for pow func ( ^ )
#include <string.h> // for strlen

int top = -1;

void push( int arr[], int size, int val){
    if(top == size - 1) {
        printf("\nStack overflow!!\n");
        return;
    }
    top++;
    arr[top] = val;
}

int pop( int arr[]){
    if(top == -1) {
        printf("\nStack underflow!!\n");
        return -1;
    }
    top--;
    return arr[top+1];
}

int peep( int arr[], int size, int n){
    if(top + 1 < n) {
        printf("\nStack underflow!!\n");
        return 0;
    }
    
    return arr[top - n + 1];
}

int isNum(char c[]){
    int len = strlen(c);
    for(int i=0;i<len;i++){
        if(c[i]<'0' || c[i]>'9') return 0;
    } 
    return 1;
}

int toNum(char str[]){
    int len = strlen(str);
    int n= 0;
    for(int i=0;i<len;i++){
        if(str[i] >= '0' && str[i] <= '9')
            n = n*10 + (str[i] - '0');
        else{
            printf("\nERROR :: NUMBER IS NOT VALID\n");
            return -1;
        }
    }
    return n;
}

int performOpr(int a, int b, char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
    if(c == '^') return (int)pow(a,b);
    return 0;
}

void prefixEval(char prefix[]){
    int len = strlen(prefix);
    int pre[len]; // stack for prefix
   
    int i=0;
    //Reverse whole numbers
    while(i<len){
        int ind = i;
        int j = i;
        //identify limit
        while(i<len && prefix[i]!=' ' ){
            i++;
        }

        // reverse it
        while(j<(i + ind)/2){
            char temp = prefix[j];
            prefix[j] = prefix[i - 1 - (j - ind)];
            prefix[i - 1 - (j - ind)] = temp;
            j++;
        }

        if(i!=len) i++; // to avoid empty space
    }

    i = 0;

    // reverse whole string to get the numbers right
    while (i < len/2)
    {
       char temp = prefix[i];
       prefix[i] = prefix[len - 1 - i];
       prefix[len - 1 - i] = temp;
       i++;
    }
    
    i = 0;
    // iterate through characters
    while(i < len){
        char c[len];
        int ind = 0;
        // collecting whole numbers or operators
        while(i<len && prefix[i]!=' ' ){
            c[ind++] = prefix[i];
            i++;
        }
        c[ind] = '\0';
        i++; // avoid empty space for next iteration
        
        if(isNum(c)){
            push(pre,len,atoi(c) ); // push to stack
        }
        else {
            push(pre,len,c[0]); // push to stack

            // while, there's 1 operator on top and 2 numbers under it
            if(top>=2){
                
                    char opr = (char)pop(pre); // operator
                    int num1 = pop(pre); // num1
                    int num2 = pop(pre); // num2
                    int temp = performOpr(num1,num2,opr);
                    push(pre,len,temp); // push answer to stack 
            }
        } 
        
    }
    
    if(top != 0 ){ // can't have more or less than 1 in stack and it should't be operator 
        printf("\nERROR :: INVALID postfix STRING\n");
        return;
    }
    printf("Answer = %d",pop(pre)); 
}

void main(){
    char prefix[1000];
    printf("Enter prefix String following given rules : \n");
    printf("1) Operators, operand and should be space-seperated \n");
    printf("2) No more than single space should be used to seperate\n");
    scanf(" %[^\n]s",prefix);
    prefixEval(prefix);
}