#pragma once
#ifndef _FEEMGRVO_H_
#define _FEEMGRVO_H_
#include "../GlobalInclude.h"
#include "../dto/FeeMgrDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���ݷ�����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FeeMgrJsonVO : public JsonVO<FeeMgrDTO::Wrapper> {
	DTO_INIT(FeeMgrJsonVO, JsonVO<FeeMgrDTO::Wrapper>);
};

/**
 * ���ݷ��÷�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FeeMgrPageJsonVO : public JsonVO<FeeMgrPageDTO::Wrapper> {
	DTO_INIT(FeeMgrPageJsonVO, JsonVO<FeeMgrPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_FEEMGRVO_H_
