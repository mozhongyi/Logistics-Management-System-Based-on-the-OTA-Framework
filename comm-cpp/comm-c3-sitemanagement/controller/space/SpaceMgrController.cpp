#include "stdafx.h"
#include "SpaceMgrController.h"
#include "../../service/space/SpaceService.h"

// ��ӳ���ִ�к���
StringJsonVO::Wrapper SpaceMgrController::execAddSpace(const SpaceAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->name || !dto->feeMoney || !dto->adminName || !dto->tel || !dto->state)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->feeMoney < 0 || dto->name->empty() || dto->adminName->empty() || dto->tel->empty() || dto->state->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SpaceService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.addSpace(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}

// �޸ĳ���ִ�к���
StringJsonVO::Wrapper SpaceMgrController::execModifySpace(const SpaceUpdateDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->spaceId || !dto->adminName || !dto->feeMoney || !dto->tel || !dto->name || !dto->state)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SpaceService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateSpace(dto)) {
		jvo->success(dto->spaceId);
	}
	else
	{
		jvo->fail(dto->spaceId);
	}
	// ��Ӧ���
	return jvo;
}

// ɾ������ִ�к���
ListJsonVO<String>::Wrapper SpaceMgrController::execRemoveSpace(const List<String>& ids)
{
	// ���巵�����ݶ���
	auto jvo = ListJsonVO<String>::createShared();
	// ����У��
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SpaceService service;
	// ִ������ɾ��
	if (service.removeSpace(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}