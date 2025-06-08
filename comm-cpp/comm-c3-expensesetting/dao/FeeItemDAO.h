#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:23:49
*/
#ifndef _FEE_ITEM_DAO_
#define _FEE_ITEM_DAO_

#include "BaseDAO.h"
#include "../domain/do/FeeItem/FeeItemDo.h"
#include "../domain/query/FeeItemQuery.h"

/**
 * ���������ݿ����ʵ��
 */
class FeeItemDAO : public BaseDAO
{
private:
	// ������ѯ������ SQL ���
	inline std::string queryConditionBuilder(const FeeItemQuery::Wrapper& query, SqlParams& params);

public:
	// ͳ�Ʒ�����������������
	uint64_t count(const FeeItemQuery::Wrapper& query);

	// ��ҳ��ѯ����������
	std::list<FeeItemDO> selectWithPage(const FeeItemQuery::Wrapper& query);


	//�����µķ���������
	int insert(const FeeItemDO& iObj);

	//// �������з���������
	int update(const FeeItemDO& uObj);
	int modifyBusiness(const FeeItemDO& newObj);

	//// ���� ID ɾ��������
	int deleteById(const FeeItemDO& uObj);
	int deleteBusiness(const FeeItemDO& newObj);
};

#endif // !_FEE_ITEM_DAO_
