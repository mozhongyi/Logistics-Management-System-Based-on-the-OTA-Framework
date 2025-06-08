/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 12:11:03

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
#include "../include/DbInit.h"
#include <sstream>

ConnPool* DbInit::connPool = NULL;

#define INFO_CONN_FAIL(config) \
cout << "mysql connection pool init fail, please check your connection info." << endl; \
cout << "host:" << config.host << endl; \
cout << "user:" << config.user << endl; \
cout << "pass:" << config.pass << endl; \
cout << "db:" << config.db << endl; \
cout << "port:" << config.port << endl; \
cout << "maxSize:" << config.poolMaxSize << endl

bool DbInit::initDbPool(DBConfig config)
{
	// �ж����Ӳ����Ƿ���ȷ
	if (config.host.empty() || config.user.empty() || config.pass.empty() || config.db.empty() || config.port < 1)
	{
		INFO_CONN_FAIL(config);
		return false;
	}

	// ���ӳ��������������С��1
	config.poolMaxSize = config.poolMaxSize < 1 ? 5 : config.poolMaxSize;

	releasePool();
	stringstream ss;
	ss << "tcp://" << config.host << ":" << config.port << "/" << config.db;
	connPool = new ConnPool(ss.str(), config.user, config.pass, config.poolMaxSize);

	// ��鵱ǰ���ӳ��е����Ӷ������Ƿ�Ϊ0
	if (connPool->getPoolSize())
	{
		cout << "mysql connection pool init finish." << endl;
		return true;
	}
	else
	{
		INFO_CONN_FAIL(config);
		return false;
	}
}

ConnPool* DbInit::getConnPool()
{
	return connPool;
}

void DbInit::releasePool()
{
	if (connPool) {
		delete connPool;
		connPool = nullptr;
		cout << "mysql connection pool release finish." << endl;
	}
}
