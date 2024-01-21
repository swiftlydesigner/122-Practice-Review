//
//  BuffOverflow.c
//  122 Lab Sample Code
//
//  Created by Kyle Parker on 1/20/24.
//
#include "BuffOverflow.h"
#include <string.h>
#include <locale.h>

// From mitre.org. CWE-121
#define BUFSIZE 256
int cwe121Basic(int argc, char **argv) {
    char buf[BUFSIZE];
    
    // This will overflow when argv[1] is larger than BUFSIZE.
    // We can migrate this attack by using strncpy
    strcpy(buf, argv[1]);
    return 0;
}



// This is an example of not checking your bounds and performing
// an out-of-bounds write (CWE-787). This can cause memory corruption
// and lead to undefined program behavior or crashes. If this
// was a critical section of code (i.e., the kernel), it may allow
// us to change critical bits switching our access to files/settings,
// cause a system crash, or lead to unexpected behaviors.
void cwe121Buffer(void) {
    // MARK: Declare Variables
    char a = 10;
    
    printf("[34] a = %d\n\n", a);
    
    char str3[5] = " !";
    
    printf("[38] a = %d\nstr3 = `%s`\n\n", a, str3);
    
    // This is has 15 chars in the string
    char str2[14] = "     is weird";
    
    printf("[43] a = %d\nstr3 = `%s`\nstr2 = `%s`\n\n", a, str3, str2);
    
    // The string below has a size of 15 (including \0). It only has
    // 10 to store into. Thus, 5 chars overflow.
    /// WARN: Initializer-string for char array is too long
    char str1[10];
    char * str1CopyValue = "Something here";
    
    // MARK: Override str2 from str1 write
    
    for (int i = 0; i < strlen(str1CopyValue); ++i) {
        str1[i] = str1CopyValue[i]; // strcpy will not work for this ex, so we must use a for loop
    }
    
    printf("a = %d\nstr3 = `%s`\nstr2 = `%s`\nstr1 = `%s`\n\n", a, str3, str2, str1);
    
    // Now, lets change the value of a using str1, str2, and str3.
    
    // MARK: Change a from modifing str1
    str3[0x5] = 23;
    
    "LITERAL STRING TO SHOW DIFFERENCE"; // Ignore this. It is used in the screenshot, logs, and explaination
    
    printf("a = %d\nstr3 = `%s`\nstr2 = `%s`\nstr1 = `%s`\n\n", a, str3, str2, str1);
    
    // MARK: Change a from modifing str2
    str2[-0x1000b] = 4;
    
    printf("a = %d\nstr3 = `%s`\nstr2 = `%s`\nstr1 = `%s`\n\n", a, str3, str2, str1);
    
    // MARK: Change a from modifing str3
    str1[-0x10001] = 12;
    
    printf("a = %d\nstr3 = `%s`\nstr2 = `%s`\nstr1 = `%s`\n\n", a, str3, str2, str1);
    
    // For me to write the lines above to modify a, I needed to first look at the memory addresses.
    // This shows that if you overflow (or somehow underflow) an array, you can override sensitive
    // data and corrupt your program leading to either a data leak or corrcupted data. Note that this
    // code could crash on your system because the offsets point to a protected region of memory.
    // Regardless, it is unlikely to change the values of a.
    
    // If this line prints addresses from lower to higher
    // (for vars a through str3), you will see the overflow caused by
    // the for loop above. This may not work on your system.
    printf("Address Table:\nVariable:\ta\t\t\tstr1\t\tstr2\t\tstr3\nAddress:\t%p\t%p\t%p\t%p\t\n\n", &a, str1, str2, str3);
    
    printf("Other Address Table:\nVariable:\tstr1CopyValue\nAddress:\t%p\t\n\n", str1CopyValue);
    
    // Not exactly a buffer overflow, but it is an instance of
    // how overflows can leak sensitive information
    // Of course, this is a basic CS course, so comprehension of
    // this is not expected.
    printf("-------------BEGIN HEART BLEED-------------\n");
    
    // Do not use define statements like this.
    // This is purely to seperate the variables.
#define HEART_BLEED_MAX 65536
    // This is similar to a heart-bleed attack. A heart-bleed occurs when we read more than we should.
    // Lets try to read other data where str1CopyValue is stored.
    char largeBuffer[HEART_BLEED_MAX]; // Warning: Some devs may have troubles with this
    char * rdOnlySec = (char*)0x100000000;
    
    size_t i = 0;
    
    for (; i < HEART_BLEED_MAX; ++i) {
        // This will copy over the data and go to the next char
        largeBuffer[i] = *rdOnlySec++;
    }
    
    // Print the read data. As I do not know what largeBuffer will
    // contain after the loop above, I need to print each indv char.
    // If there is a null char, then it will stop printing.
    for (i = 0; i < HEART_BLEED_MAX; ++i) {
        printf("%c", largeBuffer[i]);
    }
    
    printf("\n\n");
    printf("-------------END HEART BLEED-------------\n");
}
