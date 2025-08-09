package com.example.app;

public class Core {
    // متد نیتیو که در ++C پیاده‌سازی می‌کنیم
    public static native String greet(String name);

    static {
        // اسم لایبرری که در CI می‌سازیم: libcore.so
        System.loadLibrary("core");
    }
}
