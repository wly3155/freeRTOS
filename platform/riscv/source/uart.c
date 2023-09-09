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

#include <FreeRTOS.h>

#include <string.h>
#include "ns16550.h"

void usart_printf(const char *buf, uint8_t len)
{
	struct device dev;
	uint8_t i = 0;

	dev.addr = NS16550_ADDR;
	portENTER_CRITICAL();

	for (i = 0; i < len; i++)
		vOutNS16550(&dev, buf[i]);

	portEXIT_CRITICAL();
}

void usart_printf_init(void)
{

}
