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

#ifndef __LIST_H__
#define __LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include <include/atomic.h>
#include <include/container_of.h>

#define LIST_POISON1			(0)
#define LIST_POISON2			(0)

struct list_t {
    struct list_t *prev, *next;
};

static inline void __list_add(struct list_t *list,
    struct list_t *prev, struct list_t *next)
{
	next->prev = list;
	list->prev = prev;
	list->next = next;
	WRITE_ONCE(prev->next, list);
}

static inline void list_add(struct list_t *list, struct list_t *head)
{
	__list_add(list, head, head->next);
}

static inline void list_add_tail(struct list_t *list, struct list_t *head)
{
	__list_add(list, head->prev, head);
}

static inline void __list_delete(struct list_t *prev, struct list_t *next)
{
	next->prev = prev;
	WRITE_ONCE(prev->next, next);
}

static inline void list_delete(struct list_t *list)
{
	__list_delete(list->prev, list->next);
	list->prev = LIST_POISON1;
	list->next = LIST_POISON2;
}

static inline void list_init(struct list_t *list)
{
	WRITE_ONCE(list->prev, list);
	WRITE_ONCE(list->next, list);
}

#define list_is_head(list, head) \
	((list) == (head)) ? true : false

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

#define list_for_each(pos, head) \
	for (pos = (head)->next; list_is_head(pos, head); pos = pos->next)

#define list_for_each_safe(pos, n, head) \
	for (pos = (head)->next, n = pos->next; \
		!list_is_head(pos, (head)); \
		pos = n, n = pos->next)

#ifdef __cplusplus
}
#endif

#endif