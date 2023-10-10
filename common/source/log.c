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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#include <FreeRTOS.h>
#include <task.h>

#include <include/log.h>
#include <include/time.h>
#include <include/uart.h>

#define PRINTF_MAX_BUF            2560
static char log_buf[PRINTF_MAX_BUF] = {'\0'};

static void log_header_format(void)
{
	uint64_t now = get_boot_time_ns();
	uint32_t sec = now / 1000000000;
	uint32_t mini_sec = now % 1000000000 / 1000000;

	snprintf(log_buf, sizeof(log_buf), "[%lu.%03lu] ", sec, mini_sec);
}

int __wrap_printf(const char *fmt, ...)
{
	uint8_t log_buf_used = 0;
	char *log_buf_to_write = NULL;
	va_list args;

	taskDISABLE_INTERRUPTS();
	log_header_format();
	log_buf_used = strlen(log_buf);
	log_buf_to_write = log_buf + log_buf_used;
	va_start(args, fmt);
	vsnprintf(log_buf_to_write, PRINTF_MAX_BUF - log_buf_used, fmt, args);
#ifdef CFG_USART_SUPPORT
	usart_printf(log_buf, strlen(log_buf));
#endif
	va_end(args);
taskENABLE_INTERRUPTS();
	return 0;
}

int log_init()
{
#ifdef CFG_USART_SUPPORT
	usart_printf_init();
#endif
	return 0;
}
