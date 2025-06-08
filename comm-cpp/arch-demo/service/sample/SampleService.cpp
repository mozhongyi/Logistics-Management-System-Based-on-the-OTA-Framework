/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "SampleService.h"
#include "../../dao/sample/SampleDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

SamplePageDTO::Wrapper SampleService::listAll(const SampleQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SamplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SampleDO sub : result)
	{
		auto dto = SampleDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age);
		pages->addData(dto);
	}
	return pages;
}

SampleDTO::Wrapper SampleService::getById(std::string id)
{
	// ��ѯ����
	SampleDAO dao;
	auto res = dao.selectById(id);

	// û�в�ѯ������
	if (!res)
		return nullptr;

	// ��ѯ������ת����DTO
	auto dto = SampleDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
	return dto;
}

std::string SampleService::saveData(const SampleAddDTO::Wrapper& dto)
{
	// ��װDO����
	SampleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age);
	// ����ID
	UuidFacade uf;
	data.setId(uf.genUuid());
	// ���ô�����
	data.setCreateBy(dto->getPayload()->getUsername());
	// ���ô���ʱ��
	data.setCreateTime(SimpleDateTimeFormat::format());
	// ִ���������
	SampleDAO dao;
	return dao.insert(data) == 1 ? data.getId() : "";
}

bool SampleService::updateData(const SampleDTO::Wrapper& dto)
{
	// ��װDO����
	SampleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id);
	// �����޸���
	data.setUpdateBy(dto->getPayload()->getUsername());
	// �����޸�ʱ��
	data.setUpdateTime(SimpleDateTimeFormat::format());
	// ִ�������޸�
	SampleDAO dao;
	return dao.update(data) == 1;
}

bool SampleService::removeData(const oatpp::List<oatpp::String>& ids)
{
	SampleDAO dao;
	// ��������
	dao.getSqlSession()->beginTransaction();
	// ѭ��ɾ��
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// �ж��Ƿ�ȫ��ɾ���ɹ�
	if (rows == ids->size()) {
        // �ύ����
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// �ع�����
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
