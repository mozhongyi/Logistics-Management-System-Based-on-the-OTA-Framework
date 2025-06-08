#pragma once
#ifndef _HOUSEFEEMGRDO_H_
#define _HOUSEFEEMGRDO_H_
#include "DoInclude.h"
class HouseFeeMgrDO
{
private:
	//����id
	CC_SYNTHESIZE(string, fee_id, Fee_id);
	//���ñ�ʶ
	CC_SYNTHESIZE(string, fee_flag, Fee_flag);
	//��������
	CC_SYNTHESIZE(string, fee_type_cd, Fee_type_cd);
	//���Ѷ���
	CC_SYNTHESIZE(string, payer_obj_name, Payer_obj_name);
	//������
	CC_SYNTHESIZE(string, config_name, Config_name);
	//����״̬
	CC_SYNTHESIZE(string, state, State);
	//����ʱ��&Ӧ�տ�ʼʱ��
	CC_SYNTHESIZE(string, end_time, End_time);
	//����
	CC_SYNTHESIZE(string, batch_id, Batch_id);
	//Ӧ�ս���ʱ��&�շѽ�ֹʱ��
	CC_SYNTHESIZE(string, deadline_time, Deadline_time);
	//Ƿ�ѽ��
	CC_SYNTHESIZE(double, fee_pay, Fee_pay);
	//ҵ����ϵ��ʽ
	CC_SYNTHESIZE(string, owner_tel , Owner_tel);
	//ҵ������
	CC_SYNTHESIZE(string, owner_name, Owner_name);
	//ҵ��id
	CC_SYNTHESIZE(string, owner_id, Owner_id);

public:
	HouseFeeMgrDO()
	{
		fee_id = "";
		fee_flag = "";
		fee_type_cd = "";
		payer_obj_name = "";
		config_name = "";
		state = "";
		end_time = "";
		batch_id = "";
		deadline_time = "";
		fee_pay = 0.0;
		owner_tel = "";
		owner_name = "";
		owner_id = "";
	}
};

typedef std::shared_ptr<HouseFeeMgrDO> PtrHouseFeeMgrDO;
#endif // !_HOUSEFEEMGRDO_H_
