/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "SampleDAO.h"
#include "SampleMapper.h"
#include <sstream>

std::string SampleDAO::queryConditionBuilder(const SampleQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->name) {

		sqlCondition << " AND `name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->sex) {

		sqlCondition << " AND sex=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue(""));
	}
	if (query->age) {

		sqlCondition << " AND age=?";
		SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0));
	}
	return sqlCondition.str();
}

uint64_t SampleDAO::count(const SampleQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM sample ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<SampleDO> SampleDAO::selectWithPage(const SampleQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,name,sex,age FROM sample ";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// �����������
	sql += " ORDER BY IFNULL(`update_time`, `create_time`) DESC, `id` DESC ";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// ִ�в�ѯ
	SampleMapper mapper;
	return sqlSession->executeQuery<SampleDO>(sql, mapper, params);
}

std::list<SampleDO> SampleDAO::selectByName(const string& name)
{
	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	SampleMapper mapper;
	return sqlSession->executeQuery<SampleDO>(sql, mapper, "%s", name);
}

PtrSampleDO SampleDAO::selectById(std::string id)
{
	string sql = "SELECT id,name,sex,age FROM sample WHERE `id`=?";
	PtrSampleMapper mapper;
	return sqlSession->executeQueryOne<PtrSampleDO>(sql, mapper, "%s", id);
}

int SampleDAO::insert(const SampleDO& iObj)
{
	string sql = "INSERT INTO `sample` (`id`, `name`, `sex`, `age`, `create_by`, `create_time`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s", iObj.getId(), iObj.getName(), iObj.getSex(), iObj.getAge(), iObj.getCreateBy(), iObj.getCreateTime());
}

int SampleDAO::update(const SampleDO& uObj)
{
	string sql = "UPDATE `sample` SET `name`=?, `sex`=?, `age`=?, `update_by`=?, `update_time`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getUpdateBy(), uObj.getUpdateTime(), uObj.getId());
}

int SampleDAO::deleteById(std::string id)
{
	string sql = "DELETE FROM `sample` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}