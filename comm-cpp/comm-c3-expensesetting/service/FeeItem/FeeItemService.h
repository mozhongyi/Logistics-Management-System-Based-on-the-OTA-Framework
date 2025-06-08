#pragma once
#ifndef _FEEITEM_SERVICE_
#define _FEEITEM_SERVICE_

#include "../../domain/vo/FeeItemlogVO.h"
#include "../../domain/query/FeeItemQuery.h"
#include "../../domain/dto/FeeItemDTO.h"

/**
 * �����������
 */
class FeeItemService
{
public:
	// ��ҳ��ѯ��������
	FeeItemPageDTO::Wrapper listAll(const FeeItemQuery::Wrapper& query);

	//// ��������
	std::string saveData(const FeeItemAddDTO::Wrapper& dto);

	//// �޸�����
	bool updateData(const FeeItemModifyDTO::Wrapper& dto);

	//// ͨ�� ID ɾ������
	bool removeData(const FeeItemDeleteDTO::Wrapper& dto);
};

#endif // !_FEEITEM_SERVICE_
