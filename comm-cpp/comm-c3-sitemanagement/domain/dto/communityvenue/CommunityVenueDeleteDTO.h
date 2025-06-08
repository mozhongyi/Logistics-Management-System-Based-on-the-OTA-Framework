#pragma once
#ifndef _COMMUNITYVENUEDELETEDTO_H_
#define _COMMUNITYVENUEDELETEDTO_H_

#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ɾ���������ݴ������
 * ֧������ɾ����ͨ�����볡�ݱ���б�
 */
class CommunityVenueDeleteDTO : public oatpp::DTO {
    DTO_INIT(CommunityVenueDeleteDTO, DTO);

    /* ���ݱ���б� */
    DTO_FIELD(String, venueIds);
    DTO_FIELD_INFO(venueIds) {
        info->description = ZH_WORDS_GETTER("venue.field.venueIds");
    }

    /* ��ѡ����Ȩ���� */
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEDELETEDTO_H_
