#pragma once
#include "domain/vo/vos/RemitFeeVO.h"
#include "domain/query/querys/RemitFeeQuery.h"
#include "domain/dto/dtos/RemitFeeDTO.h"

class RemitFeeService {
public:
	//��ҳ��ѯ��������
	RemitFeePageDTO::Wrapper listAll(const RemitFeeQuery::Wrapper& query);
	

};