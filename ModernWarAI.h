#pragma once
// #define _UNUSING_STDAFS_
//#define _USING_UFT8CODE_
//#define ����ģʽ
#define ����ģʽ1
//#define �ѻ�����ģʽ
//#define ��������
#define �׾������� AI_FRAME_RATE  //ÿ�������
#define �׾�������1 64
#define �׾������� �׾�������1*1024
#define �׾�������ѭ���� ((unsigned int)(�׾�������*4))
//#define ��ʼ������
//1s

#define MAN_ACTION_SPEED(_speed,_rate) ((unsigned int)((_speed*�׾�������*AI_FRAME_DT*_rate)/((float)1000)))
#define MAN_CAN_ACTION(_seed,_id,_speed,_rate) ((unsigned int )((((_seed+_id)*AI_FRAME_DT)%(MAN_ACTION_SPEED(_speed,_rate)))/AI_FRAME_DT))
#define AI_TICK_COUNT_PER_MS(_ms,_rate) ((unsigned int)((_ms*�׾�������*AI_FRAME_DT*_rate)/1000))
//#define MAN_ACTION_SPEED(_rate) ((unsigned int)(1*�׾�������))
//#define AI_TICK_COUNT_PER_MS(_ms,_rate) ((unsigned int)((_ms*�׾�������)/1000))
//#define MAN_ACTION_SPEED ((unsigned int)(1*PHY_FRAME_RATE))
//#define AI_TICK_COUNT_PER_MS(_ms) ((unsigned int)((_ms*PHY_FRAME_RATE)/1000))

//#define InitIChing
#define �����쳣

#define MAN_AI_BASE_POS 2
#define ����OS��־ϵͳ

#ifdef ����OS��־ϵͳ
#define ������� ContainerThreadError3 
#else
#define �������(_d,...) printf(__VA_ARGS__);printf("\r\n"); 
#endif
//


#ifdef _LINUX_
#define ��ҳ�ڴ�
#endif

#define ͳ����Ϣ

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

using namespace �׾�;

#pragma pack(push,1)
class _���溯��
{
public:
	unsigned int _Context;
	_���溯��() { //*(unsigned int*)&״̬ = 0;
	};
	~_���溯��() {};
	//���ô���������
	void ��ʼ��() {
		//״̬.״̬ = �ȴ�����;
	};
	//���������Ƿ񴥷��������
	static ������� ����(void* pϵͳ, void* p״̬��, ������& _����);
private:

};
#pragma pack(pop)

//#define �׾������� 4
//#define �׾�������ѭ���� (2048*4096/�׾�������)
#define ���溯��(_��,...) \
��������ʼ(_��, "����");\
����(����__���溯��);ռλ����(_���溯��);\
__VA_ARGS__;\
����������;\


//������Դ����
#define ����_���� ������(0)
#define ����_�� ������(1)
#define ����_���� ������(2)
#define ����_ʹ ������(3)
#define ����_ʹ1 ������(4)
#define ����_ʹ2 ������(5)
#define ����_�� ������(6)
#define ����_�շ� ������(7)
#define ����_���� ������(8)
#define ����_��Ц ������(9)
#define ����_Ц ������(10)
#define ����_��׼ ������(11)
#define ����_����1 ������(12)
#define ����_���� ������(16)

#define ����_��		������(0)
#define ����_����	������(2)
#define ����_��		������(4)
#define ����_����	������(6)
#define ����_��		������(8)
#define ����_����	������(10)
#define ����_��		������(12)
#define ����_����	������(14)

#define ��ɫ״̬_���� ������(UnitBaseState::UnitBaseState_Death)
#define ��ɫ״̬_�ȴ� ������(UnitBaseState::UnitBaseState_Wait)

#ifdef ����ģʽ

#define �׾������� 3
#define �׾�������ѭ���� 50
#define �׾������Բ�ѭ��
#endif // ����ģʽ

template <typename _ManT>
class ModernWarAI
{
public:
	ModernWarAI() {};
	~ModernWarAI() {};
	�׾�::�׾�ϵͳ _�׾�ϵͳ;
	typedef _ManT ManT;
	
private:
	

