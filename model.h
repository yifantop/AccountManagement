#ifndef _MODEL_H
#define _MODEL_H

#include<time.h>

//定义卡信息结构体
typedef struct Card {
	char aName[18];		//卡号
	char aPwd[8];		//密码
	int nStatus;		//卡状态0-未上机，1-正在上机，2-已注销，3-失效
	time_t tStart;		//开卡时间
	time_t tEnd;		//卡的截止时间
	float fTotalUse;	//累计金额
	time_t tLast;		//最后使用时间
	int nUseCount;		//使用次数
	float fBalance;		//余额
	int nDel;			//删除标识，0-未删除，1-删除
}Card;

//定义卡信息链表结点类型
typedef struct CardNode {
	Card data;				//结点数据
	struct CardNode* next;	//指针
}CardNode, *lpCardNode;

//计费信息结构体
typedef struct Billing {
	char aCardName[18];		//卡号
	time_t tStart;			//上机时间
	time_t tEnd;			//下机时间
}Billing;

//计费信息结点
typedef struct BillingNode {
	Billing data;
	struct BillingNode* next;
}BillingNode, *lpBillingNode;

//上机信息结构体
typedef struct LogonInfo {
	char aCardName[18];		//上机卡号
	time_t tLogon;			//上机时间
	float fBalance;			//上机时的卡余额
}LogonInfo;

//下机信息结构体
typedef struct SettleInfo {
	char aCardName[18];		//卡号
	time_t tStart;			//上机时间
	time_t tEnd;			//下机时间
	float fAmount;			//消费金额
	float fBalance;			//余额
}SettleInfo;

//充值退费结构体
typedef struct Money {
	char aCardName[18];		//卡号
	time_t tTime;			//充值退费时间
	int nStatus;			//状态，0-充值，1-退费
	float fMoney;			//充值退费金额
	int nDel;				//删除标识，0-未删除，1-删除
}Money;

//充值退费信息结构体
typedef struct MoneyInfo {
	char aCardName[18];		//卡号
	float fMoney;			//充值退费金额
	float fBalance;			//余额
}MoneyInfo;

#endif // !_MODEL_H

