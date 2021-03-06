#pragma once
// #define _UNUSING_STDAFS_
//#define _USING_UFT8CODE_
//#define 调试模式
#define 调试模式1
//#define 脱机调试模式
//#define 测试五行
#define 易经机周数 AI_FRAME_RATE  //每秒多少周
#define 易经机数量1 64
#define 易经机数量 易经机数量1*1024
#define 易经机测试循环数 ((unsigned int)(易经机周数*4))
//#define 初始化符号
//1s

#define MAN_ACTION_SPEED(_speed,_rate) ((unsigned int)((_speed*易经机周数*AI_FRAME_DT*_rate)/((float)1000)))
#define MAN_CAN_ACTION(_seed,_id,_speed,_rate) ((unsigned int )((((_seed+_id)*AI_FRAME_DT)%(MAN_ACTION_SPEED(_speed,_rate)))/AI_FRAME_DT))
#define AI_TICK_COUNT_PER_MS(_ms,_rate) ((unsigned int)((_ms*易经机周数*AI_FRAME_DT*_rate)/1000))
//#define MAN_ACTION_SPEED(_rate) ((unsigned int)(1*易经机周数))
//#define AI_TICK_COUNT_PER_MS(_ms,_rate) ((unsigned int)((_ms*易经机周数)/1000))
//#define MAN_ACTION_SPEED ((unsigned int)(1*PHY_FRAME_RATE))
//#define AI_TICK_COUNT_PER_MS(_ms) ((unsigned int)((_ms*PHY_FRAME_RATE)/1000))

//#define InitIChing
#define 构造异常

#define MAN_AI_BASE_POS 2
#define 异数OS日志系统

#ifdef 异数OS日志系统
#define 容器输出 ContainerThreadError3 
#else
#define 容器输出(_d,...) printf(__VA_ARGS__);printf("\r\n"); 
#endif
//


#ifdef _LINUX_
#define 巨页内存
#endif

#define 统计信息

#ifdef  _LINUX_
#include "IChingDefineUtf8.h"
#include "IChingEngineUtf8.h"

#else
#ifdef _USING_UFT8CODE_
#include "IChingDefineUtf8.h"
#include "IChingEngineUtf8.h"

#else
#include "IChingDefine.h"
#include "IChingEngine.h"
#endif
#endif

using namespace 易经;

#pragma pack(push,1)
class _引擎函数
{
public:
	unsigned int _Context;
	_引擎函数() { //*(unsigned int*)&状态 = 0;
	};
	~_引擎函数() {};
	//设置触发器参数
	void 初始化() {
		//状态.状态 = 等待决策;
	};
	//检查天地人是否触发相关条件
	static 激励结果 激励(void* p系统, void* p状态机, 向量型& _向量);
private:

};
#pragma pack(pop)

//#define 易经机数量 4
//#define 易经机测试循环数 (2048*4096/易经机数量)
#define 引擎函数(_符,...) \
定义量开始(_符, "引擎");\
内量(内置__引擎函数);占位对象(_引擎函数);\
__VA_ARGS__;\
定义量结束;\


//动作资源定义
#define 动作_待命 常数量(0)
#define 动作_跑 常数量(1)
#define 动作_攻击 常数量(2)
#define 动作_痛 常数量(3)
#define 动作_痛1 常数量(4)
#define 动作_痛2 常数量(5)
#define 动作_跳 常数量(6)
#define 动作_空翻 常数量(7)
#define 动作_敬礼 常数量(8)
#define 动作_嘲笑 常数量(9)
#define 动作_笑 常数量(10)
#define 动作_瞄准 常数量(11)
#define 动作_待命1 常数量(12)
#define 动作_倒地 常数量(16)

#define 朝向_东		常数量(0)
#define 朝向_东南	常数量(2)
#define 朝向_南		常数量(4)
#define 朝向_西南	常数量(6)
#define 朝向_西		常数量(8)
#define 朝向_西北	常数量(10)
#define 朝向_北		常数量(12)
#define 朝向_东北	常数量(14)

#define 角色状态_死亡 常数量(UnitBaseState::UnitBaseState_Death)
#define 角色状态_等待 常数量(UnitBaseState::UnitBaseState_Wait)

#ifdef 调试模式

#define 易经机数量 3
#define 易经机测试循环数 50
#define 易经机测试不循环
#endif // 调试模式

template <typename _ManT>
class ModernWarAI
{
public:
	ModernWarAI() {};
	~ModernWarAI() {};
	易经::易经系统 _易经系统;
	typedef _ManT ManT;
	
private:
	

