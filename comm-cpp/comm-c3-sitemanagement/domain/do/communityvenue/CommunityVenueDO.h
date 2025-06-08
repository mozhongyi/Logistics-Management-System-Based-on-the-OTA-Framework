#pragma once
#ifndef _COMMUNITYVENUE_DO_
#define _COMMUNITYVENUE_DO_

#include "../DoInclude.h"

/**
 * ���ݣ�CommunityVenue�����ݿ�ʵ����
 */
class CommunityVenueDO {
    // ���ݱ�� ����Ӧ���ݿ��� community_venue.venue_id��
    CC_SYNTHESIZE(std::string, venueId, VenueId);
    // �������� ����Ӧ���ݿ��� name��
    CC_SYNTHESIZE(std::string, name, Name);
    // ��ע/���� ����Ӧ���ݿ��� remark��
    CC_SYNTHESIZE(std::string, remark, Remark);
    // ����ʱ�� ����Ӧ���ݿ��� start_time��
    CC_SYNTHESIZE(std::string, startTime, StartTime);
    // �س�ʱ�� ����Ӧ���ݿ��� end_time��
    CC_SYNTHESIZE(std::string, endTime, EndTime);
    // ״̬����ԤԼ/Y������ԤԼ/N�� ����Ӧ���ݿ��� status_cd��
    CC_SYNTHESIZE(std::string, statusCd, StatusCd);
    // С�� ID ����Ӧ���ݿ��� community_id��
    CC_SYNTHESIZE(std::string, communityId, CommunityId);
    // ҵ����� ID ����Ӧ���ݿ��� b_id��
    CC_SYNTHESIZE(std::string, bId, BId);

    // ������
    CC_SYNTHESIZE(std::string, createBy, CreateBy);
    // ����ʱ��
    CC_SYNTHESIZE(std::string, createTime, CreateTime);
    // �޸���
    CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
    // �޸�ʱ��
    CC_SYNTHESIZE(std::string, updateTime, UpdateTime);

public:
    CommunityVenueDO() {
        venueId = "";
        name = "";
        remark = "";
        startTime = "";
        endTime = "";
        statusCd = "";
        communityId = "";
        bId = "";
        // ����/�޸��ߡ�ʱ������ջ��ɿ�����
        createBy = "";
        createTime = "";
        updateBy = "";
        updateTime = "";
    }
};

// �� CommunityVenueDO ����ָ���趨������������ DAO ��ʹ��
typedef std::shared_ptr<CommunityVenueDO> PtrCommunityVenueDO;

#endif // _COMMUNITYVENUE_DO_
