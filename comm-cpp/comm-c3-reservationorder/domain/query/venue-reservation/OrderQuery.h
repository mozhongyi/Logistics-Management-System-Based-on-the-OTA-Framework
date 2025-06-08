#pragma once
#ifndef _ORDER_QUERY_H_
#define _ORDER_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����ԤԼ������ѯ����
 */
class OrderQuery : public PageQuery
{
	DTO_INIT(OrderQuery, PageQuery);
	
	// ����id
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("venue-reservation.field.communityId"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, spaceId, ZH_WORDS_GETTER("venue-reservation.field.spaceId"));
	// ״̬
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("venue-reservation.field.state"));
	// ԤԼ��
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("venue-reservation.field.personName"));
	// ԤԼ�˵绰
	API_DTO_FIELD_DEFAULT(String, personTel, ZH_WORDS_GETTER("venue-reservation.field.personTel"));
	// ԤԼʱ��
	API_DTO_FIELD_DEFAULT(String, appointmentTime, ZH_WORDS_GETTER("venue-reservation.field.appointmentTime"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_QUERY_H_