	void 系统初始化();
	void 定义天()
	{
		切换域(易经::天);
		易经机定义开始(玉帝AI, 地AI);
		定义量(时间, 场景, 常数量(9));
		定义量(天气, 场景, 符量(雷雨));
		代量(时间); 代量(天气);
		易经机定义结束;
	}
	void 诸葛亮()
	{
		易经机定义开始(诸葛亮AI, 地AI);
		定义量(弓箭兵.军令.放箭数量, 军令, 常数量(11));
		定义量(弓箭兵.军令, 军令, 符量(初始状态));
		定义量(弓箭兵.拉弓待命数量, 军令, 常数量(0));
		定义量(弓箭兵.阵型待命数, 军令, 常数量(0));
		定义量(弓箭兵.待复活数, 军令, 常数量(0));
		定义量(弓箭兵.总计复活数, 军令, 常数量(0));
		定义量(弓箭兵.复活百万数, 军令, 常数量(0));

		定义表达式(永不否决, 动作指令, 式(等于, 常数量(2), 常数量(1)));
		定义表达式(AI动作.等待, 动作指令, 式(等于, 常数量(1), 常数量(1)));

		//定义量(军令.锁, 动作指令, 符量(解锁));
		//定义表达式(军令.需要粮草, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(小于, 代量(弓箭兵.军令.放箭数量), 常数量(13))));
		//定义表达式(军令.需要待命, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(小于, 代量(弓箭兵.待命数量), 常数量(3))));
		//定义表达式(军令.需要放箭, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(大于, 代量(弓箭兵.待命数量), 常数量(3))));
#ifdef 调试模式1
		定义表达式(军令.需要粮草, 决策条件, 式(小于, 代量(弓箭兵.军令.放箭数量), 常数量(100)));
		定义表达式(军令.需要待命, 决策条件, 式(与, 式(大于, 代量(弓箭兵.阵型待命数), 常数量(60)), 式(小于, 代量(弓箭兵.拉弓待命数量), 常数量(60))));
		定义表达式(军令.需要放箭, 决策条件, 式(大于, 代量(弓箭兵.拉弓待命数量), 常数量(50)));
		定义表达式(军令.需要阵型待命, 决策条件, 式(小于, 代量(弓箭兵.阵型待命数), 常数量(100)));
#else
		定义表达式(军令.需要粮草, 决策条件, 式(小于, 代量(弓箭兵.军令.放箭数量), 常数量(13)));
		定义表达式(军令.需要待命, 决策条件, 式(与, 式(大于, 代量(弓箭兵.阵型待命数), 常数量(25000)), 式(小于, 代量(弓箭兵.拉弓待命数量), 常数量(25000))));
		定义表达式(军令.需要放箭, 决策条件, 式(大于, 代量(弓箭兵.拉弓待命数量), 常数量(25000)));
		定义表达式(军令.需要阵型待命, 决策条件, 式(小于, 代量(弓箭兵.阵型待命数), 常数量(500)));
#endif

		定义量(生命周, 动作指令, 常数量(0)); //代量(生命周);

		易经日志(诸葛亮.军令日志, 常字符串量("生命周="), 代量(生命周), 常字符串量("当前军令="), 代量(弓箭兵.军令),
			常字符串量("仓库弓箭数="), 代量(弓箭兵.军令.放箭数量), 常字符串量("拉弓待命数="), 代量(弓箭兵.拉弓待命数量), 常字符串量("阵型待命数="), 代量(弓箭兵.阵型待命数)
		);

		定义表达式(清算.数值溢出.条件, 动作指令, 式(大于, 代量(弓箭兵.总计复活数), 常数量(1000000)));
		被动序列(清算.数值溢出, 动作指令,
			五行(聚散, 代量(弓箭兵.复活百万数), 常数量(1)),
			五行(聚散, 代量(弓箭兵.总计复活数), 常数量(-1000000))
		);

		易经日志(诸葛亮.监视日志, 常字符串量("生命周="), 代量(生命周), 常字符串量("当前军令="), 代量(弓箭兵.军令),
			常字符串量("仓库弓箭数="), 代量(弓箭兵.军令.放箭数量), 常字符串量("拉弓待命数="), 代量(弓箭兵.拉弓待命数量), 常字符串量("\r\n阵型待命数="), 代量(弓箭兵.阵型待命数),
			常字符串量("待复活数="), 代量(弓箭兵.待复活数),常字符串量("总计复活数="), 代量(弓箭兵.总计复活数), 常字符串量("复活百万数="), 代量(弓箭兵.复活百万数)
		);
		引擎函数(移动到阵型目标, 符量(移动), 常数量(1));

		自动序列(自动任务.生命, 动作指令, 五行(聚散, 代量(生命周), 常数量(1)));
		自动序列(自动任务.监视日志, 动作指令, 
			待命毫秒数(6000),
			五行(动作, 代量(诸葛亮.监视日志)),
			五行(清算, 代量(清算.数值溢出.条件), 代量(清算.数值溢出)));

		
		定义量(特写.待命.参数, 特写, 常数量(0), 常数量(0), 常数量(0));
		定义量(特写.放箭.参数, 特写, 常数量(0), 常数量(1), 常数量(0));

		定义量(天气.打雷.参数, 天气, 常数量(0), 常数量(0), 常数量(0));
		定义量(天气.彩虹.参数, 天气, 常数量(0), 常数量(1), 常数量(0));

		引擎函数(特写.待命, 符量(特写), 代量(特写.待命.参数));
		引擎函数(特写.放箭, 符量(特写), 代量(特写.放箭.参数));
		引擎函数(天气.打雷, 符量(天气), 代量(天气.打雷.参数));
		引擎函数(天气.彩虹, 符量(天气), 代量(天气.彩虹.参数));

		被动序列(军令.放箭0, 动作指令,
			//五行(迁移, 代量(军令.锁), 符量(上锁)),
			五行(迁移, 代量(弓箭兵.军令), 符量(放箭)),
			五行(动作, 代量(诸葛亮.军令日志)),
			五行(动作, 代量(特写.放箭)),
			待命毫秒数(6000),//等待90个生命周期后放箭
			五行(迁移, 代量(弓箭兵.军令), 符量(放箭结束)),
			五行(动作, 代量(诸葛亮.军令日志))
			//五行(迁移, 代量(军令.锁), 符量(解锁))
		);
		被动序列(军令.拉弓待命, 动作指令,
			五行(迁移, 代量(弓箭兵.军令), 符量(拉弓待命)),
			五行(动作, 代量(诸葛亮.军令日志)),
			五行(动作, 代量(特写.待命)),
			待命毫秒数(12000),//等待90个生命周期后放箭)
			五行(迁移, 代量(弓箭兵.军令), 符量(拉弓待命结束)),
			五行(动作, 代量(诸葛亮.军令日志))
		);
		被动序列(军令.准备粮草, 动作指令,
			五行(迁移, 代量(弓箭兵.军令), 符量(粮草储备中)),
			五行(动作, 代量(诸葛亮.军令日志)),
			五行(动作, 代量(天气.打雷)),
			待命毫秒数(12000),//等待90个生命周期后放箭)
			五行(聚散, 代量(弓箭兵.军令.放箭数量), 常数量(100000)),
			五行(动作, 代量(天气.彩虹)),
			待命毫秒数(12000),
			五行(聚散, 代量(弓箭兵.军令.放箭数量), 常数量(100000)),
			五行(迁移, 代量(弓箭兵.军令), 符量(粮草储备结束)),
			五行(动作, 代量(诸葛亮.军令日志))
		);

		被动序列(军令.准备阵型, 动作指令,
			五行(迁移, 代量(弓箭兵.军令), 符量(准备阵型)),
			五行(动作, 代量(诸葛亮.军令日志)),
			待命毫秒数(9000),
			五行(迁移, 代量(弓箭兵.军令), 符量(准备阵型结束)),
			五行(动作, 代量(诸葛亮.军令日志))
		);
		//决策(攻击.放箭, 场景, 军令.放箭, 永不否决, AI动作状态机.放箭, AI动作状态机.等待, 6);
		动作状态机(AI动作状态机.等待, 动作指令, 状态式(开始, 执行, AI动作.等待), 状态式(执行, 结束, AI动作.等待));



		队列决策(攻击.准备粮草, 场景, 军令队列, 军令.需要粮草, 永不否决, 军令.准备粮草, AI动作状态机.等待);

		队列决策(攻击.放箭, 场景, 军令队列, 军令.需要放箭, 永不否决, 军令.放箭0, AI动作状态机.等待);

		队列决策(攻击.待命, 场景, 军令队列, 军令.需要待命, 永不否决, 军令.拉弓待命, AI动作状态机.等待);

		队列决策(移动.准备阵型, 场景, 军令队列, 军令.需要阵型待命, 永不否决, 军令.准备阵型, AI动作状态机.等待);

		易经机定义结束;
	}

