/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h> 
struct ListNode {
    int val;
    struct ListNode *next;
};
int c=0;
/*c即进位,初始值0
上一位的进位(c值)加上两个链表相同位的数值,(c的个位)为当前位的结果,(c的十位)为当前位的进位
利用三目运算符:
l1不为空,说明当前位还有值,则加l1当前位的值,l1地址指向下一位
l1为空,说明l1加完了,就给进位加0(不变),l1始终不变指向空
l2同理,直到l1,l2都为空,c为0停止
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL && l2==NULL && c==0)return NULL;
    l1 = l1!=NULL ? (c += l1->val, l1->next) : l1;
    l2 = l2!=NULL ? (c += l2->val, l2->next) : l2;
    /*
	同节点依次相加，值为c
    */
    struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val = c%10;//取余赋值
    c /= 10;//除10计算下一个节点初始值
    		//进位
    cur->next = addTwoNumbers(l1,l2);
    return cur;
}
//初始化链表
struct ListNode * init_linklist() {
	struct ListNode *pheader = malloc(sizeof(struct ListNode));
	if (pheader == NULL) {
		return NULL;
	}
	//头节点无数据域
	pheader->next = NULL;//头节点指针域为NULL
	int num = -1;
	//创建尾节点，利于后期添加数据
	struct ListNode *ptail = pheader;
	while (1) {
		printf("请插入数据，输入-1退出\n");
		scanf("%d", &num);
		if (num == -1) {
			break;
		}
		//创建新节点
		struct ListNode *newnode = malloc(sizeof(struct ListNode));
		newnode->next = NULL;
		newnode->val = num;
		//建立关系
		ptail->next = newnode;
		//更新尾节点
		ptail = newnode;
	}

}
int int main(){
	//创建两个链表数据
	ListNode *l1 = init_linklist();
	ListNode *l2 = init_linklist();
	//创建接收
	struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
	cur = addTwoNumbers(l1,l2);
	//free(cur);
	return 0;
}