## �շѹ���
### �����շ�
#### �������ݷ���

�������ݱ� 
1. pay_fee
2. pay_fee_config


�߼���

ǰ�˴��� �� 

~~~c++
class HouseFeeDTO : public oatpp::DTO
{
	DTO_INIT(HouseFeeDTO, DTO);
	
	//����ID house_id
	DTO_FIELD(Int32, house_id);
	DTO_FIELD_INFO(house_id) {
		info->description = ZH_WORDS_GETTER("");
	}
	
	//�������� fee_type
	DTO_FIELD(String, fee_type);
	DTO_FIELD_INFO(fee_type)
	{
		info->description = ZH_WORDS_GETTER("");
	}
	
	//�շ���Ŀ charge_project
	DTO_FIELD(String, charge_project);
	DTO_FIELD_INFO(charge_project)
	{
		info->description = ZH_WORDS_GETTER("");
	}
	//�Ʒ���ʼʱ�� start_time
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time)
	{
		info->description = ZH_WORDS_GETTER("");
	}
	//�Ʒѽ���ʱ�� end_time
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(fend_time)
	{
		info->description = ZH_WORDS_GETTER("");
	}
};
~~~
��`execAddHouseFee`�н�������У��
�� `Service`����
1. ��������`id` , `fee_type_cd` �� fee_type + charge_project ƴ�Ӻ�ת��Ϊ`id`
2. ��`pay_fee_config`����������
3. �� `PayLoad`�л�ȡ��`user_id`
4. ��`pay_fee_config`��ȡ`amount`
5. ��`PayLoad`��ȡ`commmunity_id`
6.  


~~~



## ���ӷ��ݷ��ù���ҵ��ṹ

���ӷ��ݷ�������ҵ����ϵͳ�еĺ��Ĺ���֮һ����Ҫ���ڶԷ��������շ���Ŀ���Ӵ����������������ҵ���������£�

### 1. ҵ�����

- **��������**��`SaveRoomCreateFeeCmd`���Ǵ������ӷ��ݷ��õ���ڵ㣬��������Ϊ"fee.saveRoomCreateFee"��
- **�������**���������communityId��С��ID����locationObjId������ID����configId����������ID����storeId���̻�ID���Ȳ�����

### 2. ҵ��������

1. **����У��**��У���Ҫ����������ȡ����������Ϣ��
2. **�������κ�**��ͨ��`generatorBatch`�������ɷ������κţ���������pay_fee_batch��
3. **��ѯ������Ϣ**�����ݷ���ID��ѯ�������飬����¥�㡢��Ԫ������ŵ���Ϣ��
4. **��ȡҵ����Ϣ**�����ݷ���ID��ѯҵ����Ϣ������ҵ��ID����������ϵ��ʽ�ȡ�
5. **�������ü�¼**��
   - ͨ��`feeBMOImpl.addRoomFee`���������������ü�¼
   - ��������Ϣ����������ID���������͡���ʼ/����ʱ�䡢�ɷѶ����
   - ���÷���״̬Ϊ"2008001"��������
6. **������������**��
   - ���һ���Է��ý�ֹʱ�䣨�����ã�
   - ���ҵ��ID�����ơ���ϵ��ʽ������
   - ��ӷ��ö������ƣ�¥��-��Ԫ-����ţ�
   - ��������������ͣ�������ӵ������ڡ������ʡ�������ʼʱ�������
7. **��������**��ͨ��`saveFeeAndAttrs`���������úͷ������Ա��浽���ݿ�
8. **�����¶��˵�**���첽��ʽ���������ݺ�Ƿ�����ݣ�Ϊ�����˵���׼��

### 3. ��ص����ݿ��

�Ӵ�����������ӷ��ݷ��ù����漰������Ҫ���ݿ��

