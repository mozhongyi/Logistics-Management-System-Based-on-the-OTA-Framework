#pragma once
#ifndef _FEEITEMCONTROLLER_H_
#define _FEEITEMCONTROLLER_H_

#include "domain/vo/FeeItemlogVO.h"    
#include "domain/dto/FeeItemDTO.h"
#include "domain/query/FeeItemQuery.h"  
#include "domain/vo/BaseJsonVO.h"
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include OATPP_CODEGEN_BEGIN(ApiController)

class FeeItemController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(FeeItemController);

public:

// 3.1 ����ӿ�����
	ENDPOINT_INFO(queryFeeItemLog) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("/fee_itemlog/query.get.summary"));
		// ����Ĭ����Ȩ����������ӿ���Ҫ��֤������ӣ�
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ����װ FeeItemPageJsonVO��������� FeeItemPageDTO ��װ�� JSON VO
		API_DEF_ADD_RSP_JSON_WRAPPER(FeeItemPageJsonVO);
		// ��ҳ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����Ĳ�ѯ���������������� id���Ǳ���ɰ���� true/false
		API_DEF_ADD_QUERY_PARAMS(String, "config_id", ZH_WORDS_GETTER("fee_itemlog.query.field.id"), "d934050a8bb373e8f8eed0bf7507ec17", true);
	}

	// 3.2 ����ӿڴ����߼�
	ENDPOINT(API_M_GET, "/c3-expensesetting/query-feemodifyrecord-page", queryFeeItemLog, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����������ģ�� FeeItemQuery
		API_HANDLER_QUERY_PARAM(query, FeeItemQuery, queryParams);
		// ����ִ�в�ѯ�ĺ��������ؽ��
		API_HANDLER_RESP_VO(execQueryAll(query));
	}


	// 3.1 ���������ӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/insert.post.summary"), additemlog, StringJsonVO::Wrapper);
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(additemlog) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("/fee_itemlog/insert.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/c3-expensesetting/insert-fee", additemlog, BODY_DTO(FeeItemAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAdditemlog(dto, authObject->getPayload()));
	}
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/modify.put.summary"), modifyitemlog, StringJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c3-expensesetting/modify-fee", modifyitemlog, BODY_DTO(FeeItemModifyDTO::Wrapper, dto), execModifyitemlog(dto, authObject->getPayload()));
	//// 3.1 ɾ���ӿ����������� StringJsonVO
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/delete.delete.summary"), removeSample, StringJsonVO::Wrapper);
	//// 3.2 ɾ���ӿڴ��������� config_id �ֶ�
	//ENDPOINT(API_M_DEL, "/fee_itemlog/delete", removeSample,
	//	BODY_DTO(FeeItemDeleteDTO::Wrapper, dto),
	//	execRemoveitemlog(dto, authObject->getPayload());
	// 3.1 ����ɾ���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/fee_itemlog/delete.delete.summary"), removeSample, StringJsonVO::Wrapper);
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-expensesetting/delete-fee", removeSample, BODY_DTO(FeeItemDeleteDTO::Wrapper, dto), execRemoveitemlog(dto, authObject->getPayload()));


private:
	// 3.3 ��ҳ��ѯ����
	FeeItemPageJsonVO::Wrapper execQueryAll(const FeeItemQuery::Wrapper& query);
	// 3.3 ��������
	StringJsonVO::Wrapper execAdditemlog(const FeeItemAddDTO::Wrapper& dto, const PayloadDTO& payload);
	//// 3.3 �޸�����
	StringJsonVO::Wrapper execModifyitemlog(const FeeItemModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	//// 3.3 ��ʾɾ������
	StringJsonVO::Wrapper execRemoveitemlog(const FeeItemDeleteDTO::Wrapper& dto, const PayloadDTO& payload);


};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FEEITEMCONTROLLER_H_