#include "stdafx.h"
#include "HousePayFeeService.h"
#include "../../dao/HousePayFee/HousePayFeeDAO.h"
#include "../../lib-common/include/id/SnowFlake.h"

Int32JsonVO::Wrapper HousePayFeeService::addHousePayFee(const AddHouseFeeDTO::Wrapper& houseFee, const std::shared_ptr<PayloadDTO> payload)
{
	HousePayFeeDAO dao;
	//����һ������
	auto configId = houseFee->config_id.getValue({""});
	// ��ѯcommunity_id
	cout << "In Find" << endl;
	auto xxx = dao.findCommunityId(houseFee->config_id.getValue({ "" }));
	
	cout << xxx.getCommunity() << endl;
	cout << xxx.getFeeTypeCd() << endl;
	auto resp = Int32JsonVO::createShared();
	std::string house_id = houseFee->house_id.getValue({ "" });
	
	std::vector<std::string> num(3);
	int idx = 0;
	//�ָ� house_id
	std::string sub_string;
	for (const auto& i : house_id)
	{
		if (i == '-')
		{
			num[idx] = sub_string;
			idx++;
			sub_string.clear();
		}
		else
			sub_string += i;
	}
	num[2] = sub_string;
	cout << num[0] << " " << num[1] << " " << num[2] << endl;
	std::string floor_num, unit_num, room_num;
	//��ѯ����id �� �����������Ϣ
	cout << "In HouseInfo" << endl;
	auto houseInfo = dao.searchHouseInfo(num[0], num[1], num[2], xxx.getCommunity());
	cout << houseInfo.getRoomId() << endl;
	
	//������ ����community_id �� config_id
	auto detail = CalcHousePayDTO::createShared();
	
	detail->charge_project = houseFee->charge_project;
	detail->room_area = houseInfo.getRoomArea();
	detail->built_up_area = houseInfo.getBuiltUpArea();
	detail->fee_type = xxx.getFeeTypeCd();
	detail->start_time = houseFee->start_time;
	detail->end_time = houseFee->end_time;

	cout << "In calcFee" << endl;
	auto amount = dao.calcHouseFee(detail);
	cout << "Out calcFee" << endl;
	//ƴ������
	auto payFeeDO = std::make_shared<AddPayFeeDO>();
	auto payFeeBatch = std::make_shared<AddPayFeeConfigDO>();
	//����fee_id
	AddPayFeeDO x;

	SnowFlake sf(1, 1);
	payFeeDO->setCommunityCd(xxx.getCommunity());
	std::string id = std::to_string(sf.nextId());

	payFeeDO->setFeeId(id);

	// ����b_id
	//std::to_string(sf.nextId())
	payFeeDO->setBId(id);

	//����batch_id
	payFeeBatch->setBatchId(id);
	payFeeDO->setBatchId(id);

	payFeeDO->setFeeTypeCd(xxx.getFeeTypeCd());
	payFeeDO->setPayerObjId(houseInfo.getRoomId());

	payFeeDO->setIncomeObjId(payload->getId());

	payFeeDO->setStartTime(detail->start_time.getValue({ "" }));
	payFeeDO->setEndTime(detail->end_time.getValue({ "" }));
	
	payFeeDO->setAmount(amount->data.getValue({}));
	//����status_cd
	payFeeDO->setStatusCd("1");
	payFeeBatch->setStatusCd("1");

	payFeeDO->setFeeFlag(xxx.getFeeFlag());
	payFeeDO->setUserId(payload->getId());
	payFeeDO->setConfigId(houseFee->config_id.getValue({ "" }));

	int res = checkDateRange(payFeeDO->getStartTime(), payFeeDO->getEndTime());

	if (res == 1)
	{
		payFeeDO->setState("2008001");
		payFeeBatch->setState("2008001");
	}
	else if (res == 2)
	{
		payFeeDO->setState("2007001");
		payFeeBatch->setState("2007001");
	}
	else
	{
		payFeeDO->setState("2009001");
		payFeeBatch->setState("2009001");
	}

	//
	payFeeDO->setPayerObjCd(houseFee->fee_type.getValue({""}));
	
	payFeeDO->setPayerObjId(payload->getId());

	//=======payFeeConfig
	payFeeBatch->setCommunityId(xxx.getCommunity());
	payFeeBatch->setCreateUserId(payload->getId());
	payFeeBatch->setCreateUserName(payload->getUsername());
	payFeeBatch->setMsg("NULL");
	payFeeBatch->setRemark("NULL");
	//create_time
	auto now = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(now);

	// ת��Ϊ����ʱ��
	std::tm* local_time = std::localtime(&current_time);

	// ��ʽ��ʱ���ַ��� (YYYY-MM-DD HH:MM:SS)
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);

	payFeeBatch->setCreateTime(std::string(buffer));
	payFeeDO->setCreateTime(std::string(buffer));
	// �������ݿ�
	cout << "In HouseFee" << endl;
	resp = dao.insertHouseFee(*payFeeDO, *payFeeBatch);

	//�ر�����                                                                                                                                                                              
	return resp;
}