	void ϵͳ��ʼ��();
	void ������()
	{
		�л���(�׾�::��);
		�׾������忪ʼ(���AI, ��AI);
		������(ʱ��, ����, ������(9));
		������(����, ����, ����(����));
		����(ʱ��); ����(����);
		�׾����������;
	}
	void �����()
	{
		�׾������忪ʼ(�����AI, ��AI);
		������(������.����.�ż�����, ����, ������(11));
		������(������.����, ����, ����(��ʼ״̬));
		������(������.������������, ����, ������(0));
		������(������.���ʹ�����, ����, ������(0));
		������(������.��������, ����, ������(0));
		������(������.�ܼƸ�����, ����, ������(0));
		������(������.���������, ����, ������(0));

		�������ʽ(�������, ����ָ��, ʽ(����, ������(2), ������(1)));
		�������ʽ(AI����.�ȴ�, ����ָ��, ʽ(����, ������(1), ������(1)));

		//������(����.��, ����ָ��, ����(����));
		//�������ʽ(����.��Ҫ����, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(С��, ����(������.����.�ż�����), ������(13))));
		//�������ʽ(����.��Ҫ����, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(С��, ����(������.��������), ������(3))));
		//�������ʽ(����.��Ҫ�ż�, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(����, ����(������.��������), ������(3))));
#ifdef ����ģʽ1
		�������ʽ(����.��Ҫ����, ��������, ʽ(С��, ����(������.����.�ż�����), ������(100)));
		�������ʽ(����.��Ҫ����, ��������, ʽ(��, ʽ(����, ����(������.���ʹ�����), ������(60)), ʽ(С��, ����(������.������������), ������(60))));
		�������ʽ(����.��Ҫ�ż�, ��������, ʽ(����, ����(������.������������), ������(50)));
		�������ʽ(����.��Ҫ���ʹ���, ��������, ʽ(С��, ����(������.���ʹ�����), ������(100)));
#else
		�������ʽ(����.��Ҫ����, ��������, ʽ(С��, ����(������.����.�ż�����), ������(13)));
		�������ʽ(����.��Ҫ����, ��������, ʽ(��, ʽ(����, ����(������.���ʹ�����), ������(25000)), ʽ(С��, ����(������.������������), ������(25000))));
		�������ʽ(����.��Ҫ�ż�, ��������, ʽ(����, ����(������.������������), ������(25000)));
		�������ʽ(����.��Ҫ���ʹ���, ��������, ʽ(С��, ����(������.���ʹ�����), ������(500)));
#endif

		������(������, ����ָ��, ������(0)); //����(������);

		�׾���־(�����.������־, ���ַ�����("������="), ����(������), ���ַ�����("��ǰ����="), ����(������.����),
			���ַ�����("�ֿ⹭����="), ����(������.����.�ż�����), ���ַ�����("����������="), ����(������.������������), ���ַ�����("���ʹ�����="), ����(������.���ʹ�����)
		);

		�������ʽ(����.��ֵ���.����, ����ָ��, ʽ(����, ����(������.�ܼƸ�����), ������(1000000)));
		��������(����.��ֵ���, ����ָ��,
			����(��ɢ, ����(������.���������), ������(1)),
			����(��ɢ, ����(������.�ܼƸ�����), ������(-1000000))
		);

		�׾���־(�����.������־, ���ַ�����("������="), ����(������), ���ַ�����("��ǰ����="), ����(������.����),
			���ַ�����("�ֿ⹭����="), ����(������.����.�ż�����), ���ַ�����("����������="), ����(������.������������), ���ַ�����("\r\n���ʹ�����="), ����(������.���ʹ�����),
			���ַ�����("��������="), ����(������.��������),���ַ�����("�ܼƸ�����="), ����(������.�ܼƸ�����), ���ַ�����("���������="), ����(������.���������)
		);
		���溯��(�ƶ�������Ŀ��, ����(�ƶ�), ������(1));

		�Զ�����(�Զ�����.����, ����ָ��, ����(��ɢ, ����(������), ������(1)));
		�Զ�����(�Զ�����.������־, ����ָ��, 
			����������(6000),
			����(����, ����(�����.������־)),
			����(����, ����(����.��ֵ���.����), ����(����.��ֵ���)));

		
		������(��д.����.����, ��д, ������(0), ������(0), ������(0));
		������(��д.�ż�.����, ��д, ������(0), ������(1), ������(0));

		������(����.����.����, ����, ������(0), ������(0), ������(0));
		������(����.�ʺ�.����, ����, ������(0), ������(1), ������(0));

		���溯��(��д.����, ����(��д), ����(��д.����.����));
		���溯��(��д.�ż�, ����(��д), ����(��д.�ż�.����));
		���溯��(����.����, ����(����), ����(����.����.����));
		���溯��(����.�ʺ�, ����(����), ����(����.�ʺ�.����));

		��������(����.�ż�0, ����ָ��,
			//����(Ǩ��, ����(����.��), ����(����)),
			����(Ǩ��, ����(������.����), ����(�ż�)),
			����(����, ����(�����.������־)),
			����(����, ����(��д.�ż�)),
			����������(6000),//�ȴ�90���������ں�ż�
			����(Ǩ��, ����(������.����), ����(�ż�����)),
			����(����, ����(�����.������־))
			//����(Ǩ��, ����(����.��), ����(����))
		);
		��������(����.��������, ����ָ��,
			����(Ǩ��, ����(������.����), ����(��������)),
			����(����, ����(�����.������־)),
			����(����, ����(��д.����)),
			����������(12000),//�ȴ�90���������ں�ż�)
			����(Ǩ��, ����(������.����), ����(������������)),
			����(����, ����(�����.������־))
		);
		��������(����.׼������, ����ָ��,
			����(Ǩ��, ����(������.����), ����(���ݴ�����)),
			����(����, ����(�����.������־)),
			����(����, ����(����.����)),
			����������(12000),//�ȴ�90���������ں�ż�)
			����(��ɢ, ����(������.����.�ż�����), ������(100000)),
			����(����, ����(����.�ʺ�)),
			����������(12000),
			����(��ɢ, ����(������.����.�ż�����), ������(100000)),
			����(Ǩ��, ����(������.����), ����(���ݴ�������)),
			����(����, ����(�����.������־))
		);

		��������(����.׼������, ����ָ��,
			����(Ǩ��, ����(������.����), ����(׼������)),
			����(����, ����(�����.������־)),
			����������(9000),
			����(Ǩ��, ����(������.����), ����(׼�����ͽ���)),
			����(����, ����(�����.������־))
		);
		//����(����.�ż�, ����, ����.�ż�, �������, AI����״̬��.�ż�, AI����״̬��.�ȴ�, 6);
		����״̬��(AI����״̬��.�ȴ�, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ȴ�), ״̬ʽ(ִ��, ����, AI����.�ȴ�));



		���о���(����.׼������, ����, �������, ����.��Ҫ����, �������, ����.׼������, AI����״̬��.�ȴ�);

		���о���(����.�ż�, ����, �������, ����.��Ҫ�ż�, �������, ����.�ż�0, AI����״̬��.�ȴ�);

		���о���(����.����, ����, �������, ����.��Ҫ����, �������, ����.��������, AI����״̬��.�ȴ�);

		���о���(�ƶ�.׼������, ����, �������, ����.��Ҫ���ʹ���, �������, ����.׼������, AI����״̬��.�ȴ�);

