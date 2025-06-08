#pragma once

#include "domain/vo/CommunitySpaceMgrVO.h"
#include "domain/query/CommunitySpaceMgrQuery.h"
#include "domain/dto/CommunitySpaceMgrDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class CommunitySpaceMgrService
{
public:
	// ��ҳ��ѯ��������
	CommunitySpaceMgrPageDTO::Wrapper listAll(const CommunitySpaceMgrPageQuery::Wrapper& query);
	CommunitySpaceTimeMgrPageDTO::Wrapper listTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	//CommunitySpaceTimeMgrPageDTO::Wrapper getTimeById(std::string id);
	// �޸�����
	bool updateTimeData(const CommunitySpaceTimeMgrDTO::Wrapper& dto);
	
};



