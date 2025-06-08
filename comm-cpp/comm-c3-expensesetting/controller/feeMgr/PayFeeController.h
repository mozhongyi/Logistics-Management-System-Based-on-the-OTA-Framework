#pragma once

#ifndef _PAYFEECONTROLLER_H_
#define _PAYFEECONTROLLER_H_

#include "domain/vo/PayFeeVO.h"
#include "domain/dto/PayFeeDTO.h"
#include "domain/query/PayFeeQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PayFeeController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(PayFeeController);
public: // ����ӿ�

	ENDPOINT_INFO(queryChargeItem) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("feeMgr.get.getItem"), ChargeItemListJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("feeMgr.field.community_id"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "feeType", ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"), "", true);
	}

	ENDPOINT(API_M_GET, "/c3-expensesetting/query-feeitemname", queryChargeItem, QUERY(String, community_id), QUERY(String, feeType), API_HANDLER_AUTH_PARAME) {

		API_HANDLER_RESP_VO(execQueryChargeItem(community_id, feeType));
	}


	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) {
		// ����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("feeMgr.get.summary"), PayFeePageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("feeMgr.field.community_id"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_type_cd", ZH_WORDS_GETTER("feeMgr.field.fee_type_cd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeId", ZH_WORDS_GETTER("feeMgr.field.config_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "chargeItem", ZH_WORDS_GETTER("feeMgr.field.fee_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_flag", ZH_WORDS_GETTER("feeMgr.field.fee_flag"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "payment_cd", ZH_WORDS_GETTER("feeMgr.field.payment_cd"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "deduct_from", ZH_WORDS_GETTER("feeMgr.field.deduct_from"), "", false);
	}
	// 3.2 �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c3-expensesetting/query-feeitem-page", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, PayFeeQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}


private: // ����ӿ�ִ�к���
	// 3.3 ��ҳ��ѯ����
	PayFeePageJsonVO::Wrapper execQueryAll(const PayFeeQuery::Wrapper& query);

	ChargeItemListJsonVO::Wrapper execQueryChargeItem(const String& community_id,const String& feeType);
};
#include OATPP_CODEGEN_END(ApiController)

#endif
