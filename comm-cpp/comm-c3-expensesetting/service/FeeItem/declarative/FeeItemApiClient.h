#pragma once
#ifndef _FEEITEM_API_CLIENT_H_
#define _FEEITEM_API_CLIENT_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


class FeeItemApiClient : public oatpp::web::client::ApiClient

#include OATPP_CODEGEN_BEGIN(ApiClient)

	API_CLIENT_INIT(FeeItemApiClient);

	// ���� ID ��ѯ������
	API_CALL(API_M_GET, "/feeitem/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));

	// ��ҳ+������ѯ������
	API_CALL(API_M_GET, "/feeitem/query-all", queryAll, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, feeItemName));

#include OATPP_CODEGEN_END(ApiClient)
};

#endif // !_FEEITEM_API_CLIENT_H_
