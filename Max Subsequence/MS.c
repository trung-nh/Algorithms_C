#include <stdio.h>

int main(void)
{
    int n, i, tmp, cur_sum = 0, max_sum = 0;
    FILE *fptr = fopen("input.txt", "r");
    fscanf(fptr, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fptr, "%d", &tmp);
        cur_sum = cur_sum + tmp;
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }
        if (cur_sum < 0)
        {
            cur_sum = 0;
        }
    }
    fptr = fopen("output.txt", "w");
    fprintf(fptr, "%d", max_sum);
    fclose(fptr);
    return 0;
}