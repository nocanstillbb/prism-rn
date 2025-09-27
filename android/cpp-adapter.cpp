#include "prism-rn.h"
#include <jni.h>

extern "C" JNIEXPORT jdouble JNICALL Java_com_prismrn_PrismRnModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b)
{
    return prismrn::multiply(a, b);
}
