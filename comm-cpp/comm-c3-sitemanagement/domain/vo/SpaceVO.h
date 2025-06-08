#pragma once

#ifndef _SPACEVO_H_
#define _SPACEVO_H_

#include "../GlobalInclude.h"
#include "../dto/SpaceDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  ������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SpaceJsonVO : public JsonVO<SpaceDTO::Wrapper> {
	DTO_INIT(SpaceJsonVO, JsonVO<SpaceDTO::Wrapper>);
};

/**
 * ���ط�ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class SpacePageJsonVO : public JsonVO<SpacePageDTO::Wrapper> {
	DTO_INIT(SpacePageJsonVO, JsonVO<SpacePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_