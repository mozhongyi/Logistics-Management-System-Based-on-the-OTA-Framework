#pragma once
#ifndef _MODIFYQUERY_H_
#define  _MODIFYQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class modifyQuery :public PageQuery {
	DTO_INIT(modifyQuery, PageQuery);
	//fee_type: ��������
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("modify.get.fee_id"));
	//API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("modify.get.fee_name"));
	//API_DTO_FIELD_DEFAULT(String, obj_name, ZH_WORDS_GETTER("modify.get.obj_name"));
	API_DTO_FIELD_DEFAULT(String, fee_pro, ZH_WORDS_GETTER("modify.get.fee_pro"));

	//����ʱ��
	//API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("modify.get.pay_time"));
	//�Ʒ���ʼ
	API_DTO_FIELD_DEFAULT(String, pay_start, ZH_WORDS_GETTER("modify.get.pay_start"));
	API_DTO_FIELD_DEFAULT(String, pay_end, ZH_WORDS_GETTER("modify.get.pay_end"));

	//actions : ����
	API_DTO_FIELD_DEFAULT(String, actions, ZH_WORDS_GETTER("modify.get.actions"));
	//operator : ������
	API_DTO_FIELD_DEFAULT(String, oporator, ZH_WORDS_GETTER("modify.get.oporator"));
	//opt_time : ����ʱ��
	API_DTO_FIELD_DEFAULT(String, opt_time, ZH_WORDS_GETTER("modify.get.opt_time"));

};
#include OATPP_CODEGEN_END(DTO)
#endif