/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "SampleController.h"
#include "../../service/sample/SampleService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

SamplePageJsonVO::Wrapper SampleController::execQuerySample(const SampleQuery::Wrapper& query)
{
	// ����һ��Service
	SampleService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = SamplePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

SampleJsonVO::Wrapper SampleController::execQueryById(const String& id)
{
	// ���巵�����ݶ���
	auto jvo = SampleJsonVO::createShared();

	// ����У��
	// �ǿ�У��
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SampleService service;
	// ִ����������
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//��Ӧ���
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> SampleController::execExportSample(const SampleQuery::Wrapper& query)
{
	// ����һ��Service
	SampleService service;
	// ��ѯ����
	auto result = service.listAll(query);

	// ������д�뵽Excel��
	auto buff = ExcelComponent().writeVectorToBuff("sample",
		[result](ExcelComponent* ex) {
			// д���ͷ
			ex->addHeader({
				ZH_WORDS_GETTER("sample.field.id") ,
				ZH_WORDS_GETTER("sample.field.name") ,
				ZH_WORDS_GETTER("sample.field.age") ,
				ZH_WORDS_GETTER("sample.field.sex")
				});
			// д������
			int row = 2;
			int col = 1;
			for (auto item : *(result->rows.get())) {
				col = 1;
				ex->setCellValue(row, col++, item->id);
				ex->setCellValue(row, col++, item->name);
				ex->setCellValue(row, col++, std::to_string(item->age));
				ex->setCellValue(row, col, item->sex);
				ex->setRowProperties(row++);
			}
		});

	// ��װ�·�����
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	std::string filename = "rp-sample-" + SimpleDateTimeFormat::format() + ".xlsx";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

	// Ӱ��ɹ����
	return response;
}

StringJsonVO::Wrapper SampleController::execAddSample(const SampleAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	SampleService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
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

StringJsonVO::Wrapper SampleController::execModifySample(const SampleDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	SampleService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// ��Ӧ���
	return jvo;
}

ListJsonVO<String>::Wrapper SampleController::execRemoveSample(const List<String>& ids)
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
	SampleService service;
	// ִ������ɾ��
	if (service.removeData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}

SampleJsonVO::Wrapper SampleController::execQueryOne(const String& id, const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, SampleApiClient, "sample-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	return ac->queryById(token, id)->readBodyToDto<SampleJsonVO::Wrapper>(om);
}

SamplePageJsonVO::Wrapper SampleController::execQueryAll(const SampleQuery::Wrapper& query, const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, SampleApiClient, "sample-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	return ac->queryAll(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->name))->readBodyToDto<SamplePageJsonVO::Wrapper>(om);
}
