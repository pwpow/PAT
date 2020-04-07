#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char** array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == - 1;
}

void push(struct Stack* stack, char* item){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
    // printf("%s pushed to stack\n", item);
}

char* pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top--]; 
}

// Function to return the top from stack without removing it 
char* peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top]; 
}

int main() 
{ 
    struct Stack* stack = createStack(80); 
    char temp[26];
    while(scanf("%s", temp) != EOF){
        char* word = (char*)malloc(sizeof(char) * 26);
        int i = 0;
        for(i = 0; i < 26; i++){
            if(temp[i]){
                word[i] = temp[i];
            }
        }
        word[i] = '\0';
        
        // strcpy(word, temp);
        
        // printf("%s", word);
        push(stack, word); 
    }

    int first = 1;
    while(!isEmpty(stack)){
        if(first){
            first = 0;
        }else{
            printf(" ");
        }

        printf("%s",pop(stack));
    }
  
    return 0; 
}