#pragma once
#ifndef _ORDER_SERVICE_H_
#define _ORDER_SERVICE_H_
#include "domain/query/venue-reservation/OrderQuery.h"
#include "domain/dto/venue-reservation/OrderDTO.h"

class OrderService
{
public:
	// ��ҳ��ѯ����ԤԼ
	OrderPageDTO::Wrapper listAll(const OrderQuery::Wrapper& query);
	// ȡ��ԤԼ
	bool removeData(const oatpp::String& cspId);
};

#endif // !_ORDER_SERVICE_H_