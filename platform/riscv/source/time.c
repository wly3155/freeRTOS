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

#include <include/encoding.h>
#include <include/time.h>

uint64_t get_boot_time_ns(void)
{
	uint32_t high = 0, low = 0;

	do {
		high = csr_read(CSR_TIMEH);
		low = csr_read(CSR_TIME);
	} while (high != csr_read(CSR_TIMEH));

	return (((uint64_t)high << 32 | low) * 100);
}