	void 周瑜()
	{
		易经机定义开始(周瑜AI, 地AI);
		定义量(弓箭兵.军令.放箭数量, 军令, 常数量(11));
		定义量(弓箭兵.军令, 军令, 符量(初始状态));
		定义量(弓箭兵.拉弓待命数量, 军令, 常数量(0));
		定义量(弓箭兵.阵型待命数, 军令, 常数量(0));
		定义量(弓箭兵.待复活数, 军令, 常数量(0));
		定义量(弓箭兵.总计复活数, 军令, 常数量(0));
		定义量(弓箭兵.复活百万数, 军令, 常数量(0));

		定义表达式(永不否决, 动作指令, 式(等于, 常数量(2), 常数量(1)));
		定义表达式(AI动作.等待, 动作指令, 式(等于, 常数量(1), 常数量(1)));



		定义量(生命周, 动作指令, 常数量(0)); //代量(生命周);

		易经日志(周瑜.军令日志, 常字符串量("生命周="), 代量(生命周), 常字符串量("当前军令="), 代量(弓箭兵.军令),
			常字符串量("仓库弓箭数="), 代量(弓箭兵.军令.放箭数量), 常字符串量("拉弓待命数="), 代量(弓箭兵.拉弓待命数量), 常字符串量("阵型待命数="), 代量(弓箭兵.阵型待命数)
		);

		定义表达式(清算.数值溢出.条件, 动作指令, 式(大于, 代量(弓箭兵.总计复活数), 常数量(1000000)));
		被动序列(清算.数值溢出, 动作指令,
			五行(聚散, 代量(弓箭兵.复活百万数), 常数量(1)),
			五行(聚散, 代量(弓箭兵.总计复活数), 常数量(-1000000))
		);

		易经日志(周瑜.监视日志, 常字符串量("生命周="), 代量(生命周), 常字符串量("当前军令="), 代量(弓箭兵.军令),
			常字符串量("仓库弓箭数="), 代量(弓箭兵.军令.放箭数量), 常字符串量("拉弓待命数="), 代量(弓箭兵.拉弓待命数量), 常字符串量("\r\n阵型待命数="), 代量(弓箭兵.阵型待命数),
			常字符串量("待复活数="), 代量(弓箭兵.待复活数), 常字符串量("总计复活数="), 代量(弓箭兵.总计复活数), 常字符串量("复活百万数="), 代量(弓箭兵.复活百万数)
		);
		引擎函数(移动到目标, 符量(移动), 常数量(1));
		
		定义量(目标起点, 目标, 常数量(9600), 常数量(50), 常数量(10800));
		定义量(目标A, 目标, 常数量(8000), 常数量(600), 常数量(7750));
		定义量(目标B,目标, 常数量(10000), 常数量(60), 常数量(7750));
		定义量(目标C, 目标, 常数量(10500), 常数量(120), 常数量(11000));
		定义量(目标D, 目标, 常数量(7000), 常数量(100), 常数量(7000));
		定义量(目标E, 目标, 常数量(7000), 常数量(100), 常数量(10700));
		定义量(目标F, 目标, 常数量(7000), 常数量(1000), 常数量(10700));

		引擎函数(设置目标起点, 符量(目标), 代量(目标起点));
		引擎函数(设置目标A, 符量(目标), 代量(目标A));
		引擎函数(设置目标B, 符量(目标), 代量(目标B));
		引擎函数(设置目标C, 符量(目标), 代量(目标C));
		引擎函数(设置目标D, 符量(目标), 代量(目标D));
		引擎函数(设置目标E, 符量(目标), 代量(目标E));
		引擎函数(设置目标F, 符量(目标), 代量(目标F));

		自动序列(自动任务.生命, 动作指令,
			随机待命毫秒数(1500, 500),
			五行(聚散, 代量(生命周), 常数量(1)),
			五行(动作, 代量(周瑜.军令日志)),
			五行(动作, 代量(设置目标起点)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500),

			五行(动作, 代量(设置目标A)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500),

			五行(动作, 代量(设置目标B)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500),

			五行(动作, 代量(设置目标C)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500),

			五行(动作, 代量(设置目标D)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500),

			五行(动作, 代量(设置目标E)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500),

			五行(动作, 代量(设置目标F)),
			五行(动作, 代量(移动到目标)),
			随机待命毫秒数(10500, 3500)
		);
		

		易经机定义结束;
	}

	void 许褚()
	{
		易经机定义开始(许褚AI, 地AI);
		定义量(刀盾兵.军令.粮草数量, 军令, 常数量(11));
		定义量(刀盾兵.军令, 军令, 符量(初始状态));
		定义量(刀盾兵.防守待命数量, 军令, 常数量(0));
		定义量(刀盾兵.阵型待命数, 军令, 常数量(0));
		定义量(刀盾兵.待复活数, 军令, 常数量(0));
		定义量(刀盾兵.总计复活数, 军令, 常数量(0));
		定义量(刀盾兵.复活百万数, 军令, 常数量(0));

		定义表达式(永不否决, 动作指令, 式(等于, 常数量(2), 常数量(1)));
		定义表达式(AI动作.等待, 动作指令, 式(等于, 常数量(1), 常数量(1)));

		//定义量(军令.锁, 动作指令, 符量(解锁));
		//定义表达式(军令.需要粮草, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(小于, 代量(弓箭兵.军令.放箭数量), 常数量(13))));
		//定义表达式(军令.需要待命, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(小于, 代量(弓箭兵.待命数量), 常数量(3))));
		//定义表达式(军令.需要放箭, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(大于, 代量(弓箭兵.待命数量), 常数量(3))));
		
		定义表达式(条件.需要粮草, 决策条件, 式(小于, 代量(刀盾兵.军令.粮草数量), 常数量(13)));
		定义表达式(条件.需要阵型待命, 决策条件, 式(小于, 代量(刀盾兵.阵型待命数), 常数量(2500)));
		定义表达式(条件.需要防御, 决策条件, 式(与, 式2(非, 代量(条件.需要阵型待命)), 式(小于, 代量(刀盾兵.防守待命数量), 常数量(2000))));

		//阵型待命大于26000,攻击待命大于20000则发起进攻
		定义表达式(条件.需要进攻, 决策条件, 式(与, 式2(非, 代量(条件.需要阵型待命)), 式(大于, 代量(刀盾兵.防守待命数量), 常数量(2000))));
		//定义表达式(军令.需要防御, 决策条件, 式(与, 式(大于, 代量(刀盾兵.阵型待命数), 常数量(500)), 式(大于, 代量(刀盾兵.待命数量), 常数量(5000))));
		

		定义量(生命周, 动作指令, 常数量(0)); //代量(生命周);

		易经日志(许褚.军令日志, 常字符串量("生命周="), 代量(生命周), 常字符串量("当前军令="), 代量(刀盾兵.军令),
			常字符串量("仓库粮草数="), 代量(刀盾兵.军令.粮草数量), 常字符串量("防守待命数="), 代量(刀盾兵.防守待命数量), 常字符串量("阵型待命数="), 代量(刀盾兵.阵型待命数)
		);

		定义表达式(清算.数值溢出.条件, 动作指令, 式(大于, 代量(刀盾兵.总计复活数), 常数量(1000000)));
		被动序列(清算.数值溢出, 动作指令,
			五行(聚散, 代量(刀盾兵.复活百万数), 常数量(1)),
			五行(聚散, 代量(刀盾兵.总计复活数), 常数量(-1000000))
		);
		易经日志(许褚.监视日志, 常字符串量("生命周="), 代量(生命周), 常字符串量("当前军令="), 代量(刀盾兵.军令),
			常字符串量("仓库粮草数="), 代量(刀盾兵.军令.粮草数量), 常字符串量("防守待命数="), 代量(刀盾兵.防守待命数量), 常字符串量("\r\n阵型待命数="), 代量(刀盾兵.阵型待命数),
			常字符串量("待复活数="), 代量(刀盾兵.待复活数), 常字符串量("总计复活数="), 代量(刀盾兵.总计复活数), 常字符串量("复活百万数="), 代量(刀盾兵.复活百万数)
		);
		引擎函数(移动到阵型目标, 符量(移动), 常数量(1));

		自动序列(自动任务.生命, 动作指令, 五行(聚散, 代量(生命周), 常数量(1)));
		自动序列(自动任务.监视日志, 动作指令, 
			待命毫秒数(6000),
			五行(动作, 代量(许褚.监视日志)),
			五行(清算, 代量(清算.数值溢出.条件), 代量(清算.数值溢出))
		);

		被动序列(军令.进攻, 动作指令,
			//五行(迁移, 代量(军令.锁), 符量(上锁)),
			五行(迁移, 代量(刀盾兵.军令), 符量(进攻)),
			五行(动作, 代量(许褚.军令日志)),

			待命毫秒数(3000),//等待90个生命周期后放箭
			五行(迁移, 代量(刀盾兵.军令), 符量(进攻结束)),
			五行(动作, 代量(许褚.军令日志))
			//五行(迁移, 代量(军令.锁), 符量(解锁))
		);
		被动序列(军令.防护待命, 动作指令,
			五行(迁移, 代量(刀盾兵.军令), 符量(防护待命)),
			五行(动作, 代量(许褚.军令日志)),
			待命毫秒数(4000),//等待90个生命周期后放箭)
			五行(迁移, 代量(刀盾兵.军令), 符量(防护待命结束)),
			五行(动作, 代量(许褚.军令日志))
		);
		被动序列(军令.准备粮草, 动作指令,
			五行(迁移, 代量(刀盾兵.军令), 符量(粮草储备中)),
			五行(动作, 代量(许褚.军令日志)),
			待命毫秒数(1000),//等待90个生命周期后放箭)
			五行(聚散, 代量(刀盾兵.军令.粮草数量), 常数量(70000)),
			待命毫秒数(1000),
			五行(聚散, 代量(刀盾兵.军令.粮草数量), 常数量(70000)),
			
			五行(迁移, 代量(刀盾兵.军令), 符量(粮草储备结束)),
			五行(动作, 代量(许褚.军令日志))
		);

		被动序列(军令.准备阵型, 动作指令,
			五行(迁移, 代量(刀盾兵.军令), 符量(准备阵型)),
			五行(动作, 代量(许褚.军令日志)),
			待命毫秒数(3000),//等待90个生命周期后放箭)
			五行(动作, 代量(许褚.军令日志)),
			待命毫秒数(3000),//等待90个生命周期后放箭)
			五行(迁移, 代量(刀盾兵.军令), 符量(准备阵型结束)),
			五行(动作, 代量(许褚.军令日志))
		);
		//决策(攻击.放箭, 场景, 军令.放箭, 永不否决, AI动作状态机.放箭, AI动作状态机.等待, 6);
		动作状态机(AI动作状态机.等待, 动作指令, 状态式(开始, 执行, AI动作.等待), 状态式(执行, 结束, AI动作.等待));

		

		队列决策(攻击.准备粮草, 场景, 军令队列, 条件.需要粮草, 永不否决, 军令.准备粮草, AI动作状态机.等待);

		队列决策(攻击.进攻, 场景, 军令队列, 条件.需要进攻, 永不否决, 军令.进攻, AI动作状态机.等待);

		队列决策(攻击.防御, 场景, 军令队列, 条件.需要防御, 永不否决, 军令.防护待命, AI动作状态机.等待);

		队列决策(移动.准备阵型, 场景, 军令队列, 条件.需要阵型待命, 永不否决, 军令.准备阵型, AI动作状态机.等待);

		易经机定义结束;
	}
	
