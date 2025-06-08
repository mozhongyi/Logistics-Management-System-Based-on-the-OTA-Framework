/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2025/05/17 20:01:50

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
#include "FeeItemController.h"
#include "../../../service/FeeItem/FeeItemService.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include OATPP_CODEGEN_BEGIN(ApiController) 
FeeItemPageJsonVO::Wrapper FeeItemController::execQueryAll(const FeeItemQuery::Wrapper& query)
{
	// ����һ��Service
    FeeItemService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = FeeItemPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FeeItemController::execAdditemlog(const FeeItemAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
    	auto jvo = StringJsonVO::createShared();
    
    	// �ǿ�У�飨���������Ҫ����չ��
        //��������չ
    	if (!dto->fee_type_cd || dto->fee_type_cd->empty() ||
    		!dto->fee_name || dto->fee_name->empty() ||
    		!dto->payment_cd || dto->payment_cd->empty() ||
    		!dto->start_time || dto->start_time->empty() ||
    		!dto->end_time || dto->end_time->empty())
    	{
    		jvo->init(nullptr, RS_PARAMS_INVALID);
    		return jvo;
    	}
    
    	// ִ������
    	FeeItemService service;
    	dto->setPayload(&payload);
    	std::string id = service.saveData(dto);
    
    	if (!id.empty()) {
    		jvo->success(id);
    	}
    	else {
    		jvo->fail("");
    	}
    
    	return jvo;
}
StringJsonVO::Wrapper FeeItemController::execModifyitemlog(const FeeItemModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
    OATPP_LOGD("ModifyItem", "Got modify request");
    	auto jvo = StringJsonVO::createShared();
    
    	if (!dto->config_id || dto->config_id->empty()) {
    		jvo->init(nullptr, RS_PARAMS_INVALID);
    		return jvo;
    	}
    
    	FeeItemService service;
    	dto->setPayload(&payload);
        //dto->user_id = payload.id;

    	if (service.updateData(dto)) {
    		jvo->success(dto->config_id);
    	}
    	else {
    		jvo->fail(dto->config_id);
    	}
    
    	return jvo;
}
StringJsonVO::Wrapper FeeItemController::execRemoveitemlog(const FeeItemDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
    auto jvo = StringJsonVO::createShared();

    if (!dto->config_id || dto->config_id->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    FeeItemService service;
    // ����Ȩ����Ϣ�������Ҫ��
    // dto->setPayload(&payload);  // ���FeeItemDeleteDTO�޴˷�����ȥ��

    if (service.removeData(dto)) {
        jvo->success(dto->config_id);
    }
    else {
        jvo->fail(dto->config_id);
    }

    return jvo;
}




//FeeItemPageJsonVO::Wrapper FeeItemController::execQueryAll(const FeeItemQuery::Wrapper& query)
//{
//	// ��������
//	FeeItemService service;
//
//	// ���� service ��ȡ��ҳ���
//	auto pageResult = service.listAll(query);
//
//	// ��װΪ��׼ Json ���ؽṹ
//	auto vo = FeeItemPageJsonVO::createShared();
//	vo->success(pageResult);
//	return vo;
//} 


//StringJsonVO::Wrapper FeeItemController::execAdditemlog(const FeeItemAddDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//
//	// �ǿ�У�飨���������Ҫ����չ��
//	if (!dto->fee_type_cd || dto->fee_type_cd->empty() ||
//		!dto->fee_name || dto->fee_name->empty() ||
//		!dto->payment_cd || dto->payment_cd->empty() ||
//		!dto->start_time || dto->start_time->empty() ||
//		!dto->end_time || dto->end_time->empty())
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// ִ������
//	FeeItemService service;
//	dto->setPayload(&payload);
//	std::string id = service.saveData(dto);
//
//	if (!id.empty()) {
//		jvo->success(id);
//	}
//	else {
//		jvo->fail("");
//	}
//
//	return jvo;
//}
//
//
//StringJsonVO::Wrapper FeeItemController::execModifyitemlog(const FeeItemDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//
//	if (!dto->config_id || dto->config_id->empty()) {
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	FeeItemService service;
//	dto->setPayload(&payload);
//
//	if (service.updateData(dto)) {
//		jvo->success(dto->config_id);
//	}
//	else {
//		jvo->fail(dto->config_id);
//	}
//
//	return jvo;
//}
//
//ListJsonVO<String>::Wrapper FeeItemController::execRemoveitem(const List<String>& ids)
//{
//	// ���巵�����ݶ���
//	auto jvo = ListJsonVO<String>::createShared();
//	// ����У��
//	if (ids->empty())
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// ����һ��Service
//	FeeItemService service;
//	// ִ������ɾ��
//	if (service.removeData(ids)) {
//		jvo->success(ids);
//	}
//	else
//	{
//		jvo->fail(nullptr);
//	}
//	// ��Ӧ���
//	return jvo;
//}
//FeeItemPageJsonVO::Wrapper FeeItemController::execQueryAll(const FeeItemQuery::Wrapper& query)
//{
    //// �����������
    //FeeItemService service;

    //// ��ѯ��ҳ���ݣ��ڲ����� config_id �ж��Ƿ���й��ˣ�
    //auto pageResult = service.listAll(query);

    //// ��װΪ Json ��Ӧ�ṹ
    //auto vo = FeeItemPageJsonVO::createShared();
    //vo->success(pageResult);

    //return vo;
   // return{};
//}


#include OATPP_CODEGEN_END(ApiController) 