		�׾����������;
	}

	void ���()
	{
		�׾������忪ʼ(���AI, ��AI);
		������(������.����.�ż�����, ����, ������(11));
		������(������.����, ����, ����(��ʼ״̬));
		������(������.������������, ����, ������(0));
		������(������.���ʹ�����, ����, ������(0));
		������(������.��������, ����, ������(0));
		������(������.�ܼƸ�����, ����, ������(0));
		������(������.���������, ����, ������(0));

		�������ʽ(�������, ����ָ��, ʽ(����, ������(2), ������(1)));
		�������ʽ(AI����.�ȴ�, ����ָ��, ʽ(����, ������(1), ������(1)));



		������(������, ����ָ��, ������(0)); //����(������);

		�׾���־(���.������־, ���ַ�����("������="), ����(������), ���ַ�����("��ǰ����="), ����(������.����),
			���ַ�����("�ֿ⹭����="), ����(������.����.�ż�����), ���ַ�����("����������="), ����(������.������������), ���ַ�����("���ʹ�����="), ����(������.���ʹ�����)
		);

		�������ʽ(����.��ֵ���.����, ����ָ��, ʽ(����, ����(������.�ܼƸ�����), ������(1000000)));
		��������(����.��ֵ���, ����ָ��,
			����(��ɢ, ����(������.���������), ������(1)),
			����(��ɢ, ����(������.�ܼƸ�����), ������(-1000000))
		);

		�׾���־(���.������־, ���ַ�����("������="), ����(������), ���ַ�����("��ǰ����="), ����(������.����),
			���ַ�����("�ֿ⹭����="), ����(������.����.�ż�����), ���ַ�����("����������="), ����(������.������������), ���ַ�����("\r\n���ʹ�����="), ����(������.���ʹ�����),
			���ַ�����("��������="), ����(������.��������), ���ַ�����("�ܼƸ�����="), ����(������.�ܼƸ�����), ���ַ�����("���������="), ����(������.���������)
		);
		���溯��(�ƶ���Ŀ��, ����(�ƶ�), ������(1));
		
		������(Ŀ�����, Ŀ��, ������(9600), ������(50), ������(10800));
		������(Ŀ��A, Ŀ��, ������(8000), ������(600), ������(7750));
		������(Ŀ��B,Ŀ��, ������(10000), ������(60), ������(7750));
		������(Ŀ��C, Ŀ��, ������(10500), ������(120), ������(11000));
		������(Ŀ��D, Ŀ��, ������(7000), ������(100), ������(7000));
		������(Ŀ��E, Ŀ��, ������(7000), ������(100), ������(10700));
		������(Ŀ��F, Ŀ��, ������(7000), ������(1000), ������(10700));

		���溯��(����Ŀ�����, ����(Ŀ��), ����(Ŀ�����));
		���溯��(����Ŀ��A, ����(Ŀ��), ����(Ŀ��A));
		���溯��(����Ŀ��B, ����(Ŀ��), ����(Ŀ��B));
		���溯��(����Ŀ��C, ����(Ŀ��), ����(Ŀ��C));
		���溯��(����Ŀ��D, ����(Ŀ��), ����(Ŀ��D));
		���溯��(����Ŀ��E, ����(Ŀ��), ����(Ŀ��E));
		���溯��(����Ŀ��F, ����(Ŀ��), ����(Ŀ��F));

		�Զ�����(�Զ�����.����, ����ָ��,
			�������������(1500, 500),
			����(��ɢ, ����(������), ������(1)),
			����(����, ����(���.������־)),
			����(����, ����(����Ŀ�����)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500),

			����(����, ����(����Ŀ��A)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500),

			����(����, ����(����Ŀ��B)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500),

			����(����, ����(����Ŀ��C)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500),

			����(����, ����(����Ŀ��D)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500),

			����(����, ����(����Ŀ��E)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500),

			����(����, ����(����Ŀ��F)),
			����(����, ����(�ƶ���Ŀ��)),
			�������������(10500, 3500)
		);
		

		�׾����������;
	}

	void ����()
	{
		�׾������忪ʼ(����AI, ��AI);
		������(���ܱ�.����.��������, ����, ������(11));
		������(���ܱ�.����, ����, ����(��ʼ״̬));
		������(���ܱ�.���ش�������, ����, ������(0));
		������(���ܱ�.���ʹ�����, ����, ������(0));
		������(���ܱ�.��������, ����, ������(0));
		������(���ܱ�.�ܼƸ�����, ����, ������(0));
		������(���ܱ�.���������, ����, ������(0));

		�������ʽ(�������, ����ָ��, ʽ(����, ������(2), ������(1)));
		�������ʽ(AI����.�ȴ�, ����ָ��, ʽ(����, ������(1), ������(1)));

		//������(����.��, ����ָ��, ����(����));
		//�������ʽ(����.��Ҫ����, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(С��, ����(������.����.�ż�����), ������(13))));
		//�������ʽ(����.��Ҫ����, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(С��, ����(������.��������), ������(3))));
		//�������ʽ(����.��Ҫ�ż�, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(����, ����(������.��������), ������(3))));
		
		�������ʽ(����.��Ҫ����, ��������, ʽ(С��, ����(���ܱ�.����.��������), ������(13)));
		�������ʽ(����.��Ҫ���ʹ���, ��������, ʽ(С��, ����(���ܱ�.���ʹ�����), ������(2500)));
		�������ʽ(����.��Ҫ����, ��������, ʽ(��, ʽ2(��, ����(����.��Ҫ���ʹ���)), ʽ(С��, ����(���ܱ�.���ش�������), ������(2000))));

		//���ʹ�������26000,������������20000�������
		�������ʽ(����.��Ҫ����, ��������, ʽ(��, ʽ2(��, ����(����.��Ҫ���ʹ���)), ʽ(����, ����(���ܱ�.���ش�������), ������(2000))));
		//�������ʽ(����.��Ҫ����, ��������, ʽ(��, ʽ(����, ����(���ܱ�.���ʹ�����), ������(500)), ʽ(����, ����(���ܱ�.��������), ������(5000))));
		

		������(������, ����ָ��, ������(0)); //����(������);

		�׾���־(����.������־, ���ַ�����("������="), ����(������), ���ַ�����("��ǰ����="), ����(���ܱ�.����),
			���ַ�����("�ֿ�������="), ����(���ܱ�.����.��������), ���ַ�����("���ش�����="), ����(���ܱ�.���ش�������), ���ַ�����("���ʹ�����="), ����(���ܱ�.���ʹ�����)
		);

		�������ʽ(����.��ֵ���.����, ����ָ��, ʽ(����, ����(���ܱ�.�ܼƸ�����), ������(1000000)));
		��������(����.��ֵ���, ����ָ��,
			����(��ɢ, ����(���ܱ�.���������), ������(1)),
			����(��ɢ, ����(���ܱ�.�ܼƸ�����), ������(-1000000))
		);
		�׾���־(����.������־, ���ַ�����("������="), ����(������), ���ַ�����("��ǰ����="), ����(���ܱ�.����),
			���ַ�����("�ֿ�������="), ����(���ܱ�.����.��������), ���ַ�����("���ش�����="), ����(���ܱ�.���ش�������), ���ַ�����("\r\n���ʹ�����="), ����(���ܱ�.���ʹ�����),
			���ַ�����("��������="), ����(���ܱ�.��������), ���ַ�����("�ܼƸ�����="), ����(���ܱ�.�ܼƸ�����), ���ַ�����("���������="), ����(���ܱ�.���������)
		);
		���溯��(�ƶ�������Ŀ��, ����(�ƶ�), ������(1));

		�Զ�����(�Զ�����.����, ����ָ��, ����(��ɢ, ����(������), ������(1)));
		�Զ�����(�Զ�����.������־, ����ָ��, 
			����������(6000),
			����(����, ����(����.������־)),
			����(����, ����(����.��ֵ���.����), ����(����.��ֵ���))
		);

		��������(����.����, ����ָ��,
			//����(Ǩ��, ����(����.��), ����(����)),
			����(Ǩ��, ����(���ܱ�.����), ����(����)),
			����(����, ����(����.������־)),

			����������(3000),//�ȴ�90���������ں�ż�
			����(Ǩ��, ����(���ܱ�.����), ����(��������)),
			����(����, ����(����.������־))
			//����(Ǩ��, ����(����.��), ����(����))
		);
		��������(����.��������, ����ָ��,
			����(Ǩ��, ����(���ܱ�.����), ����(��������)),
			����(����, ����(����.������־)),
			����������(4000),//�ȴ�90���������ں�ż�)
			����(Ǩ��, ����(���ܱ�.����), ����(������������)),
			����(����, ����(����.������־))
		);
		��������(����.׼������, ����ָ��,
			����(Ǩ��, ����(���ܱ�.����), ����(���ݴ�����)),
			����(����, ����(����.������־)),
			����������(1000),//�ȴ�90���������ں�ż�)
			����(��ɢ, ����(���ܱ�.����.��������), ������(70000)),
			����������(1000),
			����(��ɢ, ����(���ܱ�.����.��������), ������(70000)),
			
			����(Ǩ��, ����(���ܱ�.����), ����(���ݴ�������)),
			����(����, ����(����.������־))
		);

		��������(����.׼������, ����ָ��,
			����(Ǩ��, ����(���ܱ�.����), ����(׼������)),
			����(����, ����(����.������־)),
			����������(3000),//�ȴ�90���������ں�ż�)
			����(����, ����(����.������־)),
			����������(3000),//�ȴ�90���������ں�ż�)
			����(Ǩ��, ����(���ܱ�.����), ����(׼�����ͽ���)),
			����(����, ����(����.������־))
		);
		//����(����.�ż�, ����, ����.�ż�, �������, AI����״̬��.�ż�, AI����״̬��.�ȴ�, 6);
		����״̬��(AI����״̬��.�ȴ�, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ȴ�), ״̬ʽ(ִ��, ����, AI����.�ȴ�));

		

		���о���(����.׼������, ����, �������, ����.��Ҫ����, �������, ����.׼������, AI����״̬��.�ȴ�);

		���о���(����.����, ����, �������, ����.��Ҫ����, �������, ����.����, AI����״̬��.�ȴ�);

		���о���(����.����, ����, �������, ����.��Ҫ����, �������, ����.��������, AI����״̬��.�ȴ�);

		���о���(�ƶ�.׼������, ����, �������, ����.��Ҫ���ʹ���, �������, ����.׼������, AI����״̬��.�ȴ�);

		�׾����������;
	}
	
	void ���Զ���()
	{
		�л���(�׾�::��);
		�׾������忪ʼ(������AI, ��������);
		����(��������);
		����(��������);
		�׾����������;
	}
	void ������()
	{
		�׾������忪ʼ(������AI, ��������);

		�������ʽ(AI����.�ƶ�, ����ָ��, ʽ(��, ������(1), ������(2)));
		�������ʽ(AI����.�ȴ�, ����ָ��, ʽ(��, ������(1), ������(3)));

		//����״̬��(AI����״̬��.����, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ƶ�), ״̬ʽ(ִ��, ����, AI����.�ƶ�));
		//����״̬��(AI����״̬��.����, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ƶ�), ״̬ʽ(ִ��, ����, AI����.�ƶ�));

		//����״̬��(AI����״̬��.����, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ƶ�), ״̬ʽ(ִ��, ����, AI����.�ƶ�));
		//����״̬��(AI����״̬��.��׳���, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ƶ�), ״̬ʽ(ִ��, ����, AI����.�ƶ�));
		����״̬��(AI����״̬��.�ȴ�, ����ָ��, ״̬ʽ(��ʼ, ִ��2, AI����.�ƶ�), ״̬ʽ(ִ��2, ����, AI����.�ƶ�));
		
		�������ʽ(�������, ����ָ��, ʽ(����, ������(2), ������(1)));
		//�������ʽ(�������ʽ2, ����ָ��, ʽ(����, ����(�������ʽ), ������(0)));
		/*
		��������ʼ(AI����2.�����ƶ�, ����ָ��);
			����(�ƶ�);
			������(Ŀ������.��ע, ��ע, ����(�ȴ�����), ������(4), ������(5), ������(6));
			������(��ʼ����, ����, ������(300), ������(100), ������(400));
			������(Ŀ������, ����, ������(3000), ������(1000), ������(4000), ����(��ע));
			����(��ʼ����);
			����(Ŀ������);
		����������;
		*/
		//����״̬
		
		//�������ʽ(״̬.����, ����ָ��, ʽ(����, ������(1), ����(����)));
		//�������ʽ(״̬.����, ����ָ��, ʽ(����, ����(״̬), ����(����)));
		//�������ʽ(״̬.ʿ����, ����ָ��, ʽ(С��, ����(״̬), ������(30)));

		//����
		//�������ʽ(����.����, ����ָ��, ʽ(����, ����(����.Ŀ��), ����(����)));
		//�������ʽ(����.�任����, ����ָ��, ʽ(����, ����(����.Ŀ��), ����(�任����)));
		//�������ʽ(����.�任Բ��, ����ָ��, ʽ(����, ����(����.Ŀ��), ����(�任Բ��)));

		//�������ʽ(����.�ż�, ����ָ��, ʽ(����, ����(����.Ŀ��), ����(10)));
		//�������ʽ(����.�ż�, ����ָ��, ʽ(����, ����(�����AI.������.����.�ż�����), ������(3)));
		//������(����.��, ����ָ��, ����(����));

		������(״̬.����, ״̬��Ϣ, ����(��ʼ״̬));// ����(״̬.����);
		������(״̬.���;���, ״̬��Ϣ, ����(δ����));
		������(״̬.��������, ״̬��Ϣ, ����(δ����));
		//ʽ(����, ����(����.��), ����(����)),
		/*
		�������ʽ(����.�ż�, ����ָ��, ʽ(��, ʽ(����, ����(����.��), ����(����)), ʽ(��, ʽ(����, ����(״̬.����), ����(��������)), ʽ(��,
			ʽ(����, ����(�����AI.������.����), ����(�ż�)),
			ʽ(����, ����(�����AI.������.����.�ż�����), ������(4))))));
			*/
		�������ʽ(����.�ż�, ����ָ��, ʽ(��, ʽ(����, ����(�����AI.������.����), ����(�ż�)), ʽ(��, ʽ(����, ����(״̬.��������), ����(�Ѿ���)),
			ʽ(����, ����(�����AI.������.����.�ż�����), ������(4)))));

		//�������ʽ(����.׼������, ����ָ��, ʽ(��, ʽ(����, ����(״̬.���;���), ����(δ����)), ʽ(����, ����(�����AI.������.����), ����(׼������))));
		�������ʽ(����.׼������, ����ָ��, ʽ(����, ����(״̬.���;���), ����(δ����)));
		�������ʽ(����.����, ����ָ��, ʽ(����, ����(��ɫ.״̬), ��ɫ״̬_����));
		/*
		�������ʽ(����.�ż�, ����ָ��,  ʽ(��,
			ʽ(����, ����(�����AI.������.����), ����(�ż�)),
			ʽ(����, ����(�����AI.������.����.�ż�����), ������(3))));
		*/
		�������ʽ(����.����, ����ָ��,
			ʽ(��, ʽ(����, ����(�����AI.������.����), ����(��������)),
				ʽ(��, ʽ(����, ����(״̬.��������), ����(δ����)), ʽ(����, ����(״̬.���;���), ����(�Ѿ���)))
			));
		//����(�������ʽ);
		/*����(AI����.����);
		����(AI����.�ż�); ����(AI����.����); ����(AI����.��׳���); ����(AI����.�����ƶ�);
		*/
		//������(����������, ����, ����(������), ����(�������ʽ), ����(AI����.����),����(7));
		//
#ifdef ��������
			/*
			�Զ�����(AI����.�ż�0, ����ָ��,
				����(��ɢ,����(�����AI.������.����.�ż�����), ������(-1)),
				����(��ɢ, ����(�����AI.������.����.�ż�����), ������(-1)));
			*/
		�Զ�����(AI����.�ż�0, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(-1)));
		�Զ�����(AI����.�ż�1, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(-1)));


		�Զ�����(AI����.�ż�2, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(1)));
		�Զ�����(AI����.�ż�3, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(1)));
		/*
		�Զ�����(AI����.�ż�4, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(1)));
		�Զ�����(AI����.�ż�5, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(1)));
		�Զ�����(AI����.�ż�6, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(1)));
		�Զ�����(AI����.�ż�7, ����ָ��, ����(��ɢ, ����(�����AI.������.����.�ż�����), ������(1)));
		*/
		//����(����.�ż�, ����ָ��, ����(��й), ����(�����AI.������.����.�ż�����), ������(1));
		//���ж���(����.�ż�, ����ָ��, ������(1));
