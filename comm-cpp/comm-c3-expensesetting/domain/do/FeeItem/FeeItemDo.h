#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _FEEITEM_DO_
#define _FEEITEM_DO_

#include "../DoInclude.h"
#include <string>
#include <memory>
//#include <functional> // ? Ϊ std::hash ���֧��

/**
 * ���������ݿ�ʵ����
 */
class FeeItemDO
{
    // ���� ID
    CC_SYNTHESIZE(std::string, config_id, Config_id);

    // ��������
    CC_SYNTHESIZE(std::string, fee_type_cd, Fee_type_cd);

    // ���ñ�ʶ
    CC_SYNTHESIZE(std::string, fee_flag, Fee_flag);

    // �ɷ�����
    CC_SYNTHESIZE(std::string, payment_cycle, Payment_cycle);

    // �շ���Ŀ
    CC_SYNTHESIZE(std::string, fee_name, Fee_name);

    // ��������
    CC_SYNTHESIZE(std::string, payment_cd, Payment_cd);

    // Ԥ����
    CC_SYNTHESIZE(std::string, prepayment_period, Prepayment_period);

    // ��ʼʱ��
    CC_SYNTHESIZE(std::string, start_time, Start_time);

    // ����ʱ��
    CC_SYNTHESIZE(std::string, end_time, End_time);

    // ��λ
    CC_SYNTHESIZE(std::string, units, Units);

    // �Ƿ�֧���˻��ֿ�
    CC_SYNTHESIZE(std::string, deduct_from, Deduct_from);

    // �ֻ��ɷ�
    CC_SYNTHESIZE(std::string, pay_online, Pay_online);

    // ��λ��ʽ
    CC_SYNTHESIZE(std::string, scale, Scale);

    // ����С��λ
    CC_SYNTHESIZE(int, decimal_place, Decimal_place);

    // ���㹫ʽ
    CC_SYNTHESIZE(std::string, computing_formula, Computing_formula);

    // �Ʒѵ���
    CC_SYNTHESIZE(std::string, square_price, Square_price);

    // �̶�����
    CC_SYNTHESIZE(std::string, additional_amount, Additional_amount);


    // ������
    //CC_SYNTHESIZE(std::string, createBy, CreateBy);

    // ����ʱ��
    CC_SYNTHESIZE(std::string, create_Time, Create_Time);

    //// �޸���
    //CC_SYNTHESIZE(std::string, updateBy, UpdateBy);

    //// �޸�ʱ��
    //CC_SYNTHESIZE(std::string, updateTime, UpdateTime);

    // ���� ID
    CC_SYNTHESIZE(std::string, community_id, Community_id);

    //ҵ��id
    CC_SYNTHESIZE(std::string, b_id, B_id);

    // ����
    CC_SYNTHESIZE(std::string, operate, Operate);

    //Ĭ�Ϸ���
    CC_SYNTHESIZE(std::string, is_default, Is_default);

    //��������
    CC_SYNTHESIZE(std::string, bill_type, Bill_type);

    //�Զ��幫ʾ����
    CC_SYNTHESIZE(std::string, computing_formula_text, Computing_formula_text);



    //����״̬
    CC_SYNTHESIZE(std::string, status_cd, Status_cd);
    // �û�ID
    CC_SYNTHESIZE(std::string, user_Id, User_Id);  // ���� getUserId() / setUserId()
    // �û�name
    CC_SYNTHESIZE(std::string, name, Name);
public:
    FeeItemDO() {
        config_id = "";
        b_id = "- 1";
        fee_type_cd = "888800010008";
        fee_flag = "1003006";
        payment_cycle = "1";
        fee_name = "";
        payment_cd = "1200";
        prepayment_period = "NULL";
        start_time = "";
        end_time = "";
        units = "Ԫ";
        deduct_from = "Y";
        pay_online = "Y";
        scale = "1";
        decimal_place = 2;
        computing_formula = "1001";
        square_price = "";
        additional_amount = "";
        //createBy = "";
        //createTime = CURRENT_TIMESTAMP;
        //updateBy = "";
        //updateTime = "";
        community_id = "1";
        b_id= "";
        operate = "ADD";
        is_default = "F";
        bill_type = "004";
        computing_formula_text = "NULL";
        status_cd = "0";
        user_Id = "";
    }
};

    //    // ? ���ص�������������� config_id��
    //    bool operator==(const FeeItemDO& other) const {
    //        return this->config_id == other.config_id;
    //    }
    //};
    //
    //// ? �ػ� std::hash���� FeeItemDO ֧�ֹ�ϣ�������� unordered_map��
    //namespace std {
    //    template<>
    //    struct hash<FeeItemDO> {
    //        std::size_t operator()(const FeeItemDO& k) const {
    //            return std::hash<std::string>()(k.getConfig_id());
    //        }
     
    

    // ? ����ָ�����
    typedef std::shared_ptr<FeeItemDO> PtrFeeItemDO;

#endif // !_FEEITEM_DO_
