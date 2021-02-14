#define MAX_RES 500
void worker(int *candidates, int candidatesSize, int target, int candi_start, int **res, int *residx, int *tmp, int tmpidx, int *columnSizes)
{
    if (target < 0)
    {
        return;
    }
    else if (!target)
    {
        int len = tmpidx * sizeof(int);
        int *newres = malloc(len);
        memcpy(newres, tmp, len);
        res[*residx] = newres;
        columnSizes[*residx] = tmpidx;
        *residx += 1;
        return;
    }
    else
    {
        for (int i = candi_start; i < candidatesSize; i++)
        {
            tmp[tmpidx++] = candidates[i];
            worker(candidates, candidatesSize, target - candidates[i], i, res, residx, tmp, tmpidx, columnSizes);
            tmpidx--;
        }
        return;
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int **columnSizes, int *returnSize)
{
    int **res = malloc(MAX_RES * sizeof(int *));
    *columnSizes = malloc(MAX_RES * sizeof(int));
    int residx = 0;
    int *tmp = malloc(target * sizeof(int));
    worker(candidates, candidatesSize, target, 0, res, &residx, tmp, 0, *columnSizes);
    *returnSize = residx;
    return res;
}