#pragma once

#ifndef _FEEMGRSERVICE_H_
#define _FEEMGRSERVICE_H_
#include "domain/vo/FeeMgrVO.h"
#include "domain/dto/FeeMgrDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class FeeMgrService
{
public:
	// ͨ��ID��ѯ��������
	FeeMgrDTO::Wrapper getById (std::string id);
	// ��������
	std::string saveData(const FeeMgrAddDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif 