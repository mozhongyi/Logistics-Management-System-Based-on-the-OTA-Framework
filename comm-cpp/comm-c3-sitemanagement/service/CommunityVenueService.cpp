#include "CommunityVenueService.h"
#include "dao/communityvenue/CommunityVenueDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include<iostream>
#include "oatpp/core/base/Environment.hpp"  
#include <exception>


// ��ҳ��ѯ��������
CommunityVenuePageDTO::Wrapper CommunityVenueService::listAll(const CommunityVenueQuery::Wrapper& query) 
{
    // �������ض���
    auto pages = CommunityVenuePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // ��ѯ����������
    CommunityVenueDAO dao;
    v_uint64 count = dao.count(query);
    if (count == 0) {
        return pages;
    }

    // ����������������ҳ��
    pages->total = count;
    pages->calcPages();

    // ��ҳ��ѯ����
    list<CommunityVenueDO> result = dao.selectWithPage(query);
    for (CommunityVenueDO& doItem : result) 
    {
        auto dto = CommunityVenueDTO::createShared();
        // DO -> DTO �ֶ�ӳ�䣨���� CommunityVenueDO �����ԣ�
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, doItem,
            venueId, VenueId,    // �� ��д dto �ֶΣ���д doItem.getVenueId()
            name, Name,
            remark, Remark,
            bId, BId,
            statusCd, StatusCd,
            startTime, StartTime,
            endTime, EndTime);
        pages->addData(dto);
    }
    return pages;
}

// ͨ��ID��ѯ��������
    CommunityVenueDTO::Wrapper CommunityVenueService::getById(std::string id)
     {
        CommunityVenueDAO dao;
        auto doRes = dao.selectById(id);
        if (!doRes) {
            return nullptr;
        }
        auto dto = CommunityVenueDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, doRes,
            venueId, VenueId,
            name, Name,
            remark, Remark,
            bId, BId,

            statusCd, StatusCd,
            startTime, StartTime,
            endTime, EndTime);
        return dto;
    }

// ��������
std::string CommunityVenueService::saveData(const CommunityVenueAddDTO::Wrapper& dto) {
    // ��װ DO
    CommunityVenueDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Name, name,
        Remark, remark,
        StartTime, startTime,
        EndTime, endTime);
    // ���� ID
    SnowFlake sf(1, 1);
    std::string newId = std::to_string(sf.nextId());
    data.setVenueId(newId);

    SnowFlake sff(1, 1);
    std::string newIdd = std::to_string(sff.nextId());
    data.setCommunityId(newIdd);
    // ���ô����ˡ�����ʱ��
    //data.setCreateBy(dto->getPayload()->getUsername());
    data.setCreateTime(SimpleDateTimeFormat::format());
    data.setStatusCd("0");
    data.setBId("");

    CommunityVenueDAO dao;
    return dao.insert(data) == 1 ? data.getVenueId() : "";
}


   /* std::string CommunityVenueService::saveData(const CommunityVenueAddDTO::Wrapper& dto) {
        try {
            CommunityVenueDO data;

            // DTO -> DO �ֶο���
            ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
                Name, name,
                Remark, remark,
                StartTime, startTime,
                EndTime, endTime);

            // ��������
            SnowFlake sf(1,1);
            std::string newId = std::to_string(sf.nextId());
            data.setVenueId(newId);

            // ע������ֶ�
            data.setCreateBy(dto->getPayload()->getUsername());
            data.setCreateTime(SimpleDateTimeFormat::format());

            // ��ӡ����ǰ�����йؼ��ֶ�
            OATPP_LOGD("CommunityVenueService",
                "׼�����볡��: venueId=%s, name=%s, startTime=%s, endTime=%s, createBy=%s",
                data.getVenueId().c_str(),
                data.getName().c_str(),
                data.getStartTime().c_str(),
                data.getEndTime().c_str(),
                data.getCreateBy().c_str());

            // ִ�в���
            CommunityVenueDAO dao;
            int ret = dao.insert(data);
            if (ret != 1) {
                OATPP_LOGE("CommunityVenueService",
                    "����ʧ��: venueId=%s, ��������=%d",
                    newId.c_str(),
                    ret);
                return "";
            }

            OATPP_LOGI("CommunityVenueService",
                "����ɹ�: venueId=%s",
                newId.c_str());
            return newId;
        }
        catch (const std::exception& e) {
            OATPP_LOGE("CommunityVenueService",
                "�����쳣: %s",
                e.what());
            return "";
        }
        catch (...) {
            OATPP_LOGE("CommunityVenueService",
                "����δ֪�쳣");
            return "";
        }
    }
    */



// �޸�����
bool CommunityVenueService::updateData(const CommunityVenueModifyDTO::Wrapper& dto) {
    CommunityVenueDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Name, name,
        Remark, remark,


        StartTime, startTime,
        EndTime, endTime,
        VenueId, venueId);
    // �����޸��ˡ��޸�ʱ��
   // data.setUpdateBy(dto->getPayload()->getUsername());
    //data.setUpdateTime(SimpleDateTimeFormat::format());

    CommunityVenueDAO dao;
    return dao.update(data) == 1;
}

// ͨ��IDɾ������
bool CommunityVenueService::removeData(const oatpp::List<oatpp::String>& ids) 
{
    CommunityVenueDAO dao;
    auto session = dao.getSqlSession();
    session->beginTransaction();
    int rows = 0;
    for (auto one : *ids.get()) {
        rows += dao.deleteById(one.getValue({}));
    }
    if (rows == ids->size()) {
        session->commitTransaction();
        return true;
    }
    session->rollbackTransaction();
    return false;
}
