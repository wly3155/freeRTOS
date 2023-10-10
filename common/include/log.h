/*
 * This file is licensed under the Apache License, Version 2.0.
 *
 * Copyright (c) 2023 wuliyong3155@163.com
 *
 * A copy of the license can be obtained at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PRINTF_SUPPORT
#define DEFAULT_LOG_LEVEL        (LOG_INFO)

enum {
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARN,
	LOG_ERROR,
};

#ifdef PRINTF_SUPPORT
#define logd(format, ...) \
	if (LOG_DEBUG >= DEFAULT_LOG_LEVEL) printf(format, ##__VA_ARGS__)
#define logi(format, ...) \
	if (LOG_INFO >= DEFAULT_LOG_LEVEL) printf(format, ##__VA_ARGS__)
#define logw(format, ...) \
	if (LOG_WARN >= DEFAULT_LOG_LEVEL) printf(format, ##__VA_ARGS__)
#define loge(format, ...) \
	if (LOG_ERROR >= DEFAULT_LOG_LEVEL) printf(format, ##__VA_ARGS__)
#else
#define logd(format, ...) {}
#define logi(format, ...) {}
#define logw(format, ...) {}
#define loge(format, ...) {}
#endif

int log_init();

#ifdef __cplusplus
}
#endif
#endif