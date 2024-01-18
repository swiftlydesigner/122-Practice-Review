//
//  MallocReview.c
//  122 Lab Sample Code
//
//  Created by Kyle Parker on 1/16/24.
//

#include "MallocReview.h"

// Include string.h here since it is only used in MallocReview.h
// and no other files will need it. If other files would need string.h,
// then we would want to put it in the MallocReview.h file.
#include <string.h> // memset

/**
 For all malloc functions, you need to include stdlib.h. I included this in the MallocReview.h file.
 */

#define TEN_THOUSAND 10000

// MARK: - MALLOC
// This is a CORRECT example of how to use malloc.
void goodMalloc(void) {
    // MARK:
    // Suppose I want to have a 10_000 integer array.
    // Since this is 10_000 * 4 = 40_000 = 0.04 mb.
    // If this function is called 4 times, that is 0.16mb.
    //
    // While this may appear a small number, remember, this
    // is on the call stack. We want a lot of space for calls
    // to functions, not variables. So, we use the heap for
    // large allocations.
    //
    // You will also see a warnings in VS when you have a large
    // array in main(). Try putting `long aLotOfLongs[100000];`
    // in your main(). Observe it's warning and the suggestion.
    
    int * randomInts = (int *)malloc(sizeof(int) * TEN_THOUSAND);
    
    // MARK: Check it!
    
    // Recall: any value other than 0 is considered logically true
    // in C. 0 is considered false. That is why we can check if
    // a dynamically allocated variable was allocated by using the
    // below line. Null = 0, Any addr is non-zero.
    if (!randomInts) {
        // If this a console app, report a memory allocation error
        // if it was requested by the user.
        //
        // If this was requested by the system and it is intended to
        // interact with a user (not a back-end system), *log* the
        // error and attempt to remedy the problem; if you cannot
        // recover, then notify the user.
        //
        // There are many different contexts, so pick the most useful
        // action. Make sure you return, think of this as a guard
        // block where it will take a terminating path.
        //
        // If this is a void function and success does not matter,
        // then you can simply return as I do. If this is a critical
        // block of code, then you want to return false (a bool) or
        // if an error code if returns an int.
        return;
    }
    
    // MARK: Let's minipulate it!
    
    // MARK: Set everything to 0
    // We always want to set the values to 0 initally. If we have
    // a specific task where we want -1 or such, then we need to
    // use a loop and the following line will not work. The
    // following only works with setting values to 0. You can use
    // thisfor any type (will be very useful with strings).
    // '\0' == 0, thus we use the following line with strings.
    memset(randomInts, 0, TEN_THOUSAND * sizeof(int));
    
    // MARK: Assign random numbers to every position
    // Iterate from 0 to 10_000. This part should be really easy
    // to understand. I also use ++i instead of i++. See NOTE1.
    for (int i = 0; i < TEN_THOUSAND; ++i) {
        // Note how we use this the same as if we said `int randomInts[TEN_THOUSAND];`
        // The only difference is where the memory address is.
        // If we use the malloc version, then all variables are
        // stored in the call stack. If they are locally declared
        // (static memory), then we will find them in the stack call.
        
        // Recall: You should call srand in main before using rand.
        randomInts[i] = rand();
    }
    
    // MARK: Free it!
    
    // This is a very important part. If you forget to call free,
    // you will experience a "memory leak". This is simply memory
    // that is not properly released after being used. When this
    // function returns, malloc is not cleaned up. This is a good
    // thing. What if we wanted to return this value? Then we use
    // malloc and do not call free here. Once we are done
    // processing the ints, then we can call free anywhere in the
    // program.
    //
    // Important note: If free is called on a non-allocated variable,
    // it will cause an exception on some systems. Try it!
    free(randomInts);
    
    // It is good practice to set randomInts to NULL as free will only
    // allow that section of memory to be realeased to the system.
    // By assigning randomInts to NULL, it allows to check it before
    // we use it.
    //
    // Of course, since the program returns and there is nothing
    // following the call to randomInts, this line is not necessary in
    // this program.
    randomInts = NULL;

}

void badMalloc(void) {
    // Never make it a void *. We are working with an unknown type.
    // This is very poor practice. If you need more than one type,
    // create a structure and figure out your needs through that.
    // Additionally, you may want reconsider your ideas to use a single
    // type.
    //
    // If you must use the same variable for mutiple types, use a union.
    // It will allow you to use multiple types grouped under the same
    // varible. See https://cplusplus.com/doc/tutorial/other_data_types/
    //
    // Another problem with our code is we have 8 * 500. We do not know
    // what 8 is and 500 mean. I think it is possibly 8 bytes per element
    // times 500 elements as that is the format we use, but it could be
    // 8 elements of size 500. To eliminate confusion, we use the sizeof()
    // function to get the correct size and makes the code system independent.
    // For example, my machine may use 4 bytes for an int, but another
    // system uses 8 bytes. If a machine thought the size of int was larger than
    // what is allocated, then we will unintentionally override data in the
    // overlapping memory address, but it could also be overriden by that value
    // leading to undefined behvaior. Further, this opens a vulnerability where
    // you are writing to a location and the other program could read that data
    // and steal it. That adds to the list of reasons why we use sizeof(TYPE) * SIZE.
    //
    // We want to give a name that is easy to understand the use. array tells us nothing.
    // For example, if we want to store numbers of 500 students' grade, we could call it
    // studentGrades, or simply grades if we knew it was the students'.
    void * array = malloc(8 * 500);
    
    // We do not check if it succeded, so we could be writing to NULL. The computer
    // will force the program to crash if we write. Always be sure to check if we
    // were allocated the space requested.
    
    // First off, we should not mix types. This makes everything much more complicated.
    // Always be sure to use a single type so that we do not need to ensure values are
    // not overriden. (On my system), sizeof(int) = 4, sizeof(double) = 8, sizeof(char) = 1.
    // So when we cast to an int *, we are writing to addresses 0x00-0x04. When we cast to
    // double *, we are writing to addresses 0x08-0x0F. When we cast to char *, we are
    // writing address 0x02. As we can see, double does not override anything or get overriden.
    // When we write to the char, it will override part of the int and corrupt the value. The
    // bits for the third byte are changed and therfore ((int *)array)[0] no longer equals 100.
    ((int *)array)[0] = 100;
    ((double *)array)[1] = 4.525;
    ((char *)array)[2] = 0x005;

    // If we do not return array, then we want to be sure free() is called on array.
}

