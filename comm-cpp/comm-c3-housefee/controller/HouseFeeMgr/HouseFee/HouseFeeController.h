#pragma once
#ifndef _HOUSEFEECONTROLLER_H_
#define _HOUSEFEECONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/HouseFeeMgrVO.h"
#include "domain/dto/HouseFeeMgrDTO.h"
#include "domain/query/HouseFeeMgrQuery.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class HouseFeeController :public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(HouseFeeController);
public://����ӿ�
	// 3.1 �����ҳ��ѯ�ӿ�����
	ENDPOINT_INFO(queryAll) 
	{
		//����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("HouseFeeMgr.query.summary"), HouseFeeMgrPageJsonVO::Wrapper);

		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("HouseFeeMgr.field.communityId"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"), "01-1-1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("HouseFeeMgr.field.status"), "2008001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ownerNameLike", ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"), "kid", false);
	}
	// 3.2 �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c3-housefeemgr/query-housefee-page", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, HouseFeeMgrQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(query));
	}

	// 3.1 �����ȡ���ݷ��������ѯ�ӿ�����
	ENDPOINT_INFO(queryByFeeId)
	{
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("HouseFeeMgr.query-by-fee_id.summary"), HouseFeeMgrJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("HouseFeeMgr.field.fee_id"), "902025051980230067", true);
	}
	// 3.2 ����ID��ѯ�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c3-housefeemgr/query-housefeedetail", queryByFeeId, QUERY(String, fee_id), execQueryByFeeId(fee_id));


	// 3.1 �����ȡ���ݷ�������Ϣ��ѯ�ӿ�����
	ENDPOINT_INFO(queryByRoomNum)
	{
		//����ӿ���������Ӧ��ʽ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("HouseFeeMgr.query-by-roomNum.summary"), HouseFeeMgrPageJsonVO::Wrapper);

		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "communityId", ZH_WORDS_GETTER("HouseFeeMgr.field.communityId"), "2024022692080516", true);
		API_DEF_ADD_QUERY_PARAMS(String, "roomNum", ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"), "01-1-1", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("HouseFeeMgr.field.status"), "2008001", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "ownerNameLike", ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"), "kid", false);
	}
	// 3.2 �����ҳ��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c3-housefeemgr/query-housefeeitem", queryByRoomNum, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, HouseFeeMgrQueryByRoom, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryByRoomNum(query));
	}

private://����ӿ�ִ�к���
	HouseFeeMgrPageJsonVO::Wrapper execQueryAll(const HouseFeeMgrQuery::Wrapper& query);
	HouseFeeMgrJsonVO::Wrapper execQueryByFeeId(const String& id);
	HouseFeeMgrPageJsonVO::Wrapper execQueryByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query);

};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_HOUSEFEECONTROLLER_H_