	void 测试定义()
	{
		切换域(易经::人);
		易经机定义开始(弓箭手AI, 动作序列);
		符量(测试名称);
		代量(测试名称);
		易经机定义结束;
	}
	void 弓箭手()
	{
		易经机定义开始(弓箭手AI, 动作序列);

		定义表达式(AI动作.移动, 动作指令, 式(加, 常数量(1), 常数量(2)));
		定义表达式(AI动作.等待, 动作指令, 式(加, 常数量(1), 常数量(3)));

		//动作状态机(AI动作状态机.得令, 动作指令, 状态式(开始, 执行, AI动作.移动), 状态式(执行, 结束, AI动作.移动));
		//动作状态机(AI动作状态机.死亡, 动作指令, 状态式(开始, 执行, AI动作.移动), 状态式(执行, 结束, AI动作.移动));

		//动作状态机(AI动作状态机.撤离, 动作指令, 状态式(开始, 执行, AI动作.移动), 状态式(执行, 结束, AI动作.移动));
		//动作状态机(AI动作状态机.半蹲撤退, 动作指令, 状态式(开始, 执行, AI动作.移动), 状态式(执行, 结束, AI动作.移动));
		动作状态机(AI动作状态机.等待, 动作指令, 状态式(开始, 执行2, AI动作.移动), 状态式(执行2, 结束, AI动作.移动));
		
		定义表达式(永不否决, 动作指令, 式(等于, 常数量(2), 常数量(1)));
		//定义表达式(军令表达式2, 动作指令, 式(等于, 代量(军令表达式), 常数量(0)));
		/*
		定义量开始(AI动作2.调试移动, 动作指令);
			符量(移动);
			定义量(目标坐标.备注, 备注, 符量(等待军令), 常数量(4), 常数量(5), 常数量(6));
			定义量(起始坐标, 坐标, 常数量(300), 常数量(100), 常数量(400));
			定义量(目标坐标, 坐标, 常数量(3000), 常数量(1000), 常数量(4000), 代量(备注));
			代量(起始坐标);
			代量(目标坐标);
		定义量结束;
		*/
		//定义状态
		
		//定义表达式(状态.死亡, 动作指令, 式(等于, 常数量(1), 符量(死亡)));
		//定义表达式(状态.饥饿, 动作指令, 式(等于, 内量(状态), 符量(饥饿)));
		//定义表达式(状态.士气低, 动作指令, 式(小于, 内量(状态), 常数量(30)));

		//军令
		//定义表达式(军令.撤离, 动作指令, 式(等于, 内量(军令.目标), 符量(撤离)));
		//定义表达式(军令.变换方阵, 动作指令, 式(等于, 内量(军令.目标), 符量(变换方阵)));
		//定义表达式(军令.变换圆阵, 动作指令, 式(等于, 内量(军令.目标), 符量(变换圆阵)));

		//定义表达式(军令.放箭, 动作指令, 式(大于, 内量(军令.目标), 符量(10)));
		//定义表达式(军令.放箭, 动作指令, 式(大于, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(3)));
		//定义量(军令.锁, 动作指令, 符量(解锁));

		定义量(状态.军令, 状态信息, 符量(初始状态));// 代量(状态.军令);
		定义量(状态.阵型就绪, 状态信息, 符量(未就绪));
		定义量(状态.拉弓就绪, 状态信息, 符量(未就绪));
		//式(等于, 代量(军令.锁), 符量(解锁)),
		/*
		定义表达式(军令.放箭, 动作指令, 式(与, 式(等于, 代量(军令.锁), 符量(解锁)), 式(与, 式(等于, 代量(状态.军令), 符量(拉弓待命)), 式(与,
			式(等于, 代量(诸葛亮AI.弓箭兵.军令), 符量(放箭)),
			式(大于, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(4))))));
			*/
		定义表达式(条件.放箭, 动作指令, 式(与, 式(等于, 代量(诸葛亮AI.弓箭兵.军令), 符量(放箭)), 式(与, 式(等于, 代量(状态.拉弓就绪), 符量(已就绪)),
			式(大于, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(4)))));

		//定义表达式(条件.准备阵型, 动作指令, 式(与, 式(等于, 代量(状态.阵型就绪), 符量(未就绪)), 式(等于, 代量(诸葛亮AI.弓箭兵.军令), 符量(准备阵型))));
		定义表达式(条件.准备阵型, 动作指令, 式(等于, 代量(状态.阵型就绪), 符量(未就绪)));
		定义表达式(条件.复活, 动作指令, 式(等于, 内量(角色.状态), 角色状态_死亡));
		/*
		定义表达式(军令.放箭, 动作指令,  式(与,
			式(等于, 代量(诸葛亮AI.弓箭兵.军令), 符量(放箭)),
			式(大于, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(3))));
		*/
		定义表达式(条件.待命, 动作指令,
			式(与, 式(等于, 代量(诸葛亮AI.弓箭兵.军令), 符量(拉弓待命)),
				式(与, 式(等于, 代量(状态.拉弓就绪), 符量(未就绪)), 式(等于, 代量(状态.阵型就绪), 符量(已就绪)))
			));
		//代量(军令表达式);
		/*代量(AI动作.死亡);
		代量(AI动作.放箭); 代量(AI动作.撤离); 代量(AI动作.半蹲撤退); 代量(AI动作.调试移动);
		*/
		//定义量(进场触发器, 场景, 内量(触发器), 代量(军令表达式), 代量(AI动作.得令),数量(7));
		//
#ifdef 测试五行
			/*
			自动序列(AI动作.放箭0, 动作指令,
				五行(聚散,代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(-1)),
				五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(-1)));
			*/
		自动序列(AI动作.放箭0, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(-1)));
		自动序列(AI动作.放箭1, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(-1)));


		自动序列(AI动作.放箭2, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1)));
		自动序列(AI动作.放箭3, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1)));
		/*
		自动序列(AI动作.放箭4, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1)));
		自动序列(AI动作.放箭5, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1)));
		自动序列(AI动作.放箭6, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1)));
		自动序列(AI动作.放箭7, 动作指令, 五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1)));
		*/
		//动作(动作.放箭, 动作指令, 符量(生泄), 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(1));
		//五行动作(动作.放箭, 动作指令, 常数量(1));
