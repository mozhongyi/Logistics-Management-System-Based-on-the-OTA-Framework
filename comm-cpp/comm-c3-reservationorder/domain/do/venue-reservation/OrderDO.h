#pragma once
#ifndef _ORDER_DO_
#define _ORDER_DO_
#include "../DoInclude.h"


class OrderDO
{
	// cspId
	CC_SYNTHESIZE(string, cspId, CspId);
	// ������
	CC_SYNTHESIZE(string, venueName, VenueName);
	// ������
	CC_SYNTHESIZE(string, spaceName, SpaceName);
	// ԤԼ������
	CC_SYNTHESIZE(string, personName, PersonName);
	// ԤԼ�˵绰
	CC_SYNTHESIZE(string, personTel, PersonTel);
	// ԤԼ����
	CC_SYNTHESIZE(string, appointmentTime, AppointmentTime);
	// ԤԼʱ���
	CC_SYNTHESIZE(string, times, Times);
	// Ӧ�ս��
	CC_SYNTHESIZE(string, receivableAmount, ReceivableAmount);
	// ʵ�ս��
	CC_SYNTHESIZE(string, receivedAmount, ReceivedAmount);
	// ֧����ʽ��1Ϊ�ֽ� 2Ϊ΢�� 3Ϊ֧����
	CC_SYNTHESIZE(string, payWay, PayWay);
	// ���ݳ���ԤԼ����״̬��SΪԤԼ�ɹ� FΪԤԼʧ�� WΪ����� FΪ��֧�� CLΪ��ɾ��
	CC_SYNTHESIZE(string, state, State);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	OrderDO() {
		
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<OrderDO> PtrOrderDO;
#endif // !_ORDER_DO_