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
	// 构建返回对象
	auto pages = SamplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	SampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
	// 查询数据
	SampleDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = SampleDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
	return dto;
}

std::string SampleService::saveData(const SampleAddDTO::Wrapper& dto)
{
	// 组装DO数据
	SampleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age);
	// 生成ID
	UuidFacade uf;
	data.setId(uf.genUuid());
	// 设置创建人
	data.setCreateBy(dto->getPayload()->getUsername());
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	SampleDAO dao;
	return dao.insert(data) == 1 ? data.getId() : "";
}

bool SampleService::updateData(const SampleDTO::Wrapper& dto)
{
	// 组装DO数据
	SampleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id);
	// 设置修改人
	data.setUpdateBy(dto->getPayload()->getUsername());
	// 设置修改时间
	data.setUpdateTime(SimpleDateTimeFormat::format());
	// 执行数据修改
	SampleDAO dao;
	return dao.update(data) == 1;
}

bool SampleService::removeData(const oatpp::List<oatpp::String>& ids)
{
	SampleDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// 判断是否全部删除成功
	if (rows == ids->size()) {
        // 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
