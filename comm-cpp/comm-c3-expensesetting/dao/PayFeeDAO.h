#pragma once

#ifndef _PAYFEE_DAO_
#define _PAYFEE_DAO_


#include "BaseDAO.h"
#include "../domain/do/PayFeeDO.h"
#include "../domain/query/PayFeeQuery.h"

class PayFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string ��������SQL��䣬��WHERE���ֵ����
	// Parameter:   const SampleQuery::Wrapper& query ��ѯ���ݶ���
	// Parameter:   SqlParams& params ��Ų�ѯ���ݵĲ�������
	// Description: ��ѯ����������������SampleQuery����̬������ѯ������ز���
	//************************************
	inline std::string queryConditionBuilder(const PayFeeQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const PayFeeQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<PayFeeDO> selectWithPage(const PayFeeQuery::Wrapper& query);

	// ͨ���������Ͳ�ѯ������Ŀ
	std::list<ChargeItemDO> selectByType(std::string community_id, std::string feeType);

};



#endif // !_PAYFEE_DAO_H_
