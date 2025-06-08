#pragma once 

#ifndef _PAYFEE_SERVICE_
#define _PAYFEE_SERVICE_
#include "domain/vo/PayFeeVO.h"
#include "domain/query/PayFeeQuery.h"
#include "domain/dto/PayFeeDTO.h"

class PayFeeService
{
public:
	// ��ҳ��ѯ���з�����
	PayFeePageDTO::Wrapper listAll(const PayFeeQuery::Wrapper& query);
	// ͨ���������Ͳ�ѯ���з�����Ŀ
	ChargeItemListDTO::Wrapper listChargeItem(std::string community_id, std::string payType);
};




#endif
