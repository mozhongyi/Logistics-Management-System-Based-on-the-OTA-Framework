#pragma once
#pragma once
#ifndef _ORDER_VO_H_
#define _ORDER_VO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/venue-reservation/OrderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ԤԼ������ҳ��ʾ����
 */
class OrderPageJsonVO : public JsonVO<OrderPageDTO::Wrapper>
{
	DTO_INIT(OrderPageJsonVO, JsonVO<OrderPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_VO_H_
