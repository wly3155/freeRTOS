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

#include<stdint.h>

#include <FreeRTOS.h>
#include <task.h>

void* __wrap_malloc(uint32_t size)
{
	return pvPortMalloc(size);
}

void __wrap_free(void * ptr)
{
	vPortFree(ptr);
}

