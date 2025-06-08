#include "stdafx.h"
#include "HouseFeeMgrService.h"
#include "../dao/HouseFeeMgrDAO.h"
//#include "id/UuidFacade.h"
//#include "SimpleDateTimeFormat.h"

HouseFeeMgrPageDTO::Wrapper HouseFeeMgrService::listAll(const HouseFeeMgrQuery::Wrapper& query)
{
	// �������ض���
	auto pages = HouseFeeMgrPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	HouseFeeMgrDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<HouseFeeMgrDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (HouseFeeMgrDO sub : result)
	{
		auto dto = HouseFeeMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			fee_id,
			Fee_id,
			fee_name,
			Config_name,
			fee_flag,
			Fee_flag,
			fee_type,
			Fee_type_cd,
			fee_pay,
			Fee_pay,
			makeTime,
			End_time,
			startTime,
			End_time,
			endTime,
			Deadline_time,
			status,
			State,
			owner_id,
			Owner_id,
			ownerNameLike,
			Owner_name,
			roomNum,
			Payer_obj_name,
			owner_phone,
			Owner_tel,
			fee_order,
			Batch_id);
		pages->addData(dto);
	}
	return pages;
}

HouseFeeMgrDTO::Wrapper HouseFeeMgrService::getById(std::string id)
{
	// ��ѯ����
	HouseFeeMgrDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = HouseFeeMgrDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res,
		fee_id,
		Fee_id,
		fee_name,
		Config_name,
		fee_flag,
		Fee_flag,
		fee_type,
		Fee_type_cd,
		fee_pay,
		Fee_pay,
		makeTime,
		End_time,
		startTime,
		End_time,
		endTime,
		Deadline_time,
		status,
		State,
		owner_id,
		Owner_id,
		ownerNameLike,
		Owner_name,
		roomNum,
		Payer_obj_name,
		owner_phone,
		Owner_tel,
		fee_order,
		Batch_id);
	return dto;
}

HouseFeeMgrPageDTO::Wrapper HouseFeeMgrService::listByRoomNum(const HouseFeeMgrQueryByRoom::Wrapper& query)
{
	// �������ض���
	auto pages = HouseFeeMgrPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	HouseFeeMgrDAO dao;
	uint64_t count = dao.count2(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<HouseFeeMgrDO> result = dao.selectByOwnerNum(query);
	// ��DOת����DTO
	for (HouseFeeMgrDO sub : result)
	{
		auto dto = HouseFeeMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			fee_id,
			Fee_id,
			fee_name,
			Config_name,
			fee_flag,
			Fee_flag,
			fee_type,
			Fee_type_cd,
			fee_pay,
			Fee_pay,
			makeTime,
			End_time,
			startTime,
			End_time,
			endTime,
			Deadline_time,
			status,
			State,
			owner_id,
			Owner_id,
			ownerNameLike,
			Owner_name,
			roomNum,
			Payer_obj_name,
			owner_phone,
			Owner_tel,
			fee_order,
			Batch_id);
		pages->addData(dto);
	}
	return pages;
}