// MARK: - CALLOC
// Calloc is a way of allocating an array and is similar to malloc, but helps with design to
// clearly indicate it is an array of some type. You do not pass in a type explicitly, but
// you pass in the size. When we use sizeof(), the reader will know what type the array is.
void goodCalloc(void) {
    // Important note: When we use sizeof(), we use int since favNums is of type int *. The
    // type we allocate for should be one less level of indirection than the variable's type.
    // What that means is when we have favNums of type int * (one star), then we should
    // allocate space for a type int (zero star). It returns a pointer, so ideally, a pointer
    // will point to one less level of indirection. Note that it should be exactly one and not
    // two or more. If you require more assistance with pointers, please email me.
    int * favNums = (int *)calloc(6, sizeof(int));
    
    // Same reasoning as with malloc.
    if (!favNums) {
        return;
    }
    
    // Assume the following numbers are from users. To conserve space, I put them on the same
    // line; do not do this in practice.
    favNums[0] = 10;    favNums[1] = 24;
    favNums[2] = 56;    favNums[3] = 43;
    favNums[4] = 67;    favNums[5] = 67;
    
    // Same reasoning as with malloc.
    free(favNums);
}

void badCalloc(void) {
    // Same as malloc, poor naming, not checking allocation, and poor handing of memory leaks.
}

// MARK: - REALLOC
void goodRealloc(void) {
    // Note: All code upto realloc has already been discussed.
    int * sequentialNums = calloc(10, sizeof(int)); // or malloc(sizeof(int) * 10)
    // Since we override all the data in this array, we do not need to reset all
    // values to 0. If we wanted to, then use the following line.
    
    // memset is in string.h. We use it set a value to every element in an array.
    // Note: this only works well with strings which is why you find it in string.h.
    // Always use this when working with strings as we are not guaranteed the bytes
    // are empty.
    //
    // Param 0: The array to manipulate
    // Param 1: The value or character to set (if type is wider than 1 byte, you *must* put 0)
    // Param 2: The number of elemnts to set (if type is wider than 1 byte, you must multiply by that size)
    memset(sequentialNums, 0, 10 * sizeof(int));
    
    if (!sequentialNums) {
        return;
    }
    
    for (int i = 0; i < 10; ++i)
        sequentialNums[i] = i;
    
    // Now we are out of room, we have set all 10 numbers. We need to have an array of
    // nums from 0 to 100 (size of 101).
    //
    // realloc will return a pointer to the new address space. Data is preserved through
    // this call. If it was not, this would be a very useless function. Our first argument
    // is the old address and the new size. Note: If you have a size smaller than the
    // original size, you risk losing data you do not intend to.
    sequentialNums = realloc(sequentialNums, sizeof(int) * 101);
    
    // If we wanted to zero the new region out, we can then use:
    memset(sequentialNums + (10 * sizeof(int)) /* Preserve first 10 values */, 0, 91 * sizeof(int) /* 101 - 10 */);
    
    // Once again, we need to make sure sequentialNums is non-NULL.
    
    if (!sequentialNums) {
        return;
    }
    
    // Only set new region
    for (int i = 10; i < 101; ++i)
        sequentialNums[i] = i;
    
    // return sequentialNums
    
    // Since we return it on the line above, we do not need to call free.
}

void badRealloc(void) {
    int * sequentialNums = calloc(10, sizeof(int)); // or malloc(sizeof(int) * 10)
    
    for (int i = 0; i < 10; ++i)
        sequentialNums[i] = i;
    
    sequentialNums = realloc(sequentialNums, sizeof(int) * 101);
    
    for (int i = 0; i < 101; ++i)
        sequentialNums[i] = i;
    
    // While all of the above uses good naming, we are not guaranteed memory is allocated.
    // Therefore, we must check if they are non-null.
}


// MARK: - NOTE1
// NOTE1: i++ vs ++i
// What is the difference? The result is the same.
// When we are really picky about performance,
// we want to use ++i since it will increment the value,
// then return it. A total of 3 instructions (see detailed
// version below). When we use i++, we need to store
// the value of i, increment i, then return the old value.
// So, ++i will have one less instruction and take less
// memory. But these differences are so small that modern
// machines do not show the lag. But if we are designing a
// critical system (i.e., pre-collision system on a vehicle),
// then the small memory usage and performance advantage will
// make ++i more ideal. This is because a slight hesitation
// could allow the vehicle to run 20 more feet than it should.
// Those 20 feet could be difference between life and death.

// Detailed version of NOTE1:
// We have a MOV inst to read the value of i, ADD inst for i + 1,
// STR to save the value back to i. Sample Assembly code:
//
// LDR R0, M1         @ move M1 (i) to the 0th register
// ADD R0, R0, #0x01  @ add R0 with 1, then store result in R0
// STR R0, [M1]       @ store R0 (now i + 1) back to M1 (i)
//
// Note: I use LDR and STR which are very heavy computions and
// use a lot of clock cycles. Assuming we are working with a
// large number, we must use these functions. There may be a
// way to simplify this, but I have no clue how people do it.