#else

		�������ʽ(��������, ����ָ��, ʽ(��, ʽ(����, ����(�����AI.������.������������), ������(65535)), ʽ(С��, ����(�����AI.������.������������), ������(4))));
		//�������ʽ(��������, ����ָ��, ʽ(������, ����(״̬.����), ����(��������)));
		�׾�������־(������־, ����(��������), ���ַ�����("������="), ����(�����AI.������), ���ַ�����(" ��ǰ����="), ����(�����AI.������.����), ����(״̬.����),
			���ַ�����(" �ֿ⹭����="), ����(�����AI.������.����.�ż�����), ���ַ�����(" ������������="), ����(�����AI.������.������������)
		);

		���溯��(����.��������, ����(����), ����_��׼);
		���溯��(����.�ż�, ����(���), ����_����);
		���溯��(����.����, ����(����), ����_�շ�);
		���溯��(����.װ��, ����(����), ����_����);
		���溯��(����.����, ����(����), ����_�շ�);

		��������(AI����.�ż�0, ����ָ��,
			//����(Ǩ��, ����(����.��), ����(����)), 
			//����(����, ����(������־)),
			����(Ǩ��, ����(״̬.��������), ����(δ����)),
			����(��ɢ, ����(�����AI.������.������������), ������(-1)),
			����(��ɢ, ����(�����AI.������.����.�ż�����), ������(-3)),

			����(Ǩ��, ����(״̬.����), ����(�ż�)),

			//����(����, ����(������־)),
			�������������(2000, 1700),
			����(����, ����(����.�ż�)),
			//�������������(1000, 500),
			�������������(1200, 500),
			����(����, ����(����.��������)),

			�������������(1200, 500),
			����(����, ����(����.�ż�)),

			�������������(1200, 300),
			����(����, ����(����.��������)),

			�������������(1200, 500),
			����(����, ����(����.�ż�)),

			//�������������(1000, 500),

			//����(��ɢ, ����(�����AI.������.��������), ������(1)),
			//����(��ɢ, ����(�����AI.������.���ʹ�����), ������(-1)),
			
			����(Ǩ��, ����(״̬.����), ����(�ż�����))
			//����(Ǩ��, ����(����.��), ����(����))
		);

		��������(AI����.����, ����ָ��,
			//����(Ǩ��, ����(����.��), ����(����)),
			����(Ǩ��, ����(״̬.��������), ����(�Ѿ���)),
			����(��ɢ, ����(�����AI.������.������������), ������(1)),
			����(Ǩ��, ����(״̬.����), ����(׼����������)),

			�������������(1200, 500),
			����(����, ����(����.��������)),
			�������������(1200, 500),


			//����������(1000),
			
			����(Ǩ��, ����(״̬.����), ����(��������))
			
			
			//����(Ǩ��, ����(����.��), ����(����))
			//
		);
		���溯��(�ƶ�������Ŀ��, ����(�ƶ�), ������(1));

		��������(AI����.׼������, ����ָ��,
			����(Ǩ��, ����(״̬.����), ����(׼��������)),
			�������������(3000, 1000),
			����(����, ����(�ƶ�������Ŀ��)),
			
			�������������(3000, 1000),
			����(Ǩ��, ����(״̬.���;���), ����(�Ѿ���)),
			����(��ɢ, ����(�����AI.������.���ʹ�����), ������(1)),
			����(Ǩ��, ����(״̬.����), ����(׼�����ͽ���))
		);
		//����(����.�ż�, ����, ����.�ż�, �������, AI����״̬��.�ż�, AI����״̬��.�ȴ�, 6);
		//����״̬��(AI����״̬��.�ż�, ����ָ��, ״̬ʽ(��ʼ, ִ��, AI����.�ż�0), ״̬ʽ(ִ��, ����, AI����.�ȴ�));
		//����(����.�ż�, ����, ����.�ż�, �������, AI����״̬��.�ż�, AI����״̬��.�ȴ�, 6);
		�������ʽ(����.���;���.����, ����ָ��,  ʽ(������, ����(״̬.���;���), ����(δ����)));
		��������(����.���;���, ����ָ��,
			����(��ɢ, ����(�����AI.������.���ʹ�����), ������(-1)),
			����(Ǩ��, ����(״̬.���;���), ����(δ����))
		);
		�������ʽ(����.��������.����, ����ָ��, ʽ(������, ����(״̬.��������), ����(δ����)));
		��������(����.��������, ����ָ��,
			����(��ɢ, ����(�����AI.������.������������), ������(-1)),
			����(Ǩ��, ����(״̬.��������), ����(δ����))
			);

		��������(AI����.����, ����ָ��,
			����(Ǩ��, ����(״̬.����), ����(׼��������)), 
			����(����, ����(����.���;���.����), ����(����.���;���)),
			����(����, ����(����.��������.����), ����(����.��������)),
			����(��ɢ, ����(�����AI.������.��������), ������(1)),
			����(��ɢ, ����(�����AI.������.�ܼƸ�����), ������(1)),

			
			�������������(30000, 5000),
			//����(Ǩ��, ����(��ɫ.״̬), ��ɫ״̬_�ȴ�),
			����(����, ����(����.����)),
			�������������(1500, 300),
			����(����, ����(����.����)),
			
			
			
			����(��ɢ, ����(�����AI.������.��������), ������(-1)),
			//����(��ɢ, ����(״̬.���;���), ����(δ����)),
			
			����(Ǩ��, ����(״̬.����), ����(�������))
		);

		����(����.����, ����, ����.����, �������, AI����.����, AI����״̬��.�ȴ�);
		����(����.����, ����, ����.����, �������, AI����.����, AI����״̬��.�ȴ�);
		����(����.�ż�, ����, ����.�ż�, �������, AI����.�ż�0, AI����״̬��.�ȴ�);
		����(����.׼������, ����, ����.׼������, �������, AI����.׼������, AI����״̬��.�ȴ�);
		//����(����������1, ����, �������ʽ, �������, AI����״̬��.����, AI����.�ȴ�, 6);

