#pragma once

#ifndef _PAYFEE_DO_
#define _PAYFEE_DO_
#include "DoInclude.h"
/**
 * ���������ݿ�ʵ����
 */
class PayFeeDO
{
    // ���� ID
    CC_SYNTHESIZE(string, config_id, Config_id);

    // ��������
    CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);

    // �շ���Ŀ
    CC_SYNTHESIZE(string, fee_name, Fee_name);

    // ���ñ�ʶ
    CC_SYNTHESIZE(string, fee_flag, Fee_flag);

    // ��������
    CC_SYNTHESIZE(string, payment_cd, Payment_cd);

    // �ɷ�����
    CC_SYNTHESIZE(int, payment_cycle, Payment_cycle);

    CC_SYNTHESIZE(string, start_time, Start_time);

    CC_SYNTHESIZE(string, end_time, End_time);

    // ���㹫ʽ
    CC_SYNTHESIZE(string, computing_formula, Computing_formula);

    // �Ʒѵ���
    CC_SYNTHESIZE(string, square_price, Square_price);

    // �̶�����
    CC_SYNTHESIZE(string, additional_amount, Additional_amount);

    // �Ƿ�֧���˻��ֿ�
    CC_SYNTHESIZE(string, deduct_from, Deduct_from);


public:
    PayFeeDO() {
        config_id = "";
        fee_type_cd = "";
        fee_name = "";
        fee_flag = "";
        payment_cd = "";
        payment_cycle = 0;  
        start_time = "";
        end_time = "";
        computing_formula = "";
        square_price = "";
        additional_amount = "";
        deduct_from = "";
    }
};

class ChargeItemDO
{
    CC_SYNTHESIZE(string, config_id, Config_id);
    CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
    CC_SYNTHESIZE(string, chargeItem, ChargeItem);
    ChargeItemDO() {
        config_id = "";
        fee_type_cd = "";
        chargeItem = "";
    }
};


#endif // !_FEEITEM_DO_