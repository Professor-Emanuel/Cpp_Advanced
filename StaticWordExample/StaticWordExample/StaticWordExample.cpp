// static outside a class/struct: means that LINKAGE of that symbol  is going to be internal (visible only 
// to that translation unit that you've defined it in.)
// 
// static inside  a class/struct: means that the variable is going to SHARE memory with all of the INSTANCES
// of the CLASS (basically across all instances created of that class/struct, there is ONLY one INSTANCE
// of that variable) - similar thing applies to static METHODS

#include <iostream>


// Example 1 
// the static varible & function below, won't be visible in Main.cpp at compile time
//use STATIC when you don't need a variable to be available GLOBALLY
static int s_Varible = 5;

static void Function() {

}
