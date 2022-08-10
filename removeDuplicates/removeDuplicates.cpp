// removeDuplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include <stdlib.h>
#include <cstdio>

int removeDuplicates(int* nums, int numsSize){
    int iReady = 0, iTail = 1;

    //1 <= nums.length <= 3 * 10000
    if (numsSize < 1 || numsSize > 30000) {
        return 0;
    }

    //-100 <= nums[i] <= 100
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < -100 || nums[i] > 100) {
            return -1;
        }
    }

    while (iReady < numsSize && iTail < numsSize) {
        if (nums[iReady] == nums[iTail]) {
            if (iTail < numsSize) {
                iTail++;
            }
        } else if (nums[iReady] < nums[iTail]) {
            if (iTail - iReady > 1) {
                nums[++iReady] = nums[iTail];
            } else {
                iReady++;
            }
            //iReady++;
            if (iTail < numsSize) {
                iTail++;
            }
        }
    }
    for (int i = (iReady + 1); i < numsSize; i++) {
        nums[i] = -1;
    }
    return ++iReady;
}

int main()
{
    clock_t dStartTime, dEndTime;
    int iNums[] = { 1 ,1 ,2};
    int iCnt = sizeof(iNums) / sizeof(int);
    int iResult = 0;

    dStartTime = clock();

    printf("Original list = ");
    for (int i = 0; i < iCnt; i++) {
        printf("%d ", iNums[i]);
    }
    printf("\n");
    iResult = removeDuplicates(iNums, iCnt);
    printf("Result number = %d\n", iResult);
    printf("Result list   = ");
    for (int i = 0; i < iResult; i++) {
        printf("%d ", iNums[i]);
    }
    printf("\n");

    dEndTime = clock();

    printf("==> Execution time: %f s <==\n\r", (float)(dEndTime - dStartTime)/CLOCKS_PER_SEC) ;

    system("pause");

    return 0;
}