#ifndef ����ģʽ

			//����(����������, ����, �������ʽ, �������, AI����״̬��.����, AI����״̬��.�ȴ�);
			//����(����.�ż�, ����, ����.�ż�, �������, AI����״̬��.�ż�, AI����״̬��.�ȴ�);

			//����(����������1, ����, �������ʽ2, �������, AI����״̬��.����, AI����.�ȴ�);
			/*
			����(����������, ����, ״̬.����, �������, AI����״̬��.����, AI����״̬��.�ȴ�);
			//����(����������, ����, ״̬.����, �������, AI����״̬��.����, AI����.�ȴ�;
			//����(ʿ��������, ����, ״̬.ʿ����, �������, AI����״̬��.����, AI����.�ȴ�);
			//����(����.�ż�, ����, ����.�ż�, �������, AI����״̬��.����, AI����.�ȴ�);

			����(�˳�������, ����, ����.����, �������, AI����״̬��.����, AI����״̬��.�ȴ�);
			����(ȱ��, ����, ״̬.ʿ����, �������, AI����״̬��.����, AI����״̬��.�ȴ�);
			����(�任����.����, ����, ����.�任����, �������, AI����״̬��.����, AI����״̬��.�ȴ�);
			*/

#endif
			//����(�任����.Բ��, ����, ����.�任Բ��, �������, AI����.����, AI����.�ȴ�, 6);