#else

		定义表达式(调试条件, 动作指令, 式(或, 式(大于, 代量(诸葛亮AI.弓箭兵.拉弓待命数量), 常数量(65535)), 式(小于, 代量(诸葛亮AI.弓箭兵.拉弓待命数量), 常数量(4))));
		//定义表达式(调试条件, 动作指令, 式(不等于, 代量(状态.军令), 符量(拉弓待命)));
		易经条件日志(调试日志, 代量(调试条件), 常字符串量("生命周="), 代量(诸葛亮AI.生命周), 常字符串量(" 当前军令="), 代量(诸葛亮AI.弓箭兵.军令), 代量(状态.军令),
			常字符串量(" 仓库弓箭数="), 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常字符串量(" 待命弓箭手数="), 代量(诸葛亮AI.弓箭兵.拉弓待命数量)
		);

		引擎函数(表情.拉弓待命, 符量(表情), 动作_瞄准);
		引擎函数(动作.放箭, 符量(射击), 动作_攻击);
		引擎函数(动作.复活, 符量(复活), 动作_空翻);
		引擎函数(表情.装死, 符量(表情), 动作_倒地);
		引擎函数(表情.复活, 符量(表情), 动作_空翻);

		被动序列(AI动作.放箭0, 动作指令,
			//五行(迁移, 代量(军令.锁), 符量(上锁)), 
			//五行(动作, 代量(调试日志)),
			五行(迁移, 代量(状态.拉弓就绪), 符量(未就绪)),
			五行(聚散, 代量(诸葛亮AI.弓箭兵.拉弓待命数量), 常数量(-1)),
			五行(聚散, 代量(诸葛亮AI.弓箭兵.军令.放箭数量), 常数量(-3)),

			五行(迁移, 代量(状态.军令), 符量(放箭)),

			//五行(动作, 代量(调试日志)),
			随机待命毫秒数(2000, 1700),
			五行(动作, 代量(动作.放箭)),
			//随机待命毫秒数(1000, 500),
			随机待命毫秒数(1200, 500),
			五行(动作, 代量(表情.拉弓待命)),

			随机待命毫秒数(1200, 500),
			五行(动作, 代量(动作.放箭)),

			随机待命毫秒数(1200, 300),
			五行(动作, 代量(表情.拉弓待命)),

			随机待命毫秒数(1200, 500),
			五行(动作, 代量(动作.放箭)),

			//随机待命毫秒数(1000, 500),

			//五行(聚散, 代量(诸葛亮AI.弓箭兵.待命数量), 常数量(1)),
			//五行(聚散, 代量(诸葛亮AI.弓箭兵.阵型待命数), 常数量(-1)),
			
			五行(迁移, 代量(状态.军令), 符量(放箭结束))
			//五行(迁移, 代量(军令.锁), 符量(解锁))
		);

		被动序列(AI动作.待命, 动作指令,
			//五行(迁移, 代量(军令.锁), 符量(上锁)),
			五行(迁移, 代量(状态.拉弓就绪), 符量(已就绪)),
			五行(聚散, 代量(诸葛亮AI.弓箭兵.拉弓待命数量), 常数量(1)),
			五行(迁移, 代量(状态.军令), 符量(准备拉弓待命)),

			随机待命毫秒数(1200, 500),
			五行(动作, 代量(表情.拉弓待命)),
			随机待命毫秒数(1200, 500),


			//待命毫秒数(1000),
			
			五行(迁移, 代量(状态.军令), 符量(拉弓待命))
			
			
			//五行(迁移, 代量(军令.锁), 符量(解锁))
			//
		);
		引擎函数(移动到阵型目标, 符量(移动), 常数量(1));

		被动序列(AI动作.准备阵型, 动作指令,
			五行(迁移, 代量(状态.军令), 符量(准备阵型中)),
			随机待命毫秒数(3000, 1000),
			五行(动作, 代量(移动到阵型目标)),
			
			随机待命毫秒数(3000, 1000),
			五行(迁移, 代量(状态.阵型就绪), 符量(已就绪)),
			五行(聚散, 代量(诸葛亮AI.弓箭兵.阵型待命数), 常数量(1)),
			五行(迁移, 代量(状态.军令), 符量(准备阵型结束))
		);
		//决策(攻击.放箭, 场景, 军令.放箭, 永不否决, AI动作状态机.放箭, AI动作状态机.等待, 6);
		//动作状态机(AI动作状态机.放箭, 动作指令, 状态式(开始, 执行, AI动作.放箭0), 状态式(执行, 结束, AI动作.等待));
		//决策(攻击.放箭, 场景, 军令.放箭, 永不否决, AI动作状态机.放箭, AI动作状态机.等待, 6);
		定义表达式(清算.阵型就绪.条件, 动作指令,  式(不等于, 代量(状态.阵型就绪), 符量(未就绪)));
		被动序列(清算.阵型就绪, 动作指令,
			五行(聚散, 代量(诸葛亮AI.弓箭兵.阵型待命数), 常数量(-1)),
			五行(迁移, 代量(状态.阵型就绪), 符量(未就绪))
		);
		定义表达式(清算.拉弓就绪.条件, 动作指令, 式(不等于, 代量(状态.拉弓就绪), 符量(未就绪)));
		被动序列(清算.拉弓就绪, 动作指令,
			五行(聚散, 代量(诸葛亮AI.弓箭兵.拉弓待命数量), 常数量(-1)),
			五行(迁移, 代量(状态.拉弓就绪), 符量(未就绪))
			);

		被动序列(AI动作.复活, 动作指令,
			五行(迁移, 代量(状态.军令), 符量(准备复活中)), 
			五行(清算, 代量(清算.阵型就绪.条件), 代量(清算.阵型就绪)),
			五行(清算, 代量(清算.拉弓就绪.条件), 代量(清算.拉弓就绪)),
			五行(聚散, 代量(诸葛亮AI.弓箭兵.待复活数), 常数量(1)),
			五行(聚散, 代量(诸葛亮AI.弓箭兵.总计复活数), 常数量(1)),

			
			随机待命毫秒数(30000, 5000),
			//五行(迁移, 内量(角色.状态), 角色状态_等待),
			五行(动作, 代量(动作.复活)),
			随机待命毫秒数(1500, 300),
			五行(动作, 代量(表情.复活)),
			
			
			
			五行(聚散, 代量(诸葛亮AI.弓箭兵.待复活数), 常数量(-1)),
			//五行(聚散, 代量(状态.阵型就绪), 符量(未就绪)),
			
			五行(迁移, 代量(状态.军令), 符量(复活结束))
		);

		决策(决策.复活, 场景, 条件.复活, 永不否决, AI动作.复活, AI动作状态机.等待);
		决策(决策.待命, 场景, 条件.待命, 永不否决, AI动作.待命, AI动作状态机.等待);
		决策(决策.放箭, 场景, 条件.放箭, 永不否决, AI动作.放箭0, AI动作状态机.等待);
		决策(决策.准备阵型, 场景, 条件.准备阵型, 永不否决, AI动作.准备阵型, AI动作状态机.等待);
		//决策(进场触发器1, 场景, 军令表达式, 永不否决, AI动作状态机.得令, AI动作.等待, 6);

