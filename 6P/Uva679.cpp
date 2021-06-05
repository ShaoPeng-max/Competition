#include <cstdio>

int main(){
    int depth, balls, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int number = 1;
        scanf("%d%d", &depth, &balls);
        for (int d = 2; d <= depth; d++)
        {
            if (balls & 1)
            {
                number *= 2;
                balls = (balls + 1) / 2;
            }
            else
            {
                number = number * 2 + 1;
                balls /= 2;
            }
        }
        printf("%d\n", number);
    }
    scanf("%d", &n);
    return 0;
}