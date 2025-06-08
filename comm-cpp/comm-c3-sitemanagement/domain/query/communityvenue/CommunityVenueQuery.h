
#pragma once
#ifndef _COMMUNITYVENUE_QUERY_H_
#define _COMMUNITYVENUE_QUERY_H_

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ݷ�ҳ��ѯ����

 */
class CommunityVenueQuery : public PageQuery {
public:
    DTO_INIT(CommunityVenueQuery, PageQuery);

    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("venue.field.id");
    }
    /* �������� */
    DTO_FIELD(String, name);
    DTO_FIELD_INFO(name) {
        info->description = ZH_WORDS_GETTER("venue.field.name");
    }

};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUE_QUERY_H_
