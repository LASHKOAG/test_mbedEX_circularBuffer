/*
743 example from gocumentation
*/
/*
 * Copyright (c) 2016-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed.h"
#include "platform/CircularBuffer.h"
 
#define BUF_SIZE    10
 
CircularBuffer<char, BUF_SIZE> buf;
char data_stream[] = "DataToBeAddedToBuffer";
 
int main()
{
    uint32_t bytes_written = 0;
    
    while (!buf.full()) {
        buf.push(data_stream[bytes_written++]);
    }
    
    printf("Circular buffer is full: \"%s\" or empty: \"%s\" \n", 
           (buf.full()? "true":"false"), 
           (buf.empty()? "true":"false") );
    printf ("Bytes written %d \n", bytes_written);
    
    // If buffer is full, contents will be over-written
    buf.push(data_stream[bytes_written++]);
    
    char data;
    printf ("Buffer contents: ");
    while (!buf.empty()) {
        buf.pop(data);
        printf("%c", data);
    }
    printf("\n");
 
    printf("Circular buffer is full: \"%s\" or empty: \"%s\" \n", 
           (buf.full()? "true":"false"), 
           (buf.empty()? "true":"false") );
 
    return 0;
    
}