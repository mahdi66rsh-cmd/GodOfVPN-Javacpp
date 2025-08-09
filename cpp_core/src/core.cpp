#include <jni.h>
#include <string>

// امضای JNI باید دقیقاً با پکیج و کلاس/متد جاوا یکی باشد:
// Java_{package_underscored}_{ClassName}_{methodName}
// package: com.example.app  →  com_example_app
// class:   Core
// method:  greet
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_app_Core_greet(JNIEnv* env, jclass /*clazz*/, jstring jname) {
    const char* nameChars = env->GetStringUTFChars(jname, nullptr);
    std::string name = (nameChars ? nameChars : "User");
    if (nameChars) env->ReleaseStringUTFChars(jname, nameChars);

    std::string out = "Hello from C++ 👋, " + name + "!";
    return env->NewStringUTF(out.c_str());
}
