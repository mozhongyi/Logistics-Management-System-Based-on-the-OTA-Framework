#pragma once
#ifndef _HOUSEFEEMGRDTO_H_
#define _HOUSEFEEMGRDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//�����dto
class HouseFeeMgrDTO :public oatpp::DTO
{
	DTO_INIT(HouseFeeMgrDTO, DTO);
	//����id
	API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_id"));
	//������Ŀ
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_name"));
	//���ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_flag"));
	//��������
	API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_type"));
	//Ӧ�ս��
	API_DTO_FIELD_DEFAULT(Float32, fee_pay, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_pay"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, makeTime, ZH_WORDS_GETTER("HouseFeeMgr.field.makeTime"));
	//�Ʒ���ʼʱ��
	API_DTO_FIELD_DEFAULT(String, startTime, ZH_WORDS_GETTER("HouseFeeMgr.field.startTime"));
	//�Ʒѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("HouseFeeMgr.field.endTime"));
	//״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("HouseFeeMgr.field.status"));
	//ҵ��id
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("HouseFeeMgr.field.owner_id"));
	//ҵ������
	API_DTO_FIELD_DEFAULT(String, ownerNameLike, ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"));
	//���ݺ�
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"));
	//ҵ����ϵ��ʽ
	API_DTO_FIELD_DEFAULT(String, owner_phone, ZH_WORDS_GETTER("HouseFeeMgr.field.owner_phone"));
	//��������
	API_DTO_FIELD_DEFAULT(String, fee_order, ZH_WORDS_GETTER("HouseFeeMgr.field.fee_order"));
};
//��ҳ��dto
class HouseFeeMgrPageDTO :public PageDTO<HouseFeeMgrDTO::Wrapper>
{
	DTO_INIT(HouseFeeMgrPageDTO, PageDTO<HouseFeeMgrDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif
