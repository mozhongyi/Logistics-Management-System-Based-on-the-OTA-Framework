#pragma once
#pragma once
#ifndef _ORDER_DTO_H_
#define _ORDER_DTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ԤԼ����id
 */
class OrderIdDTO : public oatpp::DTO
{
	DTO_INIT(OrderIdDTO, oatpp::DTO);

	// �������
	API_DTO_FIELD_DEFAULT(String, cspId, ZH_WORDS_GETTER("venue-reservation.field.cspId"));
};

/**
 * ����ԤԼ������ҳ�������
 */
class OrderDTO : public OrderIdDTO
{
	DTO_INIT(OrderDTO, OrderIdDTO);

	// ����
	API_DTO_FIELD_DEFAULT(String, venueName, ZH_WORDS_GETTER("venue-reservation.field.venueName"));
	// ����
	API_DTO_FIELD_DEFAULT(String, spaceName, ZH_WORDS_GETTER("venue-reservation.field.spaceName"));
	// ԤԼ��
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("venue-reservation.field.personName"));
	// ԤԼ�绰
	API_DTO_FIELD_DEFAULT(String, personTel, ZH_WORDS_GETTER("venue-reservation.field.personTel"));
	// ԤԼ����
	API_DTO_FIELD_DEFAULT(String, appointmentTime, ZH_WORDS_GETTER("venue-reservation.field.appointmentTime"));
	// ԤԼʱ��
	API_DTO_FIELD_DEFAULT(String, times, ZH_WORDS_GETTER("venue-reservation.field.times"));
	// Ӧ�ս��
	API_DTO_FIELD_DEFAULT(String, receivableAmount, ZH_WORDS_GETTER("venue-reservation.field.receivableAmount"));
	// ʵ�ս��
	API_DTO_FIELD_DEFAULT(String, receivedAmount, ZH_WORDS_GETTER("venue-reservation.field.receivedAmount"));
	// ֧����ʽ
	API_DTO_FIELD_DEFAULT(String, payWay, ZH_WORDS_GETTER("venue-reservation.field.payWay"));
	// ֧����ʽ����
	API_DTO_FIELD_DEFAULT(String, payWayName, ZH_WORDS_GETTER("venue-reservation.field.payWayName"));
	// ״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("venue-reservation.field.state"));
	// ״̬����
	API_DTO_FIELD_DEFAULT(String, stateName, ZH_WORDS_GETTER("venue-reservation.field.stateName"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("venue-reservation.field.createTime"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("venue-reservation.field.remark"));
};

class OrderPageDTO : public PageDTO<OrderDTO::Wrapper>
{
	DTO_INIT(OrderPageDTO, PageDTO<OrderDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_DTO_H_
