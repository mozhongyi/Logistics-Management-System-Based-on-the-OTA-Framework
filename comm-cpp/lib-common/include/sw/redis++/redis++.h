/**************************************************************************
   Copyright (c) 2017 sewenew

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 *************************************************************************/

#ifndef SEWENEW_REDISPLUSPLUS_REDISPLUSPLUS_H
#define SEWENEW_REDISPLUSPLUS_REDISPLUSPLUS_H

#ifdef _MSC_VER
#define ssize_t redis_ssize_t
#pragma warning(push)
#pragma warning(disable: 4200)
#endif

#include "redis.h"
#include "redis_cluster.h"
#include "queued_redis.h"
#include "sentinel.h"

#ifdef _MSC_VER
#undef ssize_t
#pragma warning(pop)
#endif

#endif // end SEWENEW_REDISPLUSPLUS_REDISPLUSPLUS_H
