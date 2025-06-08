#pragma once
#ifndef _HOUSEFEEMGRSERVICE_H_
#define _HOUSEFEEMGRSERVICE_H_
#include "domain/vo/HouseFeeMgrVO.h"
#include "domain/query/HouseFeeMgrQuery.h"
#include "domain/dto/HouseFeeMgrDTO.h"

class HouseFeeMgrService
{
public:
	// ��ҳ��ѯ��������
	HouseFeeMgrPageDTO::Wrapper listAll(const HouseFeeMgrQuery::Wrapper& query);
	// ͨ��ID��ѯ��������
	HouseFeeMgrDTO::Wrapper getById(std::string id);
	// ͨ�����ݺŲ�ѯ��������
	HouseFeeMgrPageDTO::Wrapper listByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query);
};

#endif // !_HOUSEFEEMGRSERVICE_H_
