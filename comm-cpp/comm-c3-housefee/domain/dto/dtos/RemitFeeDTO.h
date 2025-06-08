#pragma once
#ifndef  _REMITFEEDTO_H_
#define _REMITFEEDTO_H_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class RemitFeeDTO :public oatpp::DTO
{
	DTO_INIT(RemitFeeDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, detail_id, ZH_WORDS_GETTER("record.get.detail_id"));
	//  receipt_id: ������
	API_DTO_FIELD_DEFAULT(String,receipt_id, ZH_WORDS_GETTER("record.get.receipt_id"));
	//pay_obj: �շѶ���
	API_DTO_FIELD_DEFAULT(String, pay_obj, ZH_WORDS_GETTER("record.get.pay_obj"));
	//cycle : ����
	API_DTO_FIELD_DEFAULT(Float64, cycle, ZH_WORDS_GETTER("record.get.cycle"));
	//receivable_amount : Ӧ�շ���
	//API_DTO_FIELD_DEFAULT(Float64, receivable_amount, ZH_WORDS_GETTER("record.get.receivable_amount"));
	////amount : ʵ�շ���
	//API_DTO_FIELD_DEFAULT(Float64, amount, ZH_WORDS_GETTER("record.get.amount"));
	API_DTO_FIELD_DEFAULT(String, receive_received, ZH_WORDS_GETTER("record.get.receive-received"));

	//Remit_path : �ɷѷ�ʽ
	API_DTO_FIELD_DEFAULT(String, pay_path, ZH_WORDS_GETTER("record.get.pay_path"));
	//pay_period : �ɷѽ׶�
	API_DTO_FIELD_DEFAULT(String, pay_period, ZH_WORDS_GETTER("record.get.pay_period"));

	//API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("record.get.start_time"));
	//API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("record.get.end_time"));

	//pay_time : �ɷ�ʱ��
	API_DTO_FIELD_DEFAULT(String, pay_time, ZH_WORDS_GETTER("record.get.pay_time"));
	//receive_id : ����Ա
	API_DTO_FIELD_DEFAULT(String, receive_id, ZH_WORDS_GETTER("record.get.receive_id"));
	//status_cd : ״̬
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("record.get.status_cd"));
	//remark : ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("record.get.remark"));
	//opt : ����
	API_DTO_FIELD_DEFAULT(String,opt, ZH_WORDS_GETTER("record.get.opt"));
	/*CC_SYNTHESIZE(const PayloadDTO*, Payload);*/
};
/*
* ʵ����ҳ�������
*/
class RemitFeePageDTO :public PageDTO<RemitFeeDTO::Wrapper>
{
	DTO_INIT(RemitFeePageDTO, PageDTO<RemitFeeDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // 