#ifndef 调试模式

			//决策(进场触发器, 场景, 军令表达式, 永不否决, AI动作状态机.得令, AI动作状态机.等待);
			//决策(攻击.放箭, 场景, 军令.放箭, 永不否决, AI动作状态机.放箭, AI动作状态机.等待);

			//决策(进场触发器1, 场景, 军令表达式2, 永不否决, AI动作状态机.得令, AI动作.等待);
			/*
			决策(死亡触发器, 场景, 状态.死亡, 永不否决, AI动作状态机.死亡, AI动作状态机.等待);
			//决策(饥饿触发器, 场景, 状态.饥饿, 永不否决, AI动作状态机.撤离, AI动作.等待;
			//决策(士气触发器, 场景, 状态.士气低, 永不否决, AI动作状态机.撤离, AI动作.等待);
			//决策(攻击.放箭, 场景, 军令.放箭, 永不否决, AI动作状态机.撤离, AI动作.等待);

			决策(退场触发器, 场景, 军令.撤离, 永不否决, AI动作状态机.撤离, AI动作状态机.等待);
			决策(缺箭, 场景, 状态.士气低, 永不否决, AI动作状态机.撤离, AI动作状态机.等待);
			决策(变换阵型.方阵, 场景, 军令.变换方阵, 永不否决, AI动作状态机.得令, AI动作状态机.等待);
			*/

#endif
			//决策(变换阵型.圆阵, 场景, 军令.变换圆阵, 永不否决, AI动作.得令, AI动作.等待, 6);

