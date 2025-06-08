#pragma once

#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "../dto/CommunitySpaceMgrDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CommunitySpaceMgrJsonVO : public JsonVO<CommunitySpaceMgrDTO::Wrapper> {
	DTO_INIT(CommunitySpaceMgrJsonVO, JsonVO<CommunitySpaceMgrDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CommunitySpaceMgrPageJsonVO : public JsonVO<CommunitySpaceMgrPageDTO::Wrapper> {
	DTO_INIT(CommunitySpaceMgrPageJsonVO, JsonVO<CommunitySpaceMgrPageDTO::Wrapper>);
};



/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CommunitySpaceTimeMgrJsonVO : public JsonVO<CommunitySpaceTimeMgrDTO::Wrapper> {
	DTO_INIT(CommunitySpaceTimeMgrJsonVO, JsonVO<CommunitySpaceTimeMgrDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class CommunitySpaceTimeMgrPageJsonVO : public JsonVO<CommunitySpaceTimeMgrPageDTO::Wrapper> {
	
	DTO_INIT(CommunitySpaceTimeMgrPageJsonVO, JsonVO<CommunitySpaceTimeMgrPageDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

