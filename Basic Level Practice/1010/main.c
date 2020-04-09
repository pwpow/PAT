#include<stdio.h>
#include<stdlib.h>

int main(){
    int j;
    int len;
    int num;
    int size;
    int* arr;
    int first;
    
    len = 0;
    size = 1000;
    arr = (int*)malloc(sizeof(int) * size);
    while (scanf("%d", &num) != EOF){
        arr[len++] = num;
    }
    
    first = 1;
    for(j = 0; j < len; j++){
        //系数
        if(j % 2 == 0){
            if(arr[j + 1] == 0){
                continue;
            }
            if(first == 1){
                first = 0;
            }else{
                printf(" ");
            }
            printf("%d", arr[j + 1] * arr[j]);
        }else{
            if(arr[j] == 0){
                continue;
            }
            printf(" %d", arr[j] - 1);
        }
    }

    if(first == 1){
        printf("0 0");
    }

    free(arr);
}