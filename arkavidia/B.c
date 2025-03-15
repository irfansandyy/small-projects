#include <stdio.h>

int main() {
    int kata;
    scanf("%d", &kata);
    getchar();
    for(int i = 0; i < kata; i++) { 
        int salah = 0;
        char c;
        c = getchar();
        while(1) {
            if (c == EOF || c == '\n' || c == 0) break;
            if (c == 'a') {
                c = getchar();
                if (c != 'g') {
                    salah = 1;
                    continue;
                }
                c = getchar();
                if (c != 'a') {
                    salah = 1;
                    continue;
                }
            } else if (c == 'i') {
                c = getchar();
                if (c != 'g') {
                    salah = 1;
                    continue;
                }
                c = getchar();
                if (c != 'i') {
                    salah = 1;
                    continue;
                }
            } else if (c == 'u') {
                c = getchar();
                if (c != 'g') {
                    salah = 1;
                    continue;
                }
                c = getchar();
                if (c != 'u') {
                    salah = 1;
                    continue;
                }
            } else if (c == 'e') {
                c = getchar();
                if (c != 'g') {
                    salah = 1;
                    continue;
                }
                c = getchar();
                if (c != 'e') {
                    salah = 1;
                    continue;
                }
            } else if (c == 'o') {
                c = getchar();
                if (c != 'g') {
                    salah = 1;
                    continue;
                }
                c = getchar();
                if (c != 'o') {
                    salah = 1;
                    continue;
                }
            }
            if (c == EOF || c == '\n' || c == 0) break;
            c = getchar();
        }
        if(salah) printf("Sagalagah\n");
        else printf("Begenagar\n");
    }
}
