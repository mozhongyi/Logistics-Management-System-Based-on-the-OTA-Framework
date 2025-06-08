
// �ļ���domain/dto/communityvenue/CommunityVenuePageDTO.h
#pragma once
#ifndef _COMMUNITYVENUEPAGEDTO_H_
#define _COMMUNITYVENUEPAGEDTO_H_

#include "domain/GlobalInclude.h"
#include "CommunityVenueDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���ݷ�ҳ�������
 * �̳��� PageDTO����װ CommunityVenueDTO
 */
class CommunityVenuePageDTO : public PageDTO<CommunityVenueDTO::Wrapper> {
public:
	DTO_INIT(CommunityVenuePageDTO, PageDTO<CommunityVenueDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _COMMUNITYVENUEPAGEDTO_H_
