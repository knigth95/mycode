#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct Node *next;
};

int search(int *nums, int numsSize, int target)
{
    int i = 0, right = numsSize - 1, left = 0, mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        int num = nums[mid];
        if (num == target)
            return mid;
        else if (num > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int firstBadVersion(int n)
{
    int left = 1, right = n;
    while (left < right)
    {
        int mid = (right - left) / 2 + left;
        // if(isBadVersion(mid)) right=mid;
        // else left=mid+1;
    }
    return left;
}

int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1, mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        int k = nums[mid];
        if (k == target)
            return mid;
        else if (k > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    int t;
    for (int i = 0; i < numsSize - 1; ++i)
    {

        for (int j = 0; j < numsSize - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
            }
        }
    }
    return nums;
}

void rotate(int *nums, int numsSize, int k)
{
    int ans[numsSize + k];
    for (int i = 0; i < numsSize; i++)
    {
        ans[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = ans[i];
    }
}

void moveZeroes(int *nums, int numsSize)
{
    int ans[numsSize + numsSize];
    int cnt = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[cnt] = nums[i];
            cnt++;
        }
    }
    for (int i = cnt; i < numsSize; i++)
    {
        nums[i] = 0;
    }
}

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *index = (int *)malloc(sizeof(int) * (*returnSize));
    int start = 0, end = numbersSize - 1; // 不-1会出现堆栈溢出
    for (int i = start; i < numbersSize; i++)
    {
        if (numbers[start] + numbers[end] == target)
        {
            index[0] = start + 1;
            index[1] = end + 1;
            break;
        }
        else if (numbers[start] + numbers[end] > target)
            end--;
        else if (numbers[start] + numbers[end] < target)
            start++;
    }
    return index;
}

void reverseString(char *s, int sSize)
{
    for (int i = 0, j = sSize - 1; i < j; ++i, --j)
    {
        char t = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = t;
    }
}

char *reverseWords(char *s)
{
    int cnt = strlen(s), i = 0, j;
    char *ans = (char *)malloc(sizeof(char) * (cnt + 1));
    ans[cnt] = 0; // 最后一个赋值0，不然对应下标时会出现越界错误
    while (i < cnt)
    {
        int k = i;
        while (i < cnt && s[i] != ' ')
            i++;
        for (int j = k; j < i; j++)
        {
            ans[j] = s[k + i - 1 - j];
        }
        while (i < cnt && s[i] == ' ')
        {
            ans[i] = ' ';
            i++;
        }
    }
    return ans;
}

struct ListNode *middleNode(struct ListNode *head)
{
    int cnt = 0;
    /*
    struct ListNode* node1=head;
    struct ListNode* node2=head;
    while(node1!=NULL && node1->next!=NULL){
        node1=node1->next->next;//五十步与百步
        node2=node2->next;
    }
    return node2;
    */
    struct ListNode *node;
    node = head;
    while (node != NULL)
    {
        cnt++;
        node = node->next;
    }
    node = head;
    for (int i = 0; i < cnt / 2; i++)
    {
        node = node->next;
    }
    return node;
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int cnt = 0;
    struct ListNode *k = (ListNode *)malloc(sizeof(struct ListNode));
    k->next = head;
    while (head != NULL)
    {
        ++cnt;
        head = head->next;
    }
    struct ListNode *node = k;
    for (int i = 1; i < cnt - n + 1; i++)
        node = node->next;
    node->next = node->next->next;
    struct ListNode *head_node = k->next;
    free(k);
    return head_node;
}

int lengthOfLongestSubstring(char *s)
{
    int i = 0, j = 0, len = strlen(s);
    int ans[200] = {0}, cnt = 0, cnt0 = 0;
    while (i < len)
    {
        if (ans[s[i]] == 0)
        {
            ans[s[i]] = 1;
            cnt++;
            i++;
            cnt0 = cnt0 > cnt ? cnt0 : cnt;
        }
        else
        {
            ans[s[j]] = 0;
            j++;
            cnt--;
        }
    }
    return cnt0;
}

