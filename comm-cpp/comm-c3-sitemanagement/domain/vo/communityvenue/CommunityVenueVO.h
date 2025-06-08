
#pragma once
#ifndef _COMMUNITYVENUE_VO_
#define _COMMUNITYVENUE_VO_

#include "domain/GlobalInclude.h"
#include "../../dto/communityvenue/CommunityVenueDTO.h"
#include "../../dto/communityvenue/CommunityVenuePageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ʾ JsonVO��������Ӧ���ͻ��˵� Json ����
 */
class CommunityVenueJsonVO : public JsonVO<CommunityVenueDTO::Wrapper> {
	DTO_INIT(CommunityVenueJsonVO, JsonVO<CommunityVenueDTO::Wrapper>);
};

/**
 * ���ݷ�ҳ��ʾ JsonVO��������Ӧ���ͻ��˵� Json ����
 */
class CommunityVenuePageJsonVO : public JsonVO<CommunityVenuePageDTO::Wrapper> {
	DTO_INIT(CommunityVenuePageJsonVO, JsonVO<CommunityVenuePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _COMMUNITYVENUE_VO_
