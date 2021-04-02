/*
 * letimer.c
 *
 *  Created on: Mar 31, 2021
 *      Author: Andrew Murfin
 */

//***********************************************************************************
// Include files
//***********************************************************************************
#include "btnevtfifo.h"

//***********************************************************************************
// defined files
//***********************************************************************************

//***********************************************************************************
// global variables
//***********************************************************************************

//***********************************************************************************
// function
//***********************************************************************************

struct btn_evt_node_t* create_queue(state_change_t state_change) {
    struct btn_evt_node_t * head = NULL;
    if (is_empty(&head))
    {
    	head = create_new_node(state_change);
    	return head;
    }
    else
    	return NULL;
}

struct btn_evt_node_t* create_new_node(state_change_t state_change) {
    struct btn_evt_node_t * newNode = (struct btn_evt_node_t *) malloc(sizeof(struct btn_evt_node_t));
    newNode->state_change = state_change;
    newNode->next = NULL;
    return newNode;
}

state_change_t peek(struct btn_evt_node_t** head) {
    return (* head)->state_change;
}

void pop(struct btn_evt_node_t** head) {
    struct btn_evt_node_t * oldHead = * head;
    (*head) = (*head)->next;
    free(oldHead);
}

void push(struct btn_evt_node_t** head, state_change_t state_change) {
    struct btn_evt_node_t * currNode = * head;
    struct btn_evt_node_t * newNode = create_new_node(state_change);
    while (currNode->next != NULL)
        currNode = currNode->next;
    newNode->next = NULL;
    currNode->next = newNode;
}

bool is_empty(struct btn_evt_node_t** head) {
    if ((*head) == NULL)
        return true;
    else
        return false;
}

void empty_queue(struct btn_evt_node_t** head) {
    while (!is_empty(head))
        pop(head);
}
