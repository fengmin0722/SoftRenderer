/**
  @file SrRenderContext.h
  
  @author yikaiming

  ������־ history
  ver:1.0
   
 */

#ifndef SrRenderContext_h__
#define SrRenderContext_h__

class SrFragmentBuffer;

struct SrRendContext
{
	SrRendContext(int w, int h, int obpp)
	{
			memset(this, 0, sizeof(SrRendContext));
			width = w;
			height = h;
			bpp = obpp / 8;
			viewport = SrViewport(0.f,0.f,(float)width,(float)height,1.f,1000.f);

			SYSTEM_INFO siSysInfo;
			GetSystemInfo(&siSysInfo); 

			processorNum = siSysInfo.dwNumberOfProcessors;
	}

	// ��Ⱦ�������
	void OpenFeature( ERenderFeature feature )
	{
		features |= feature;
	}
	void CloseFeature( ERenderFeature feature )
	{
		features &= ~feature;
	}
	BOOL IsFeatureEnable( ERenderFeature feature )
	{
		return features & feature;
	}
	
	// ��ϸ����
	int width;							///< ��Ⱦ������
	int height;							///< ��Ⱦ���߶�
	SrViewport viewport;				///< 3ά�ӿ�
	int bpp;							///< ����λ������λbyte
	uint32 features;					///< ��Ⱦ����
	int processorNum;					///< ����������

	SrFragmentBuffer* fBuffer;			///< FragBuffer
};
extern SrRendContext* g_context;

#endif // SrRenderContext_h__

