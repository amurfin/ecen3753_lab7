/*
 * btnevtfifo.h
 *
 *  Created on: Mar 31, 2021
 *      Author: Andrew Murfin
 */

#ifndef SRC_HEADER_FILES_BTNEVTFIFO_H_
#define SRC_HEADER_FILES_BTNEVTFIFO_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//***********************************************************************************
// defined files
//***********************************************************************************

/**
 * @brief
 * Structure of button event fifo
 *
 * @param state_change
 * Enumeration to hold state change, either rising or falling edge.  Default value
 * should be "none"
 *
 * @param next
 * Next node in the fifo
 */
typedef enum state_change_t
{
	none,
	btn0,
	btn1
} state_change_t;

typedef struct btn_evt_node_t
{
	state_change_t state_change;
	struct btn_evt_node_t * next;
} btn_evt_node_t;

//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Creates a queue.
///
/// @param[in] state_change The state change type for the new head element
///
/// @return the head of the new queue
///
//----------------------------------------------------------------------------------------------------------------------------------
struct btn_evt_node_t* create_queue(state_change_t state_change);

//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Create a new node for the queue
///
/// @param[in] state_change
///	State change type for the new node
///
/// @return a newly allocated task
//----------------------------------------------------------------------------------------------------------------------------------
struct btn_evt_node_t* create_new_node(state_change_t state_change);

//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Returns the state change type of the top node in the queue
///
/// @param head The head of the queue
///
/// @return the state change type at the top of the queue
//----------------------------------------------------------------------------------------------------------------------------------
state_change_t peek(struct btn_evt_node_t** head);

//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Removes the element at the top of the queue.
///
/// @param head The head of the queue.
//----------------------------------------------------------------------------------------------------------------------------------
void pop(struct btn_evt_node_t** head);

//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Push a new state change into the queue
///
/// @param head The head of the queue
/// @param state_change The state_change to be put into the queue
//----------------------------------------------------------------------------------------------------------------------------------
void push(struct btn_evt_node_t** head, state_change_t state_change);

//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Determines whether the specified head is empty.
///
/// @param head The head of the Queue
///
/// @return True if the specified head is empty, False otherwise.
//----------------------------------------------------------------------------------------------------------------------------------
bool is_empty(struct btn_evt_node_t** head);

//----------------------------------------------------------------------------------------------------------------------------------
/// @brief Remove all items from the queue
///
/// @param head The head of the queue
//----------------------------------------------------------------------------------------------------------------------------------
void empty_queue(struct btn_evt_node_t** head);

#endif /* SRC_HEADER_FILES_BTNEVTFIFO_H_ */
