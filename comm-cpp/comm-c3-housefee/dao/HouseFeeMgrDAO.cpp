#include "stdafx.h"
#include "HouseFeeMgrDAO.h"
#include "HouseFeeMgrMapper.h"
#include <sstream>

std::string HouseFeeMgrDAO::queryConditionBuilder(const HouseFeeMgrQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->communityId) {

		//sqlCondition << " AND `report_owe_fee`.`community_id`=?";
		sqlCondition << " AND `pay_fee`.`community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	if (query->roomNum) {

		sqlCondition << " AND `report_owe_fee`.`payer_obj_name`=?";
		//sqlCondition << " AND `payer_obj_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->roomNum.getValue(""));
	}
	if (query->status) {
	
		//sqlCondition << " AND `pay_fee`.`state`=?";
		sqlCondition << " AND `pay_fee`.`state`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue(""));
	}
	if (query->ownerNameLike) {

		//sqlCondition << " AND `report_owe_fee`.`owner_name`=?";
		sqlCondition << " AND `report_owe_fee`.`owner_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ownerNameLike.getValue(""));
	}
	return sqlCondition.str();
}
std::string HouseFeeMgrDAO::queryConditionBuilder2(const HouseFeeMgrQueryByRoom::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->communityId) {

		//sqlCondition << " AND `report_owe_fee`.`community_id`=?";
		sqlCondition << " AND `pay_fee`.`community_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	if (query->roomNum) {

		sqlCondition << " AND `report_owe_fee`.`payer_obj_name`=?";
		//sqlCondition << " AND `payer_obj_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->roomNum.getValue(""));
	}
	return sqlCondition.str();
}

	// ͳ����������
uint64_t HouseFeeMgrDAO::count(const HouseFeeMgrQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM `report_owe_fee` JOIN `pay_fee` ON `report_owe_fee`.`fee_id` = `pay_fee`.`fee_id`";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}
uint64_t HouseFeeMgrDAO::count2(const HouseFeeMgrQueryByRoom::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM `report_owe_fee` JOIN `pay_fee` ON `report_owe_fee`.`fee_id` = `pay_fee`.`fee_id`";
	// ������ѯ����
	sql += queryConditionBuilder2(query, params);
	// ִ�в�ѯ
	return sqlSession->executeQueryNumerical(sql, params);
}
	// ��ҳ��ѯ����
std::list<HouseFeeMgrDO> HouseFeeMgrDAO::selectWithPage(const HouseFeeMgrQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT \
`report_owe_fee`.`fee_id`,\
`pay_fee`.`fee_flag`,\
`pay_fee`.`fee_type_cd`,\
`report_owe_fee`.`payer_obj_name`, \
`report_owe_fee`.`config_name`,\
`pay_fee`.`state`,\
`report_owe_fee`.`end_time`,\
`pay_fee`.`batch_id`,\
`report_owe_fee`.`deadline_time`,\
`report_owe_fee`.`amount_owed`,\
`report_owe_fee`.`owner_tel`,\
`report_owe_fee`.`owner_name`,\
`report_owe_fee`.`owner_id` \
 FROM `report_owe_fee` JOIN `pay_fee` ON `report_owe_fee`.`fee_id` = `pay_fee`.`fee_id` AND `pay_fee`.`state`='2008001'";
	// ������ѯ����
	sql += queryConditionBuilder(query, params);
	// �����������
	sql += " ORDER BY `report_owe_fee`.`owe_id` DESC ";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	//std::cout << "DEBUG SQL: " << sql << std::endl;
	// ִ�в�ѯ
	HouseFeeMgrMapper mapper;
	return sqlSession->executeQuery<HouseFeeMgrDO>(sql, mapper, params);
}
	// ͨ������id��ѯ����
PtrHouseFeeMgrDO HouseFeeMgrDAO::selectById(std::string id)
{
	string sql = "SELECT \
`report_owe_fee`.`fee_id`,\
`pay_fee`.`fee_flag`,\
`pay_fee`.`fee_type_cd`,\
`report_owe_fee`.`payer_obj_name`, \
`report_owe_fee`.`config_name`,\
`pay_fee`.`state`,\
`report_owe_fee`.`end_time`,\
`pay_fee`.`batch_id`,\
`report_owe_fee`.`deadline_time`,\
`report_owe_fee`.`amount_owed`,\
`report_owe_fee`.`owner_tel`,\
`report_owe_fee`.`owner_name`,\
`report_owe_fee`.`owner_id` \
 FROM `report_owe_fee` JOIN `pay_fee` ON `report_owe_fee`.`fee_id` = `pay_fee`.`fee_id` WHERE `report_owe_fee`.`fee_id`= ? ";
	PtrHouseFeeMgrMapper mapper;
	return sqlSession->executeQueryOne<PtrHouseFeeMgrDO>(sql, mapper, "%s", id);
}
	// ͨ�����ݺŲ�ѯ����
std::list<HouseFeeMgrDO> HouseFeeMgrDAO::selectByOwnerNum(const HouseFeeMgrQueryByRoom::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT \
`report_owe_fee`.`fee_id`,\
`pay_fee`.`fee_flag`,\
`pay_fee`.`fee_type_cd`,\
`report_owe_fee`.`payer_obj_name`, \
`report_owe_fee`.`config_name`,\
`pay_fee`.`state`,\
`report_owe_fee`.`end_time`,\
`pay_fee`.`batch_id`,\
`report_owe_fee`.`deadline_time`,\
`report_owe_fee`.`amount_owed`,\
`report_owe_fee`.`owner_tel`,\
`report_owe_fee`.`owner_name`,\
`report_owe_fee`.`owner_id` \
 FROM `report_owe_fee` JOIN `pay_fee` ON `report_owe_fee`.`fee_id` = `pay_fee`.`fee_id` AND `pay_fee`.`state`='2008001' ";
	// ������ѯ����
	sql += queryConditionBuilder2(query, params);
	// �����������
	sql += " ORDER BY `report_owe_fee`.`owe_id` DESC ";
	// ������ҳ����
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	//std::cout << "DEBUG SQL: " << sql << std::endl;
	// ִ�в�ѯ
	HouseFeeMgrMapper mapper;
	return sqlSession->executeQuery<HouseFeeMgrDO>(sql, mapper, params);
}