1. **pay_fee����������**��
   - feeId������ID��������
   - communityId��С��ID
   - configId����������ID
   - payerObjId���ɷѶ���ID������ID��
   - payerObjType���ɷѶ������ͣ�"3333"��ʾ���ݣ�
   - feeTypeCd���������ͱ���
   - startTime���Ʒѿ�ʼʱ��
   - endTime���Ʒѽ���ʱ��
   - maxTime��������ʱ��
   - amount����-1��ʾ��̬���㣩
   - feeFlag���շѱ�ʶ�������Ի�һ���ԣ�
   - state��״̬��2008001��ʾ������
   - batchId������ID
   - incomeObjId���������ID���̻�ID��
   - userId�������û�ID

2. **pay_fee_attr���������Ա�**��
   - attrId������ID��������
   - feeId������ID�������
   - specCd�������루�������ֲ�ͬ���ԣ�
   - value������ֵ
   - communityId��С��ID
   
   ������specCd������
   - 390001��ҵ��ID
   - 390002��ҵ������
   - 390003��ҵ����ϵ��ʽ
   - 390004��֧���������ƣ�¥��-��Ԫ-���䣩
   - 390006��һ���Է��ý�ֹʱ��
   - 390008������������
   - 390009����������
   - 390010����������ʼʱ��

3. **pay_fee_batch���������α�**��
   - batchId������ID��������
   - communityId��С��ID
   - createUserId�������û�ID
   - createUserName�������û�����
   - state��״̬
   - msg������

4. **pay_fee_config���������ñ�**��
   - configId������ID��������
   - feeName����������
   - feeTypeCd���������ͱ���
   - computingFormula�����㹫ʽ
   - squarePrice��ÿƽ�׵���
   - additionalAmount�����ӷ���
   - communityId��С��ID
   - feeFlag���շѱ�ʶ

5. **report_fee_month_statistics�������¶�ͳ�Ʊ�**��
   - statisticsId��ͳ��ID��������
   - feeId������ID
   - communityId��С��ID
   - configId����������ID
   - feeCreateTime�����ô���ʱ��
   - feeYear���������
   - feeMonth�������·�
   - receivableAmount��Ӧ�ս��
   - receivedAmount��ʵ�ս��
   - oweAmount��Ƿ�ѽ��

6. **report_owe_fee��Ƿ�ѱ�**��
   - oweId��Ƿ��ID��������
   - feeId������ID
   - communityId��С��ID
   - configId����������ID
   - payerObjId���ɷѶ���ID
   - payerObjType���ɷѶ�������
   - ownerId��ҵ��ID
   - ownerName��ҵ������
   - ownerTel��ҵ���绰
   - amountOwed��Ƿ�ѽ��

### 4. ���ݹ�ϵ

- һ�����ݿ��Թ������������Ŀ
- ÿ��������Ŀͨ��configId��������������
- ÿ�������ж���������ԣ�ͨ��feeId����
- ������ҵ��ͨ���������Ա������ҵ��ID�洢��fee_attr���У�
- ��������ͨ��batchId����������ü�¼
- �¶�ͳ�ƺ�Ƿ������ͨ��feeId���������ü�¼

### 5. ���⴦��

1. **������**��������Ҫ��ʱ����������ͨ���������Լ�¼�������ڡ������ʺ͵�����ʼʱ�䡣
2. **һ���Է���**�����һ���Է��ã���Ҫ���ý�ֹʱ�����ԡ�
3. **�Ʒѽ��**�����ü�¼��amount�ֶ�Ĭ��Ϊ-1����ʾ��Ҫ��̬���㣬ϵͳ����ݸ������أ�����������ۡ���ʽ�ȣ�����ʵ�ʷ��á�

�����ǶԷ����շѵ����ӷ��ݷ��ù��ܵ�ҵ��ṹ�͹������ݿ��ķ������ù���ͨ�������������ƣ�ʵ�������ķ��ù���֧�ֶ��ּƷѷ�ʽ�����⴦���߼���

~~~

# С���ܹ�
С������Ľ�ɫ�У�
��ҵ
�̻�
�����Ŷ�
��Ӫ�Ŷ�
community_member ���¼��С����С����ɫ����Ϣ![alt text](PixPin_2025-05-20_12-37-00.png)