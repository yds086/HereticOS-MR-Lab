#pragma once
#include "SerLib.h"
#define RES_LIB_VER  20200518 
#define MAIN_MAP_USER_POS 5000
#pragma pack(push,4)
enum SceneResType
{
	SceneRes_Tree,		//��
	SceneRes_Terrain,	//���͵�λ
	SceneRes_Spirit,	//����	
	SceneRes_Particle,	//����	
	SceneRes_UI,		//UI
	SceneRes_Special,	//��д
};

enum SceneResSubType
{
	SceneResSub_None,		//��
	SceneResSub_Explosion,	//��ը
	SceneResSub_Arrow		//����
};

//���͵�λפ������
struct SelectRange
{
	char* pSubSelectName; 
	float fBeginPosX; float fBeginPosY; float fBeginPosZ;
	float fXLen; float fYLen; float fZLen;
	SceneContext::CollisionObjectType type;
};
struct SelectInfo
{
	char* pSelectName;
	float fScaleMake;//����ʱ�������ű���
	SelectRange* pRangeArray;
	unsigned int nDynamicTerrainID;
	unsigned int nDynamicSubTerrainID;
};

//ShootRangeType˵��Ŀ�귶Χ�������������ϵ��Χ�������������͵�λ���귶Χ��
enum ShootRangeType
{
	ShootRangeType_World = 0,
	ShootRangeType_LargeUnit,
};
//����ϵ�������
enum ShootRangeRefType
{
	ShootRangeRefType_UnitSelf = 0, //��λ������Ϊ���
	ShootRangeRefType_OwnerUnit,		//ӵ�иõ�λ�ľ��͵�λ������Ϊ��� 
};
enum ShootDstType
{
	ShootDstType_BaseUnit = 0x1,		//ֻ����������λ
	ShootDstType_LargeUnit=0x2,		//ֻ�������͵�λ
	ShootDstType_ALL= ShootDstType_BaseUnit| ShootDstType_LargeUnit,				//������������Ŀ��
};
struct ShootRangeRes
{
	struct
	{
		unsigned int nWorldRangeType : 1;//1Ϊ���緶Χ
		unsigned int nRangeRefType : 1;//����ϵ����
		unsigned int nShootDstType : 2;
		unsigned int nRangeR : 8;
	}State;
	float fRangePosX;
	float fRangePosZ;
	float fR;
};

//פ����Ϣ

struct GarrisonSoldiersInfo
{
	char* pTerrainName;			//���͵�λ��
	char* pSelectName;			//��Ƭ����
	unsigned int nUnitCount;	//פ������	
	unsigned int nUnitType;
	unsigned int nWorkMode;
	char* pAIName;				//�󶨵�AI
	unsigned int nShootRange[4];
};
//���͵�λmod��Ϣ
struct LargeUnitMod
{
	char* pObjName;
	char* pszMod;//mod�ļ�·��
	float fScaleX;//x��������
	float fScaleY;//x��������
	float fScaleZ;//x��������

	float fRotateX;//x��������
	float fRotateY;//y������ת
	float fRotateZ;//z������ת
};
//ģ�Ͷ���
struct ModRes
{
	struct
	{
		unsigned int nResType : 8;
		unsigned int nSubResType : 8;
		unsigned int nW : 16;		//X�� ��λΪ0.1��
		unsigned int nH : 16;		//Y��
		unsigned int nL : 16;		//Z 
	};

	char* pObjName;
	char* pFunctionName;
	char* pszMod;				//mod�ļ�·��
	unsigned int nFrameCount;	//֡��
	unsigned int nWaitID;		//����ѭ����ʼ֡
	unsigned int nModIndex;		//�����������ڲ�
	unsigned int nModSubIndex;	//�����������ڲ�
};
//��д
struct SpecialRes
{
	//unsigned int nSpecialUnitType:8;	//��д��λ����
	unsigned int nWaitTime : 12;		//��д�ȴ�ʱ�� 100msΪ��λ
	unsigned int nDiff : 8;				//��д���뱶�� 0.1Ϊ��λ
	unsigned int bTurn:1;				//��ת
	char* pBindUnitName;				//�󶨵ĵ�λ��
	char* pSpecialName;					//��д�� 
	char* pFunctionName;				//ָ�����õ�Mod ������Դ
	char* pszBindSound;					//�󶨵���Ч��
	char* pFromat;
	unsigned int nBindUnitType : 4;
	unsigned int nBindUnitID : 16;
	unsigned int nBindModResID : 12;
	int iSoundID=-1;
};