#endif

			//����(�������ʽ);
			//����(�������ʽ);
			//����(�������ʽ1);
			//����(�������ʽ2);
			//����(�������ʽ2);
			//����(�������ʽ2);
			//����(����������);


			//����(ˮ, 1, 2, 3, 4, 5, 6, 7, 8, 9);
			//�������ʽ(�˷���, ���ͼ���, ʽ(��, ����(ˮ), ����(ˮ)));
			//���Դ�ӡ(�˷���);
			//*/
		�׾����������;
	}
	void ���ܱ�()
	{
		�׾������忪ʼ(���ܱ�AI, ��������);

		
		
		�������ʽ(�������, ����ָ��, ʽ(����, ������(2), ������(1)));
		
		�������ʽ(����.����, ����ָ��, ʽ(����, ����(��ɫ.״̬), ��ɫ״̬_����)); 
		������(����.��, ����ָ��, ����(����));

		������(״̬.����, ״̬��Ϣ, ����(��ʼ״̬));// ����(״̬.����);
		
		�������ʽ(����.����, ����ָ��, ʽ(��, ʽ(����, ����(����AI.���ܱ�.����), ����(����)), ʽ(��, ʽ(����, ����(״̬.����), ����(��������)),
			ʽ(����, ����(����AI.���ܱ�.����.��������), ������(4)))));

		�������ʽ(����.׼������, ����ָ��, ʽ(��, ʽ(����, ����(����AI.���ܱ�.����), ����(׼������)),
			ʽ(����, ����(״̬.����), ����(�������))
		));
		
		�������ʽ(����.��������, ����ָ��,
			ʽ(��, ʽ(����, ����(����AI.���ܱ�.����), ����(��������)),
				ʽ(������, ����(״̬.����), ����(��������))));
		

		�������ʽ(��������, ����ָ��, ʽ(��, ʽ(����, ����(����AI.������.��������), ������(65535)), ʽ(С��, ����(����AI.���ܱ�.��������), ������(4))));
		//�������ʽ(��������, ����ָ��, ʽ(������, ����(״̬.����), ����(��������)));
		�׾�������־(������־, ����(��������), ���ַ�����("������="), ����(����AI.������), ���ַ�����(" ��ǰ����="), ����(����AI.���ܱ�.����), ����(״̬.����),
			���ַ�����(" �ֿ⹭����="), ����(����AI.���ܱ�.����.��������), ���ַ�����(" ������������="), ����(����AI.���ܱ�.��������)
		);

		���溯��(����.����, ����(����), ����_��);
		���溯��(����.����, ����(���), ����_����);
		���溯��(����.����, ����(����), ����_�շ�);
		���溯��(����.װ��, ����(����), ����_����);
		���溯��(����.����, ����(����), ����_����);

		��������(AI����.����, ����ָ��,
			//����(Ǩ��, ����(����.��), ����(����)), 
			//����(����, ����(������־)),
			����(Ǩ��, ����(״̬.����), ����(����)),

			����(��ɢ, ����(����AI.���ܱ�.���ش�������), ������(-1)),
			����(��ɢ, ����(����AI.���ܱ�.����.��������), ������(-1)),
			//����(����, ����(������־)),
			
			�������������(2000, 1000),
			����(����, ����(����.����)),
			�������������(2000, 1000),
			//����(��ɢ, ����(����AI.������.��������), ������(1)),
			����(Ǩ��, ����(״̬.����), ����(��ʼ״̬))
			//����(Ǩ��, ����(����.��), ����(����))
		);

		��������(AI����.����, ����ָ��,
			//����(Ǩ��, ����(����.��), ����(����)),
			����(Ǩ��, ����(״̬.����), ����(׼������)),
			����(��ɢ, ����(����AI.���ܱ�.���ش�������), ������(1)),
			�������������(3000, 1000),
			����(����, ����(����.����)),
			�������������(3000, 1000),
			//����������(1000),
			
			����(Ǩ��, ����(״̬.����), ����(��������))//,

			//����(Ǩ��, ����(����.��), ����(����))
			//
		);
		���溯��(�ƶ�������Ŀ��, ����(�ƶ�), ������(1));

		��������(AI����.׼������, ����ָ��,
			����(Ǩ��, ����(״̬.����), ����(׼��������)),
			�������������(3000, 1000),
			����(����, ����(�ƶ�������Ŀ��)),
			
			�������������(3000, 1000),

			����(Ǩ��, ����(״̬.����), ����(׼�����ͽ���)),
			����(��ɢ, ����(����AI.���ܱ�.���ʹ�����), ������(1))
		);

		��������(AI����.�ȴ�, ����ָ��,
			����(Ǩ��, ����(״̬.����), ����(���еȴ�)),
			�������������(3000, 1000),
			�������������(3000, 1000),
			����(Ǩ��, ����(״̬.����), ����(���еȴ�����))
		);

		�������ʽ(AI����.�ȴ�, ����ָ��, ʽ(��, ������(1), ������(3)));
		��������(AI����.����, ����ָ��,
			����(Ǩ��, ����(״̬.����), ����(׼��������)),
			����(��ɢ, ����(����AI.���ܱ�.���ʹ�����), ������(-1)),
			����(��ɢ, ����(����AI.���ܱ�.�ܼƸ�����), ������(1)),
			����(��ɢ, ����(����AI.���ܱ�.��������), ������(1)),
			�������������(30000, 5000),
			//����(Ǩ��, ����(��ɫ.״̬), ��ɫ״̬_�ȴ�),
			����(����, ����(����.����)),
			����(��ɢ, ����(����AI.���ܱ�.��������), ������(-1)),
			�������������(1500, 500),
			����(����, ����(����.����)),
			

			����(Ǩ��, ����(״̬.����), ����(�������))
		);
		
		����(����.����, ����, ����.����, �������, AI����.����, AI����.�ȴ�);

		����(����.����, ����, ����.��������, �������, AI����.����, AI����.�ȴ�);
		����(����.����, ����, ����.����, �������, AI����.����, AI����.�ȴ�);
		����(����.׼������, ����, ����.׼������, �������, AI����.׼������, AI����.�ȴ�);


		�׾����������;
	}

	void �����()
	{
		�л���(�׾�::��);
		�����();
		����();
		���();
	}

	void ������()
	{
		//�л�ϵͳ(_�׾�ϵͳ);
		�л���(�׾�::��);
		
		������();
		���ܱ�();

	}
	void ������()
	{
		_�׾�ϵͳ._�����׾���(�׾�::��, "���AI", 0, 0, 0, "���AI", NULL);
	}
	void �����()
	{
		_�׾�ϵͳ._�����׾���(�׾�::��, "�����AI", 1, 0, 0, "�����AI", NULL);
		_�׾�ϵͳ._�����׾���(�׾�::��, "����AI", 2, 0, 0, "����AI", NULL);
	}
