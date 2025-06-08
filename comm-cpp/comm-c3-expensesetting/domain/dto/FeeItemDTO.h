#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: 2025/05/17
*/

#ifndef _FEEITEMDTO_H_
#define _FEEITEMDTO_H_
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӷ������ģ��
 */
class FeeItemAddDTO : public oatpp::DTO
{
    DTO_INIT(FeeItemAddDTO, DTO);

    // ��������
    API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("fee-item.field.fee_type_cd"));

    // ���ñ�ʶ
    API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("fee-item.field.fee_flag"));

    // �ɷ�����
    API_DTO_FIELD_DEFAULT(String, payment_cycle, ZH_WORDS_GETTER("fee-item.field.payment_cycle"));

    // �շ���Ŀ
    API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("fee-item.field.fee_name"));

    // ��������
    API_DTO_FIELD_DEFAULT(String, payment_cd, ZH_WORDS_GETTER("fee-item.field.payment_cd"));

    // Ԥ����
    API_DTO_FIELD_DEFAULT(String, prepayment_period, ZH_WORDS_GETTER("fee-item.prepayment_period"));

    // ��ʼʱ��
    API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("fee-item.field.start_time"));

    // ����ʱ��
    API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("fee-item.field.end_time"));

    // ��λ
    API_DTO_FIELD_DEFAULT(String, units, ZH_WORDS_GETTER("fee-item.field.units"));

    // �Ƿ�֧���˻��ֿ�
    API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("fee-item.field.deduct_from"));

    // �ֻ��ɷ�
    API_DTO_FIELD_DEFAULT(String, pay_online, ZH_WORDS_GETTER("fee-item.field.pay_online"));

    // ��λ��ʽ
    API_DTO_FIELD_DEFAULT(String, scale, ZH_WORDS_GETTER("fee-item.field.scale"));

    // ����С��λ
    API_DTO_FIELD(Int32, decimal_place, ZH_WORDS_GETTER("fee-item.field.decimal_place"), true, 2);

    // ���㹫ʽ
    API_DTO_FIELD_DEFAULT(String, computing_formula, ZH_WORDS_GETTER("fee-item.field.computing_formula"));

    // �Ʒѵ���
    API_DTO_FIELD_DEFAULT(String, square_price, ZH_WORDS_GETTER("fee-item.field.square_price"));

    // �̶�����
    API_DTO_FIELD_DEFAULT(String, additional_amount, ZH_WORDS_GETTER("fee-item.field.additional_amount"));

    // ���� ID
    API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("fee-item.field.community_id"));

    ////  ���ֶΣ�ǰ�˿������� operationTime
    //API_DTO_FIELD_DEFAULT(String, operationTime, ZH_WORDS_GETTER("fee-item.field.operation_time"));
    //// �û�ID
    //API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("fee-item.field.user_id"));



    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};


/**
 * ���������� DTO�������� ID��
 */
class FeeItemDTO : public FeeItemAddDTO
{
    DTO_INIT(FeeItemDTO, FeeItemAddDTO);

    // ���� ID
    API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("fee-itemlog.field.caId"));
    //  ���ֶΣ�ǰ�˿������� operationTime
    API_DTO_FIELD_DEFAULT(String, operation_Time, ZH_WORDS_GETTER("fee-item.field.operation_time"));
    //API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("fee-item.field.user_id"));
    API_DTO_FIELD_DEFAULT(String, user_name, ZH_WORDS_GETTER("fee-item.field.user_name"));// ��ʾ�û���

};


/**
 * ��ҳ������ DTO�����ڷ�ҳ��ѯ�����
 */
class FeeItemPageDTO : public PageDTO<FeeItemDTO::Wrapper>
{
    DTO_INIT(FeeItemPageDTO, PageDTO<FeeItemDTO::Wrapper>);
};

/**
 * �޸ķ������ģ��
 */
class FeeItemModifyDTO : public FeeItemAddDTO
{
    DTO_INIT(FeeItemModifyDTO, FeeItemAddDTO);

    // ���� ID
    API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("fee-itemlog.field.caId"));
    //API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("fee-item.field.user_id"));
};
class FeeItemDeleteDTO : public oatpp::DTO {

    DTO_INIT(FeeItemDeleteDTO, DTO)

        DTO_FIELD(String, config_id); // ������ config_id һ���ֶ�
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEEITEMDTO_H_
