#include <stdio.h>
#include <algorithm>
using namespace std;

int list[4][4000];
int sum[4000*4000];

int main()
{
    int n;
    scanf("%d", &n);
    int nn = n*n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &list[0][i], &list[1][i], &list[2][i], &list[3][i]);
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[k] = list[2][i] + list[3][j];
            ++k;
        }
    }
    sort(sum, sum + nn);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int s = list[0][i] + list[1][j];
            pair<int*, int*> range = equal_range(sum, sum + nn, -s);
            count += range.second - range.first;
        }
    }
    printf("%d\n", count);
}