#ifdef ��ҳ�ڴ�
	//vector<������״̬��, yss_allocator<������״̬��, MemoryMgr_FreeListSmall>> m_������;
#else
	//vector<������״̬��> m_������;
#endif
	void Make()
	{
		������();
		�����();
		//for (unsigned int n = 0; n < 65536; n++)
		{
			//������();
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
		//m_������.resize(�׾�������);
		//_�׾�ϵͳ._�����׾���(�׾�::��, "������AI", 2, 0, 1, "������AI", &m_������[2]);
		//for (int i = 3; i < �׾�������;i++)
#ifdef _USING_UFT8CODE_
		string szAiName = GetAiName(szManAIName);
#else
		string szAiName = szManAIName;
#endif

		{
			
			//_�׾�ϵͳ._�����׾���(�׾�::��, "AI", i, �׾�::��, "������AI", &m_������[i]);
			return _�׾�ϵͳ._��ģ�幹���׾���(�׾�::��, szAiName.c_str(), pMachineState, nNature, nSociety);
		}
		//_�׾�ϵͳ._�����׾���(�׾�::��, "AI", 1, �׾�::��, "������AI");
	}

	unsigned int MakeTerrainAI(char * szManAIName, void * pMachineState, unsigned int nNature = 0, unsigned int nSociety = 0)
	{
		//m_������.resize(�׾�������);
		//_�׾�ϵͳ._�����׾���(�׾�::��, "������AI", 2, 0, 1, "������AI", &m_������[2]);
		//for (int i = 3; i < �׾�������;i++)
#ifdef _USING_UFT8CODE_
		string szAiName = GetAiName(szManAIName);
#else
		string szAiName = szManAIName;
#endif
		{

			//_�׾�ϵͳ._�����׾���(�׾�::��, "AI", i, �׾�::��, "������AI", &m_������[i]);
			return _�׾�ϵͳ._��ģ�幹���׾���(�׾�::��, szAiName.c_str(), pMachineState, nNature, nSociety);
		}
		//_�׾�ϵͳ._�����׾���(�׾�::��, "AI", 1, �׾�::��, "������AI");
	}

	void ���Զ���()
	{
		_�׾�ϵͳ.����_������();
	}
	void ����ʵ��()
	{
		_�׾�ϵͳ.����_��ʵ��();
	}
	ULONGLONG ��ʱ;
	void Begin()
	{
		if ((_�׾�ϵͳ.m_���� % �׾�������ѭ����) == 1)
		{
			��ʱ = ::GetTickCount64us();
		}
		_�׾�ϵͳ.m_����++;
		_�׾�ϵͳ.����((unsigned int)0, true);
		_�׾�ϵͳ.����((unsigned int)1, true);
		_�׾�ϵͳ.����((unsigned int)2, true);
#ifdef ͳ����Ϣ
		_�׾�ϵͳ.m_��ֵ��_����ʽ = _�׾�ϵͳ.m_��ֵ��_������ = _�׾�ϵͳ.m_��ֵ��_״̬�� = _�׾�ϵͳ.m_��ֵ��_����ʽ��ֵ = 0;
#endif
	}
	void End()
	{
		

#ifdef ͳ����Ϣ
		if ((_�׾�ϵͳ.m_���� % �׾�������ѭ����) == 1)
		{
			��ʱ = ::GetTickCount64us() - ��ʱ;
			ULONGLONG ÿ��ָ��ִ���� = _�׾�ϵͳ.m_��ֵ��_����ʽ + _�׾�ϵͳ.m_��ֵ��_������ + _�׾�ϵͳ.m_��ֵ��_״̬�� + _�׾�ϵͳ.m_��ֵ��_����ʽ��ֵ;
			_�׾�ϵͳ.�׾�����־("�׾�������(%u)��������(%0.2f) ��ʱ%llums %.4f�ײ���ÿ�� ����״��(%llu(%llu)-%llu-%llu-%llu) %.2fMips\r\n",
				_�׾�ϵͳ.m_�׾���ʵ����.size(), ((double)�׾�������ѭ���� * 1000) / (double)(��ʱ / 1000), ��ʱ / 1000, ((double)�׾�������ѭ���� * _�׾�ϵͳ.m_�׾���ʵ����.size()) / ��ʱ,
				_�׾�ϵͳ.m_��ֵ��_����ʽ, _�׾�ϵͳ.m_��ֵ��_����ʽ��ֵ, _�׾�ϵͳ.m_��ֵ��_������, _�׾�ϵͳ.m_��ֵ��_״̬��,
				ÿ��ָ��ִ����, ((double)�׾�������ѭ���� * ÿ��ָ��ִ����) / ��ʱ);
		}
		

#else
		//_�׾�ϵͳ.�׾�����־("�׾�������(%u)��������(%u) ��ʱ%llums %.4fM����ÿ��\r\n", �׾�������, �׾�������ѭ����, ��ʱ/1000, ((double)�׾�������ѭ���� * �׾�������) / ��ʱ);
#endif
	}
	unsigned int GetAIStepTimeout()
	{
		return 1000000 / �׾�������;
	}
	void Action(unsigned int i,bool bLock=false)
	{
		_�׾�ϵͳ.����(i, bLock);
	}

	void Action()
	{
#ifdef ͳ����Ϣ
		_�׾�ϵͳ.m_��ֵ��_����ʽ = _�׾�ϵͳ.m_��ֵ��_������ = _�׾�ϵͳ.m_��ֵ��_״̬�� = _�׾�ϵͳ.m_��ֵ��_����ʽ��ֵ = 0;
#endif
		_�׾�ϵͳ.����();
	}

	void Init(unsigned int nContainerID, ManT * pManSystem)
	{
		_�׾�ϵͳ.m_����ID = nContainerID;
		_�׾�ϵͳ.��ʼ��(pManSystem);
		ϵͳ��ʼ��();
		//m_pManSystem = pManSystem;

	};
	template<typename ObjectManT>
	void BindMan()
	{
		/*
		������(�׾�::��, ����, ��ɫNPC, ��ɫ״̬, ����);
		������(�׾�::��, ����.Ŀ������, ��ɫNPC, ��ɫ״̬, ����.Ŀ������);
		������32(�׾�::��, ����.Ŀ��, ��ɫNPC, ��ɫ״̬, ����.Ŀ��);
		������32(�׾�::��, ����.״̬, ��ɫNPC, ��ɫ״̬, ����.״̬);
		������(�׾�::��, ��ɫ����, ��ɫNPC, ��ɫ״̬, ��ɫ����);
		������32(�׾�::��, ״̬, ��ɫNPC,��ɫ״̬, ״̬);
		������64(�׾�::��, ��ɫ����, ��ɫNPC, ��ɫ״̬, ����);
		��λ(�׾�::��, �ڲ�״̬.����, ��ɫNPC, ��ɫ״̬, �ڲ�״̬.����);
		������(�׾�::��, ��ɫ�ڲ�״̬, ��ɫNPC, ��ɫ״̬, �ڲ�״̬);
		*/
	}
	void Init1()
	{
		
		������();
		�����();
		������();

		Make();

	};
	void Info()
	{
		_�׾�ϵͳ.����_������Ŵ���();
		//���Զ���();
		���Զ���();
		
#ifdef ����ģʽ
		����ʵ��();

#endif
		_�׾�ϵͳ.����_��ʵ����ֵ��();
	}
	
};

