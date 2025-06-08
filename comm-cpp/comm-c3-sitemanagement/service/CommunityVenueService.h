#pragma once



#ifndef _COMMUNITYVENUESERVICE_
#define _COMMUNITYVENUESERVICE_
#include "domain/vo/communityvenue/CommunityVenueVO.h"
#include "domain/query/communityvenue/CommunityVenueQuery.h"
#include "domain/dto/communityvenue/CommunityVenueModifyDTO.h"

class CommunityVenueService
{
public:
	// ��ҳ��ѯ��������
	CommunityVenuePageDTO::Wrapper listAll(const CommunityVenueQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	CommunityVenueDTO::Wrapper getById(std::string id);
	// ��������
	std::string saveData(const CommunityVenueAddDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const CommunityVenueModifyDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif