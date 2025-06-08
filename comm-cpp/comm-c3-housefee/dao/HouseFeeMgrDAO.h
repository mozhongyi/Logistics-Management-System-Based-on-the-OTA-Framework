#pragma once
#ifndef _HOUSEFEEMGRDAO_H_
#define _HOUSEFEEMGRDAO_H_
#include "BaseDAO.h"
#include "../domain/do/HouseFeeMgrDO.h"
#include "../domain/query/HouseFeeMgrQuery.h"

class HouseFeeMgrDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const HouseFeeMgrQuery::Wrapper& query, SqlParams& params);
	inline std::string queryConditionBuilder2(const HouseFeeMgrQueryByRoom::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const HouseFeeMgrQuery::Wrapper& query);
	uint64_t count2(const HouseFeeMgrQueryByRoom::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<HouseFeeMgrDO> selectWithPage(const HouseFeeMgrQuery::Wrapper& query);
	// ͨ������id��ѯ����
	PtrHouseFeeMgrDO selectById(std::string id);
	// ͨ�����ݺŲ�ѯ����
	std::list<HouseFeeMgrDO> selectByOwnerNum(const HouseFeeMgrQueryByRoom::Wrapper& query);
};


#endif // !_HOUSEFEEMGRDAO_H_
