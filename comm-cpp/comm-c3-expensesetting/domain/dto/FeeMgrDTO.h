#pragma once
#ifndef _FEEMGRDTO_H_
#define _FEEMGRDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ۿ۴���ģ��
 */
class FeeMgrAddDTO : public oatpp::DTO
{
    DTO_INIT(FeeMgrAddDTO, DTO);
    //�ۿ�����
    API_DTO_FIELD_DEFAULT(String, discount_type, ZH_WORDS_GETTER("FeeMgr.field.discount_type"));
    //�ۿ�����
    API_DTO_FIELD_DEFAULT(String, discount_name, ZH_WORDS_GETTER("FeeMgr.field.discount_name"));
   //�ɷ���ʼʱ��
    API_DTO_FIELD_DEFAULT(String,start_time, ZH_WORDS_GETTER("FeeMgr.field.start_time"));
	//�ɷѽ���ʱ��
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("FeeMgr.field.end_time"));
    //�ۿ���ֹʱ��
    API_DTO_FIELD_DEFAULT(String,discount_end_time, ZH_WORDS_GETTER("FeeMgr.field.discount_end_time"));

    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


//ɾ���ۿ۴���ģ��
class FeeMgrDeleteDTO : public oatpp::DTO
{
    DTO_INIT(FeeMgrDeleteDTO, DTO);
    //�ۿ�ID
    API_DTO_FIELD_DEFAULT(String, discount_id, ZH_WORDS_GETTER("FeeMgr.field.discount_id"));
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

//��ȡ�����������Ϣ����ģ��
class FeeMgrGetDTO : public oatpp::DTO
{
    DTO_INIT(FeeMgrGetDTO, DTO);
    //�ۿ�ID
    API_DTO_FIELD_DEFAULT(String, fee_id, ZH_WORDS_GETTER("FeeMgr.field.fee_id"));
    //��������
    API_DTO_FIELD_DEFAULT(String, fee_type, ZH_WORDS_GETTER("FeeMgr.field.fee_type"));
    //�շ���Ŀ
    API_DTO_FIELD_DEFAULT(String, fee_project, ZH_WORDS_GETTER("FeeMgr.field.fee_project"));
    //���ñ�ʶ
    API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("FeeMgr.field.fee_flag"));
    //�߽�����
    API_DTO_FIELD_DEFAULT(String, urge_type, ZH_WORDS_GETTER("FeeMgr.field.urge_type"));
    //��������
    API_DTO_FIELD_DEFAULT(String, pay_type, ZH_WORDS_GETTER("FeeMgr.field.pay_type"));
    //��������
    API_DTO_FIELD_DEFAULT(String, pay_cycle, ZH_WORDS_GETTER("FeeMgr.field.pay_cycle"));
    //��Ч��
    API_DTO_FIELD_DEFAULT(String, valid_time, ZH_WORDS_GETTER("FeeMgr.field.valid_time"));
    //��ʽ
    API_DTO_FIELD_DEFAULT(String, pay_formula, ZH_WORDS_GETTER("FeeMgr.field.pay_formula"));
    //�Ʒѵ���
    API_DTO_FIELD_DEFAULT(String, pay_price, ZH_WORDS_GETTER("FeeMgr.field.pay_price"));
    //�ƷѸ���
    API_DTO_FIELD_DEFAULT(String, pay_extra, ZH_WORDS_GETTER("FeeMgr.field.pay_extra"));
    //�˻��ֿ�
    API_DTO_FIELD_DEFAULT(String, account_deduction, ZH_WORDS_GETTER("FeeMgr.field.account_deduction"));

    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * ���������� DTO�������� ID��
 */
class FeeMgrDTO : public FeeMgrAddDTO
{
    DTO_INIT(FeeMgrDTO, FeeMgrAddDTO);

    // ���� ID
    API_DTO_FIELD_DEFAULT(String, discount_id, ZH_WORDS_GETTER("FeeMgr.field.discount_id"));
};


//��ҳ��dto
class FeeMgrPageDTO :public PageDTO<FeeMgrDTO::Wrapper>
{
    DTO_INIT(FeeMgrPageDTO, PageDTO<FeeMgrDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif
