#pragma once

#ifndef _SPACE_DAO_
#define _SPACE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/space/SpaceDO.h"
//#include "../../domain/query/space/SpaceQuery.h"

/**
 * space�����ݿ����ʵ��
 */
class SpaceDAO : public BaseDAO
{
private:
	
public:
	// ���볡������
	int insert(const SpaceDO& iObj);
	// �޸ĳ�������
	int update(const SpaceDO& uObj);
	// ͨ��IDɾ����������
	int deleteById(std::string spaceId);
};
#endif // !_SPACE_DAO_
