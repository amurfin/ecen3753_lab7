#include <stdlib.h>
#include "ctest.h"
#include "btnevtfifo.h"

// push_and_peek_test_1:
// Tests queue creation w/button 0, and a push of falling btn0.
// Tests that peeked data is as expected, and is_empty returns true after
// two pops.

CTEST_DATA(push_and_peek_test_1) {
	struct btn_evt_node_t * head;
};

CTEST_SETUP(push_and_peek_test_1) {
	data->head = create_queue(btn0);
	push(&data->head, btn1);
}

CTEST2(push_and_peek_test_1, test_peekpopnempty)
{
	state_change_t test_state = peek(&data->head);
	pop(&data->head);
	ASSERT_EQUAL(btn0, test_state);
	test_state = peek(&data->head);
	pop(&data->head);
	ASSERT_EQUAL(btn1, test_state);
	bool test_is_empty = is_empty(&data->head);
	ASSERT_EQUAL(true, test_is_empty);
}

// push_and_peek_test_2
// Tests queue creation with button 0, peek to confirm button 0
// pushes button 1, button 0 and button 0
// peeks again to confirm button 0 (first one wasn't popped) then pops it
// calls is_empty and confirms False
// peeks to confirm button 1, pops
// peeks to confirm button 0, pops
// pushes button 1
// calls is_empty, confirms false
// now w/two nodes in queue, calls empty_queue
// calls is_empty and confirms true

CTEST_DATA(push_and_peek_test_2) {
	struct btn_evt_node_t * head;
};

CTEST_SETUP(push_and_peek_test_2) {
	data->head = create_queue(btn0);
}

CTEST2(push_and_peek_test_2, test_the_things)
{
	state_change_t test_state = peek(&data->head);
	ASSERT_EQUAL(btn0, test_state);
	push(&data->head, btn1);
	push(&data->head, btn0);
	push(&data->head, btn0);
	test_state = peek(&data->head);
	ASSERT_EQUAL(btn0, test_state);
	pop(&data->head);
	bool test_is_empty = is_empty(&data->head);
	ASSERT_EQUAL(false, test_is_empty);
	test_state = peek(&data->head);
	ASSERT_EQUAL(btn1, test_state);
	pop(&data->head);
	test_state = peek(&data->head);
	ASSERT_EQUAL(btn0, test_state);
	pop(&data->head);
	push(&data->head, btn1);
	test_is_empty = is_empty(&data->head);
	ASSERT_EQUAL(false, test_is_empty);
	empty_queue(&data->head);
	test_is_empty = is_empty(&data->head);
	ASSERT_EQUAL(true, test_is_empty);
}