void TestModernWarAI()
{
	ModernWarAI<int> AI;
	AI.Init(0,NULL);
	AI.Init1();
	ULONGLONG ��ʱ = ::GetTickCount64us();
	for (int i = MAN_AI_BASE_POS+1; i < �׾�������; i++)
	{

		//_�׾�ϵͳ._�����׾���(�׾�::��, "AI", i, �׾�::��, "������AI", &m_������[i]);
		AI.MakeManAI("������AI", NULL);
	}
	AI.Info();

	//_�׾�ϵͳ.�׾�����־("�׾������� ��ʱ%ums %u size=%uMB\r\n",��ʱ/1000, �׾�������, �׾�������*sizeof(ModernWarAI::������״̬��)/(1024*1024));
	//if(�׾�������<4)AI.����ʵ��();
	//AI._�׾�ϵͳ.����_��ʵ����ֵ��();
	//AI.����();
	//AI.����();
#ifndef �׾������Բ�ѭ��
	for (;;)
#endif
	{
		
		for (unsigned int i=0;i< �׾�������;i++)
		{
			//Sleep(10);

			AI.Action(i);
		}
		AI.End();
		AI.Begin();
		
	}
}


template <typename _ManT>
void ModernWarAI<_ManT>::ϵͳ��ʼ��()
{
	//��ʼ���ڲ�����,�󶨵�����������
	�л�ϵͳ(_�׾�ϵͳ);
	//�ڲ�����(����,С��,����,���ڵ���,С�ڵ���,��,��,��,��, ��ջ, ��ջ);
	//_�󶨾�̬����<�ƶ�����>(�׾�::��, "����_�ƶ�����", 0);
	�󶨺���(�׾�::��, _���溯��, 0);
	׷�ӷ���(�ƶ�); ׷�ӷ���(����); ׷�ӷ���(���);
	��λ(�׾�::��, ��ɫ.״̬, ��ɫNPC, MAN, m_ManState.nState);
	//_�׾�ϵͳ._�󶨸���(�׾�::��, "��ɫ����X", ��ƫ��(��ɫ״̬, ����X), "��ɫNPC");
	/*
	������(�׾�::��, ����, ��ɫNPC, ��ɫ״̬, ����);
	������(�׾�::��, ����.Ŀ������, ��ɫNPC, ��ɫ״̬, ����.Ŀ������);
	������32(�׾�::��, ����.Ŀ��, ��ɫNPC, ��ɫ״̬, ����.Ŀ��);
	������32(�׾�::��, ����.״̬, ��ɫNPC, ��ɫ״̬, ����.״̬);
	������(�׾�::��, ��ɫ����, ��ɫNPC, ��ɫ״̬, ��ɫ����);
	������32(�׾�::��, ״̬, ��ɫNPC,��ɫ״̬, ״̬);
	������64(�׾�::��, ��ɫ����, ��ɫNPC, ��ɫ״̬, ����);
	��λ(�׾�::��, �ڲ�״̬.����, ��ɫNPC, ��ɫ״̬, �ڲ�״̬.����);
	������(�׾�::��, ��ɫ�ڲ�״̬, ��ɫNPC, ��ɫ״̬, �ڲ�״̬);
	*/
}

#ifdef �ѻ�����ģʽ
������� _���溯��::����(void* pϵͳ, void* p״̬��, ������& _����)
{
	((�׾�ϵͳ*)pϵͳ)->�׾�����־("_�ƶ����� %u %p", _����.�����б�.size(), ((�׾�ϵͳ*)pϵͳ)->m_pSystem);
	return �ɹ�;
}
#endif