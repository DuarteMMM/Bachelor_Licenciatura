#ifndef DEBUG_H
#define DEBUG_H 1

#include<cstdio>

// Colors using ANSI
#define BLK   "\x1B[30m"
#define BBLK  "\x1B[90m"
#define RED   "\x1B[31m"
#define BRED  "\x1B[31m"
#define GRN   "\x1B[32m"
#define BGRN  "\x1B[32m"
#define YEL   "\x1B[33m"
#define BYEL  "\x1B[33m"
#define BLU   "\x1B[34m"
#define BBLU  "\x1B[34m"
#define MAG   "\x1B[35m"
#define BMAG  "\x1B[35m"
#define CYN   "\x1B[36m"
#define BCYN  "\x1B[36m"
#define WHT   "\x1B[37m"
#define BWHT  "\x1B[37m"
#define RESET "\x1B[0m"

#define BlackPrint(X, ...)   printf(BLK X RESET, ##__VA_ARGS__)
#define RedPrint(X, ...)     printf(RED X RESET, ##__VA_ARGS__)
#define GreenPrint(X, ...)   printf(GRN X RESET, ##__VA_ARGS__)
#define YellowPrint(X, ...)  printf(YEL X RESET, ##__VA_ARGS__)
#define BluePrint(X, ...)    printf(BLU X RESET, ##__VA_ARGS__)
#define MagentaPrint(X, ...) printf(MAG X RESET, ##__VA_ARGS__)
#define CyanPrint(X, ...)    printf(CYN X RESET, ##__VA_ARGS__)
#define WhitePrint(X, ...)   printf(WHT X RESET, ##__VA_ARGS__)

#define BrightBlackPrint(X, ...)   printf(BBLK X RESET, ##__VA_ARGS__)
#define BrightRedPrint(X, ...)     printf(BRED X RESET, ##__VA_ARGS__)
#define BrightGreenPrint(X, ...)   printf(BGRN X RESET, ##__VA_ARGS__)
#define BrightYellowPrint(X, ...)  printf(BYEL X RESET, ##__VA_ARGS__)
#define BrightBluePrint(X, ...)    printf(BBLU X RESET, ##__VA_ARGS__)
#define BrightMagentaPrint(X, ...) printf(BMAG X RESET, ##__VA_ARGS__)
#define BrightCyanPrint(X, ...)    printf(BCYN X RESET, ##__VA_ARGS__)
#define BrightWhitePrint(X, ...)   printf(BWHT X RESET, ##__VA_ARGS__)

// DEBUG
#define DEBUG_DBL(DEBUG_VAR, VARNAME, SIZE, X)                                                                                          \
        if(DEBUG_VAR) {                                                                                                                 \
                RedPrint(VARNAME ":\n");                                                                                                \
                for(int i=0; i<SIZE; i++) printf("\t%5d | %Le\n", i, X[i]);  \
        }                                                                                                                               \
                                                                                                                                        \
        free(X);                                                                                                                        \
        X = NULL;

#define DEBUG_INT(DEBUG_VAR, VARNAME, SIZE, X)                                                                                          \
        if(DEBUG_VAR) {                                                                                                                 \
                RedPrint(VARNAME ":\n");                                                                                                \
                for(int i=0; i<SIZE; i++) printf("\t%5d | %Le | %d\n", i, M_MIN + (long double)i*(M_MAX - M_MIN)/(long double)(M_DIV-1), X[i]);   \
        }                                                                                                                               \
                                                                                                                                        \
        free(X);                                                                                                                        \
        X = NULL;

#endif
