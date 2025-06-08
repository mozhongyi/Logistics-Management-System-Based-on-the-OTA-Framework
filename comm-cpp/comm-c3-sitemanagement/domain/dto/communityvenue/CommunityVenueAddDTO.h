#pragma once
#ifndef _COMMUNITYVENUEADDTO_H_
#define _COMMUNITYVENUEADDTO_H_

#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ӳ������ݴ������
 */
class CommunityVenueAddDTO : public oatpp::DTO {
    DTO_INIT(CommunityVenueAddDTO, DTO);



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


    /* ����һ�� PayloadDTO �������ݶ������м�Ȩ���� */
    CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);

};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEADDTO_H_