#endif

			//代量(军令表达式);
			//代量(军令表达式);
			//代量(军令表达式1);
			//代量(军令表达式2);
			//代量(军令表达式2);
			//代量(军令表达式2);
			//代量(进场触发器);


			//泛量(水, 1, 2, 3, 4, 5, 6, 7, 8, 9);
			//定义表达式(乘法表, 泛型计算, 式(乘, 泛量(水), 泛量(水)));
			//调试打印(乘法表);
			//*/
		易经机定义结束;
	}
	void 刀盾兵()
	{
		易经机定义开始(刀盾兵AI, 动作序列);

		
		
		定义表达式(永不否决, 动作指令, 式(等于, 常数量(2), 常数量(1)));
		
		定义表达式(条件.复活, 动作指令, 式(等于, 内量(角色.状态), 角色状态_死亡)); 
		定义量(军令.锁, 动作指令, 符量(解锁));

		定义量(状态.军令, 状态信息, 符量(初始状态));// 代量(状态.军令);
		
		定义表达式(条件.进攻, 动作指令, 式(与, 式(等于, 代量(许褚AI.刀盾兵.军令), 符量(进攻)), 式(与, 式(等于, 代量(状态.军令), 符量(防护待命)),
			式(大于, 代量(许褚AI.刀盾兵.军令.粮草数量), 常数量(4)))));

		定义表达式(条件.准备阵型, 动作指令, 式(或, 式(等于, 代量(许褚AI.刀盾兵.军令), 符量(准备阵型)),
			式(等于, 代量(状态.军令), 符量(复活结束))
		));
		
		定义表达式(条件.防护待命, 动作指令,
			式(与, 式(等于, 代量(许褚AI.刀盾兵.军令), 符量(防护待命)),
				式(不等于, 代量(状态.军令), 符量(防护待命))));
		

		定义表达式(调试条件, 动作指令, 式(或, 式(大于, 代量(许褚AI.弓箭兵.待命数量), 常数量(65535)), 式(小于, 代量(许褚AI.刀盾兵.待命数量), 常数量(4))));
		//定义表达式(调试条件, 动作指令, 式(不等于, 代量(状态.军令), 符量(拉弓待命)));
		易经条件日志(调试日志, 代量(调试条件), 常字符串量("生命周="), 代量(许褚AI.生命周), 常字符串量(" 当前军令="), 代量(许褚AI.刀盾兵.军令), 代量(状态.军令),
			常字符串量(" 仓库弓箭数="), 代量(许褚AI.刀盾兵.军令.粮草数量), 常字符串量(" 待命弓箭手数="), 代量(许褚AI.刀盾兵.待命数量)
		);

		引擎函数(表情.防护, 符量(表情), 动作_跳);
		引擎函数(动作.攻击, 符量(射击), 动作_攻击);
		引擎函数(动作.复活, 符量(复活), 动作_空翻);
		引擎函数(表情.装死, 符量(表情), 动作_倒地);
		引擎函数(表情.复活, 符量(表情), 动作_敬礼);

		被动序列(AI动作.进攻, 动作指令,
			//五行(迁移, 代量(军令.锁), 符量(上锁)), 
			//五行(动作, 代量(调试日志)),
			五行(迁移, 代量(状态.军令), 符量(进攻)),

			五行(聚散, 代量(许褚AI.刀盾兵.防守待命数量), 常数量(-1)),
			五行(聚散, 代量(许褚AI.刀盾兵.军令.粮草数量), 常数量(-1)),
			//五行(动作, 代量(调试日志)),
			
			随机待命毫秒数(2000, 1000),
			五行(动作, 代量(动作.攻击)),
			随机待命毫秒数(2000, 1000),
			//五行(聚散, 代量(许褚AI.弓箭兵.待命数量), 常数量(1)),
			五行(迁移, 代量(状态.军令), 符量(初始状态))
			//五行(迁移, 代量(军令.锁), 符量(解锁))
		);

		被动序列(AI动作.待命, 动作指令,
			//五行(迁移, 代量(军令.锁), 符量(上锁)),
			五行(迁移, 代量(状态.军令), 符量(准备防护)),
			五行(聚散, 代量(许褚AI.刀盾兵.防守待命数量), 常数量(1)),
			随机待命毫秒数(3000, 1000),
			五行(动作, 代量(表情.防护)),
			随机待命毫秒数(3000, 1000),
			//待命毫秒数(1000),
			
			五行(迁移, 代量(状态.军令), 符量(防护待命))//,

			//五行(迁移, 代量(军令.锁), 符量(解锁))
			//
		);
		引擎函数(移动到阵型目标, 符量(移动), 常数量(1));

		被动序列(AI动作.准备阵型, 动作指令,
			五行(迁移, 代量(状态.军令), 符量(准备阵型中)),
			随机待命毫秒数(3000, 1000),
			五行(动作, 代量(移动到阵型目标)),
			
			随机待命毫秒数(3000, 1000),

			五行(迁移, 代量(状态.军令), 符量(准备阵型结束)),
			五行(聚散, 代量(许褚AI.刀盾兵.阵型待命数), 常数量(1))
		);

		被动序列(AI动作.等待, 动作指令,
			五行(迁移, 代量(状态.军令), 符量(空闲等待)),
			随机待命毫秒数(3000, 1000),
			随机待命毫秒数(3000, 1000),
			五行(迁移, 代量(状态.军令), 符量(空闲等待结束))
		);

		定义表达式(AI动作.等待, 动作指令, 式(加, 常数量(1), 常数量(3)));
		被动序列(AI动作.复活, 动作指令,
			五行(迁移, 代量(状态.军令), 符量(准备复活中)),
			五行(聚散, 代量(许褚AI.刀盾兵.阵型待命数), 常数量(-1)),
			五行(聚散, 代量(许褚AI.刀盾兵.总计复活数), 常数量(1)),
			五行(聚散, 代量(许褚AI.刀盾兵.待复活数), 常数量(1)),
			随机待命毫秒数(30000, 5000),
			//五行(迁移, 内量(角色.状态), 角色状态_等待),
			五行(动作, 代量(动作.复活)),
			五行(聚散, 代量(许褚AI.刀盾兵.待复活数), 常数量(-1)),
			随机待命毫秒数(1500, 500),
			五行(动作, 代量(表情.复活)),
			

			五行(迁移, 代量(状态.军令), 符量(复活结束))
		);
		
		决策(决策.复活, 场景, 条件.复活, 永不否决, AI动作.复活, AI动作.等待);

		决策(决策.待命, 场景, 条件.防护待命, 永不否决, AI动作.待命, AI动作.等待);
		决策(决策.进攻, 场景, 条件.进攻, 永不否决, AI动作.进攻, AI动作.等待);
		决策(决策.准备阵型, 场景, 条件.准备阵型, 永不否决, AI动作.准备阵型, AI动作.等待);


		易经机定义结束;
	}

	void 定义地()
	{
		切换域(易经::地);
		诸葛亮();
		许褚();
		周瑜();
	}

	void 定义人()
	{
		//切换系统(_易经系统);
		切换域(易经::人);
		
		弓箭手();
		刀盾兵();

	}
	void 构造天()
	{
		_易经系统._构造易经机(易经::天, "玉帝AI", 0, 0, 0, "玉帝AI", NULL);
	}
	void 构造地()
	{
		_易经系统._构造易经机(易经::地, "诸葛亮AI", 1, 0, 0, "诸葛亮AI", NULL);
		_易经系统._构造易经机(易经::地, "许褚AI", 2, 0, 0, "许褚AI", NULL);
	}
#ifdef 巨页内存
	//vector<弓箭手状态机, yss_allocator<弓箭手状态机, MemoryMgr_FreeListSmall>> m_弓箭手;
#else
	//vector<弓箭手状态机> m_弓箭手;
#endif
	void Make()
	{
		构造天();
		构造地();
		//for (unsigned int n = 0; n < 65536; n++)
		{
			//构造人();
		}
	}
