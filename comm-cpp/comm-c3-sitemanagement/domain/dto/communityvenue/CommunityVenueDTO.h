
// �ļ���domain/dto/communityvenue/CommunityVenueDTO.h
#pragma once
#ifndef _COMMUNITYVENUEDTO_H_
#define _COMMUNITYVENUEDTO_H_

#include "domain/GlobalInclude.h"
#include "CommunityVenueAddDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����Ŀ¼����ģ��
 * �����б�չʾ������鿴��������
 */
class CommunityVenueDTO : public CommunityVenueAddDTO {
public:
    DTO_INIT(CommunityVenueDTO, CommunityVenueAddDTO);


    /* ���ݱ�ţ�varchar(30)��*/
    DTO_FIELD(String, venueId);
    DTO_FIELD_INFO(venueId) {
        info->description = ZH_WORDS_GETTER("venue.field.venueId");
    }


    /* ״̬ status_cd��varchar(2)������ԤԼ/����ԤԼ */
    DTO_FIELD(String, statusCd);
    DTO_FIELD_INFO(statusCd) {
        info->description = ZH_WORDS_GETTER("venue.field.statusCd");
    }
    /* С��ID community_id��varchar(30)��*/
    DTO_FIELD(String, communityId);
    DTO_FIELD_INFO(communityId) {
        info->description = ZH_WORDS_GETTER("venue.field.communityId");
    }
    /* ����ҵ��ID b_id��varchar(30)��*/
    DTO_FIELD(String, bId);
    DTO_FIELD_INFO(bId) {
        info->description = ZH_WORDS_GETTER("venue.field.bId");
    }

    // create_time �����ݿ��Զ����ɣ����ŵ� AddDTO ��
};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEDTO_H_
