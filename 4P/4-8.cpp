#include <stdio.h>
#include <string.h>

char c[7];
char b[7];

void ex(char* s, int x, int y){
    char t = *(s + x);
    *(s+x) = *(s+y);
    *(s+y) = t;
}

void r1(){
    ex(c, 2, 5);
    ex(c, 2, 3);
    ex(c, 4, 5);
}

void r2(){
    ex(c, 2, 5);
    ex(c, 1, 2);
    ex(c, 5, 6);
}

void r3(){
    ex(c, 1, 6);
    ex(c, 1, 3);
    ex(c, 4, 6);
}

bool rcmp(){
    bool ok = true;
    for (int i = 1; i <= 6; i++) ok &= c[i] == b[i];
    return ok;
}

int main(){
    char in[15];
    while (scanf("%s", in) != EOF){
        for (int i = 0; i < 6; i++) c[i+1] = in[i];
        for (int i = 6; i < 12; i++) b[i-5] = in[i];
        bool ok = false;
        for (int i = 1; i <= 4; i++){
            r1();
            for (int j = 1; j <= 4; j++){
                r2();
                for (int k = 1; k <= 4; k++){
                    r3();
                    ok |= rcmp();
                }
            }
        }
        printf("%s\n", ok ? "TRUE" : "FALSE");
    }
}