public:
	void CacheAI(unsigned int nAIID)
	{

	}
	string GetAiName(char * pAIName)
	{
		char szAiName[512] = { 0 };
		for (unsigned int i = 0, p = 0; pAIName[i]; i++)
		{
			if (pAIName[i] < 0)
			{
				char szTmp[4];
				szAiName[p++] = 'H';
				szAiName[p++] = 'U';
				sprintf(&szTmp[0], "%02hhx", pAIName[i]);
				szAiName[p++] = szTmp[0];
				szAiName[p++] = szTmp[1];
			}
			else
			{
				szAiName[p++] = pAIName[i];
			}
		}
		return string(szAiName);
	}

	unsigned int MakeManAI(char * szManAIName,void * pMachineState,unsigned int nNature=0,unsigned int nSociety=1)
	{
		//m_弓箭手.resize(易经机数量);
		//_易经系统._构造易经机(易经::人, "弓箭手AI", 2, 0, 1, "弓箭手AI", &m_弓箭手[2]);
		//for (int i = 3; i < 易经机数量;i++)
#ifdef _USING_UFT8CODE_
		string szAiName = GetAiName(szManAIName);
#else
		string szAiName = szManAIName;
#endif

		{
			
			//_易经系统._构造易经机(易经::人, "AI", i, 易经::人, "弓箭手AI", &m_弓箭手[i]);
			return _易经系统._从模板构造易经机(易经::人, szAiName.c_str(), pMachineState, nNature, nSociety);
		}
		//_易经系统._构造易经机(易经::人, "AI", 1, 易经::人, "弓箭手AI");
	}

	unsigned int MakeTerrainAI(char * szManAIName, void * pMachineState, unsigned int nNature = 0, unsigned int nSociety = 0)
	{
		//m_弓箭手.resize(易经机数量);
		//_易经系统._构造易经机(易经::人, "弓箭手AI", 2, 0, 1, "弓箭手AI", &m_弓箭手[2]);
		//for (int i = 3; i < 易经机数量;i++)
#ifdef _USING_UFT8CODE_
		string szAiName = GetAiName(szManAIName);
#else
		string szAiName = szManAIName;
#endif
		{

			//_易经系统._构造易经机(易经::人, "AI", i, 易经::人, "弓箭手AI", &m_弓箭手[i]);
			return _易经系统._从模板构造易经机(易经::地, szAiName.c_str(), pMachineState, nNature, nSociety);
		}
		//_易经系统._构造易经机(易经::人, "AI", 1, 易经::人, "弓箭手AI");
	}

	void 调试定义()
	{
		_易经系统.调试_量定义();
	}
	void 调试实例()
	{
		_易经系统.调试_量实例();
	}
	ULONGLONG 用时;
	void Begin()
	{
		if ((_易经系统.m_生命 % 易经机测试循环数) == 1)
		{
			用时 = ::GetTickCount64us();
		}
		_易经系统.m_生命++;
		_易经系统.激励((unsigned int)0, true);
		_易经系统.激励((unsigned int)1, true);
		_易经系统.激励((unsigned int)2, true);
#ifdef 统计信息
		_易经系统.m_求值数_表达式 = _易经系统.m_求值数_决策器 = _易经系统.m_求值数_状态机 = _易经系统.m_求值数_表达式求值 = 0;
#endif
	}
	void End()
	{
		

#ifdef 统计信息
		if ((_易经系统.m_生命 % 易经机测试循环数) == 1)
		{
			用时 = ::GetTickCount64us() - 用时;
			ULONGLONG 每周指令执行数 = _易经系统.m_求值数_表达式 + _易经系统.m_求值数_决策器 + _易经系统.m_求值数_状态机 + _易经系统.m_求值数_表达式求值;
			_易经系统.易经机日志("易经机数量(%u)生命周数(%0.2f) 用时%llums %.4f兆步数每秒 表决状总(%llu(%llu)-%llu-%llu-%llu) %.2fMips\r\n",
				_易经系统.m_易经机实例表.size(), ((double)易经机测试循环数 * 1000) / (double)(用时 / 1000), 用时 / 1000, ((double)易经机测试循环数 * _易经系统.m_易经机实例表.size()) / 用时,
				_易经系统.m_求值数_表达式, _易经系统.m_求值数_表达式求值, _易经系统.m_求值数_决策器, _易经系统.m_求值数_状态机,
				每周指令执行数, ((double)易经机测试循环数 * 每周指令执行数) / 用时);
		}
		

#else
		//_易经系统.易经机日志("易经机数量(%u)激励次数(%u) 用时%llums %.4fM步数每秒\r\n", 易经机数量, 易经机测试循环数, 用时/1000, ((double)易经机测试循环数 * 易经机数量) / 用时);
#endif
	}
	unsigned int GetAIStepTimeout()
	{
		return 1000000 / 易经机周数;
	}
	void Action(unsigned int i,bool bLock=false)
	{
		_易经系统.激励(i, bLock);
	}

	void Action()
	{
#ifdef 统计信息
		_易经系统.m_求值数_表达式 = _易经系统.m_求值数_决策器 = _易经系统.m_求值数_状态机 = _易经系统.m_求值数_表达式求值 = 0;
#endif
		_易经系统.激励();
	}

	void Init(unsigned int nContainerID, ManT * pManSystem)
	{
		_易经系统.m_容器ID = nContainerID;
		_易经系统.初始化(pManSystem);
		系统初始化();
		//m_pManSystem = pManSystem;

	};
	template<typename ObjectManT>
	void BindMan()
	{
		/*
		绑定引用(易经::人, 军令, 角色NPC, 角色状态, 军令);
		绑定引用(易经::人, 军令.目标坐标, 角色NPC, 角色状态, 军令.目标坐标);
		绑定整数32(易经::人, 军令.目标, 角色NPC, 角色状态, 军令.目标);
		绑定整数32(易经::人, 军令.状态, 角色NPC, 角色状态, 军令.状态);
		绑定引用(易经::人, 角色坐标, 角色NPC, 角色状态, 角色坐标);
		绑定整数32(易经::人, 状态, 角色NPC,角色状态, 状态);
		绑定整数64(易经::人, 角色年龄, 角色NPC, 角色状态, 年龄);
		绑定位(易经::人, 内部状态.离线, 角色NPC, 角色状态, 内部状态.离线);
		绑定引用(易经::人, 角色内部状态, 角色NPC, 角色状态, 内部状态);
		*/
	}
	void Init1()
	{
		
		定义天();
		定义地();
		定义人();

		Make();

	};
	void Info()
	{
		_易经系统.调试_输出符号代码();
		//测试定义();
		调试定义();
		
#ifdef 调试模式
		调试实例();

#endif
		_易经系统.调试_量实例求值表();
	}
	
};

void TestModernWarAI()
{
	ModernWarAI<int> AI;
	AI.Init(0,NULL);
	AI.Init1();
	ULONGLONG 用时 = ::GetTickCount64us();
	for (int i = MAN_AI_BASE_POS+1; i < 易经机数量; i++)
	{

		//_易经系统._构造易经机(易经::人, "AI", i, 易经::人, "弓箭手AI", &m_弓箭手[i]);
		AI.MakeManAI("弓箭手AI", NULL);
	}
	AI.Info();

	//_易经系统.易经机日志("易经机构造 用时%ums %u size=%uMB\r\n",用时/1000, 易经机数量, 易经机数量*sizeof(ModernWarAI::弓箭手状态机)/(1024*1024));
	//if(易经机数量<4)AI.调试实例();
	//AI._易经系统.调试_量实例求值表();
	//AI.激励();
	//AI.激励();
#ifndef 易经机测试不循环
	for (;;)
#endif
	{
		
		for (unsigned int i=0;i< 易经机数量;i++)
		{
			//Sleep(10);

			AI.Action(i);
		}
		AI.End();
		AI.Begin();
		
	}
}


template <typename _ManT>
void ModernWarAI<_ManT>::系统初始化()
{
	//初始化内部变量,绑定导出变量函数
	切换系统(_易经系统);
	//内部符号(大于,小于,等于,大于等于,小于等于,加,减,乘,除, 进栈, 出栈);
	//_绑定静态函数<移动函数>(易经::天, "内置_移动函数", 0);
	绑定函数(易经::天, _引擎函数, 0);
	追加符量(移动); 追加符量(表情); 追加符量(射击);
	绑定位(易经::地, 角色.状态, 角色NPC, MAN, m_ManState.nState);
	//_易经系统._绑定浮点(易经::人, "角色坐标X", 量偏移(角色状态, 坐标X), "角色NPC");
	/*
	绑定引用(易经::人, 军令, 角色NPC, 角色状态, 军令);
	绑定引用(易经::人, 军令.目标坐标, 角色NPC, 角色状态, 军令.目标坐标);
	绑定整数32(易经::人, 军令.目标, 角色NPC, 角色状态, 军令.目标);
	绑定整数32(易经::人, 军令.状态, 角色NPC, 角色状态, 军令.状态);
	绑定引用(易经::人, 角色坐标, 角色NPC, 角色状态, 角色坐标);
	绑定整数32(易经::人, 状态, 角色NPC,角色状态, 状态);
	绑定整数64(易经::人, 角色年龄, 角色NPC, 角色状态, 年龄);
	绑定位(易经::人, 内部状态.离线, 角色NPC, 角色状态, 内部状态.离线);
	绑定引用(易经::人, 角色内部状态, 角色NPC, 角色状态, 内部状态);
	*/
}

#ifdef 脱机调试模式
激励结果 _引擎函数::激励(void* p系统, void* p状态机, 向量型& _向量)
{
	((易经系统*)p系统)->易经机日志("_移动函数 %u %p", _向量.向量列表.size(), ((易经系统*)p系统)->m_pSystem);
	return 成功;
}
#endif