int  HousePayFeeService::checkDateRange(const std::string& date1, const std::string& date2) {
	// ���ַ�������ת��Ϊtime_t����ҹʱ�����
	auto strToTimeT = [](const std::string& dateStr) -> time_t {
		std::tm tm = {};
		std::istringstream ss(dateStr);
		ss >> std::get_time(&tm, "%Y-%m-%d");
		tm.tm_isdst = -1; // �Զ���������ʱ
		return std::mktime(&tm);
		};

	// ��ȡ��ǰ���ڵ���ҹʱ���
	time_t now = time(nullptr);
	std::tm* now_tm = std::localtime(&now);
	now_tm->tm_hour = 0;
	now_tm->tm_min = 0;
	now_tm->tm_sec = 0;
	now_tm->tm_isdst = -1;
	time_t now_midnight = std::mktime(now_tm);

	// ת����������
	time_t t1 = strToTimeT(date1);
	time_t t2 = strToTimeT(date2);

	// ȷ���������������
	time_t early = (t1 < t2) ? t1 : t2;
	time_t late = (t1 > t2) ? t1 : t2;

	// ��鵱ǰ����λ��
	if (now_midnight < early) {
		return 2; // ��ǰ����������������
	}
	else if (now_midnight > late) {
		return 0; // ��ǰ����������������
	}
	return 1; // ��ǰ�����������ڣ������߽磩
}

 Int32JsonVO::Wrapper HousePayFeeService::removeHousePayFee(const HouseFeeIdDTO::Wrapper& delInfo)
{
	
	HousePayFeeDAO dao;
	auto res = dao.deleteHouseFee(delInfo->fee_id.getValue({ "" }));
	return res;
}


 Int32JsonVO::Wrapper HousePayFeeService::modifyHousePayFee(const ModifyHouseFeeDTO::Wrapper& modifyInfo)
 {
	 HousePayFeeDAO dao ;
	 cout << "In SearchModifyInfo " << endl;
	 auto info = dao.searchModifyInfo(modifyInfo->fee_id.getValue({ "" }));
	 cout << "Out SearchModifyInfo " << endl;

	 //����ʱ���
	double diff =  dao.calcTimeDiff(modifyInfo->start_time.getValue({ "" }), modifyInfo->end_time.getValue({ "" }));
	 Float64 amount;
	 amount = info.getAdditionalPrice() + info.getBuildUpArea()* info.getSquarePrice() * diff;

	 auto dto = CalcDiscountDTO::createShared() ;
	 dto->community_id = info.getCommunityId();
	 dto->fee_type = info.getFeeType();
	 dto->amount = amount;
	 // �����ۿ۷���
	 cout << "In calcDiscount " << endl;
	 amount = dao.calcDiscount(dto)->data;
	 cout << "OutcalcDiscount " << endl;
	 
	 return dao.modifyHoueFee(modifyInfo,amount);

 }

 std::string getCurrentTimeString() {
	 // ��ȡ��ǰϵͳʱ��
	 auto now = std::chrono::system_clock::now();
	 std::time_t current_time = std::chrono::system_clock::to_time_t(now);

	 // ת��Ϊ����ʱ��
	 std::tm* local_time = std::localtime(&current_time);

	 // ��ʽ��ʱ���ַ��� (YYYY-MM-DD HH:MM:SS)
	 char buffer[80];
	 std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);

	 return std::string(buffer);
 }
 Int32JsonVO::Wrapper HousePayFeeService::payHouseFee(const PayFeeDTO::Wrapper& pay, const std::shared_ptr<PayloadDTO> payload)
 {
	 HousePayFeeDAO dao;
	 PaymentInfoDO data;
	
	 //ѩ���㷨����id
	 SnowFlake sf(1, 1);
	 data.setDetailId(std::to_string(sf.nextId()));

	// ����b_id
	 SnowFlake sf1(1, 2);
	 data.setBId(std::to_string(sf1.nextId()));
	// fee_id
	 data.setFeeId(pay->fee_id.getValue({ "" }));
	 // community_id
	 data.setCommunityId(pay->community_id.getValue({ "" }));
	 // cycles
	 if (pay->real_cycle != 0)
	 {

	 }
	 data.setCycles(pay->cycle.getValue({ }));

	 // receivable_amount
	 data.setReceivableAmount(pay->amount_due);
	 //received_amount
	 data.setReceivedAmount(pay->pay_amount);
	 //pay->pay_fee_way.getValue({""})
	 int way = 1;
	 if (pay->pay_fee_way.getValue({ "" }) == u8"΢��")
	 {
		 way = 1;
	 }
	 else if (pay->pay_fee_way.getValue({ "" }) == u8"�ֽ�")
	 {
		 way = 2;
	 }
	 else if (pay->pay_fee_way.getValue({ "" }) == u8"�˻��ֿ�")
	 {
		 way = 3;
	 }
	 //prime_rate
	 data.setPrimeRate(way);
	 //  remark
	 data.setRemark(pay->remark.getValue({ "" }));
	 // create_time
	 data.setCreateTime(getCurrentTimeString());
	 
	 
	 StatusTimeDO timeDO = dao.searchFeeState(pay->fee_id.getValue({ "" }));

	 //status_cd
	 data.setStatusCd("1");
	 data.setState("1");
	 data.setStartTime(getCurrentTimeString());
	 data.setEndTime(getCurrentTimeString());

	 data.setStatusCd(timeDO.getStatusCd());
	 data.setState(timeDO.getState());
	 data.setStartTime(timeDO.getStartTime());
	 data.setEndTime(timeDO.getEndTime());

	 cout << data.getStatusCd() << " " << data.getState() << " " << data.getStartTime() << " " << data.getEndTime() << endl;

	 //payable_amount
	 data.setPayableAmount(pay->amount);

	 //pay_order_id
	 SnowFlake sf2(2, 2);
	 data.setPayOrderId(std::to_string(sf2.nextId()));
	 
	 //cashier_id
	
	 data.setCashierId(payload->getId());
	 data.setCashierName(payload->getUsername());

	 // open_invoice
	 data.setOpenInvoice(false);
	 data.setAcctAmount(0);

	 auto info = dao.searchFeeDiscount(timeDO.getConfigId());

	 data.setDiscountAmount(0), data.setDeductionAmount(0), data.setLateAmount(0);
	 for (const auto& i : info)
	 {
		 if (i.getDiscountType() == "1001")
		 {
			 if (i.getSpecValue() < 1)
			 {
				 data.setDiscountAmount(data.getAcctAmount() * i.getSpecValue());
			 }
			 else
			 {
				 data.setDeductionAmount(data.getAcctAmount() + i.getSpecValue());
			 }
		 }
		 else
		 {
			 data.setLateAmount(i.getSpecValue());
		 }
	 }
	 //���ͽ��
	 data.setGiftAmount(0);

	 
	 return dao.insertPayFee(data);
 }
