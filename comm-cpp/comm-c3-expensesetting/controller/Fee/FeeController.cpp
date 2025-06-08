#include "stdafx.h"
#include "FeeController.h"
#include "../../service/FeeMgr/FeeMgrService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include <iostream>

#include OATPP_CODEGEN_BEGIN(ApiController)  

//��ҳ��ѯ
FeeMgrPageJsonVO::Wrapper FeeController::execQueryAll(const FeeMgrQuery::Wrapper& query)
{
    // ����һ��Service
    FeeMgrService service;
    // ��ѯ����
    auto result = service.getById("1111");
    // ��Ӧ���
    auto jvo = FeeMgrPageJsonVO::createShared();
    //jvo->success(result);
    return jvo;
}



//...........................................................
FeeMgrJsonVO::Wrapper FeeController::execAdditemlog(const FeeMgrAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
    auto jvo = FeeMgrJsonVO::createShared();

    
    FeeMgrService service;
    dto->setPayload(&payload);
    std::string id = service.saveData(dto);

    return jvo;
}


FeeMgrJsonVO::Wrapper FeeController::execRemoveitem(const FeeMgrDeleteDTO::Wrapper& dto, const PayloadDTO& payload)
{
    auto jvo = FeeMgrJsonVO::createShared();

    if (!dto->discount_id || dto->discount_id->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    return jvo;
}

FeeMgrJsonVO::Wrapper FeeController::execGetFeeItemInfo(const FeeMgrGetDTO::Wrapper& dto, const PayloadDTO& payload)
{
    return {};
}