bool checkInclusion(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 > len2)
        return 0;
    int cnt[100] = {0};
    for (int i = 0; i < len1; ++i)
        --cnt[s1[i] - 'a'];

    int j = 0;
    for (int i = 0; i < len2; ++i)
    {
        int x = s2[i] - 'a';
        ++cnt[x];
        while (cnt[x] > 0)
        {
            --cnt[s2[j] - 'a'];
            ++j;
        }
        if (i - j + 1 == len1)
            return 1;
    }
    return 0;
}

void dfs(int **image, int x, int y, int color, int newColor, int imageSize, int *imageColSize)
{
    //  如果坐标越界就不用涂色
    if (x < 0 || x >= imageSize || y < 0 || y >= imageColSize[0])
    {
        return;
    }
    // 如果周围颜色与初始的颜色一致，则将他涂成新的颜色，并向上下左右dfs
    if (image[x][y] == color)
    {
        // 将颜色替换
        image[x][y] = newColor;
        // 深度优先搜索四周的像素点
        dfs(image, x - 1, y, color, newColor, imageSize, imageColSize);
        dfs(image, x + 1, y, color, newColor, imageSize, imageColSize);
        dfs(image, x, y - 1, color, newColor, imageSize, imageColSize);
        dfs(image, x, y + 1, color, newColor, imageSize, imageColSize);
    }
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize, int **returnColumnSizes)
{
    // 这里要判断一下初始颜色和新的颜色是否一样，不然会造成无限递归
    if (image[sr][sc] != newColor)
    {
        dfs(image, sr, sc, image[sr][sc], newColor, imageSize, imageColSize);
    }
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}

