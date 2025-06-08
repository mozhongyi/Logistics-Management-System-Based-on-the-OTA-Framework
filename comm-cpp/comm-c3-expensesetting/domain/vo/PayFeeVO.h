#pragma once

#ifndef _PAYFEEVO_H_
#define _PAYFEEVO_H_

#include "../GlobalInclude.h"
#include "../dto/PayFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//class ChargeItemJsonVO : public JsonVO<ChargeItemDTO::Wrapper> {
//	DTO_INIT(ChargeItemJsonVO, JsonVO<ChargeItemDTO::Wrapper>);
//};

class ChargeItemListJsonVO : public JsonVO<ChargeItemListDTO::Wrapper> {
	DTO_INIT(ChargeItemListJsonVO, JsonVO<ChargeItemListDTO::Wrapper>);
};

/**
 * �˵�Ŀ¼��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PayFeePageJsonVO : public JsonVO<PayFeePageDTO::Wrapper> {
	DTO_INIT(PayFeePageJsonVO, JsonVO<PayFeePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !PAYFEEVO_H_