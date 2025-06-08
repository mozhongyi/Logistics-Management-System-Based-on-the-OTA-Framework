#pragma once
#ifndef _HOUSEFEEMGRVO_H_
#define _HOUSEFEEMGRVO_H_
#include "../GlobalInclude.h"
#include "../dto/HouseFeeMgrDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ���ݷ�����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class HouseFeeMgrJsonVO : public JsonVO<HouseFeeMgrDTO::Wrapper> {
	DTO_INIT(HouseFeeMgrJsonVO, JsonVO<HouseFeeMgrDTO::Wrapper>);
};

/**
 * ���ݷ��÷�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class HouseFeeMgrPageJsonVO : public JsonVO<HouseFeeMgrPageDTO::Wrapper> {
	DTO_INIT(HouseFeeMgrPageJsonVO, JsonVO<HouseFeeMgrPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_HOUSEFEEMGRVO_H_
