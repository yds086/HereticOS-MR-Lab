#pragma once
#include "GameResLib.h"



//MOD�汾��
#define MOD_VER			20200518
//MOD��ƷID
#define MOD_PUBID		"AF0E7E87-A856-4EED-9121-C61294A46A9C"
//MOD����
#define MOD_NAME		"�������"

#define MOD_DESC		\
"\r\n  ������,��������ӭ����̾,�����,������������ľ���,Ψ�кڰ����ܴ������,���������޷�����֮��,��֮���佫������΢֮������,��ҫ�ڹǺ��ѻ���ɽͷ---����֮��\r\n\r\n"\
"  ��MOD��Ҫչʾ����OS MR Lab�еĸ���ս���������ԣ�����Ȥ�Ŀɼ���MOD QQȺ�μ�MOD���� 739924481\r\n\r\n"\
"��������:\r\n  ��MOD�������MOD�������ز������������磬�������о�ѧϰ��������Ȩ����ϵ��ѩԭ�����ҡ�\r\n\r\n"\
"  Death can bring praise, destruction can bring real salvation. Only darkness can bring dawn. When the destruction is impossible, God's grace will rise from the most remote place and shine on the mountain where bones are piled up - the song of continued death\r\n\r\n"\
"Disclaimer:\r\n  This mod belongs to free mod. All materials are from the Internet and are only used for research and learning. If there is any infringement, please contact Da Xueyuan studio."\

#define MOD_DIR		"Dawn"

#define MOD_HELP	"���������Ϊ�ĸ�����,�ֱ�Ϊ�������,����������,���ܵ�������,������������\r\n\r\n����˵��\r\n\r\n1.������ܣ��ұ�����Ϊ��������ۣ��Զ����ܡ�\r\n"\
"2.����������\r\n"\
"�ո��(Space)         ʹ�õ��Ϊ�����ݳ��\r\n"\
"3.���ܵ�������\r\n"\
"����1-4               ʹ��������Ϊ���ܵ��ݳ�磬ͬʱ�Ὺ�����Ϊ����������\r\n"\
"4.��������\r\n"\
"W S D A               ǰ�������ƶ�\r\n"\
"�� ��                 �����ƶ�\r\n"\
"Page up   Page Down   ���ǵ���\r\n\r\n\r\n"\
"The operation interface is divided into four parts: battery energy storage, main capacitance energy storage, skill capacitance energy storage and action controller.\r\n\r\nOperating instructions\r\n\r\n1.Battery energy storage, the right container is battery energy tank, automatic energy storage.\r\n"\
"2.main capacitance energy storage\r\n"\
"Space Key    Use battery to charge main capacitor\r\n"\
"3.skill capacitance energy storage\r\n"\
"1-4 Key      Use the main capacitor to charge the skill capacitor and turn on the battery to store energy\r\n"\
"4.action controller\r\n"\
"W S D A      Move backand forth leftand right\r\n"\
"�� ��        Move up and down\r\n"\
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
	//��
	void InitMod1()
	{
		ModInfo(MOD_VER, MOD_NAME, "��", MOD_DESC, "\r\n  �����ս��", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{_T("data/")_T(MOD_DIR)_T("/images/1RBack.bmp")},
			{"data/Dawn/images/1Front.bmp"},
			{"data/Dawn/images/1Top.bmp"},
			{"data/Dawn/images/1Left.bmp"},
			{"data/Dawn/images/1Right.bmp"},
			{"data/Dawn/images/sand1.bmp"},//����
			{NULL}
		};
		SaveRes(MOD_DIR, 1);
	}
	//��
	void InitMod2()
	{
		ModInfo(MOD_VER, MOD_NAME, "��", MOD_DESC, "\r\n  �����ս��", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{"data/Dawn/images/2RBack.bmp"},
			{"data/Dawn/images/2Front.bmp"},
			{"data/Dawn/images/2Top.bmp"},
			{"data/Dawn/images/2Left.bmp"},
			{"data/Dawn/images/2Right.bmp"},
			{"data/Dawn/images/sand2.bmp"},//����
			{NULL}
		};
		SaveRes(MOD_DIR, 2);
	}
	//��
	void InitMod3()
	{
		ModInfo(MOD_VER, MOD_NAME, "��", MOD_DESC, "\r\n  �����ս��", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{"data/Dawn/images/3RBack.bmp"},
			{"data/Dawn/images/3Front.bmp"},
			{"data/Dawn/images/3Top.bmp"},
			{"data/Dawn/images/3Left.bmp"},
			{"data/Dawn/images/3Right.bmp"},
			{"data/Dawn/images/sand3.bmp"},//����
			{NULL}
		};
		SaveRes(MOD_DIR, 3);
	}
	//��
	void InitMod4()
	{
		ModInfo(MOD_VER, MOD_NAME, "��", MOD_DESC, "\r\n  �����ս��", MOD_HELP, "./data/Dawn/ui/1920.png", MOD_PUBID);
		gSkyRes = {
			{"data/Dawn/images/4RBack.bmp"},
			{"data/Dawn/images/4Front.bmp"},
			{"data/Dawn/images/4Top.bmp"},
			{"data/Dawn/images/4Left.bmp"},
			{"data/Dawn/images/4Right.bmp"},
			{"data/Dawn/images/sand4.bmp"},//����
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
			{"����ս��","��ǽ�ұ�",800,0,0,"������",1,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"����ս��","��ǽ���",800,0,0,"������",2,0,0,0},//���͵�λ����ϵ����λ�������͵�λ����xƫ��500 zƫ��30�������
			{"����ս��","���᳡��",3000,0,0,"������",4,0,0,0},//��������ϵ����λ��������xƫ��1000�������
			{NULL,NULL,1000,0,0,""}
		});

		gGarrisonSoldiers.push_back({
			{"����ս��","��ǽ�ұ�",800,0,0,"������",5,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"����ս��","��ǽ���",800,0,0,"������",6,0,0,0},//���͵�λ����ϵ����λ�������͵�λ����xƫ��500 zƫ��30�������
			{"����ս��","���᳡��",3000,0,0,"������",7,0,0,0},//��������ϵ����λ��������xƫ��1000�������
			{NULL,NULL,1000,0,0,""},
		});

		gGarrisonSoldiers.push_back({
			{"���ս��","��ǽ�ұ�",800,0,0,"������",5,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"���ս��","��ǽ���",800,0,0,"������",6,0,0,0},//���͵�λ����ϵ����λ�������͵�λ����xƫ��500 zƫ��30�������
			{"���ս��","���᳡��",3000,0,0,"������",7,0,0,0},//��������ϵ����λ��������xƫ��1000�������
			{NULL,NULL,1000,0,0,""},
		});
#define TA_UNIT_COUNT 120
#define TA_UNIT_COUNT2 260

		gGarrisonSoldiers.push_back( {
			{"��¥3-1","��-1",TA_UNIT_COUNT,0,0,"������",8,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-1","��-2",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-1","��-3",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-1","��-4",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-1","��-5",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-1","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},

			{"��¥3-1","��-1",TA_UNIT_COUNT,0,0,"������",9,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-1","��-2",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-1","��-3",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-1","��-4",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-1","��-5",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-1","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},

			{"��¥3-1","��-1",TA_UNIT_COUNT,0,0,"������",10,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-1","��-2",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-1","��-3",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-1","��-4",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-1","��-5",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-1","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},

			{"��¥3-1","��-1",TA_UNIT_COUNT,0,0,"������",11,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-1","��-2",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-1","��-3",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-1","��-4",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-1","��-5",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-1","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},
			{NULL,NULL,1000,0,0,""},
		});

		gGarrisonSoldiers.push_back({
			{"��¥3-2","��-1",TA_UNIT_COUNT2,0,0,"������",8,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-2","��-2",TA_UNIT_COUNT2,0,0,"������",8,0,0,0},
			{"��¥3-2","��-3",TA_UNIT_COUNT2,0,0,"������",8,0,0,0},
			{"��¥3-2","��-4",TA_UNIT_COUNT2,0,0,"������",8,0,0,0},
			{"��¥3-2","��-5",TA_UNIT_COUNT2,0,0,"������",14,0,0,0},
			{"��¥3-2","��-6",TA_UNIT_COUNT2,0,0,"������",13,0,0,0},

			{"��¥3-2","��-1",TA_UNIT_COUNT2,0,0,"������",9,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-2","��-2",TA_UNIT_COUNT2,0,0,"������",9,0,0,0},
			{"��¥3-2","��-3",TA_UNIT_COUNT2,0,0,"������",9,0,0,0},
			{"��¥3-2","��-4",TA_UNIT_COUNT2,0,0,"������",9,0,0,0},
			{"��¥3-2","��-5",TA_UNIT_COUNT2,0,0,"������",13,0,0,0},
			{"��¥3-2","��-6",TA_UNIT_COUNT2,0,0,"������",14,0,0,0},

			{"��¥3-2","��-1",TA_UNIT_COUNT2,0,0,"������",10,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-2","��-2",TA_UNIT_COUNT2,0,0,"������",10,0,0,0},
			{"��¥3-2","��-3",TA_UNIT_COUNT2,0,0,"������",10,0,0,0},
			{"��¥3-2","��-4",TA_UNIT_COUNT2,0,0,"������",10,0,0,0},
			{"��¥3-2","��-5",TA_UNIT_COUNT2,0,0,"������",14,0,0,0},
			{"��¥3-2","��-6",TA_UNIT_COUNT2,0,0,"������",13,0,0,0},

			{"��¥3-2","��-1",TA_UNIT_COUNT2,0,0,"������",11,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-2","��-2",TA_UNIT_COUNT2,0,0,"������",11,0,0,0},
			{"��¥3-2","��-3",TA_UNIT_COUNT2,0,0,"������",11,0,0,0},
			{"��¥3-2","��-4",TA_UNIT_COUNT2,0,0,"������",11,0,0,0},
			{"��¥3-2","��-5",TA_UNIT_COUNT2,0,0,"������",13,0,0,0},
			{"��¥3-2","��-6",TA_UNIT_COUNT2,0,0,"������",14,0,0,0},
			{NULL,NULL,1000,0,0,""},
		});

		gGarrisonSoldiers.push_back({
			{"��¥3-3","��-1",TA_UNIT_COUNT,0,0,"������",8,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-3","��-2",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-3","��-3",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-3","��-4",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-3","��-5",TA_UNIT_COUNT,0,0,"������",8,0,0,0},
			{"��¥3-3","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},

			{"��¥3-3","��-1",TA_UNIT_COUNT,0,0,"������",9,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-3","��-2",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-3","��-3",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-3","��-4",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-3","��-5",TA_UNIT_COUNT,0,0,"������",9,0,0,0},
			{"��¥3-3","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},

			{"��¥3-3","��-1",TA_UNIT_COUNT,0,0,"������",10,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-3","��-2",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-3","��-3",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-3","��-4",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-3","��-5",TA_UNIT_COUNT,0,0,"������",10,0,0,0},
			{"��¥3-3","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},

			{"��¥3-3","��-1",TA_UNIT_COUNT,0,0,"������",11,0,0,0},//���͵�λ����ϵ����λ��������xƫ��-100 zƫ��30�������
			{"��¥3-3","��-2",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-3","��-3",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-3","��-4",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-3","��-5",TA_UNIT_COUNT,0,0,"������",11,0,0,0},
			{"��¥3-3","��-6",TA_UNIT_COUNT,0,0,"������",12,0,0,0},
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
			SELECT_RANGE_DEF("��ǽ�ұ�",gTerrainSelectArray[0]),
			SELECT_RANGE_DEF("��ǽ���",gTerrainSelectArray[1]),
			SELECT_RANGE_DEF("���᳡��",gTerrainSelectArray[2]),
			{NULL,NULL},
		});

		gShootRangeRes= { BEINRANGE,
			SHOOTRANGE("��ǽ�ұ�",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_ALL,-200,30,50),
			SHOOTRANGE("��ǽ���",ShootRangeType_LargeUnit,ShootRangeRefType_OwnerUnit,ShootDstType_ALL,900,-330,50),
			SHOOTRANGE("���᳡��",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_ALL,1000,0,500),
			SHOOTRANGE("���᳡��1",ShootRangeType_World,ShootRangeRefType_OwnerUnit,ShootDstType_LargeUnit,1200,0,100),

			SHOOTRANGE("��ǽ�ұ�",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,-200,30,80),
			SHOOTRANGE("��ǽ���",ShootRangeType_LargeUnit,ShootRangeRefType_OwnerUnit,ShootDstType_BaseUnit,900,-330,50),
			SHOOTRANGE("���᳡��",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-1200,0,30),

			SHOOTRANGE("��¥3-��",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,300,0,100),
			SHOOTRANGE("��¥3-��",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,-400,0,100),
			SHOOTRANGE("��¥3-��",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,0,300,100),
			SHOOTRANGE("��¥3-��",ShootRangeType_LargeUnit,ShootRangeRefType_UnitSelf,ShootDstType_BaseUnit,0,-400,100),
			SHOOTRANGE("��¥3-1",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-1200,0,100),
			SHOOTRANGE("��¥3-2-1",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-1200,-600,100),
			SHOOTRANGE("��¥3-2-2",ShootRangeType_World,ShootRangeRefType_UnitSelf,ShootDstType_LargeUnit,-2700,0,100),
		};

		gTerrainSelectInfoArray.push_back( 
		{
			SELECT_RANGE_DEF("��-1",gTerrainSelectArray[RectRangePos(2,1,0)]),
			SELECT_RANGE_DEF("��-1",gTerrainSelectArray[RectRangePos(2,1,1)]),
			SELECT_RANGE_DEF("��-1",gTerrainSelectArray[RectRangePos(2,1,2)]),
			SELECT_RANGE_DEF("��-1",gTerrainSelectArray[RectRangePos(2,1,3)]),
			SELECT_RANGE_DEF("��-2",gTerrainSelectArray[RectRangePos(2,2,0)]),
			SELECT_RANGE_DEF("��-2",gTerrainSelectArray[RectRangePos(2,2,1)]),
			SELECT_RANGE_DEF("��-2",gTerrainSelectArray[RectRangePos(2,2,2)]),
			SELECT_RANGE_DEF("��-2",gTerrainSelectArray[RectRangePos(2,2,3)]),
			SELECT_RANGE_DEF("��-3",gTerrainSelectArray[RectRangePos(2,3,0)]),
			SELECT_RANGE_DEF("��-3",gTerrainSelectArray[RectRangePos(2,3,1)]),
			SELECT_RANGE_DEF("��-3",gTerrainSelectArray[RectRangePos(2,3,2)]),
			SELECT_RANGE_DEF("��-3",gTerrainSelectArray[RectRangePos(2,3,3)]),
			SELECT_RANGE_DEF("��-4",gTerrainSelectArray[RectRangePos(2,4,0)]),
			SELECT_RANGE_DEF("��-4",gTerrainSelectArray[RectRangePos(2,4,1)]),
			SELECT_RANGE_DEF("��-4",gTerrainSelectArray[RectRangePos(2,4,2)]),
			SELECT_RANGE_DEF("��-4",gTerrainSelectArray[RectRangePos(2,4,3)]),
			SELECT_RANGE_DEF("��-5",gTerrainSelectArray[RectRangePos(2,5,0)]),
			SELECT_RANGE_DEF("��-5",gTerrainSelectArray[RectRangePos(2,5,1)]),
			SELECT_RANGE_DEF("��-5",gTerrainSelectArray[RectRangePos(2,5,2)]),
			SELECT_RANGE_DEF("��-5",gTerrainSelectArray[RectRangePos(2,5,3)]),
			SELECT_RANGE_DEF("��-6",gTerrainSelectArray[RectRangePos(2,6,0)]),
			SELECT_RANGE_DEF("��-6",gTerrainSelectArray[RectRangePos(2,6,1)]),
			SELECT_RANGE_DEF("��-6",gTerrainSelectArray[RectRangePos(2,6,2)]),
			SELECT_RANGE_DEF("��-6",gTerrainSelectArray[RectRangePos(2,6,3)]),
			{NULL,NULL},
		});
		gSkyRes = {
			{"data/Dawn/images/3RBack.bmp"},
			{"data/Dawn/images/3Front.bmp"},
			{"data/Dawn/images/3Top.bmp"},
			{"data/Dawn/images/3Left.bmp"},
			{"data/Dawn/images/3Right.bmp"},
			{"data/Dawn/images/sand1.bmp"},//����
			{NULL}
		};
		
		gLargeUnitMod = {
#ifdef UI_EDIT_MODE
			{"��¥3","data/Dawn/ta/ta3.3ds",5.15,5.15,5.15,-15,-22.5,-6.3},
			//{"����","data/Dawn/main/main.3ds",0.15,0.15,0.15,0,0,0},
#else
			{"����","data/Dawn/main/main.3ds",0.15,0.15,0.15,0,0,0},
			{"��¥2","data/Dawn/ta/ta2.3ds",5.15,5.15,5.15,0,0,0},
			{"��¥3","data/Dawn/ta/ta3.3ds",5.15,5.15,5.15,-15,-22.5,-6.3},
#endif
			{NULL,NULL}
		};
		gModRes = {
			{SceneRes_Tree,SceneResSub_None,10,10,10,"��0","","data/Dawn/images/CACTUS0.BMP",1,0},
			{SceneRes_Tree,SceneResSub_None,10,10,10,"��1","","data/Dawn/images/CACTUS1.BMP",1,0},
			{SceneRes_Tree,SceneResSub_None,10,10,10,"��2","","data/Dawn/images/CACTUS2.BMP",1,0},
			{SceneRes_Tree,SceneResSub_None,10,10,10,"��3","","data/Dawn/images/CACTUS3.BMP",1,0},
			{SceneRes_Particle,SceneResSub_Explosion,10,10,10,"��ը","��ը","data/Dawn/images/explosion1.BMP",1,0},
			//{SceneRes_Particle,SceneResSub_Explosion,1,1,"��ը","��ը","data/Dawn/images/explosion0.BMP",1,0},
			//{SceneRes_Particle,SceneResSub_Arrow,1,1,"����","����","data/Dawn/images/explosion0.BMP",1,0},
			{SceneRes_Particle,SceneResSub_Arrow,30,5,5,"����","����","data/Dawn/images/jian.3ds",1,0},
			{SceneRes_Special,SceneResSub_None,10,10,10,"�����","ȫ������","data/Dawn/images/explosion0.BMP",1,0},
			{SceneRes_Special,SceneResSub_None,10,10,10,"�����","�ż�","data/Dawn/images/explosion1.BMP",1,0},

			{SceneRes_Special,SceneResSub_None,10,10,10,"������","����","data/Dawn/images/explosion0.BMP",1,0},
		};

		//������д
		//UnitType_AI_Aircraft
		gSpecialRes.push_back(
			
			{
				{50,20,1,"����ս��","�����","ȫ������","��ը","������׼��,4,3,2,1,0...\r\nArcher preparation,4,3,2,1,0..."},
				{50,15,0,"��¥3-3","�����","�ż�","��ը","��...\r\nTo shoot an arrow"}
			}
		);
		//UnitType_AI_Man
		gSpecialRes.push_back(
			{
			{50,20,0,"","������","����","�������һؼң��ҵ��޶��ڵ���...\r\nPlease��let me go home,My wife is waiting for me..."}
			}
		);

		gWaveRes = {
			{"ѩԭ����","data/Dawn/music/daxueyuan.mp3",1.0,true},
			{"����","data/Dawn/music/miezui.mp3",1.0,true},
			{"����1","data/Dawn/music/miezui1.mp3",1.0,true},
			{"һ��","data/Dawn/music/yidao.mp3",0.8,true},
			{"����","data/Dawn/music/wangshi.mp3",1.0,true},
			{"ֱ����","data/Dawn/music/zhishengji.mp3",1.0,true},
			{"��ը3","data/Dawn/music/BOMB3.mp3",1.0,true},
			{"�ϼ�","data/Dawn/music/mix.mp3",1.0,true},
			{"��","data/Dawn/music/yu.mp3",1.0,true},
			{"����1","data/Dawn/music/WOOSH4.mp3",1.4,true}
		};
		gSoundRes ={
			{"����","����",1.0,150,0,0,2},
			{"����1","����1",1.0,170,0,0,2},
			{"��ս","һ��",1.0,120,0,0,1},
			{"����","����",1.0,250,0,0,3},
			{"����","ֱ����",1,50,0,55,3},
			{"��ը","��ը3",1,1.0,0,0,3},
			{"����","����1",1,1.0,0,0,3},
			{"����1","�ϼ�",1.0,1.0,100,25,3},
			{"����2","�ϼ�",1.0,1.0,75,25,3},
			{"ֹս","��",1.0,300,0,0,3},
		};
#define UNNAME_SEC "����","",1,UnitType_SceneRes

		g_SceneResTab =
		{
		#ifdef UI_EDIT_MODE
			//{"��¥23","��¥3",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,210,0.5,0,0,0,0,&gTerrainSelect2[0],&gGarrisonSoldiers4[0],NULL}
			{"��¥3-1","��¥3",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4200,280,1.0,0,0,0,0,& gTerrainSelectInfoArray[1][0],& gGarrisonSoldiers[3][0],NULL,NULL}
			//{"����ս��","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,72.5,1.0,0,5,200,0,& gTerrainSelectInfoArray[0][0],& gGarrisonSoldiers[0][0],NULL,"����1"}
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

			{"���ս��","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,3600,-4800,50,1.0,0,10,0,0,&gTerrainSelectInfoArray[0][0],&gGarrisonSoldiers[2][0],"���AI","��ս"},
			{"ս���ػ���","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,2600,-1500,205,1.0,-90,20,24,0,NULL,NULL,NULL,NULL},
			{"����","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,800,-1200,550,1.5,90,50,0,0,NULL,NULL,NULL,NULL},
			{"����ս��","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,72.5,1.0,0,5,200,0,&gTerrainSelectInfoArray[0][0],&gGarrisonSoldiers[0][0],NULL,"����1"},
			{"����ս��","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,3500,-4200,145,1.0,45,80,0,0,&gTerrainSelectInfoArray[0][0],&gGarrisonSoldiers[1][0],NULL,"��ս"},
			{"��������","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,0,-8200,145,0.8,-45,80,0,0,NULL,NULL,NULL,"����"},
			{"ֹս֮��","����",0,UnitType_AI_Aircraft,SceneRes_Terrain,6000,-10200,145,0.8,-45,80,0,0,NULL,NULL,NULL,"ֹս"},
			//{"���ս��",UnitType_AI_Aircraft,SceneRes_Terrain,3800,-1700,600,1.0,0,10,0,0,&gTerrainSelect3[0],&gGarrisonSoldiers3[0],"���AI"},
			//{"���ս��",UnitType_AI_Aircraft,SceneRes_Terrain,2000,-1750,400,1.0,0,10,0,0,&gTerrainSelect3[0],&gGarrisonSoldiers3[0],"���AI"},
			//{"����ս��",UnitType_AI_Aircraft,SceneRes_Terrain,2200,-4300,72.5,1.0,0,5,200,0,&gTerrainSelect1[0],&gGarrisonSoldiers1[0],NULL},
			
			{"��¥3-1","��¥3",0,UnitType_AI_Aircraft,SceneRes_Terrain,3500,-3000,280,1.2,0,0,0,0,&gTerrainSelectInfoArray[1][0],&gGarrisonSoldiers[3][0],NULL,NULL},
			{"��¥3-2","��¥3",0,UnitType_AI_Aircraft,SceneRes_Terrain,3700,-1000,440,2.0,45,0,0,0,&gTerrainSelectInfoArray[1][0],&gGarrisonSoldiers[4][0],NULL,"����1"},
			{"��¥3-3","��¥3",0,UnitType_AI_Aircraft,SceneRes_Terrain,2000,-1500,240,1.0,180,0,0,0,&gTerrainSelectInfoArray[1][0],&gGarrisonSoldiers[5][0],NULL,"����"},

			
			//{"����ս��","����",0,UnitType_SceneRes,SceneRes_Terrain,2200,-4300,22.5,1.0,-90,0,0,0,&gTerrainSelect1[0],&gGarrisonSoldiers1[0],NULL},

			
			

			{"��¥22","��¥2",0,UnitType_AI_Aircraft,SceneRes_Terrain,1455,-4300,162,1.0,0,0,0,0,NULL,NULL,NULL}
			
			//{"��¥23","��¥3-3",0,UnitType_SceneRes,SceneRes_Terrain,3600,-3000,210,1.0,0,0,0,0,&gTerrainSelect2[0],&gGarrisonSoldiers4[0],NULL},
			//{"��¥23","��¥3-4",0,UnitType_SceneRes,SceneRes_Terrain,3600,-3000,210,1.0,0,0,0,0,&gTerrainSelect2[0],&gGarrisonSoldiers4[0],NULL},
		#endif

			
			//{"��¥22","��¥2",0,UnitType_SceneRes,SceneRes_Terrain,1000,-500,250,1.0,90,5,0,0,NULL,NULL,NULL},
			//{"��¥23","��¥3",0,UnitType_SceneRes,SceneRes_Terrain,2800,-500,250,1.0,90,5,0,0,NULL,NULL,NULL}
		};
		InitMod1();
		InitMod2();
		InitMod3();
		InitMod4();
		
		return bInitMod ? true : false;
	}
private:

};


//��¥2





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





