#pragma once
#ifndef _FEECONTROLLER_H_
#define _FEECONTROLLER_H_


#include "domain/vo/FeeMgrVO.h"
#include "domain/dto/FeeMgrDTO.h"
#include "domain/query/FeeMgrQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class FeeController :public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FeeController);
public://����ӿ�
    // 3.1 �����ҳ��ѯ�ӿ�����
    ENDPOINT_INFO(queryAll)
    {
        //����ӿ���������Ӧ��ʽ
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("FeeMgr.query.summary"), FeeMgrPageJsonVO::Wrapper);

        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();

        // ����������ѯ��������
       // API_DEF_ADD_QUERY_PARAMS(String, "discount_id", ZH_WORDS_GETTER("FeeMgr.field.discount_id"), "132025051652540020", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_name", ZH_WORDS_GETTER("FeeMgr.field.discount_name"), "testBewater", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_rule", ZH_WORDS_GETTER("FeeMgr.field.discount_rule"), "test", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_type", ZH_WORDS_GETTER("FeeMgr.field.discount_type"), "weiyue", false);

        API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("FeeMgr.field.start_time"), "2024.1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("FeeMgr.field.end_time"), "2025.2", false);
        API_DEF_ADD_QUERY_PARAMS(String, "discount_end_time", ZH_WORDS_GETTER("FeeMgr.field.discount_end_time"), "2025.3", false);

    }
    // 3.2 �����ҳ��ѯ�ӿڴ���
    ENDPOINT(API_M_GET, "/c3-expensesetting/query-discount-page", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(query, FeeMgrQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryAll(query));
    }

    



    // 3.1 ���������ӿ�����
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/FeeMgr/insert.post.summary"), additemlog, FeeMgrJsonVO::Wrapper);
    // 3.2 ���������ӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/c3-expensesetting/insert-discount", additemlog, BODY_DTO(FeeMgrAddDTO::Wrapper, dto), execAdditemlog(dto, authObject->getPayload()));

    // 3.1 ����ɾ���ӿ�����
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/FeeMgr/delete.delete.summary"), removeSample, FeeMgrJsonVO::Wrapper);
    // 3.2 ����ɾ���ӿڴ���
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c3-expensesetting/delete-discount", removeSample, BODY_DTO(FeeMgrDeleteDTO::Wrapper, dto), execRemoveitem(dto, authObject->getPayload()));

    //test:�����ȡ�����������Ϣ�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("/FeeMgr/getFeeItemInfo.get.summary"), getFeeItemInfo, FeeMgrJsonVO::Wrapper);
	//test:�����ȡ�����������Ϣ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c3-expensesetting/query-feeiteminfo", getFeeItemInfo, BODY_DTO(FeeMgrGetDTO::Wrapper, dto), execGetFeeItemInfo(dto, authObject->getPayload()));







private://����ӿ�ִ�к���
    FeeMgrPageJsonVO::Wrapper execQueryAll(const FeeMgrQuery::Wrapper& query);
    //FeeMgrJsonVO::Wrapper execQueryByFeeId(const String& id);

    // 3.3 ��������
    FeeMgrJsonVO::Wrapper execAdditemlog(const FeeMgrAddDTO::Wrapper& dto, const PayloadDTO& payload);
    
    // 3.3 ��ʾɾ������
    FeeMgrJsonVO::Wrapper execRemoveitem(const FeeMgrDeleteDTO::Wrapper& dto, const PayloadDTO& payload);

	//test:��ʾ��ȡ�����������Ϣ
	FeeMgrJsonVO::Wrapper execGetFeeItemInfo(const FeeMgrGetDTO::Wrapper& dto, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController)
#endif //