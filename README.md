# GodOfVPN-Javacpp (Skeleton)
Minimal Java (JDK 17) + C++ (JNI) project that compiles a shared library and calls it from Java.

## Structure
- `java_cli/src/com/example/app/` → Java sources (`Core`, `Main`)
- `cpp_core/src/core.cpp` → JNI implementation
- GitHub Actions builds `libcore.so`, runs the Java app, and uploads artifacts.

## Run locally (Linux/Mac)
```bash
mkdir -p target/classes cpp_core/include
javac -h cpp_core/include -d target/classes $(find java_cli/src -name "*.java")
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -Icpp_core/include \
   -fPIC -shared cpp_core/src/core.cpp -o target/libcore.so
java -Djava.library.path=target -cp target/classes com.example.app.Main Mahdi
