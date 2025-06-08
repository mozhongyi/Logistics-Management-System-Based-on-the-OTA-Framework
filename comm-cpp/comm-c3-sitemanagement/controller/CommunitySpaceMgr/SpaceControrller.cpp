#include "stdafx.h" 
#include "SpaceController.h"
#include "../../service/CommunitySpaceMgrService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

CommunitySpaceMgrPageJsonVO::Wrapper SpaceController::execQueryList(const CommunitySpaceMgrPageQuery::Wrapper& query) {
	// ����һ��Service
	CommunitySpaceMgrService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CommunitySpaceMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


CommunitySpaceTimeMgrPageJsonVO::Wrapper SpaceController::execQueryTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query) {
	// ����һ��Service
	CommunitySpaceMgrService service;
	// ��ѯ����
	auto result = service.listTime(query);
	// ��Ӧ���
	auto jvo = CommunitySpaceTimeMgrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}




StringJsonVO::Wrapper SpaceController::execModifyTime(const CommunitySpaceTimeMgrDTO::Wrapper& dto, const PayloadDTO& payload) {

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->space_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	CommunitySpaceMgrService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateTimeData(dto)) {
		jvo->success(dto->space_id);
	}
	else
	{
		jvo->fail(dto->space_id);
	}
	// ��Ӧ���
	return jvo;
}