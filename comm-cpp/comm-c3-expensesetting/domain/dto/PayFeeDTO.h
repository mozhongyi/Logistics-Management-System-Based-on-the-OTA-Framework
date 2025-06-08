#pragma once

#ifndef _PAYFEEDTO_H_
#define _PAYFEEDTO_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


// ����������DTO
class ChargeItemDTO : public oatpp::DTO
{
	DTO_INIT(ChargeItemDTO, DTO);
	
	// ID
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("feeMgr.field.config_id"));

// ��������
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"));

	// ����
	API_DTO_FIELD_DEFAULT(String, chargeItem, ZH_WORDS_GETTER("feeMgr.field.fee_name"));
};

class ChargeItemListDTO : public oatpp::DTO
{
	DTO_INIT(ChargeItemListDTO, oatpp::DTO);

	// ����
	API_DTO_FIELD_DEFAULT(List<Object<ChargeItemDTO>>, chargeItemList, ZH_WORDS_GETTER("feeMgr.field.itemList"));
};


class PayFeeDTO : public oatpp::DTO
{
    DTO_INIT(PayFeeDTO, DTO);

	// ���� ID
	API_DTO_FIELD_DEFAULT(String, config_id, ZH_WORDS_GETTER("feeMgr.field.config_id"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, fee_type_cd, ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"));

	// �շ���Ŀ
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("feeMgr.field.fee_name"));

	// ���ñ�ʶ
	API_DTO_FIELD_DEFAULT(String, fee_flag, ZH_WORDS_GETTER("feeMgr.field.fee_flag"));

	// ��������
	API_DTO_FIELD_DEFAULT(String, payment_cd, ZH_WORDS_GETTER("feeMgr.field.payment_cd"));

	// �ɷ�����
	API_DTO_FIELD_DEFAULT(Int32, payment_cycle, ZH_WORDS_GETTER("feeMgr.field.payment_cycle"));

	//// ��ʼʱ��
	//API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("feeMgr.field.start_time"));

	//// ����ʱ��
	//API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("feeMgr.field.end_time"));

	//��Ч��
	API_DTO_FIELD_DEFAULT(String, validDate, ZH_WORDS_GETTER("feeMgr.field.validDate"));

	// ���㹫ʽ
	API_DTO_FIELD_DEFAULT(String, computing_formula, ZH_WORDS_GETTER("feeMgr.field.computing_formula"));

	// �Ʒѵ���
	API_DTO_FIELD_DEFAULT(String, square_price, ZH_WORDS_GETTER("feeMgr.field.square_price"));

	// �̶�����
	API_DTO_FIELD_DEFAULT(String, additional_amount, ZH_WORDS_GETTER("feeMgr.field.additional_amount"));
	
	// �Ƿ�֧���˻��ֿ�
	API_DTO_FIELD_DEFAULT(String, deduct_from, ZH_WORDS_GETTER("feeMgr.field.deduct_from"));

};
/**
 * ��ҳ������ DTO�����ڷ�ҳ��ѯ�����
 */
class  PayFeePageDTO : public PageDTO<PayFeeDTO::Wrapper>
{
	DTO_INIT(PayFeePageDTO, PageDTO<PayFeeDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !PAYFEEDTO_H_
