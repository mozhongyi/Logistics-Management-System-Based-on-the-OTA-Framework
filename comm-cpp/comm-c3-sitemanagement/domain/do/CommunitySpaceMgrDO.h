#pragma once
#include "DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */

class CommunitySpaceMgrDO
{
	// ���ر��
	CC_SYNTHESIZE(string, space_id, Space_Id);
	// ��������
	CC_SYNTHESIZE(string, name, Name);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_time, Start_Time);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_time, End_Time);
	//
	CC_SYNTHESIZE(double, fee_money, Fee_Money);
	// ����Ա
	CC_SYNTHESIZE(string, admin_name, Admin_Name);
	// �绰
	CC_SYNTHESIZE(string, tel, Tel);
	// 
	CC_SYNTHESIZE(string, b_id, B_Id);
	// 
	CC_SYNTHESIZE(string, community_id, Community_Id);
	// 
	CC_SYNTHESIZE(string, state, State);
	// 
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// 
	CC_SYNTHESIZE(string, status_cd, Status_Cd);
	// 
	CC_SYNTHESIZE(string, venue_id, Venue_Id);

public:
	CommunitySpaceMgrDO() {
		name = "";
		start_time = "";
		end_time = "";
		admin_name = "";
		tel = "";
		fee_money = 0;

		space_id = "";
		b_id = "";
		community_id = "";
		venue_id = "";
		state = "";
		status_cd = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CommunitySpaceMgrDO> PtrCommunitySpaceMgrDO;

//---------------------------------------------------------------------------------------------------

class CommunitySpaceTimeMgrDO
{
	// 
	CC_SYNTHESIZE(string, time_id, Time_Id);
	// 
	CC_SYNTHESIZE(string, space_id, Space_Id);
	// 
	CC_SYNTHESIZE(int, hours, Hours);
	//
	CC_SYNTHESIZE(string, is_open, Is_Open);
	// 
	CC_SYNTHESIZE(string, b_id, B_Id);
	// 
	CC_SYNTHESIZE(string, community_id, Community_Id);
	// 
	CC_SYNTHESIZE(string, create_time, Create_Time);
	// 
	CC_SYNTHESIZE(string, status_cd, Status_Cd);

public:
	CommunitySpaceTimeMgrDO() {
		hours = 0;
		is_open = "N";

		space_id = "";
		time_id = "";
		b_id = "";
		community_id = "";
		status_cd = "";
	}
};

// ��SampleDO����ָ���趨һ����������ʹ��
typedef std::shared_ptr<CommunitySpaceTimeMgrDO> PtrCommunitySpaceTimeMgrDO;