int getarea(int **grid, int size, int *gridCOL, int i, int j)
{
    if (i < 0 || i >= size || j < 0 || j >= gridCOL[0] || !grid[i][j])
        return 0;
    grid[i][j] = 0;
    int sum = 1 + getarea(grid, size, gridCOL, i + 1, j) +
              getarea(grid, size, gridCOL, i - 1, j) +
              getarea(grid, size, gridCOL, i, j + 1) +
              getarea(grid, size, gridCOL, i, j - 1);

    return sum;
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
    int max = 0, cnt = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridColSize[0]; j++)
        {
            cnt = getarea(grid, gridSize, gridColSize, i, j);
            max = max > cnt ? max : cnt;
        }
    }
    return max;
}

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2)
{
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;
    root1->val = root1->val + root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
/*
struct Node* connect(struct Node* root) {
    if(root == NULL) return NULL;
    struct Node* leftroot=root;

    while(leftroot->left != NULL){
        struct Node* zzm=leftroot;

        while(zzm != NULL){
            zzm->left->next=zzm->right;
            if(zzm->next !=NULL ){
                zzm->right->next=zzm->next->left;
            }
            zzm=zzm->next;
        }
        leftroot=leftroot->left;
    }
    return root;
}
*/
#define INTMAX 999999
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes)
{
    int i, m = matSize, m_col = *matColSize;
    if (matSize == 0 || matColSize[0] == 0)
        return NULL;
    int **returnMat = (int **)malloc(sizeof(int *) * matSize);
    int *colSize = (int *)malloc(sizeof(int) * matSize);
    for (i = 0; i < m; i++)
    {
        returnMat[i] = (int *)malloc(sizeof(int) * m_col);
        colSize[i] = m_col;
    }
    *returnColumnSizes = colSize;
    *returnSize = matSize;
    for (i = 0; i < m; ++i)
    {
        for (int j = 0; j < m_col; ++j)
        {
            returnMat[i][j] = INTMAX;
        }
    }
    for (i = 0; i < m; ++i)
        for (int j = 0; j < m_col; ++j)
            if (mat[i][j] == 0)
                returnMat[i][j] = 0;
    // 向左、向上
    for (i = 0; i < m; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            if (i - 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i - 1][j] + 1);
            if (j - 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i][j - 1] + 1);
        }
    }
    // 向左、向下
    for (i = 0; i < m; ++i)
    {
        for (int j = 0; j < m_col; ++i)
        {
            if (i + 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i + 1][j] + 1);
            if (j - 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i][j - 1] + 1);
        }
    }
    // 向右、向上
    for (i = 0; i < m; ++i)
    {
        for (int j = 0; j < m_col; ++j)
        {
            if (i - 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i - 1][j] + 1);
            if (j + 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i][j + 1] + 1);
        }
    }
    // 向右、向下
    for (i = 0; i < m; ++i)
    {
        for (int j = 0; j < m_col; ++j)
        {
            if (i + 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i + 1][j] + 1);
            if (j + 1 >= 0)
                returnMat[i][j] = min(returnMat[i][j], returnMat[i][j + 1] + 1);
        }
    }
    return returnMat;
}

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{
    int cnt = 0, i, j;
    for (i = 0; i < gridSize; i++)
    {
        for (j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    while (1)
    {
        int k = 1;
        for (i = 0; i < gridSize; i++)
        {
            for (j = 0; j < *gridColSize; j++)
            {
                if (grid[i][j] == 3)
                    grid[i][j] = 2;
                else if (grid[i][j] == 1)
                {
                    if ((i < gridSize - 1 && grid[i + 1][j] == 2) || (j < *gridColSize - 1 && grid[i][j + 1] == 2))
                    {
                        k = 0;
                        grid[i][j] = 2;
                    }
                }
                else if (grid[i][j] == 2)
                {
                    if (i < gridSize - 1 && grid[i + 1][j] == 1)
                    {
                        grid[i + 1][j] = 3;
                        k = 0;
                    }
                    if (j < *gridColSize - 1 && grid[i][j + 1] == 1)
                    {
                        k = 0;
                        grid[i][j + 1] = 3;
                    }
                }
            }
        }
        if (k)
            break;
        else
            cnt++;
    }

    return cnt;
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

struct ListNode *reverseList(struct ListNode *head)
{

    struct ListNode *k = NULL;
    struct ListNode *n = head;
    /*
    while(n!=NULL){
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=n->val;
        node->next=k;
        k=node;
        n=n->next;
    }
    return k;
    */
    // 迭代
    while (n != NULL)
    {
        struct ListNode *next = n->next;
        n->next = k;
        k = n;
        n = next;
    }
    return k;
}

int *t, tsize, **ans, anssize;
void dfs(int n, int k, int z, int val)
{
    int i;
    if (z == k)
    {
        int *temp = (int *)malloc(sizeof(int) * k);
        for (i = 0; i < k; i++)
        {
            temp[i] = t[i];
        }
        ans[anssize] = temp;
        anssize++;
        return;
    }
    for (i = val + 1; i <= n - k + z + 1; i++)
    {
        t[z] = i;
        dfs(n, k, z + 1, i);
    }
}

int **combine(int n, int k, int *returnSize, int **returnColS)
{
    int i;
    t = (int *)malloc(sizeof(int) * k);
    ans = (int **)malloc(sizeof(int *) * 10000);
    anssize = 0, tsize = 0;
    dfs(n, k, 0, 0);
    *returnColS = (int *)malloc(sizeof(int) * anssize);
    for (i = 0; i < anssize; i++)
    {
        (*returnColS)[i] = k;
    }
    *returnSize = anssize;
    return ans;
}

int bin(int i)
{
    int k = 0;
    return 0;
}

bool isPowerOfTwo(int n)
{
    int i, k;
    cin >> n;
    for (i = 0; i < 32; i++)
    {
        k = pow(2, i);
        if (k == n)
        {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
}

bool isPowerOfTwo1(int n)
{
    if (n <= 0)
    {
        return false;
    }
    while (n)
    {
        if ((n % 2) != 0)
        {
            if (n == 1)
                return true;
            else
                return false;
        }
        n = n / 2;
    }
    return false;
}

int hammingWeight(uint32_t n)
{
    /*
    int cnt=0;
    while(n>0){
        if(n & 0x1) cnt++;
        n=n>>1;
    }
    return cnt;
    */
   int cnt=0;
   unsigned long long sum=n;
   while(sum){
    if(sum%2!=0) cnt++;
    sum=sum/2;
   }
   return cnt;
}

int climbStairs(int n){
    /*
    if(n<=1) return n;
    int sum[1024];
    sum[0]=1;
    sum[1]=2;
    for(int i=3;i<=n;i++){
        sum[i]=sum[i-1]+sum[i-2];
    }
    return sum[n];
    */
    //递归
    int cnt[1024]={0};
    cnt[1]=1;
    cnt[2]=2;
    if(cnt[n]==0) cnt[n]=climbStairs(n-1)+climbStairs(n-2);
    return cnt[n];
}

int singleNumber(int* nums, int numsSize){
    int i,cnt=0;
    for(i=0;i<numsSize;i++){
        cnt=cnt^nums[i];
    }
    return cnt;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t cnt=0;
    int i;
    for(i=0;i<8*sizeof(uint32_t);i++){
        cnt=cnt*2+n%2;
        n=n/2;
    }
    return cnt;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i,dp[triangleSize][triangleSize];
    dp[0][0]=triangle[0][0];
    for(i=0;i<triangleSize;i++){
        dp[i][0]=dp[i-1][0]+triangle[i][0];
        for(int j=1;j<i;j++){
            dp[i][j]=fmin(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
        }
        dp[i][i]=dp[i-1][i-1]+triangle[i][i];
    }
    int cnt=dp[triangleSize-1][0];
    for(i=1;i<triangleSize;i++){
        cnt=fmin(cnt,dp[triangleSize-1][i]);
    }
    return cnt;
}

int MAX(int a,int b){
    if(a>b) return a;
    else return b;
}

int rob(int* nums, int numsSize){
    int i,sum1=0,sum2=0;
    for(i=0;i<numsSize;i++){
        if(i%2==0){
            sum1+=nums[i];
            sum1=MAX(sum1,sum2);
        }else{
            sum2+=nums[i];
            sum2=MAX(sum1,sum2);
        }
    }
    return MAX(sum1,sum2);
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtracking(int* nums, int numsSize, int** res, int* returnSize, 
                  int** returnColumnSizes, int* path, int pathSize, int* used) {
    if (pathSize == numsSize) {
        res[*returnSize] = (int*)malloc(sizeof(int) * pathSize);
        memcpy(res[*returnSize], path, sizeof(int) * pathSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i] == 1) {
            continue;
        }
        path[pathSize] = nums[i];
        used[i] = 1;
        backtracking(nums, numsSize, res, returnSize, returnColumnSizes, path, pathSize + 1, used);
        used[i] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100001);
    int**res = (int**)malloc(sizeof(int*) * 100001);
    int* path = (int*)malloc(sizeof(int) * numsSize);
    int* used = (int*)malloc(sizeof(int) * numsSize);
    backtracking(nums, numsSize, res, returnSize, returnColumnSizes, path, 0, used);
    return res;
}

void DFS(char *s,int p,char **ans,int* returnSize){
    while(s[p]!='\0' && isdigit(s[p])) p++;
    if(s[p]=='\0'){
        ans[*returnSize] = (char*)malloc(sizeof(char)*(strlen(s)+1));
        strcpy(ans[*returnSize],s);
        (*returnSize)++;
        return;
    }
    s[p]^=32;
    DFS(s,p+1,ans,returnSize);
    s[p]^=32;
    DFS(s,p+1,ans,returnSize);
}
char ** letterCasePermutation(char * s, int* returnSize){
    int n=strlen(s);
    *returnSize=0;
    char **ans=(char**)malloc(sizeof(char*)*(1<<n));
    DFS(s,0,ans,returnSize);
    return ans;
}

int main()
{
    int nums[10]={2,7,9,3,1};
    int k=rob(nums,5);
    cout<<k<<endl;
    /*
    int nums[]={2,7,11,15};
    int i=4,right=0;
    //int *nums1=sortedSquares(nums,i);
    int *index=twoSum(nums,i,9,nums);
    for(int j=0;j<2;j++){
        cout<<index[j]<<" ";
    }
    cout<<endl;
    
    uint32_t sum=01000010110;
    int i = 0;
    char str[1024];
    sprintf(str,"%c",sum);
    cout<<str<<endl;
    char buf[1024] = {0};
    do
    {
        buf[i++] = sum%10+'0';
    }while(32);
    */
    return 0;
}
