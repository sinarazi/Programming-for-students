#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void search(char* pat, char* txt) //algorithme native string matching
{
    int M = strlen(pat);
    int N = strlen(txt);
    bool flag;
    for (int i = 0; i <= N - M; i++) {
        int j;

        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])

                break;

        if (j == M)
            // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);
            flag = (j==M);
    }
    if(flag = 0){
        printf("No");
    }
    else{
        printf("Yes");
    }
}

int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "ABA";
    search(pat, txt);
    return 0;
}
