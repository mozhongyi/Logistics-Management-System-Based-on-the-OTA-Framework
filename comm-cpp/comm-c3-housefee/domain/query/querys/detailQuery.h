#pragma once
#ifndef _DETAILQUERY_H_
#define  _DETAILQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class detailQuery :public PageQuery {
	DTO_INIT(detailQuery, PageQuery);
	//fee_id: �ɷ�ID
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("detail.get.fee_id"));
	//cycle : ����(��λ : ��)
	API_DTO_FIELD_DEFAULT(String, cycle, ZH_WORDS_GETTER("detail.get.cycle"));
	//pay_path : �ɷѷ�ʽ
	API_DTO_FIELD_DEFAULT(String, pay_path, ZH_WORDS_GETTER("detail.get.pay_path"));
	//receiveable_amount : Ӧ�ս��
	API_DTO_FIELD_DEFAULT(String, receivable_amount, ZH_WORDS_GETTER("detail.get.receivable_amount"));
	//amount : ʵ�ս��
	API_DTO_FIELD_DEFAULT(String, amount, ZH_WORDS_GETTER("detail.get.amount"));
	//pay_time : �ɷ�ʱ��
	API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("detail.get.pay_time"));
	//start_time : �ɷѿ�ʼ
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("detail.get.start_time"));
	//end_time : �ɷѽ���
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("detail.get.end_time"));
	//end_time : ����Ա
	API_DTO_FIELD_DEFAULT(String, receive_id, ZH_WORDS_GETTER("detail.get.receive_id"));
	//status_cd : ״̬
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("detail.get.status_cd"));
	//remark : ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("detail.get.remark"));
	//opt : ����
	API_DTO_FIELD_DEFAULT(String, opt, ZH_WORDS_GETTER("detail.get.opt"));
};
#include OATPP_CODEGEN_END(DTO)
#endif