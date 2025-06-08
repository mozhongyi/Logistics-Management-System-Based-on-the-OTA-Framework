#include "stdafx.h"
#include "CommunitySpaceMgrService.h"
#include "../dao/CommunitySpaceMgrDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

CommunitySpaceMgrPageDTO::Wrapper CommunitySpaceMgrService::listAll(const CommunitySpaceMgrPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CommunitySpaceMgrPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CommunitySpaceMgrDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CommunitySpaceMgrDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CommunitySpaceMgrDO sub : result)
	{
		auto dto = CommunitySpaceMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, space_id, Space_Id, name, Name, start_time, Start_Time, end_time, End_Time,
			fee_money, Fee_Money, admin_name, Admin_Name, tel, Tel, state, State);
			//b_id, B_Id, community_id, Community_Id, , status_cd, Status_Cd, venue_id, Venue_Id);
		pages->addData(dto);
	}
	return pages;
}

CommunitySpaceTimeMgrPageDTO::Wrapper CommunitySpaceMgrService::listTime(const CommunitySpaceTimeMgrPageQuery::Wrapper& query) {
	auto pages = CommunitySpaceTimeMgrPageDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;

	// ��ѯ����������
	CommunitySpaceMgrDAO dao;
	uint64_t count = dao.countTime(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CommunitySpaceTimeMgrDO> result = dao.selectTimeWithPage(query);
	// ��DOת����DTO
	for (CommunitySpaceTimeMgrDO sub : result)
	{
		auto dto = CommunitySpaceTimeMgrDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, space_id, Space_Id, hours, Hours, is_open, Is_Open, time_id , Time_Id);
			//, space_id, Space_Id, b_id, B_Id,status_cd, Status_Cd, community_id, Community_Id);
		pages->addData(dto);
	}
	return pages;
}

bool CommunitySpaceMgrService::updateTimeData(const CommunitySpaceTimeMgrDTO::Wrapper& dto)
{
	// ��װDO����
	CommunitySpaceTimeMgrDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Space_Id, space_id, Hours, hours, Is_Open, is_open);
	// �����޸���
	//data.setUpdateBy(dto->getPayload()->getUsername());
	// �����޸�ʱ��
	data.setCreate_Time(SimpleDateTimeFormat::format());
	// ִ�������޸�
	CommunitySpaceMgrDAO dao;
	return dao.update(data) == 1;
}


//CommunitySpaceTimeMgrPageDTO::Wrapper getTimeById(std::string id) {
//	// ��ѯ����
//	CommunitySpaceMgrDAO dao;
//	auto res = dao.selectTimeById(id);
//
//	// û�в�ѯ������
//	if (!res)
//		return nullptr;
//
//	// ��ѯ������ת����DTO
//	auto dto = SampleDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
//	return dto;
//}
//SampleDTO::Wrapper SampleService::getById(std::string id)
//{
//	// ��ѯ����
//	SampleDAO dao;
//	auto res = dao.selectById(id);
//
//	// û�в�ѯ������
//	if (!res)
//		return nullptr;
//
//	// ��ѯ������ת����DTO
//	auto dto = SampleDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
//	return dto;
//}