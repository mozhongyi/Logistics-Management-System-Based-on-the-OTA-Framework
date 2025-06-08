/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:02:34

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "StringUtil.h"
#include "ServerInfo.h"
#include "HttpServer.h"
#include "controller/Router.h"
#include "controller/OtherComponent.hpp"
#include "DbInit.h"

#ifdef LINUX
#include "NacosClient.h"
#endif

/**
 * ��������������
 * ע�⣺
 * ������������Ҫ����һ���ĸ�ʽ���磺sp=8090��sn=feign-cpp-sample
 * ǰ׺����ʵֵ֮��ʹ��=�ָ�
 */
void parseServerArgs(int argc, char* argv[]) {
	// �������˿�
	std::string serverPort = "8090";
	// ���ݿ�������Ϣ
	std::string dbUsername = "";
	std::string dbPassword = "";
	std::string dbName = "";
	std::string dbHost = "";
	int dbPort = -1;
	int dbMax = -1;
#ifdef LINUX
	// Nacos���ò���
	std::string nacosAddr = "";
	std::string nacosNs = "";
	std::string serviceName = "";
	std::string regIp = "";
#endif

	// ��ʼ����
	int currIndex = 1;
	int setDbParamNum = 0;
	while (currIndex < argc)
	{
		// ����ַ���
		auto args = StringUtil::split(argv[currIndex], "=");
		// �жϲ����Ƿ�Ϸ�
		if (args.size() != 2)
		{
			cout << "arg: " << argv[currIndex] << ", format error." << endl;
			exit(1);
		}

		// ���ݲ���ǰ׺�Բ�ͬ���Ը�ֵ
		std::string prefix = args[0];
		std::string val = args[1];
		if (prefix == "sp") serverPort = val;
		else if (prefix == "du")
		{
			setDbParamNum++;
			dbUsername = val;
		}
		else if (prefix == "dp")
		{
			setDbParamNum++;
			dbPassword = val;
		}
		else if (prefix == "dn")
		{
			setDbParamNum++;
			dbName = val;
		}
		else if (prefix == "dh")
		{
			setDbParamNum++;
			dbHost = val;
		}
		else if (prefix == "dP")
		{
			setDbParamNum++;
			dbPort = atoi(val.c_str());
		}
		else if (prefix == "dm") dbMax = atoi(val.c_str());
#ifdef LINUX
		else if (prefix == "na") nacosAddr = val;
		else if (prefix == "ns") nacosNs = val;
		else if (prefix == "sn") serviceName = val;
		else if (prefix == "ip") regIp = val;
#endif
		// ��������
		currIndex++;
	}

	// �������л�ȡ���ݿ�����
	if (setDbParamNum < 5)
	{
#ifdef LINUX
		// ��ȡNacos�е����ݿ�����
		NacosClient nacosClient(nacosAddr, nacosNs);
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
		// ��ȡ�����ļ��е����ݿ�����
		YAML::Node node = YAML::LoadFile("./conf/data-source.yaml");
#endif
		// ����������Ϣ
		YamlHelper yaml;
		std::string dbUrl = yaml.getString(&node, "spring.datasource.url");
		if (dbUrl != "")
		{
			// �������ݿ������ַ���
			yaml.parseDbConnUrl(dbUrl, &dbHost, &dbPort, &dbName);
			// ��ȡ���ݿ��û���������
			dbUsername = dbUsername == "" ? yaml.getString(&node, "spring.datasource.username") : dbUsername;
			dbPassword = dbPassword == "" ? yaml.getString(&node, "spring.datasource.password") : dbPassword;
			dbMax = dbMax == -1 ? atoi(yaml.getString(&node, "spring.datasource.druid.max-active").c_str()) : dbMax;
		}
	}

	// ��¼���������õ��ڴ��з���ʹ��
	ServerInfo::getInstance().setServerPort(serverPort);
	ServerInfo::getInstance().setDbUsername(dbUsername);
	ServerInfo::getInstance().setDbPassword(dbPassword);
	ServerInfo::getInstance().setDbName(dbName);
	ServerInfo::getInstance().setDbHost(dbHost);
	ServerInfo::getInstance().setDbPort(dbPort);
	ServerInfo::getInstance().setDbMax(dbMax);
#ifdef LINUX
	ServerInfo::getInstance().setNacosAddr(nacosAddr);
	ServerInfo::getInstance().setNacosNs(nacosNs);
	ServerInfo::getInstance().setRegIp(regIp);
	ServerInfo::getInstance().setServiceName(serviceName);
#endif
}

int main(int argc, char* argv[]) {
	// ������������ʼ��
	parseServerArgs(argc, argv);

#ifndef _RELEASE_DOC_
	// ��ʼ���ݿ�����
	bool initConnPool = DbInit::initDbPool(DBConfig(
		ServerInfo::getInstance().getDbUsername(),
		ServerInfo::getInstance().getDbPassword(),
		ServerInfo::getInstance().getDbName(),
		ServerInfo::getInstance().getDbHost(),
		ServerInfo::getInstance().getDbPort(),
		ServerInfo::getInstance().getDbMax()));
	if (!initConnPool) return -1;
#endif

#ifdef LINUX
	// ����Nacos�ͻ��˶���
	NacosClient nacosClient(
		ServerInfo::getInstance().getNacosAddr(),
		ServerInfo::getInstance().getNacosNs());

	// ע�����
	if (!ServerInfo::getInstance().getServiceName().empty() && !ServerInfo::getInstance().getRegIp().empty())
	{
		nacosClient.registerInstance(
			ServerInfo::getInstance().getRegIp(),
			atoi(ServerInfo::getInstance().getServerPort().c_str()),
			ServerInfo::getInstance().getServiceName());
	}
#endif

	// ����HTTP������
	HttpServer::startServer(ServerInfo::getInstance().getServerPort(),
		[=](Endpoints* doc, HttpRouter* router) {
			Router(doc, router).initRouter();
		},
		[](std::shared_ptr<AbstractComponentReg>* o) {
			*o = std::make_shared<OtherComponent>();
		});

#ifndef _RELEASE_DOC_
	// �ͷ����ݿ�����
	DbInit::releasePool();
#endif

#ifdef LINUX
	// ��ע�����
	if (!ServerInfo::getInstance().getServiceName().empty() && !ServerInfo::getInstance().getRegIp().empty())
	{
		nacosClient.deregisterInstance(
			ServerInfo::getInstance().getRegIp(),
			atoi(ServerInfo::getInstance().getServerPort().c_str()),
			ServerInfo::getInstance().getServiceName());
	}
#endif
	return 0;
}
