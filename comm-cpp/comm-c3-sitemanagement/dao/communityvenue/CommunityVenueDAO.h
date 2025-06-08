#pragma once


#ifndef _COMMUNITYVENUE_DAO_
#define _COMMUNITYVENUE_DAO_

#include "BaseDAO.h"
#include "domain/do/communityvenue/CommunityVenueDO.h"
#include "domain/query/communityvenue/CommunityVenueQuery.h"

class CommunityVenueDAO : public BaseDAO {
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
	inline std::string queryConditionBuilder(const CommunityVenueQuery::Wrapper& query, SqlParams& params);


public:
	uint64_t count(const CommunityVenueQuery::Wrapper& query);
	std::list<CommunityVenueDO> selectWithPage(const CommunityVenueQuery::Wrapper& query);
	std::list<CommunityVenueDO> selectByName(const std::string& name);
	PtrCommunityVenueDO selectById(const std::string& id);
	int insert(const CommunityVenueDO& obj);
	int update(const CommunityVenueDO& obj);
	int deleteById(const std::string& id);
};

#endif//!_CommunityVenue_DAO_