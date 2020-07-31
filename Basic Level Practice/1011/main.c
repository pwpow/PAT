#include <stdio.h>

int main(){
    int T;
    int i;
    int A;
    int B;
    int C;

    scanf("%d", &T);

    for(i = 0; i < T; i++){
        scanf("%d %d %d", &A, &B, &C);
        if(A + B < 0 && A > 0 && B > 0){
            printf("Case #%d: true\n", i + 1);
            continue;
        }
        if(A + B > 0 && A < 0 && B < 0){
            printf("Case #%d: false\n", i + 1);
            continue;
        }
        if(A + B > C){
            printf("Case #%d: true\n", i + 1);
        }else{
            printf("Case #%d: false\n", i + 1);
        }
    }

    return 0;
}
