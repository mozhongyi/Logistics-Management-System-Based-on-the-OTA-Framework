#pragma once
#ifndef _ORDER_CONTROLLER_H_
#define _ORDER_CONTROLLER_H_

#include "domain/query/venue-reservation/OrderQuery.h"
#include "domain/vo/venue-reservation/OrderVO.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrderController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(OrderController);

public:
	// ���峡��ԤԼ������ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryOrder) {
		// ����ӿڱ��⡢�����Ӧ���ݡ���Ӱ�ȫ��֤
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("venue-reservation.query-order.summary"), OrderPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("venue-reservation.field.communityId"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "spaceId", ZH_WORDS_GETTER("venue-reservation.field.spaceId"), "102025051649290124", false);
		API_DEF_ADD_QUERY_PARAMS(String, "state", ZH_WORDS_GETTER("venue-reservation.field.state"), "S", false);
		API_DEF_ADD_QUERY_PARAMS(String, "personName", ZH_WORDS_GETTER("venue-reservation.field.personName"), ZH_WORDS_GETTER("venue-reservation.example.personName"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "personTel", ZH_WORDS_GETTER("venue-reservation.field.personTel"), "12345678910", false);
		API_DEF_ADD_QUERY_PARAMS(String, "appointmentTime", ZH_WORDS_GETTER("venue-reservation.field.appointmentTime"), "2025-05-21 23:59:59", false);
	}
	// ���峡��ԤԼ������ҳ��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c3-paceapp/query-order-page", queryOrder, OrderQuery, execQueryOrder(query));

	// ����ȡ��ԤԼ�ӿ�����
	ENDPOINT_INFO(removeOrder) {
		// ����ӿڱ��⡢�����Ӧ���ݡ���Ӱ�ȫ��֤
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("venue-reservation.remove-order.summary"), StringJsonVO::Wrapper);
	}
	// ����ȡ��ԤԼ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-paceapp/remove-order", removeOrder, BODY_DTO(OrderIdDTO::Wrapper, dto), execRemoveOrder(dto));

	// ���峡��ԤԼ������ҳ��ѯ�ӿ�ִ�к���
	OrderPageJsonVO::Wrapper execQueryOrder(const OrderQuery::Wrapper& query);
	// ����ȡ��ԤԼ�ӿ�ִ�к���
	StringJsonVO::Wrapper execRemoveOrder(const OrderIdDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ORDER_CONTROLLER_H_

