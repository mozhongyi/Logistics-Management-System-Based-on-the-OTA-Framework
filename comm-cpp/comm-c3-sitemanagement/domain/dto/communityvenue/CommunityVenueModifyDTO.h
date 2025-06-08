#pragma once

#ifndef _COMMUNITYVENUEMODIFYDTO_H_
#define _COMMUNITYVENUEMODIFYDTO_H_

#include "domain/GlobalInclude.h"
#include "CommunityVenueAddDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �޸ĳ������ݴ������
 */
class CommunityVenueModifyDTO : public CommunityVenueAddDTO {
public:

    DTO_INIT(CommunityVenueModifyDTO, CommunityVenueAddDTO);

    /* ���ݱ�ţ�venue_id���� ������ڶ�λҪ�޸ĵļ�¼ */
    DTO_FIELD(String, venueId);
    DTO_FIELD_INFO(venueId) {
        info->description = ZH_WORDS_GETTER("venue.field.venueId");
    }

    /* �������ƣ�varchar(30)��*/
    DTO_FIELD(String, name);
    DTO_FIELD_INFO(name) {
        info->description = ZH_WORDS_GETTER("venue.field.name");
    }
    /* ��ע/������varchar(512)��*/
    DTO_FIELD(String, remark);
    DTO_FIELD_INFO(remark) {
        info->description = ZH_WORDS_GETTER("venue.field.remark");
    }
    /* ����ʱ�� start_time��varchar(30)��*/
    DTO_FIELD(String, startTime);
    DTO_FIELD_INFO(startTime) {
        info->description = ZH_WORDS_GETTER("venue.field.startTime");
    }

    /* �س�ʱ�� end_time��varchar(30)��*/
    DTO_FIELD(String, endTime);
    DTO_FIELD_INFO(endTime) {
        info->description = ZH_WORDS_GETTER("venue.field.endTime");
    }


};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEMODIFYDTO_H_
