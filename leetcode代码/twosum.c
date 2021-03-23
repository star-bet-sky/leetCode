/**
 * Note: The returned array must be malloced, assume caller calls free().
 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
 */
#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *ret;//定义返回数组
    *returnSize=2;//定义返回数组大小
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){//两个循环遍历数组
            if(nums[i]+nums[j]==target){//判断数据和
                if(i!=j){//判断两个下标不相等
                    ret=(int*)malloc(sizeof(int)*2);//为返回数组分配空间
                    ret[0]=i;
                    ret[1]=j;//为返回数组赋值
                    return ret;
                }
            }
        }
    }
    return ret;
}
int main(){
    int nums[]={1,2,3,4,5,6,7};
    int numsSize=sizeof(nums);
    int target=13;
    int returnsize;
    int *ret=twoSum(nums,numsSize,target,returnsize);
    return 0;
}
