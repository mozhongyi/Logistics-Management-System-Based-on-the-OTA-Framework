#include "stdafx.h"
#include "PayFeeController.h"
#include "../../service/PayFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "SimpleDateTimeFormat.h"

PayFeePageJsonVO::Wrapper PayFeeController::execQueryAll(const PayFeeQuery::Wrapper& query)
{
	PayFeeService service;
	auto result = service.listAll(query);
	auto jvo = PayFeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	return {};
}

ChargeItemListJsonVO::Wrapper PayFeeController::execQueryChargeItem(const String& community_id, const String& feeType)
{
	// ���巵�����ݶ���
	auto jvo = ChargeItemListJsonVO::createShared();
	PayFeeService service;
	auto res = service.listChargeItem(community_id.getValue({}), feeType.getValue({}));
	jvo->success(res);
	//��Ӧ���
	return jvo;
}