//��Ч��Դ����
struct WaveRes
{
	char * pszWaveName;		//��Ч��Դ��
	char * pszWaveFile;		//��Ч�ļ���
	float fA;				//��������
	struct
	{
		unsigned int bCache : 1;	//�Ƿ񻺴棬�����ռ�ô����ڴ棬������Ļ����������ڹ�����Դ
	};
	int iWaveID;				//��ԴID ,�ڲ�ʹ��
};

//��Ч����
struct SoundRes
{
	char* pszSoundName;		//��Ч��
	char* pszWaveName;		//��������Ч��Դ��
	//char* pszEffect;		//����Ч��
	float fA;				//��������
	float fSize;			//������С˥���߽�
	unsigned int nBeginFrame;//��ʼ֡��ÿ֡40ms
	unsigned int nUsedFrame;//֡��//��0�򲥷ŵ�����
	float fAuraLevel = 2;	//�������ȼ�������ʱ��Ҫ
	float fRadiation=2;		//�������䷶Χ�ӳɣ�Ĭ��Ϊ2
	int iWaveResID=-1;		//�ڲ�ʹ��				
};

struct SceneRes
{
	char* pObjName;
	char* pModObjName;
	struct
	{
		unsigned int bStaticUnit : 1;	//��̬��λ
		unsigned int nType : 4;
		unsigned int nSubType : 4;
	};

	float fInitXPos;	//��������
	float fInitZPos;
	float fInitYPos;	
	float fSize;		//�ߴ�����
	float fAngle;		//�Ƕ�
	float fFloat;		//�������
	float fTurnXZ;		//��ת�ٶ�
	unsigned short nID;	//�ڲ�ʹ��
	SelectInfo * pContext;
	GarrisonSoldiersInfo* pContext1;
	char* pszAIName;	//�󶨵�AI��
	char* pszBindSoundName;	//�󶨵�����
	int iSoundID ;		//�ڲ�ʹ��
};

struct SkyRes
{
	char* pszPath;
};

#define SHOOTRANGE(_name,_RangeType,_RefType,_DstType,_Posx,_Posz,_fR) {{_RangeType,_RefType,_DstType,(unsigned char)((_fR/MAP_SCALE)+1)},_Posx,_Posz,_fR}
#define BEINRANGE SHOOTRANGE("��ʼ",0,0,0,0,0,0)


#define SELECT_RANGE_DEF(_name,_select) {_name,1.5,&_select[0],0,0}


#define RectRangePos(_name,_level,_dir) ((_name)<<7|(_level)<<2|_dir)

