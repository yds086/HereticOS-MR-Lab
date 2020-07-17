#pragma once
#include "GameResLib.h"



//MOD版本号
#define MOD_VER			20200518
//MOD产品ID
#define MOD_PUBID		"AF0E7E87-A856-4EED-9121-C61294A46A9C"
//MOD名称
#define MOD_NAME		"黎明曙光"

#define MOD_DESC		\
"\r\n  死亡吧,死亡才能迎来赞叹,覆灭吧,覆灭才是真正的救赎,唯有黑暗才能带了曙光,当沉沦至无法沉沦之际,神之恩典将自最幽微之处升起,照耀在骨骸堆积的山头---续亡之歌\r\n\r\n"\
"  本MOD主要展示异数OS MR Lab中的各项战争体验特性，感兴趣的可加入MOD QQ群参加MOD制作 739924481\r\n\r\n"\
"免责声明:\r\n  本MOD属于免费MOD，所有素材资料来自网络，仅用于研究学习，如有侵权请联系大雪原工作室。\r\n\r\n"\
"  Death can bring praise, destruction can bring real salvation. Only darkness can bring dawn. When the destruction is impossible, God's grace will rise from the most remote place and shine on the mountain where bones are piled up - the song of continued death\r\n\r\n"\
"Disclaimer:\r\n  This mod belongs to free mod. All materials are from the Internet and are only used for research and learning. If there is any infringement, please contact Da Xueyuan studio."\

#define MOD_DIR		"Dawn"

#define MOD_HELP	"操作界面分为四个部分,分别为电池蓄能,主电容蓄能,技能电容蓄能,动作控制器。\r\n\r\n操作说明\r\n\r\n1.电池蓄能，右边容器为电池能量槽，自动蓄能。\r\n"\
"2.主电容蓄能\r\n"\
"空格键(Space)         使用电池为主电容充电\r\n"\
"3.技能电容蓄能\r\n"\
"键盘1-4               使用主电容为技能电容充电，同时会开启电池为主电容蓄能\r\n"\
"4.动作控制\r\n"\
"W S D A               前后左右移动\r\n"\
"↑ ↓                 上下移动\r\n"\
"Page up   Page Down   仰角调整\r\n\r\n\r\n"\
"The operation interface is divided into four parts: battery energy storage, main capacitance energy storage, skill capacitance energy storage and action controller.\r\n\r\nOperating instructions\r\n\r\n1.Battery energy storage, the right container is battery energy tank, automatic energy storage.\r\n"\
"2.main capacitance energy storage\r\n"\
"Space Key    Use battery to charge main capacitor\r\n"\
"3.skill capacitance energy storage\r\n"\
"1-4 Key      Use the main capacitor to charge the skill capacitor and turn on the battery to store energy\r\n"\
"4.action controller\r\n"\
"W S D A      Move backand forth leftand right\r\n"\
"↑ ↓        Move up and down\r\n"\
"Page up Page Down   Elevation adjustment\r\n"\

#define TA2_LEVEL_HIGH 60


class ResData :public GameResLib
{
public:
	ResData() {};
	~ResData() {};
	

