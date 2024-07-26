## PT  
A PT is a program structure that allows a function to suspend execution midway and resume later without blocking the entire program. Coroutines are widely used in modern programming, especially in scenarios requiring concurrent tasks such as I/O operations and network requests.

## Features

	1. Non-blocking: Coroutines can suspend while waiting for a task to complete, yielding execution to other coroutines, thus achieving non-blocking concurrent processing.
	2. Lightweight: Compared to threads, coroutines are more lightweight, requiring no support from the operating system kernel, and have lower overhead for creation and destruction.
	3. Cooperative multitasking: Unlike preemptive multitasking (such as threads), coroutines rely on the program to explicitly yield control.

## Implementation

There are various API to implement coroutines, mainly including:

	1. PT_INIT()  
	2. PT_BLOCK() 
	3. PT_DEINIT() 
	4. PT_RESUME() 
	5. PT_CREATE() 
see the example 'main.c' file.

## compile  
`scons` 

## Application Scenarios

	1. I/O intensive tasks: Such as file reading/writing and network requests, coroutines can yield execution while waiting for I/O operations to complete, thus improving efficiency.
	2. High-concurrency servers: For example, network servers can handle many concurrent connections using coroutines, enhancing performance.
	3. User interface programming: In GUI programming, coroutines can handle asynchronous events to avoid interface freezing.

## author
MIT by Jim

