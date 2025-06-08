-- Change DataBase
USE `zo_community`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of m_menu_catalog
-- ----------------------------
-- INSERT INTO `m_menu_catalog` (`ca_id`, `name`, `icon`, `seq`, `store_type`, `url`, `is_show`, `create_time`, `status_cd`, `priv_id`) VALUES ('102022022641270001', '首页', 'fa fa-home', 1, '800900000003', '/', 'Y', '2022-02-26 11:31:54', '0', NULL);4012536900010');
-- TODO 需要后续补充

-- ----------------------------
-- Records of m_menu_group
-- ----------------------------
-- INSERT INTO `m_menu_group` (`g_id`, `name`, `icon`, `label`, `seq`, `description`, `create_time`, `status_cd`, `group_type`, `store_type`) VALUES ('800201904001', '组织', 'fa fa-th-large', '', 17, '员工管理', '2019-04-01 02:17:37', '0', 'P_WEB', '800900000003');
-- TODO 需要后续补充

-- ----------------------------
-- Records of m_menu
-- ----------------------------
-- INSERT INTO `m_menu` (`m_id`, `name`, `g_id`, `url`, `seq`, `p_id`, `description`, `create_time`, `status_cd`, `is_show`) VALUES ('700201904001', '员工信息', '800201904001', '/#/pages/frame/staff', 2, '500201904001', '员工信息', '2019-04-01 02:19:51', '0', 'Y');
-- TODO 需要后续补充

SET FOREIGN_KEY_CHECKS = 1;