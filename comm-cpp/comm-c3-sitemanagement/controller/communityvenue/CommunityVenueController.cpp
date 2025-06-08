#include "stdafx.h"
#include "CommunityVenueController.h"
#include "service/CommunityVenueService.h"

/*--- ��ҳ��ѯ���� ---*/
CommunityVenuePageJsonVO::Wrapper
CommunityVenueController::execQueryVenue(const CommunityVenueQuery::Wrapper& query) {

    CommunityVenueService service;
    //ֱ�ӷ���һ��PageDTOʵ��
    auto result = service.listAll(query);
    auto jvo = CommunityVenuePageJsonVO::createShared();

    jvo->success(result);
    return jvo;
}

/*id ��ѯ*/
CommunityVenueJsonVO::Wrapper CommunityVenueController::execQueryById(const String& id)
{
    // ���巵�����ݶ���
    auto jvo = CommunityVenueJsonVO::createShared();

    // ����У��
    // �ǿ�У��
    if (!id)
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // ����һ��Service
    CommunityVenueService service;
    // ִ����������
    auto res = service.getById(id.getValue({}));
    jvo->success(res);

    //��Ӧ���
    return jvo;
}

/*--- �������� ---*/
StringJsonVO::Wrapper
CommunityVenueController::execAddVenue(const CommunityVenueAddDTO::Wrapper& dto,
    const PayloadDTO& payload) {
    // 1. �������� VO
    auto jvo = StringJsonVO::createShared();

    // 2. ����У�飺�ǿ� & �ǿ��ַ���
    if (!dto->name || dto->name->empty() ||
        !dto->startTime || dto->startTime->empty() ||
        !dto->endTime || dto->endTime->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // 3. ע�� Payload
    dto->setPayload(&payload);

    // 4. ���� Service ִ������
    CommunityVenueService service;
    std::string newId = service.saveData(dto);

    // 5. ���� Service ����ֵ���� success �� fail
    if (!newId.empty()) {
        jvo->success(newId);
    }
    else {
        jvo->fail("");
    }

    return jvo;
}


/*--- �޸ĳ��� ---*/
StringJsonVO::Wrapper CommunityVenueController::execModifyVenue(const CommunityVenueModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // ���巵�����ݶ���
    auto jvo = StringJsonVO::createShared();
    // ����У��
    if (!dto->venueId)
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    CommunityVenueService service;
    // ִ�������޸�
    dto->setPayload(&payload);
    if (service.updateData(dto)) {
        jvo->success(dto->venueId);
    }
    else
    {
        jvo->fail(dto->venueId);
    }
    // ��Ӧ���
    return jvo;
}



/*--- ɾ������ ---*/
ListJsonVO<String>::Wrapper
CommunityVenueController::execDeleteVenue(const List<String>& ids) {
    auto jvo = ListJsonVO<String>::createShared();
    if (ids->empty()) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }
    CommunityVenueService service;
    // TODO: ɾ���߼�������ɾ����� ID 
    if (service.removeData(ids)) {
        jvo->success(ids);
    }
    else
    {
        jvo->fail(nullptr);
    }
    return jvo;
}