#define MakeRectRange(_name,_level,_l,_w,_w1,_x,_z,_h,_dh) \
gTerrainSelectArray[RectRangePos(_name,_level,2)] = {\
	{"��",(_x), (_h), (_z-_w1), (_w1), (_dh), -((_w)-(_w1)),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\
\
gTerrainSelectArray[RectRangePos(_name,_level,3)] = {\
	{"��",(_x), (_h), ((_z)-(_w)), (_l), (_dh), -(_w1),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\
\
gTerrainSelectArray[RectRangePos(_name,_level,0)] = {\
	{"��",(_x)+(_l)-(_w1), (_h), (_z)-(_w1), (_w1), (_dh), -((_w)-(_w1)),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\
\
gTerrainSelectArray[RectRangePos(_name,_level,1)] = {\
	{"��",(_x), (_h), (_z), (_l), (_dh), -(_w1),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\

#define RectRangeBegin(_name) if(gTerrainSelectArray.size()<((_name+1)<<7)) gTerrainSelectArray.resize(((_name+1)<<7));
#define RectRangeEnd(_name) nSelectPos=((_name+1)<<7);



#define _ResData ResData::GetInstance()
#define AddRes(_res,_set) _res.push_back(_set)
#define ModInfo(_nModVer,_pszModName,_pszSubModName,_pszModDesc,_pszSubModDesc,_pszModHelp,_pszTitlePic,_pszPublishID) m_ModHead={RES_LIB_VER,_nModVer,_pszModName,_pszSubModName,_pszModDesc,_pszSubModDesc,_pszModHelp,_pszTitlePic,_pszPublishID};
class GameResLib :public SerLib
{
public:
	
	vector<vector<SelectRange>> gTerrainSelectArray;
	vector<vector<SelectInfo>>	gTerrainSelectInfoArray;
	vector<vector<GarrisonSoldiersInfo>> gGarrisonSoldiers;
	vector<vector<SpecialRes>> gSpecialRes;

	vector<SceneRes> g_SceneResTab;
	vector<ShootRangeRes> gShootRangeRes;
	vector<LargeUnitMod> gLargeUnitMod;
	vector<ModRes> gModRes;
	vector<SkyRes> gSkyRes;
	vector<WaveRes> gWaveRes;
	vector<SoundRes> gSoundRes;

	string m_szModName;
	
	struct ModHead
	{
		unsigned int nVer;
		unsigned int nModVer;
		char* pszModName;
		char* pszSubModName;
		char* pszModDesc;
		char* pszSubModDesc;
		char* pszModHelp;
		char* pszTitlePic;
		char* pszPublishID;
	};
	ModHead m_ModHead;

	

	GameResLib() {};
	~GameResLib() {};

	void Reset()
	{
		gTerrainSelectArray.clear();
		gTerrainSelectInfoArray.clear();
		gGarrisonSoldiers.clear();
		gSpecialRes.clear();

		g_SceneResTab.clear();
		gShootRangeRes.clear();
		gLargeUnitMod.clear();
		gModRes.clear();
		gSkyRes.clear();
		gWaveRes.clear();
		gSoundRes.clear();
	}

	bool SaveRes(char* pMod,unsigned int nSubMod)
	{
		m_szModName = pMod;
		char szMod[256];
		sprintf(szMod, "data/%s/game%u.mod", pMod, nSubMod);
		string szModFile = szMod;
#ifdef _LINUX_
		char szUtf8File[512];
		m_hFile = fopen(GetUtf8FileName((char*)szModFile.c_str(), &szUtf8File[0], 512), "wb+");
#else
		m_hFile = fopen(szModFile.c_str(), "wb+");
#endif
		if (m_hFile)
		{
			
			SerString(m_ModHead.pszPublishID);
			SerString(m_ModHead.pszModName);
			SerString(m_ModHead.pszModDesc);
			SerString(m_ModHead.pszSubModName);
			SerString(m_ModHead.pszSubModDesc);
			SerString(m_ModHead.pszModHelp);
			SerString(m_ModHead.pszTitlePic);

			fwrite(&m_ModHead, sizeof(m_ModHead), 1, m_hFile);

			SerString2D(gTerrainSelectArray, pSubSelectName);
			/*
			for (unsigned int i = 0; i < gTerrainSelectArray.size(); i++)
			{
				for (unsigned int j = 0; j < gTerrainSelectArray[i].size(); j++)
				{
					gTerrainSelectArray[i][j].pSubSelectName = MakeStringIndex(gTerrainSelectArray[i][j].pSubSelectName);
				}
			}
			*/
			SerString2D(gTerrainSelectInfoArray, pSelectName);
			SerString2D(gGarrisonSoldiers, pTerrainName);
			SerString2D(gGarrisonSoldiers, pSelectName);
			SerString2D(gGarrisonSoldiers, pAIName);

			SerString1D(gLargeUnitMod, pObjName);
			SerString1D(gLargeUnitMod, pszMod);//mod�ļ�·��
			SerString1D(g_SceneResTab, pObjName);
			SerString1D(g_SceneResTab, pModObjName);
			SerString1D(g_SceneResTab, pszAIName);
			SerString1D(g_SceneResTab, pszBindSoundName);

			SerString1D(gSkyRes, pszPath);
			SerString1D(gModRes, pObjName);
			SerString1D(gModRes, pszMod);			//mod�ļ�·��
			SerString1D(gModRes, pFunctionName);
			SerString2D(gSpecialRes, pSpecialName);
			SerString2D(gSpecialRes, pFromat);
			SerString2D(gSpecialRes, pFunctionName);
			SerString2D(gSpecialRes, pBindUnitName);
			SerString2D(gSpecialRes, pszBindSound);

			
			SerString1D(gWaveRes, pszWaveName);
			SerString1D(gWaveRes, pszWaveFile);

			SerString1D(gSoundRes, pszSoundName);
			SerString1D(gSoundRes, pszWaveName);

			SerObject2D(gTerrainSelectInfoArray, pRangeArray, gTerrainSelectArray);
			SerObject(g_SceneResTab, pContext, gTerrainSelectInfoArray);
			SerObject(g_SceneResTab, pContext1, gGarrisonSoldiers);

			SaveStringArray();
			SaveArray2D(gTerrainSelectArray);
			SaveArray2D(gTerrainSelectInfoArray);
			SaveArray2D(gGarrisonSoldiers);
			SaveArray2D(gSpecialRes);

			SaveArray1D(g_SceneResTab);
			SaveArray1D(gShootRangeRes);
			SaveArray1D(gLargeUnitMod);
			SaveArray1D(gSkyRes);
			SaveArray1D(gModRes);
			SaveArray1D(gWaveRes);
			SaveArray1D(gSoundRes);

			fflush(m_hFile);
			fclose(m_hFile);
			return true;
		}
		return false;
	}

	bool LoadRes(char* pMod,unsigned int nSubMod)
	{
		m_szModName = pMod;
		char szMod[256];
		sprintf(szMod, "data/%s/game%u.mod", pMod, nSubMod);
		string szModFile = szMod;
#ifdef _LINUX_
		char szUtf8File[512];
		m_hFile = fopen(GetUtf8FileName((char*)szModFile.c_str(), &szUtf8File[0], 512), "rb+");
#else
		m_hFile = fopen(szModFile.c_str(), "rb+");
#endif

		if (m_hFile)
		{
			fread(&m_ModHead, sizeof(m_ModHead), 1, m_hFile);
			if (m_ModHead.nVer != RES_LIB_VER)
				return false;

			Reset();

			LoadStringArray();
			LoadArray2D(gTerrainSelectArray);
			LoadArray2D(gTerrainSelectInfoArray);
			LoadArray2D(gGarrisonSoldiers);
			LoadArray2D(gSpecialRes);

			LoadArray1D(g_SceneResTab);
			LoadArray1D(gShootRangeRes);
			LoadArray1D(gLargeUnitMod);
			LoadArray1D(gSkyRes);
			LoadArray1D(gModRes);

			LoadArray1D(gWaveRes);
			LoadArray1D(gSoundRes);

			//m_ModHead.pszPublishID
			UnSerString(m_ModHead.pszPublishID);
			UnSerString(m_ModHead.pszModName);
			UnSerString(m_ModHead.pszModDesc);
			UnSerString(m_ModHead.pszSubModName);
			UnSerString(m_ModHead.pszSubModDesc);
			UnSerString(m_ModHead.pszModHelp);
			UnSerString(m_ModHead.pszTitlePic);

			UnSerString2D(gTerrainSelectArray, pSubSelectName);
			UnSerString2D(gTerrainSelectInfoArray, pSelectName);
			UnSerString2D(gGarrisonSoldiers, pTerrainName);
			UnSerString2D(gGarrisonSoldiers, pSelectName);
			UnSerString2D(gGarrisonSoldiers, pAIName);
			UnSerString2D(gSpecialRes, pSpecialName);
			UnSerString2D(gSpecialRes, pFromat);
			UnSerString2D(gSpecialRes, pFunctionName);
			UnSerString2D(gSpecialRes, pBindUnitName);
			UnSerString2D(gSpecialRes, pszBindSound);

			UnSerString1D(gLargeUnitMod, pObjName);
			UnSerString1D(gLargeUnitMod, pszMod);//mod�ļ�·��
			UnSerString1D(g_SceneResTab, pObjName);
			UnSerString1D(g_SceneResTab, pModObjName);
			UnSerString1D(g_SceneResTab, pszAIName);
			UnSerString1D(g_SceneResTab, pszBindSoundName);

			UnSerString1D(gSkyRes, pszPath);
			UnSerString1D(gModRes, pObjName);
			UnSerString1D(gModRes, pszMod);			//mod�ļ�·��
			UnSerString1D(gModRes, pFunctionName);

			UnSerString1D(gWaveRes, pszWaveName);
			UnSerString1D(gWaveRes, pszWaveFile);

			UnSerString1D(gSoundRes, pszSoundName);
			UnSerString1D(gSoundRes, pszWaveName);


			UnSerObject2D(gTerrainSelectInfoArray, pRangeArray, gTerrainSelectArray);
			UnSerObject(g_SceneResTab, pContext, gTerrainSelectInfoArray);
			UnSerObject(g_SceneResTab, pContext1, gGarrisonSoldiers);
			



			fclose(m_hFile);
			return true;

		}

		return false;
	}

	
};

#pragma pack(pop)