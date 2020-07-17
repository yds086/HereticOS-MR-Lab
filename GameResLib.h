#pragma once
#include "SerLib.h"
#define RES_LIB_VER  20200518 
#define MAIN_MAP_USER_POS 5000
#pragma pack(push,4)
enum SceneResType
{
	SceneRes_Tree,		//树
	SceneRes_Terrain,	//巨型单位
	SceneRes_Spirit,	//精灵	
	SceneRes_Particle,	//粒子	
	SceneRes_UI,		//UI
	SceneRes_Special,	//特写
};

enum SceneResSubType
{
	SceneResSub_None,		//树
	SceneResSub_Explosion,	//爆炸
	SceneResSub_Arrow		//弓箭
};

//巨型单位驻兵区域
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
	float fScaleMake;//制作时工具缩放倍数
	SelectRange* pRangeArray;
	unsigned int nDynamicTerrainID;
	unsigned int nDynamicSubTerrainID;
};

//ShootRangeType说明目标范围是相对世界坐标系范围，还是所属巨型单位坐标范围。
enum ShootRangeType
{
	ShootRangeType_World = 0,
	ShootRangeType_LargeUnit,
};
//参照系起点坐标
enum ShootRangeRefType
{
	ShootRangeRefType_UnitSelf = 0, //单位自身作为起点
	ShootRangeRefType_OwnerUnit,		//拥有该单位的巨型单位坐标作为起点 
};
enum ShootDstType
{
	ShootDstType_BaseUnit = 0x1,		//只攻击基本单位
	ShootDstType_LargeUnit=0x2,		//只攻击巨型单位
	ShootDstType_ALL= ShootDstType_BaseUnit| ShootDstType_LargeUnit,				//攻击所有类型目标
};
struct ShootRangeRes
{
	struct
	{
		unsigned int nWorldRangeType : 1;//1为世界范围
		unsigned int nRangeRefType : 1;//参照系类型
		unsigned int nShootDstType : 2;
		unsigned int nRangeR : 8;
	}State;
	float fRangePosX;
	float fRangePosZ;
	float fR;
};

//驻兵信息

struct GarrisonSoldiersInfo
{
	char* pTerrainName;			//巨型单位名
	char* pSelectName;			//子片区名
	unsigned int nUnitCount;	//驻兵数量	
	unsigned int nUnitType;
	unsigned int nWorkMode;
	char* pAIName;				//绑定的AI
	unsigned int nShootRange[4];
};
//巨型单位mod信息
struct LargeUnitMod
{
	char* pObjName;
	char* pszMod;//mod文件路径
	float fScaleX;//x方向缩放
	float fScaleY;//x方向缩放
	float fScaleZ;//x方向缩放

	float fRotateX;//x方向缩放
	float fRotateY;//y方向旋转
	float fRotateZ;//z方向旋转
};
//模型动作
struct ModRes
{
	struct
	{
		unsigned int nResType : 8;
		unsigned int nSubResType : 8;
		unsigned int nW : 16;		//X宽 单位为0.1米
		unsigned int nH : 16;		//Y高
		unsigned int nL : 16;		//Z 
	};

	char* pObjName;
	char* pFunctionName;
	char* pszMod;				//mod文件路径
	unsigned int nFrameCount;	//帧数
	unsigned int nWaitID;		//待命循环开始帧
	unsigned int nModIndex;		//索引，用于内部
	unsigned int nModSubIndex;	//索引，用于内部
};
//特写
struct SpecialRes
{
	//unsigned int nSpecialUnitType:8;	//特写单位类型
	unsigned int nWaitTime : 12;		//特写等待时间 100ms为单位
	unsigned int nDiff : 8;				//特写距离倍数 0.1为单位
	unsigned int bTurn:1;				//旋转
	char* pBindUnitName;				//绑定的单位名
	char* pSpecialName;					//特写名 
	char* pFunctionName;				//指定引用的Mod 功能资源
	char* pszBindSound;					//绑定的音效名
	char* pFromat;
	unsigned int nBindUnitType : 4;
	unsigned int nBindUnitID : 16;
	unsigned int nBindModResID : 12;
	int iSoundID=-1;
};

//音效资源定义
struct WaveRes
{
	char * pszWaveName;		//音效资源名
	char * pszWaveFile;		//音效文件名
	float fA;				//音量修正
	struct
	{
		unsigned int bCache : 1;	//是否缓存，缓存会占用大量内存，不缓存的话，则不能用于共享音源
	};
	int iWaveID;				//资源ID ,内部使用
};

//音效定义
struct SoundRes
{
	char* pszSoundName;		//音效名
	char* pszWaveName;		//关联的音效资源名
	//char* pszEffect;		//音场效果
	float fA;				//音量修正
	float fSize;			//音场最小衰减边界
	unsigned int nBeginFrame;//起始帧，每帧40ms
	unsigned int nUsedFrame;//帧数//填0则播放到结束
	float fAuraLevel = 2;	//音场优先级，斗气时需要
	float fRadiation=2;		//音场辐射范围加成，默认为2
	int iWaveResID=-1;		//内部使用				
};

struct SceneRes
{
	char* pObjName;
	char* pModObjName;
	struct
	{
		unsigned int bStaticUnit : 1;	//静态单位
		unsigned int nType : 4;
		unsigned int nSubType : 4;
	};

	float fInitXPos;	//启动坐标
	float fInitZPos;
	float fInitYPos;	
	float fSize;		//尺寸修正
	float fAngle;		//角度
	float fFloat;		//浮动振幅
	float fTurnXZ;		//旋转速度
	unsigned short nID;	//内部使用
	SelectInfo * pContext;
	GarrisonSoldiersInfo* pContext1;
	char* pszAIName;	//绑定的AI名
	char* pszBindSoundName;	//绑定的音乐
	int iSoundID ;		//内部使用
};

struct SkyRes
{
	char* pszPath;
};

#define SHOOTRANGE(_name,_RangeType,_RefType,_DstType,_Posx,_Posz,_fR) {{_RangeType,_RefType,_DstType,(unsigned char)((_fR/MAP_SCALE)+1)},_Posx,_Posz,_fR}
#define BEINRANGE SHOOTRANGE("起始",0,0,0,0,0,0)


#define SELECT_RANGE_DEF(_name,_select) {_name,1.5,&_select[0],0,0}


#define RectRangePos(_name,_level,_dir) ((_name)<<7|(_level)<<2|_dir)

#define MakeRectRange(_name,_level,_l,_w,_w1,_x,_z,_h,_dh) \
gTerrainSelectArray[RectRangePos(_name,_level,2)] = {\
	{"西",(_x), (_h), (_z-_w1), (_w1), (_dh), -((_w)-(_w1)),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\
\
gTerrainSelectArray[RectRangePos(_name,_level,3)] = {\
	{"北",(_x), (_h), ((_z)-(_w)), (_l), (_dh), -(_w1),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\
\
gTerrainSelectArray[RectRangePos(_name,_level,0)] = {\
	{"东",(_x)+(_l)-(_w1), (_h), (_z)-(_w1), (_w1), (_dh), -((_w)-(_w1)),SceneContext::eCollisionObject_Land},\
	{NULL,0, 0, 0, 0, 0, 0,SceneContext::eCollisionObject_Land}\
};\
\
gTerrainSelectArray[RectRangePos(_name,_level,1)] = {\
	{"南",(_x), (_h), (_z), (_l), (_dh), -(_w1),SceneContext::eCollisionObject_Land},\
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
			SerString1D(gLargeUnitMod, pszMod);//mod文件路径
			SerString1D(g_SceneResTab, pObjName);
			SerString1D(g_SceneResTab, pModObjName);
			SerString1D(g_SceneResTab, pszAIName);
			SerString1D(g_SceneResTab, pszBindSoundName);

			SerString1D(gSkyRes, pszPath);
			SerString1D(gModRes, pObjName);
			SerString1D(gModRes, pszMod);			//mod文件路径
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
			UnSerString1D(gLargeUnitMod, pszMod);//mod文件路径
			UnSerString1D(g_SceneResTab, pObjName);
			UnSerString1D(g_SceneResTab, pModObjName);
			UnSerString1D(g_SceneResTab, pszAIName);
			UnSerString1D(g_SceneResTab, pszBindSoundName);

			UnSerString1D(gSkyRes, pszPath);
			UnSerString1D(gModRes, pObjName);
			UnSerString1D(gModRes, pszMod);			//mod文件路径
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