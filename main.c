#include <stdio.h>

/*  print Fahrenheit-Celsius table
 * for fahr = 0, 20 .... 300 */
#define LOWER 0
#define UPPER 300
#define STEP 20

/* Word counting
*/
#define IN  1 /* inside a word*/
#define OUT 0 /* outside a word*/

void convertFor() {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}

void convert() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    int truncate = 5 / 9;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("%d", truncate);
}

void charmaker() {
    int c, nline;
    nline = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nline;
        printf("%1d\n", nline);
    }
    
}

void wordCounting() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }
            
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }  
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d  %d %d\n", nl, nw, nc);

}

void arrays() {
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i=0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c-'0'];
        }
        else if (c == ' ' && c == '\n' || c == '\n') {
            ++nwhite;
        }
        else
        ++nother;
    }

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space= %d, other = %d\n", nwhite, nother);
}


int main() {
    printf("Hello, World!\n");
    wordCounting();
    return 0;
}

