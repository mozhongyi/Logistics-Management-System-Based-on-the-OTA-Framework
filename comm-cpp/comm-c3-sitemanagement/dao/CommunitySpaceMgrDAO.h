#pragma once

#include "BaseDAO.h"
#include "../domain/do/CommunitySpaceMgrDO.h"
#include "../domain/query/CommunitySpaceMgrQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CommunitySpaceMgrDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const CommunitySpaceMgrPageQuery::Wrapper& query, SqlParams& params);
	inline std::string queryConditionTimeBuilder(const CommunitySpaceTimeMgrPageQuery::Wrapper& query, SqlParams& params);
public:
	// ͳ����������
	uint64_t count(const CommunitySpaceMgrPageQuery::Wrapper& query);
	uint64_t countTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);
	// ��ҳ��ѯ����
	std::list<CommunitySpaceMgrDO> selectWithPage(const CommunitySpaceMgrPageQuery::Wrapper& query);
	// ��ѯʱ��
	//std::list<CommunitySpaceTimeMgrDO> selectTimeById(std::string id);
	std::list<CommunitySpaceTimeMgrDO> selectTimeWithPage(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);
	// �޸�����
	int update(const CommunitySpaceTimeMgrDO& uObj);
};