	static ResData & GetInstance()
	{
		static ResData _self;
		return _self;
	}
	//春
	void InitMod1()
	{
		ModInfo(MOD_VER, MOD_NAME, "春", MOD_DESC, "\r\n  春天的战争", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{_T("data/")_T(MOD_DIR)_T("/images/1RBack.bmp")},
			{"data/Dawn/images/1Front.bmp"},
			{"data/Dawn/images/1Top.bmp"},
			{"data/Dawn/images/1Left.bmp"},
			{"data/Dawn/images/1Right.bmp"},
			{"data/Dawn/images/sand1.bmp"},//地面
			{NULL}
		};
		SaveRes(MOD_DIR, 1);
	}
	//夏
	void InitMod2()
	{
		ModInfo(MOD_VER, MOD_NAME, "夏", MOD_DESC, "\r\n  夏天的战争", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{"data/Dawn/images/2RBack.bmp"},
			{"data/Dawn/images/2Front.bmp"},
			{"data/Dawn/images/2Top.bmp"},
			{"data/Dawn/images/2Left.bmp"},
			{"data/Dawn/images/2Right.bmp"},
			{"data/Dawn/images/sand2.bmp"},//地面
			{NULL}
		};
		SaveRes(MOD_DIR, 2);
	}
	//秋
	void InitMod3()
	{
		ModInfo(MOD_VER, MOD_NAME, "秋", MOD_DESC, "\r\n  秋天的战争", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{"data/Dawn/images/3RBack.bmp"},
			{"data/Dawn/images/3Front.bmp"},
			{"data/Dawn/images/3Top.bmp"},
			{"data/Dawn/images/3Left.bmp"},
			{"data/Dawn/images/3Right.bmp"},
			{"data/Dawn/images/sand3.bmp"},//地面
			{NULL}
		};
		SaveRes(MOD_DIR, 3);
	}
	//冬
	void InitMod4()
	{
		ModInfo(MOD_VER, MOD_NAME, "冬", MOD_DESC, "\r\n  冬天的战争", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{"data/Dawn/images/4RBack.bmp"},
			{"data/Dawn/images/4Front.bmp"},
			{"data/Dawn/images/4Top.bmp"},
			{"data/Dawn/images/4Left.bmp"},
			{"data/Dawn/images/4Right.bmp"},
			{"data/Dawn/images/sand4.bmp"},//地面
			{NULL}
		};
		SaveRes(MOD_DIR, 4);
	}
	bool Init(char * pModName, unsigned int nSubMod,bool bInitMod=false)
	{
		if (bInitMod)
		{
			
		}
		else
		{
			if (LoadRes(pModName, nSubMod))
			{
				return true;
			}
		}


		gGarrisonSoldiers.push_back({
			{"启航战船","城墙右臂",800,0,0,"弓箭兵",1,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"启航战船","城墙左臂",800,0,0,"弓箭兵",2,0,0,0},//巨型单位坐标系，向单位所属巨型单位坐标x偏移500 z偏移30方向射击
			{"启航战船","集结场地",3000,0,0,"弓箭兵",4,0,0,0},//世界坐标系，向单位自身坐标x偏移1000方向射击
			{NULL,NULL,1000,0,0,""}
		});

		gGarrisonSoldiers.push_back({
			{"海盗战船","城墙右臂",800,0,0,"弓箭兵",5,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"海盗战船","城墙左臂",800,0,0,"弓箭兵",6,0,0,0},//巨型单位坐标系，向单位所属巨型单位坐标x偏移500 z偏移30方向射击
			{"海盗战船","集结场地",3000,0,0,"弓箭兵",7,0,0,0},//世界坐标系，向单位自身坐标x偏移1000方向射击
			{NULL,NULL,1000,0,0,""},
		});

		gGarrisonSoldiers.push_back({
			{"周瑜战船","城墙右臂",800,0,0,"弓箭兵",5,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"周瑜战船","城墙左臂",800,0,0,"弓箭兵",6,0,0,0},//巨型单位坐标系，向单位所属巨型单位坐标x偏移500 z偏移30方向射击
			{"周瑜战船","集结场地",3000,0,0,"弓箭兵",7,0,0,0},//世界坐标系，向单位自身坐标x偏移1000方向射击
			{NULL,NULL,1000,0,0,""},
		});
#define TA_UNIT_COUNT 120
#define TA_UNIT_COUNT2 260

		gGarrisonSoldiers.push_back( {
			{"塔楼3-1","东-1",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-1","东-2",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-1","东-3",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-1","东-4",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-1","东-5",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-1","东-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},

			{"塔楼3-1","西-1",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-1","西-2",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-1","西-3",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-1","西-4",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-1","西-5",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-1","西-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},

			{"塔楼3-1","南-1",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-1","南-2",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-1","南-3",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-1","南-4",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-1","南-5",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-1","南-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},

			{"塔楼3-1","北-1",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-1","北-2",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-1","北-3",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-1","北-4",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-1","北-5",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-1","北-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},
			{NULL,NULL,1000,0,0,""},
		});

		gGarrisonSoldiers.push_back({
			{"塔楼3-2","东-1",TA_UNIT_COUNT2,0,0,"弓箭兵",8,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-2","东-2",TA_UNIT_COUNT2,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-2","东-3",TA_UNIT_COUNT2,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-2","东-4",TA_UNIT_COUNT2,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-2","东-5",TA_UNIT_COUNT2,0,0,"弓箭兵",14,0,0,0},
			{"塔楼3-2","东-6",TA_UNIT_COUNT2,0,0,"弓箭兵",13,0,0,0},

			{"塔楼3-2","西-1",TA_UNIT_COUNT2,0,0,"弓箭兵",9,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-2","西-2",TA_UNIT_COUNT2,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-2","西-3",TA_UNIT_COUNT2,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-2","西-4",TA_UNIT_COUNT2,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-2","西-5",TA_UNIT_COUNT2,0,0,"弓箭兵",13,0,0,0},
			{"塔楼3-2","西-6",TA_UNIT_COUNT2,0,0,"弓箭兵",14,0,0,0},

			{"塔楼3-2","南-1",TA_UNIT_COUNT2,0,0,"弓箭兵",10,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-2","南-2",TA_UNIT_COUNT2,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-2","南-3",TA_UNIT_COUNT2,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-2","南-4",TA_UNIT_COUNT2,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-2","南-5",TA_UNIT_COUNT2,0,0,"弓箭兵",14,0,0,0},
			{"塔楼3-2","南-6",TA_UNIT_COUNT2,0,0,"弓箭兵",13,0,0,0},

			{"塔楼3-2","北-1",TA_UNIT_COUNT2,0,0,"弓箭兵",11,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-2","北-2",TA_UNIT_COUNT2,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-2","北-3",TA_UNIT_COUNT2,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-2","北-4",TA_UNIT_COUNT2,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-2","北-5",TA_UNIT_COUNT2,0,0,"弓箭兵",13,0,0,0},
			{"塔楼3-2","北-6",TA_UNIT_COUNT2,0,0,"弓箭兵",14,0,0,0},
			{NULL,NULL,1000,0,0,""},
		});

		gGarrisonSoldiers.push_back({
			{"塔楼3-3","东-1",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-3","东-2",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-3","东-3",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-3","东-4",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-3","东-5",TA_UNIT_COUNT,0,0,"弓箭兵",8,0,0,0},
			{"塔楼3-3","东-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},

			{"塔楼3-3","西-1",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-3","西-2",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-3","西-3",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-3","西-4",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-3","西-5",TA_UNIT_COUNT,0,0,"弓箭兵",9,0,0,0},
			{"塔楼3-3","西-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},

			{"塔楼3-3","南-1",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-3","南-2",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-3","南-3",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-3","南-4",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-3","南-5",TA_UNIT_COUNT,0,0,"弓箭兵",10,0,0,0},
			{"塔楼3-3","南-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},

			{"塔楼3-3","北-1",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},//巨型单位坐标系，向单位自身坐标x偏移-100 z偏移30方向射击
			{"塔楼3-3","北-2",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-3","北-3",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-3","北-4",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-3","北-5",TA_UNIT_COUNT,0,0,"弓箭兵",11,0,0,0},
			{"塔楼3-3","北-6",TA_UNIT_COUNT,0,0,"弓箭兵",12,0,0,0},
			{NULL,NULL,1000,0,0,""},
		});

		unsigned int nSelectPos = 0;
		unsigned int nSelectInfoPos = 0;
		gTerrainSelectArray.push_back(
		{
			{"1", 33, 73.5, -60, 14, 3, -368, SceneContext::eCollisionObject_Land},
			{ "2",33, 73.5, -487, 14, 3, -100,SceneContext::eCollisionObject_Land },
			{ "3",9, 73.5, -417, 13, 3, -79,SceneContext::eCollisionObject_Land },
				//{"4",48, 73.5, -424, 12, 3, -66,SceneContext::eCollisionObject_Land},
			{ "4",48, 73.5, -424, 18, 3, -66,SceneContext::eCollisionObject_Land },
			{ NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land }
		});
		gTerrainSelectArray.push_back(
		{
			{"1",558, 73.5, -59, 14, 3, -78,SceneContext::eCollisionObject_Land},
			{"2",558, 73.5, -196, 14, 3, -440,SceneContext::eCollisionObject_Land},
			{"3",533.5, 73.5, -126.5, 14, 3, -82,SceneContext::eCollisionObject_Land},
			{"4",571, 73.5, -134.5, 18, 3, -66,SceneContext::eCollisionObject_Land},
			{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}
		});
		gTerrainSelectArray.push_back(
		{
			{"2",45, 33, -57, 60, 7, -285,SceneContext::eCollisionObject_Land},
			{"3",148, 37.5, -57, 350, 3, -93,SceneContext::eCollisionObject_Land},
			{"4",410, 38.5, -155, 90, 3, -175,SceneContext::eCollisionObject_Land},
			//{"1",150, 28.5, -99, 200, 3, -200,SceneContext::eCollisionObject_Land},

			{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}
		});
		RectRangeBegin(2);
		MakeRectRange(2, 1, 96 + 8, (87 + 7), 10, 218 - 4, -221, (102 + (0 * TA2_LEVEL_HIGH)) - 2, 3);
		MakeRectRange(2, 2, 96, 87 - 1, 10, 218, -221 - 4, (102 + (1 * TA2_LEVEL_HIGH)) + 1, 3);
		MakeRectRange(2, 3, 96 - 1, 87 - 3, 10, 218 + 1, -221 - 6, (102 + (2 * TA2_LEVEL_HIGH)) - 1, 3);
		MakeRectRange(2, 4, 96 - 6, 87 - 7, 9, 218 + 3, -221 - 8, (102 + (3 * TA2_LEVEL_HIGH)) - 5, 3);
		MakeRectRange(2, 5, 96 - 9, 87 - 10, 9, 218 + 5, -221 - 10, (102 + (4 * TA2_LEVEL_HIGH)) - 10, 3);
		MakeRectRange(2, 6, 96 - 15, 87 - 16, 9, 218 + 8, -221 - 13, (102 + (5 * TA2_LEVEL_HIGH)) - 18, 3);
		RectRangeEnd(2);

		gTerrainSelectInfoArray.push_back(
		{
			SELECT_RANGE_DEF("城墙右臂",gTerrainSelectArray[0]),
			SELECT_RANGE_DEF("城墙左臂",gTerrainSelectArray[1]),
			SELECT_RANGE_DEF("集结场地",gTerrainSelectArray[2]),
			{NULL,NULL},
		});

		gShootRangeRes= { BEINRANGE,
			SHOOTRANGE("城墙右臂",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_ALL,-200,30,50),
			SHOOTRANGE("城墙左臂",ShootRangeType_LargeUnit,ShootRangeRefType_OwnerUnit,ShootDstType_ALL,900,-330,50),
			SHOOTRANGE("集结场地",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_ALL,1000,0,500),
			SHOOTRANGE("集结场地1",ShootRangeType_World,ShootRangeRefType_OwnerUnit,ShootDstType_LargeUnit,1200,0,100),

			SHOOTRANGE("城墙右臂",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,-200,30,80),
			SHOOTRANGE("城墙左臂",ShootRangeType_LargeUnit,ShootRangeRefType_OwnerUnit,ShootDstType_BaseUnit,900,-330,50),
			SHOOTRANGE("集结场地",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-1200,0,30),

			SHOOTRANGE("塔楼3-东",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,300,0,100),
			SHOOTRANGE("塔楼3-西",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,-400,0,100),
			SHOOTRANGE("塔楼3-南",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,0,300,100),
			SHOOTRANGE("塔楼3-北",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,0,-400,100),
			SHOOTRANGE("塔楼3-1",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-1200,0,100),
			SHOOTRANGE("塔楼3-2-1",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-1200,-600,100),
			SHOOTRANGE("塔楼3-2-2",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-2700,0,100),
		};

		gTerrainSelectInfoArray.push_back( 
		{
			SELECT_RANGE_DEF("东-1",gTerrainSelectArray[RectRangePos(2,1,0)]),
			SELECT_RANGE_DEF("南-1",gTerrainSelectArray[RectRangePos(2,1,1)]),
			SELECT_RANGE_DEF("西-1",gTerrainSelectArray[RectRangePos(2,1,2)]),
			SELECT_RANGE_DEF("北-1",gTerrainSelectArray[RectRangePos(2,1,3)]),
			SELECT_RANGE_DEF("东-2",gTerrainSelectArray[RectRangePos(2,2,0)]),
			SELECT_RANGE_DEF("南-2",gTerrainSelectArray[RectRangePos(2,2,1)]),
			SELECT_RANGE_DEF("西-2",gTerrainSelectArray[RectRangePos(2,2,2)]),
			SELECT_RANGE_DEF("北-2",gTerrainSelectArray[RectRangePos(2,2,3)]),
			SELECT_RANGE_DEF("东-3",gTerrainSelectArray[RectRangePos(2,3,0)]),
			SELECT_RANGE_DEF("南-3",gTerrainSelectArray[RectRangePos(2,3,1)]),
			SELECT_RANGE_DEF("西-3",gTerrainSelectArray[RectRangePos(2,3,2)]),
			SELECT_RANGE_DEF("北-3",gTerrainSelectArray[RectRangePos(2,3,3)]),
			SELECT_RANGE_DEF("东-4",gTerrainSelectArray[RectRangePos(2,4,0)]),
			SELECT_RANGE_DEF("南-4",gTerrainSelectArray[RectRangePos(2,4,1)]),
			SELECT_RANGE_DEF("西-4",gTerrainSelectArray[RectRangePos(2,4,2)]),
			SELECT_RANGE_DEF("北-4",gTerrainSelectArray[RectRangePos(2,4,3)]),
			SELECT_RANGE_DEF("东-5",gTerrainSelectArray[RectRangePos(2,5,0)]),
			SELECT_RANGE_DEF("南-5",gTerrainSelectArray[RectRangePos(2,5,1)]),
			SELECT_RANGE_DEF("西-5",gTerrainSelectArray[RectRangePos(2,5,2)]),
			SELECT_RANGE_DEF("北-5",gTerrainSelectArray[RectRangePos(2,5,3)]),
			SELECT_RANGE_DEF("东-6",gTerrainSelectArray[RectRangePos(2,6,0)]),
			SELECT_RANGE_DEF("南-6",gTerrainSelectArray[RectRangePos(2,6,1)]),
			SELECT_RANGE_DEF("西-6",gTerrainSelectArray[RectRangePos(2,6,2)]),
			SELECT_RANGE_DEF("北-6",gTerrainSelectArray[RectRangePos(2,6,3)]),
			{NULL,NULL},
		});
		gSkyRes = {
			{"data/Dawn/images/3RBack.bmp"},
			{"data/Dawn/images/3Front.bmp"},
			{"data/Dawn/images/3Top.bmp"},
			{"data/Dawn/images/3Left.bmp"},
			{"data/Dawn/images/3Right.bmp"},
			{"data/Dawn/images/sand1.bmp"},//地面
			{NULL}
		};
		
		gLargeUnitMod = {
#ifdef UI_EDIT_MODE
			{"塔楼3","data/Dawn/ta/ta3.3ds",5.15,5.15,5.15,-15,-22.5,-6.3},
			//{"主城","data/Dawn/main/main.3ds",0.15,0.15,0.15,0,0,0},
#else
			{"主城","data/Dawn/main/main.3ds",0.15,0.15,0.15,0,0,0},
			{"塔楼2","data/Dawn/ta/ta2.3ds",5.15,5.15,5.15,0,0,0},
			{"塔楼3","data/Dawn/ta/ta3.3ds",5.15,5.15,5.15,-15,-22.5,-6.3},
#endif
			{NULL,NULL}
		};
		gModRes = {
			{SceneRes_Tree,SceneResSub_None,10,10,10,"树0","","data/Dawn/images/CACTUS0.BMP",1,0},
			{SceneRes_Tree,SceneResSub_None,10,10,10,"树1","","data/Dawn/images/CACTUS1.BMP",1,0},
			{SceneRes_Tree,SceneResSub_None,10,10,10,"树2","","data/Dawn/images/CACTUS2.BMP",1,0},
			{SceneRes_Tree,SceneResSub_None,10,10,10,"树3","","data/Dawn/images/CACTUS3.BMP",1,0},
			{SceneRes_Particle,SceneResSub_Explosion,10,10,10,"爆炸","爆炸","data/Dawn/images/explosion1.BMP",1,0},
			//{SceneRes_Particle,SceneResSub_Explosion,1,1,"爆炸","爆炸","data/Dawn/images/explosion0.BMP",1,0},
			//{SceneRes_Particle,SceneResSub_Arrow,1,1,"弓箭","弓箭","data/Dawn/images/explosion0.BMP",1,0},
			{SceneRes_Particle,SceneResSub_Arrow,30,5,5,"弓箭","弓箭","data/Dawn/images/jian.3ds",1,0},
			{SceneRes_Special,SceneResSub_None,10,10,10,"诸葛亮","全军待命","data/Dawn/images/explosion0.BMP",1,0},
			{SceneRes_Special,SceneResSub_None,10,10,10,"诸葛亮","放箭","data/Dawn/images/explosion1.BMP",1,0},

			{SceneRes_Special,SceneResSub_None,10,10,10,"弓箭手","败逃","data/Dawn/images/explosion0.BMP",1,0},
		};

		//定义特写
		//UnitType_AI_Aircraft
		gSpecialRes.push_back(
			
			{
				{50,20,1,"启航战船","诸葛亮","全军待命","爆炸","弓箭手准备,4,3,2,1,0...\r\nArcher preparation,4,3,2,1,0..."},
				{50,15,0,"塔楼3-3","诸葛亮","放箭","爆炸","放...\r\nTo shoot an arrow"}
			}
		);
		//UnitType_AI_Man
		gSpecialRes.push_back(
			{
			{50,20,0,"","弓箭手","败逃","请你让我回家，我的妻儿在等我...\r\nPlease，let me go home,My wife is waiting for me..."}
			}
		);

		gWaveRes = {
			{"雪原背景","data/Dawn/music/daxueyuan.mp3",1.0,true},
			{"灭罪","data/Dawn/music/miezui.mp3",1.0,true},
			{"灭罪1","data/Dawn/music/miezui1.mp3",1.0,true},
			{"一刀","data/Dawn/music/yidao.mp3",0.8,true},
			{"往事","data/Dawn/music/wangshi.mp3",1.0,true},
			{"直升机","data/Dawn/music/zhishengji.mp3",1.0,true},
			{"爆炸3","data/Dawn/music/BOMB3.mp3",1.0,true},
			{"合集","data/Dawn/music/mix.mp3",1.0,true},
			{"雨","data/Dawn/music/yu.mp3",1.0,true},
			{"发射1","data/Dawn/music/WOOSH4.mp3",1.4,true}
		};
		gSoundRes ={
			{"拯救","灭罪",1.0,150,0,0,2},
			{"拯救1","灭罪1",1.0,170,0,0,2},
			{"快战","一刀",1.0,120,0,0,1},
			{"世外","往事",1.0,250,0,0,3},
			{"主角","直升机",1,50,0,55,3},
			{"爆炸","爆炸3",1,1.0,0,0,3},
			{"发射","发射1",1,1.0,0,0,3},
			{"死亡1","合集",1.0,1.0,100,25,3},
			{"死亡2","合集",1.0,1.0,75,25,3},
			{"止战","雨",1.0,300,0,0,3},
		};
#define UNNAME_SEC "无名","",1,UnitType_SceneRes

		g_SceneResTab =
		{
		#ifdef UI_EDIT_MODE
			//{"塔楼23","塔楼3",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,210,0.5,0,0,0,0,&gTerrainSelect2[0],&gGarrisonSoldiers4[0],NULL}
			{"塔楼3-1","塔楼3",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4200,280,1.0,0,0,0,0,& gTerrainSelectInfoArray[1][0],& gGarrisonSoldiers[3][0],NULL,NULL}
			//{"启航战船","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,72.5,1.0,0,5,200,0,& gTerrainSelectInfoArray[0][0],& gGarrisonSoldiers[0][0],NULL,"拯救1"}
		#else

			//Tree
			{UNNAME_SEC,SceneRes_Tree,2500,-3000,0,300,0,0,0,0,NULL,NULL,NULL,NULL},
			{UNNAME_SEC,SceneRes_Tree,2100,-3200,0,300,0,0,0,0,NULL,NULL,NULL,NULL},
			{UNNAME_SEC,SceneRes_Tree,1600,-2000,0,200,0,0,0,NULL,NULL,NULL,NULL},
			{UNNAME_SEC,SceneRes_Tree,2200,0,0,400,0,0,0,0,NULL,NULL,NULL,NULL},
			{UNNAME_SEC,SceneRes_Tree,0,-1500,0,400,0,0,0,0,NULL,NULL,NULL,NULL},
			{UNNAME_SEC,SceneRes_Tree,4900,-1500,0,400,0,0,0,0,NULL,NULL,NULL,NULL},
			//
			{UNNAME_SEC,SceneRes_Tree,1000,-4100,0,400,0,0,0,0,NULL,NULL,NULL,NULL},
			//Terrain

			{"周瑜战船","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,3600,-4800,50,1.0,0,10,0,0,&gTerrainSelectInfoArray[0][0],&gGarrisonSoldiers[2][0],"周瑜AI","快战"},
			{"战场守护船","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,2600,-1500,205,1.0,-90,20,24,0,NULL,NULL,NULL,NULL},
			{"无名","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,800,-1200,550,1.5,90,50,0,0,NULL,NULL,NULL,NULL},
			{"启航战船","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,72.5,1.0,0,5,200,0,&gTerrainSelectInfoArray[0][0],&gGarrisonSoldiers[0][0],NULL,"拯救1"},
			{"海盗战船","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,3500,-4200,145,1.0,45,80,0,0,&gTerrainSelectInfoArray[0][0],&gGarrisonSoldiers[1][0],NULL,"快战"},
			{"避世方舟","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,0,-8200,145,0.8,-45,80,0,0,NULL,NULL,NULL,"世外"},
			{"止战之城","主城",0,UnitType_AI_Aircraft,SceneRes_Terrain,6000,-10200,145,0.8,-45,80,0,0,NULL,NULL,NULL,"止战"},
			//{"周瑜战船",UnitType_AI_Aircraft,SceneRes_Terrain,3800,-1700,600,1.0,0,10,0,0,&gTerrainSelect3[0],&gGarrisonSoldiers3[0],"周瑜AI"},
			//{"周瑜战船",UnitType_AI_Aircraft,SceneRes_Terrain,2000,-1750,400,1.0,0,10,0,0,&gTerrainSelect3[0],&gGarrisonSoldiers3[0],"周瑜AI"},
			//{"启航战船",UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,72.5,1.0,0,5,200,0,&gTerrainSelect1[0],&gGarrisonSoldiers1[0],NULL},
			
			{"塔楼3-1","塔楼3",0,UnitType_AI_Aircraft,SceneRes_Terrain,3500,-3000,280,1.2,0,0,0,0,&gTerrainSelectInfoArray[1][0],&gGarrisonSoldiers[3][0],NULL,NULL},
			{"塔楼3-2","塔楼3",0,UnitType_AI_Aircraft,SceneRes_Terrain,3700,-1000,440,2.0,45,0,0,0,&gTerrainSelectInfoArray[1][0],&gGarrisonSoldiers[4][0],NULL,"拯救1"},
			{"塔楼3-3","塔楼3",0,UnitType_AI_Aircraft,SceneRes_Terrain,2000,-1500,240,1.0,180,0,0,0,&gTerrainSelectInfoArray[1][0],&gGarrisonSoldiers[5][0],NULL,"拯救"},

			
			//{"启航战船","主城",0,UnitType_SceneRes,SceneRes_Terrain,2200,-4300,22.5,1.0,-90,0,0,0,&gTerrainSelect1[0],&gGarrisonSoldiers1[0],NULL},

			
			

			{"塔楼22","塔楼2",0,UnitType_AI_Aircraft,SceneRes_Terrain,1455,-4300,162,1.0,0,0,0,0,NULL,NULL,NULL}
			
			//{"塔楼23","塔楼3-3",0,UnitType_SceneRes,SceneRes_Terrain,3600,-3000,210,1.0,0,0,0,0,&gTerrainSelect2[0],&gGarrisonSoldiers4[0],NULL},
			//{"塔楼23","塔楼3-4",0,UnitType_SceneRes,SceneRes_Terrain,3600,-3000,210,1.0,0,0,0,0,&gTerrainSelect2[0],&gGarrisonSoldiers4[0],NULL},
		#endif

			
			//{"塔楼22","塔楼2",0,UnitType_SceneRes,SceneRes_Terrain,1000,-500,250,1.0,90,5,0,0,NULL,NULL,NULL},
			//{"塔楼23","塔楼3",0,UnitType_SceneRes,SceneRes_Terrain,2800,-500,250,1.0,90,5,0,0,NULL,NULL,NULL}
		};
		InitMod1();
		InitMod2();
		InitMod3();
		InitMod4();
		
		return bInitMod ? true : false;
	}
private:

};


//塔楼2





/*
static SelectRange gTerrainSelect2_2_1[] = {
	{"1",558, 73.5, -59, 14, 3, -78,SceneContext::eCollisionObject_Land},
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}
};
static SelectRange gTerrainSelect2_2_2[] = {
	{"1",558, 73.5, -59, 14, 3, -78,SceneContext::eCollisionObject_Land},
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}
};
static SelectRange gTerrainSelect2_2_3[] = {
	{"1",558, 73.5, -59, 14, 3, -78,SceneContext::eCollisionObject_Land},
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}
};
static SelectRange gTerrainSelect2_2_4[] = {
	{"1",558, 73.5, -59, 14, 3, -78,SceneContext::eCollisionObject_Land},
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}
};*/





