/*
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

#ifndef __UTILITY_H__
#define __UTILITY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

extern void *pvPortMalloc(size_t xWantedSize);
extern void vPortFree(void * pv);
#define malloc(x)	pvPortMalloc(x)
#define free(x)		vPortFree(x)

#define log(x)		vSendString(x)

#ifdef __cplusplus
}
#endif

#endif