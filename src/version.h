#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

#ifdef VERSION_INFO
    #define VERSION_CSTRING MACRO_STRINGIFY(VERSION_INFO)
#else
    #define VERSION_CSTRING "dev"
#endif