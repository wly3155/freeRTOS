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
#include <task.h>

#include <include/list.h>
#include <include/log.h>
#include <include/utility.h>

struct test_list {
	struct list_t head;
};

struct test_list_message {
	struct list_t list;
	uint8_t test_var1;
	uint8_t test_var2;
};

static struct test_list tl;

static void test_list_main(void *param)
{
	struct test_list_message *tlm = NULL;
	struct list_t *pos = NULL, *tmp = NULL;
	static uint8_t test_var1 = 0, test_var2 = 0;

	list_init(&tl.head);
	while (1) {
		tlm = malloc(sizeof(struct test_list_message));
		if (!tlm) {
			vSendString( "malloc fail!" );
			configASSERT(0);
		}
		list_init(&tlm->list);
		tlm->test_var1 = ++test_var1;
		tlm->test_var2 = ++test_var2;
		list_add_tail(&tlm->list, &tl.head);
		logi("Hello FreeRTOS %u %u!\n", tlm->test_var1, tlm->test_var2);

		printf("dump list start\n");
		list_for_each_safe(pos, tmp, &tl.head) {
			tlm = list_entry(pos, struct test_list_message, list);
			printf("tlm->test_var1 %u test_var2 %u\n",
				tlm->test_var1, tlm->test_var2);
			list_delete(pos);
		}
		printf("dump list end\n");

		vTaskDelay(1000);
	}
}

void test_list_init(void)
{
#define TEST_LIST_TASK_STACK_DEPTH (512)
#define TEST_LIST_TASK_PRIORITY (configMAX_PRIORITIES - 3)
	vSendString( "Hello FreeRTOS!" );
	xTaskCreate(test_list_main, "test_list", TEST_LIST_TASK_STACK_DEPTH,
		NULL, TEST_LIST_TASK_PRIORITY, NULL);
	vTaskStartScheduler();
}
