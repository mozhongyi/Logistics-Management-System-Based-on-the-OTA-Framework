#include "stdafx.h"
#include "HouseFeeController.h"
#include "../../../service/HouseFeeMgrService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
HouseFeeMgrPageJsonVO::Wrapper HouseFeeController::execQueryAll(const HouseFeeMgrQuery::Wrapper& query)
{
	// ����һ��Service
	HouseFeeMgrService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = HouseFeeMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
HouseFeeMgrJsonVO::Wrapper HouseFeeController::execQueryByFeeId(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = HouseFeeMgrJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	HouseFeeMgrService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}
HouseFeeMgrPageJsonVO::Wrapper HouseFeeController::execQueryByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query)
{
	// ����һ��Service
	HouseFeeMgrService service;
	// ��ѯ����
	auto result = service.listByRoomNum(query);
	// ��Ӧ���
	auto jvo = HouseFeeMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
