#pragma once
#ifndef _ORDER_DAO_
#define _ORDER_DAO_

#include "BaseDAO.h"
#include "domain/do/venue-reservation/OrderDO.h"
#include "domain/query/venue-reservation/OrderQuery.h"

class OrderDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const OrderQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const OrderQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<OrderDO> selectWithPage(const OrderQuery::Wrapper& query);
	// �޸�����
	int update(const std::string id);
};

#endif // !_ORDER_DAO_
